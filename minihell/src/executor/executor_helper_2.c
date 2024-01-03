/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_helper_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:45:23 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/11 18:04:17 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * replaces the content in the command token with the path to the executable
*/
void	get_cmd_path(t_statment *stm, t_data *data)
{
	int		i;
	char	*full_cmd;

	i = 0;
	if (ft_get_cmd_path_protection(stm, data) == 0)
		return ;
	full_cmd = ft_strjoin("/", stm->start_token->content);
	while (data->cmd_paths[i])
	{
		stm->cmd_path = ft_strjoin(data->cmd_paths[i], full_cmd);
		if (access(stm->cmd_path, X_OK) == 0)
		{
			free(full_cmd);
			return ;
		}
		free(stm->cmd_path);
		stm->cmd_path = NULL;
		i++;
	}
	ft_get_cmd_path_executable(stm);
	return (free(full_cmd));
}

/**
 * checks if a cmd token should be checked for the paths, what would not be
 * the case if it starts with ./ or already is a correct path
*/
int	ft_get_cmd_path_protection(t_statment *stm, t_data *data)
{
	if (ft_strncmp(stm->start_token->content, "./", 2) == 0)
	{
		stm->cmd_path = ft_strdup(stm->start_token->content);
		return (0);
	}
	if (ft_is_correct_path(stm->start_token->content))
	{
		stm->cmd_path = ft_strdup(stm->start_token->content);
		return (0);
	}
	if (!data->cmd_paths)
		return (0);
	if (ft_strncmp("", stm->start_token->content, 1) == 0)
		return (0);
	return (1);
}

/**
 * if a cmd of a token starts with ./, set the it to the 
 * stm->cmd path as it is
*/
void	ft_get_cmd_path_executable(t_statment *stm)
{
	if (stm->cmd_path != NULL)
	{
		if (ft_strncmp(stm->cmd_path, "./", 2) != 0)
			stm->cmd_path = ft_strdup(stm->start_token->content);
		else
			stm->cmd_path = NULL;
	}
	return ;
}

/**
 * prepares the command arguments for execve(), through adding 
 * the strings of the tokens afterm the cmd
*/
void	get_cmd_args(t_statment *stm)
{
	int		i;
	int		token_len;
	t_token	*cur_token;

	cur_token = stm->start_token;
	stm->cmd_args = malloc(sizeof(char *) * (stm->no_cmd_tokens + 1));
	if (!stm->cmd_args)
		return ;
	i = 0;
	while (i < stm->no_cmd_tokens && !ft_is_redirection(cur_token))
	{
		token_len = ft_strlen(cur_token->content);
		stm->cmd_args[i] = malloc(sizeof(char) * (token_len + 1));
		if (!stm->cmd_args[i])
			return ;
		ft_strlcpy(stm->cmd_args[i], cur_token->content, token_len + 1);
		cur_token = cur_token->next;
		i++;
	}
	stm->cmd_args[i] = NULL;
}

/**
 * checks if str already exists in the arr
*/
int	str_in_array(char *str, char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL || str == NULL)
		return (0);
	while (arr[i] != NULL)
	{
		if (ft_strncmp(arr[i], str, ft_strlen(str)) == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
