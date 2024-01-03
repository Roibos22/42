/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:08:46 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/11 17:37:29 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Initialises the next statment. Calls parent and child processes if system 
 * command and executes builtins if builtin found.
*/
void	ft_executor(t_token *token, int fdIn, t_data *data)
{
	t_statment	*stm;

	data->stm_count++;
	stm = init_stm(fdIn, token);
	if (stm->start_token->type == PIPE && stm->start_token->prev)
		stm->start_token = stm->start_token->next;
	pipe(stm->pipe);
	stm->fd_in = fdIn;
	if (ft_parser(stm, data))
	{
		prepare_stm(stm, data);
		if (stm->is_builtin == 0 && stm->stm_has_cmd && !stm->stm_has_red_only)
			ft_execute_sys_cmd(stm, data);
		else
			ft_execute_builtin(stm, data);
	}
	else
		ft_exec_next_stm(token, stm, data);
	ft_free_stm(stm);
}

/**
 * Forks the process and calls child and parent command
*/
void	ft_execute_sys_cmd(t_statment *stm, t_data *data)
{
	stm->pid = fork();
	ft_signals(2, data);
	if (stm->pid == 0)
		ft_executor_child(stm, data);
	else
		ft_execute_parent(stm, data);
}

/**
 * handles fd's, exit status of child process and recursively calls
 * ft_executor if there is a next statement
*/
void	ft_execute_parent(t_statment *stm, t_data *data)
{
	int		status;
	int		i;
	t_token	*new_start;

	close(stm->pipe[1]);
	if (stm->fd_out != STDOUT_FILENO)
		close(stm->fd_out);
	if (stm->fd_in != STDIN_FILENO)
		close(stm->fd_in);
	i = 1;
	dup2(data->orig_std_in, STDIN_FILENO);
	dup2(data->orig_std_out, STDOUT_FILENO);
	new_start = stm->start_token;
	ft_exec_next_stm(stm->start_token, stm, data);
	while (i < stm->no_tokens)
	{
		new_start = new_start->next;
		i++;
	}
	close(stm->pipe[0]);
	close(stm->pipe[1]);
	waitpid(stm->pid, &status, 0);
	data->exit_status = WEXITSTATUS(status);
	if (new_start->next == NULL)
		data->exit_status_final = WEXITSTATUS(status);
}

/**
 * executes the system command and manually cleans data if it fails
*/
void	ft_executor_child(t_statment *stm, t_data *data)
{
	ft_prepare_fds(stm);
	if (execve(stm->cmd_path, stm->cmd_args, data->env) == -1)
	{
		ft_perror("minishell: Permission denied\n", NULL, 1, data);
		ft_free_stm(stm);
		ft_clean_data(data, 1);
		exit(EXIT_FAILURE);
	}
}
