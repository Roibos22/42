/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:42:27 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/08 16:45:21 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_redirections(t_token *token, t_statment *stm, t_data *data)
{
	int		exit;

	exit = 1;
	stm->fd_out = stm->pipe[1];
	while (token && token->type != PIPE)
	{
		if (token->type == OUT_REDIR)
			exit = handle_red_out(token, stm, data);
		else if (token->type == APPEND)
			exit = handle_red_app(token, stm, data);
		else if (token->type == IN_REDIR)
			exit = handle_red_in(token, stm, data);
		else if (token->type == HERE_DOC)
			exit = handle_red_heredoc(token, stm, data);
		if (!exit)
			return (exit);
		token = token->next;
	}
	if (stm->fd_out == stm->pipe[1] && !token)
		stm->fd_out = STDOUT_FILENO;
	if (stm->fd_out != stm->pipe[1])
		close(stm->pipe[1]);
	g_received_signal = false;
	return (exit);
}

int	handle_red_out(t_token *token, t_statment *stm, t_data *data)
{
	if (!token->next)
		return (ft_perror(SY_ERR_ROUT, NULL, 2, data), 0);
	if (access(token->next->content, F_OK) == -1)
		data->created_files = \
		add_str_to_arr(token->next->content, data->created_files);
	stm->fd_out = open(token->next->content, \
	O_CREAT | O_WRONLY | O_TRUNC, 0666);
	return (1);
}

int	handle_red_app(t_token *token, t_statment *stm, t_data *data)
{
	if (!token->next)
		return (ft_perror(SY_ERR_RAPP, NULL, 2, data), 0);
	if (access(token->next->content, F_OK) == -1)
		data->created_files = \
		add_str_to_arr(token->next->content, data->created_files);
	stm->fd_out = \
	open(token->next->content, O_CREAT | O_WRONLY | O_APPEND, 0666);
	return (1);
}

int	handle_red_in(t_token *token, t_statment *stm, t_data *data)
{
	if (token->next == NULL)
		return (ft_perror(SY_ERR_RIN, NULL, 2, data), 0);
	if (str_in_array(token->next->content, data->created_files))
		return (ft_perror(NO_FILE, NULL, 1, data), 0);
	if (access(token->next->content, R_OK) == -1)
		return (ft_perror(NO_FILE, NULL, 1, data), 0);
	stm->fd_in = open(token->next->content, O_RDONLY, 0666);
	return (1);
}

int	handle_red_heredoc(t_token *token, t_statment *stm, t_data *data)
{
	char	*line;
	char	*linenl;

	line = "";
	linenl = "";
	stm->fd_in = open(".heredoc", O_CREAT | O_RDWR, 0777);
	if (!token->next)
		return (ft_perror(SY_ERR_HD, NULL, 2, data), 0);
	while (!ft_same_str(line, token->next->content))
	{
		line = readline("> ");
		if (handle_red_heredoc_empty(line, data) == 0)
			break ;
		if (g_received_signal == true)
		{
			g_received_signal = false;
			return (ft_perror(NULL, NULL, 130, data), 0);
		}
		linenl = ft_strjoin(line, "\n");
		if (!ft_same_str(line, token->next->content))
			write(stm->fd_in, linenl, ft_strlen(linenl));
		free(linenl);
	}
	close(stm->fd_in);
	return (stm->fd_in = open(".heredoc", O_RDONLY), 1);
}
