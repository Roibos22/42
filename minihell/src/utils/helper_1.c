/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:07:23 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/08 16:50:08 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_env_paths(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		if (ft_strnstr(data->env[i], "PATH", 4))
			data->cmd_paths = ft_split(data->env[i] + 5, ':');
		i++;
	}
}

char	**add_str_to_arr(char *str, char **arr)
{
	int		i;
	char	**res;

	i = 0;
	while (arr[i] != NULL)
		i++;
	res = malloc(sizeof(char *) * (i + 2));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		res[i] = arr[i];
		i++;
	}
	res[i] = strdup(str);
	res[i + 1] = NULL;
	i = 0;
	while (arr[i] != NULL) 
	{
		free(arr[i]);
		i++;
	}
	return (free(arr), res);
}

char	**ft_copy_array(char **array)
{
	char	**res;
	int		i;

	i = 0;
	while (array[i])
		i++;
	res = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (array[i])
	{
		res[i] = ft_strdup(array[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_exec_next_stm(t_token *token, t_statment *stm, t_data *data)
{
	if (token)
	{
		while (token->type != PIPE && token->next)
			token = token->next;
		if (token->type == PIPE && token->next != NULL)
		{
			ft_executor(token->next, stm->pipe[0], data);
			return ;
		}
		else
			data->exit_status_final = data->exit_status;
	}
	else
		data->exit_status_final = data->exit_status;
}
