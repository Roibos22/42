/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:18:45 by smargine          #+#    #+#             */
/*   Updated: 2023/12/08 01:30:57 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * handles the export command in minishell
*/
int	ft_export(t_statment *stm, t_data *data)
{
	int	i;
	int	y;

	i = 1;
	y = -1;
	if (!stm->cmd_args[i])
	{
		while (data->env[++y])
			ft_printf("declare -x %s\n", data->env[y]);
	}
	else
	{
		while (stm->cmd_args[i])
		{
			if (!ft_check_arg(stm->cmd_args[i], data) && \
			!ft_check_ifvar(stm->cmd_args[i], data->env))
			{
				if (stm->cmd_args[i])
					data->env = ft_add_to_env(stm->cmd_args[i], data->env);
			}
			i++;
		}
	}
	return (0);
}

/**
 * checks if a specific variable exists within the env array,
 * if exists will replace it
*/
bool	ft_check_ifvar(char	*str, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(str, env[i], ft_var_len(str)) == 0)
		{
			free(env[i]);
			env[i] = ft_strdup(str);
			return (true);
		}
		i++;
	}
	return (false);
}

/**
 * validate arguments used in export command 
 * where environment variable assignments are made
*/
int	ft_check_arg(char *str, t_data *data)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!str[i])
		return (ft_export_error(str, data), 1);
	if (str[i] == '=')
		res = ft_export_error(str, data);
	if (ft_isdigit(str[i]))
		res = ft_export_error(str, data);
	while (str[i] && str[i] != '=')
	{
		if (ft_special_char(str[i]) || ft_null_space(str[i]))
		{
			res = ft_export_error(str, data);
			break ;
		}
		i++;
	}
	if (res == 1)
		return (1);
	else
		return (0);
}

/**
 * helper function, checks for space char
*/
bool	ft_null_space(char c)
{
	if (c == ' ')
		return (true);
	else
		return (false);
}

/**
 * helper function, checks for special char
*/
bool	ft_special_char(char c)
{
	if (c >= 33 && c <= 47)
		return (true);
	else if (c >= 58 && c <= 64)
		return (true);
	else if (c >= 91 && c <= 94)
		return (true);
	else if (c >= 123 && c <= 126)
		return (true);
	else
		return (false);
}
