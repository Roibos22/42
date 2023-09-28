/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:30:13 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/09/01 11:54:19 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	put_error(char *msg, t_data *data)
{
	if (msg)
		ft_printf(msg);
	if (data)
		clean_exit(data, 0);
	exit (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	clean_exit(t_data *data, int success)
{
	if (success)
	{
		close_pipe(data);
		close(data->fd_out);
		close(data->fd_in);
		waitpid(data->pid1, NULL, 0);
		waitpid(data->pid2, NULL, 0);
	}
	if (data->cmd_paths)
		free_tab(data->cmd_paths);
	if (data->cmd1_args)
		free_tab(data->cmd1_args);
	if (data->cmd2_args)
		free_tab(data->cmd2_args);
	if (data)
		free(data);
	exit (1);
}

void	close_pipe(t_data *data)
{
	close(data->pipe[0]);
	close(data->pipe[1]);
}
