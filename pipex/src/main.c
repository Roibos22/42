/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:27:49 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/31 15:48:14 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = parse_data(argc, argv, envp);
	if (pipe(data->pipe) == -1)
		exit (1);
	data->pid1 = fork();
	if (data->pid1 == -1)
		return (0); 
	if (data->pid1 == 0)
		exec_child_1(data);
	data->pid2 = fork();
	if (data->pid2 == -1)
		return (0);
	if (data->pid2 == 0)
		exec_child_2(data);
	clean_exit(data, 1);
	return (0);
}

/*pipe[0] -> read; pipe[1] -> write*/

void	exec_child_1(t_data *data)
{
	dup2(data->pipe[1], STDOUT_FILENO);
	dup2(data->fd_in, STDIN_FILENO);
	close_pipe(data);
	if (execve(get_cmd_path(data->cmd1_args[0], data), \
	data->cmd1_args, NULL) == -1)
	{
		perror("execve");
		clean_exit(data, 1);
	}
}

void	exec_child_2(t_data *data)
{
	dup2(data->pipe[0], STDIN_FILENO);
	dup2(data->fd_out, STDOUT_FILENO);
	close_pipe(data);
	if (execve(get_cmd_path(data->cmd2_args[0], data), \
	data->cmd2_args, NULL) == -1)
	{
		perror("execve");
		clean_exit(data, 1);
	}
}
