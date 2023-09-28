/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:30:11 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/09/01 11:59:43 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data	*parse_data(int argc, char **argv, char **envp)
{
	t_data	*data;
	int		i;

	data = NULL;
	i = 0;
	if (argc == 5)
	{
		data = malloc(sizeof(t_data));
		while (envp[i])
		{
			if (ft_strnstr(envp[i], "PATH", 4))
				data->cmd_paths = ft_split(envp[i] + 5, ':');
			i++;
		}
		data->cmd1_args = ft_split(argv[2], ' ');
		data->cmd2_args = ft_split(argv[3], ' ');
		if (!data->cmd1_args || !data->cmd2_args)
			put_error(ERR_MSG_CMD, data);
		error_handling(argv, data);
	}
	else
		put_error(ERR_MSG_ARGS, data);
	return (data);
}

void	error_handling(char **argv, t_data *data)
{
	char	*path;

	path = get_cmd_path(data->cmd1_args[0], data);
	if (!path)
	{
		free(path);
		put_error(ERR_MSG_CMD, data);
	}
	free(path);
	path = get_cmd_path(data->cmd2_args[0], data);
	if (!path)
	{
		free(path);
		put_error(ERR_MSG_CMD, data);
	}
	free(path);
	data->fd_in = open(argv[1], O_RDONLY);
	if (data->fd_in < 0)
		put_error(ERR_MSG_INFILE, data);
	data->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (data->fd_out < 0)
	{
		close(data->fd_in);
		put_error(ERR_MSG_OUTFILE, data);
	}
}

char	*get_cmd_path(char *cmd, t_data *data)
{
	char	*full_cmd;
	char	*joined_path;
	int		i;

	i = 0;
	full_cmd = ft_strjoin("/", cmd);
	while (data->cmd_paths[i])
	{
		joined_path = ft_strjoin(data->cmd_paths[i], full_cmd);
		if (access(joined_path, X_OK) == 0)
			return (free(full_cmd), joined_path);
		free(joined_path);
		i++;
	}
	return (free(full_cmd), NULL);
}
