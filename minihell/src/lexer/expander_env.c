/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:41:12 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/07 23:57:52 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * gets the env value of an env variable
*/
char	*get_env_value(char *var_name, char **env, t_data *data)
{
	int		len;
	int		i;
	char	*exit_status;
	char	*exit;

	if (var_name == NULL)
		return (NULL);
	if (ft_strncmp(var_name, "?", 1) == 0)
	{
		exit_status = ft_itoa(data->exit_status);
		exit = ft_strjoin(exit_status, var_name + 1);
		free(exit_status);
		return (exit);
	}
	len = strlen(var_name);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], var_name, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}

/**
 * gets the env variable name
*/
char	*get_var_name(char *ptr, char *end)
{
	int		len;
	char	*temp;
	char	*var_name;

	len = end - ptr - 1;
	temp = malloc(len + 1);
	ft_strlcpy(temp, ptr + 1, len + 1);
	temp[len] = '\0';
	var_name = ft_strdup(temp);
	free(temp);
	return (var_name);
}

/**
 * checks if a string has a $ in it and returns the position
*/
int	ft_has_env_value(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (!(!str[i + 1] || str[i + 1] == ' ' || str[i + 1] == '='))
				return (1);
		}
		i++;
	}
	return (0);
}
