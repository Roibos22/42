/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:17:10 by smargine          #+#    #+#             */
/*   Updated: 2023/12/08 01:21:22 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * handles the cd command in minishell
*/
int	ft_cd(t_statment *stm, t_data *data)
{
	int	i;
	int	exit_status;

	i = 1;
	exit_status = ft_change_pwd(data, "OLDPWD=");
	if (!stm->cmd_args[i] && !ft_check_home(data))
		return (EXIT_FAILURE);
	if (!stm->cmd_args[i])
		return (ft_cd_home(data));
	if (stm->cmd_args[2])
	{
		ft_perror("minishell: cd: too many arguments\n", NULL, 1, data);
		return (EXIT_FAILURE);
	}
	exit_status = chdir(stm->cmd_args[i]);
	if (exit_status < 0)
		return (ft_perror(CD_NOPTH_ERR, NULL, 1, data), EXIT_FAILURE);
	exit_status = ft_change_pwd(data, "PWD=");
	return (exit_status);
}

/**
 * handle the scenario where the cd command is invoked without any arguments
*/
int	ft_cd_home(t_data *data)
{
	int		exit_status;
	int		i;
	char	**home;

	exit_status = ft_change_pwd(data, "OLDPWD=");
	i = 0;
	home = NULL;
	while (data->env[i]) 
	{
		if (ft_strncmp(data->env[i], "HOME=", 5) == 0) 
		{
			home = ft_split(data->env[i], '=');
			if (!home)
				return (EXIT_FAILURE);
			exit_status = chdir(home[1]);
			if (exit_status < 0) 
				return (ft_free_str_arr(home), \
				ft_perror(CD_NOPTH_ERR, NULL, 1, data), EXIT_FAILURE);
			break ;
		}
		i++;
	}
	ft_free_str_arr(home);
	exit_status = ft_change_pwd(data, "PWD=");
	return (exit_status);
}

/**
 * helper function, checks if HOME variable is set or not
*/
int	ft_check_home(t_data *data)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], "HOME=", 5) == 0)
		{
			x = 1;
			break ;
		}
		i++;
	}
	if (!x)
	{
		ft_perror("minishell: cd: HOME not set\n", NULL, 1, data);
		return (0);
	}
	return (1);
}

/**
 * function responsible for updating the environment variables 
 * related to the current working directory (PWD and OLDPWD)
*/
int	ft_change_pwd(t_data *data, char *str)
{
	int		i;
	char	*temp;
	char	*new_value;

	i = 0;
	temp = getcwd(NULL, 0);
	if (!temp)
		return (EXIT_FAILURE);
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], str, ft_strlen(str)) == 0) 
		{
			free(data->env[i]);
			new_value = ft_strjoin(str, temp);
			if (!new_value) 
				return (free(temp), EXIT_FAILURE);
			data->env[i] = new_value;
			free(temp); 
			return (EXIT_SUCCESS);
		}
		i++;
	}
	free (temp);
	return (EXIT_FAILURE);
}
