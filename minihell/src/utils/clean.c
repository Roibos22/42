/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:49:58 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/08 00:02:08 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// cleans everything, so porgram can exit without leaks
// only clean env if exit == 1
void	ft_clean_data(t_data *data, int exit)
{
	ft_free_tokens(data->tokens);
	if (data->tok_is_red_str != NULL)
	{
		free(data->tok_is_red_str);
		data->tok_is_red_str = NULL;
	}
	data->tokens = NULL;
	if (exit)
	{
		ft_free_str_arr(data->env);
		ft_free_str_arr(data->cmd_paths);
		ft_free_str_arr(data->created_files);
		free(data);
	}
}

void	ft_free_lexer(t_lexer_help *lh)
{
	int	i;

	i = 0;
	ft_free_str_arr(lh->result);
	free(lh->line);
	free(lh->envp);
	free(lh);
	return ;
}

void	ft_free_tokens(t_token *list)
{
	t_token	*temp;

	if (!list)
		return ;
	while (list->prev)
		list = list->prev;
	while (list)
	{
		temp = list->next;
		free(list->content);
		free(list);
		list = temp;
	}
}

void	ft_free_str_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_stm(t_statment *stm)
{
	unlink(".heredoc");
	if (stm->cmd_args)
		ft_free_str_arr(stm->cmd_args);
	if (stm->cmd_path != NULL)
		free(stm->cmd_path);
	free(stm);
}
