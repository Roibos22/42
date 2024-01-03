/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:13:37 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/11 17:33:28 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * checks if str has a valid path to an executable of the system.
 * I t iterates through the PATH env variable and returns the 
 * correect path if available
 * @param *str command or path to be checked
*/
bool	ft_is_system_command(char *str, t_data *data)
{
	char	*full_cmd;
	char	*joined_path;
	int		i;

	if (!data->cmd_paths)
		return (false);
	if (ft_strlen(str) == 0)
		return (false);
	if (ft_strncmp("..", str, 2) == 0)
		return (false);
	full_cmd = ft_strjoin("/", str);
	i = 0;
	while (data->cmd_paths[i])
	{
		joined_path = ft_strjoin(data->cmd_paths[i], full_cmd);
		if (access(joined_path, X_OK) == 0)
			return (free(full_cmd), free(joined_path), true);
		free(joined_path);
		i++;
	}
	free(full_cmd);
	return (false);
}

/**
 * checks if str is one of the 6 builtin functions
*/
bool	ft_is_builtin(char *str)
{
	if (ft_strncmp(str, "echo", 5) == 0)
		return (true);
	else if (ft_strncmp(str, "cd", 3) == 0)
		return (true);
	else if (ft_strncmp(str, "pwd", 4) == 0)
		return (true);
	else if (ft_strncmp(str, "export", 7) == 0)
		return (true);
	else if (ft_strncmp(str, "unset", 6) == 0)
		return (true);
	else if (ft_strncmp(str, "env", 4) == 0)
		return (true);
	else if (ft_strncmp(str, "exit", 5) == 0)
		return (true);
	return (false);
}

/**
 * checks if the string given to is a valid command or path
 * to an excutable.
 * @param *str the command or path given to the function
 */
bool	ft_is_command(char *str, t_data *data)
{
	if (ft_strncmp(str, "echo", 5) == 0)
		return (true);
	else if (ft_strncmp(str, "cd", 3) == 0)
		return (true);
	else if (ft_strncmp(str, "pwd", 4) == 0)
		return (true);
	else if (ft_strncmp(str, "export", 7) == 0)
		return (true);
	else if (ft_strncmp(str, "unset", 6) == 0)
		return (true);
	else if (ft_strncmp(str, "env", 4) == 0)
		return (true);
	else if (ft_strncmp(str, "exit", 5) == 0)
		return (true);
	else if (ft_is_system_command(str, data))
		return (true);
	else if (ft_is_correct_path(str))
		return (true);
	return (false);
}
