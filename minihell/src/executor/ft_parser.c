/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:43:27 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/08 16:05:20 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parser(t_statment *stm, t_data *data)
{
	ft_signals(4, data);
	if (!handle_redirections(stm->start_token, stm, data))
		return (0);
	if (!ft_syntax_check(stm->start_token, data))
		return (0);
	return (1);
}

/**
 * helper function to check the input from the user
 * @param *list - pointer to the linked list of tokens
*/
int	ft_syntax_check(t_token *token, t_data *data)
{
	if (!token->prev && token->type == PIPE)
		return (ft_perror(SY_ERR_PIPE, NULL, 2, data), 0); 
	while (token != NULL && token->type != PIPE)
	{
		token = ft_syntax_check_red(data, token);
		if (token == NULL || (!token->next && ft_is_redirection(token)))
			return (0);
		if (token->type == COMMAND)
			token = ft_syntax_check_cmd(token);
		else if (!ft_is_redirection(token->prev))
			return (ft_perror(NO_CMD, token->content, 127, data), 0);
		token = ft_syntax_check_red(data, token);
		if (token == NULL)
			return (0);
		if (token->type == PIPE && token->next == NULL)
			return (ft_perror(SY_ERR_PIPE, NULL, 2, data), 0);
		if (token->type == PIPE)
			break ;
		token = token->next;
	}
	return (1);
}

t_token	*ft_syntax_check_red(t_data *data, t_token *token)
{
	if (ft_is_redirection(token))
	{
		if (!ft_lonely_red(data, token))
			return (NULL);
		token = token->next;
		if (token->next && token->prev->type != PIPE)
			token = token->next;
	}
	return (token);
}

/**
 * cheks if the statment only consists of a redirection
 * or a pipe in the beginning what will lead to a syntax error
*/
int	ft_lonely_red(t_data *data, t_token *token)
{
	if (token->type == IN_REDIR && token->next == NULL)
		return (ft_perror(SY_ERR_RIN, NULL, 2, data), 0);
	if (token->type == OUT_REDIR && !token->next)
		return (ft_perror(SY_ERR_ROUT, NULL, 2, data), 0);
	if (token->type == APPEND && !token->next)
		return (ft_perror(SY_ERR_RAPP, NULL, 2, data), 0);
	if (token->type == HERE_DOC && !token->next)
		return (ft_perror(SY_ERR_HD, NULL, 2, data), 0);
	return (1);
}

t_token	*ft_syntax_check_cmd(t_token *token)
{
	if (token->next)
		token = token->next;
	while (token->type == WORD && token->next)
		token = token->next;
	return (token);
}
