/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_helper_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 06:14:10 by smargine          #+#    #+#             */
/*   Updated: 2023/12/11 18:13:31 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * initialises a new statment
*/
t_statment	*init_stm(int fdIn, t_token *token)
{
	t_statment	*stm;

	stm = malloc(sizeof(t_statment));
	if (!stm)
		return (NULL);
	stm->fd_in = fdIn;
	stm->fd_out = STDOUT_FILENO;
	stm->start_token = token;
	stm->cur_token = 0;
	stm->no_tokens = 0;
	stm->cmd_args = NULL;
	stm->cmd_path = NULL;
	return (stm);
}

/**
 * Prepares a stm for execution and calls necessary helper functions
*/
void	prepare_stm(t_statment *stm, t_data *data)
{
	stm->no_tokens = 0;
	stm->no_cmd_tokens = 0;
	stm->is_builtin = 0;
	stm->cur_token = 1;
	stm->stm_has_red_only = 0;
	while (stm->start_token && stm->start_token->type != PIPE)
	{
		if (stm->start_token->type == COMMAND)
		{
			stm->stm_has_cmd = 1;
			stm->is_builtin = ft_is_builtin(stm->start_token->content);
			break ;
		}
		stm->start_token = stm->start_token->next;
		stm->stm_has_cmd = 0;
	}
	count_tokens_helper(stm, data);
}

/**
 * Counts the tokens of one statment until a PIPE or the end
*/
void	count_tokens_helper(t_statment *stm, t_data *data)
{
	t_token	*tmp;

	tmp = stm->start_token;
	while (tmp)
	{
		if (tmp->type == PIPE)
			break ;
		stm->no_tokens++;
		tmp = tmp->next;
	}
	tmp = stm->start_token;
	while (tmp)
	{
		if (tmp->type == PIPE)
			break ;
		if (ft_is_redirection(tmp))
			stm->stm_has_red_only = 1;
		tmp = tmp->next;
	}
	count_cmd_tokens(stm, data);
}

/**
 * Counts the tokens of one stm until a PIPE or the end, 
 * while starting at the cmd token if found
*/
void	count_cmd_tokens(t_statment *stm, t_data *data)
{
	t_token	*tmp;

	tmp = stm->start_token;
	while (tmp)
	{
		if (tmp->type != WORD && tmp->type != COMMAND)
			break ;
		stm->no_cmd_tokens++;
		tmp = tmp->next;
	}
	if (stm->stm_has_cmd)
	{
		get_cmd_path(stm, data);
		get_cmd_args(stm);
		stm->stm_has_red_only = 0;
	}
}
