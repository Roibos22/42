/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 02:38:39 by smargine          #+#    #+#             */
/*   Updated: 2023/12/08 11:05:55 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * handles the unset command in minishell
*/
int	ft_unset(t_statment *stm, t_data *data)
{
	int	i;
	int	y;

	i = 1;
	if (!stm->cmd_args[i])
		return (EXIT_SUCCESS);
	else
	{
		while (stm->cmd_args[i])
		{
			y = 0;
			while (data->env[y] != NULL)
			{
				if (ft_strncmp(data->env[y], stm->cmd_args[i], \
				ft_var_len(stm->cmd_args[i])) == 0)
				{
					data->env = ft_remove_from_env(stm->cmd_args[i], data->env);
					break ;
				}
				y++;
			}
			i++;
		}
	}
	return (0);
}

/**
 * remove a specific environment variable from the given env array
 * and realocates memory
*/
char	**ft_remove_from_env(char *str, char **env)
{
	int		i;
	int		y;
	char	**res;

	i = 0;
	y = 0;
	while (env[i])
		i++;
	res = malloc(sizeof(char *) * i);
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], str, ft_var_len(str)) != 0)
			res[y] = ft_strdup(env[i]);
		else
			y--;
		y++;
	}
	res[y] = NULL;
	i = -1;
	while (env[++i])
		free(env[i]);
	free(env);
	return (res);
}

/**
 * calculates the length of a variable name
*/
int	ft_var_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

/**
 * this function creates a new array containing the existing 
 * environment variables plus an additional variable
*/
char	**ft_add_to_env(char *str, char **env)
{
	char	**res;
	int		i;

	i = 0;
	while (env[i])
		i++;
	res = malloc(sizeof(char *) * (i + 2));
	if (!res)
		return (NULL);
	i = -1;
	while (env[++i])
		res[i] = ft_strdup(env[i]);
	res[i] = ft_strdup(str);
	res [i + 1] = NULL;
	i = -1;
	while (env[++i])
		free(env[i]);
	free(env);
	return (res);
}
