/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:46:20 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/08 14:00:49 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_same_str(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL) 
		return (0);
	while (*s1 && *s2) 
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else
		return (0);
}

/**
 * checks if the type of a token is a redirection
 * @param *list - the linked list of tokens
 * @return - true if the type is a redirection, false otherwise
*/
bool	ft_is_redirection(t_token *list)
{
	if (!list)
		return (false);
	if (list->type == IN_REDIR || list->type == OUT_REDIR \
	|| list->type == HERE_DOC || list->type == APPEND)
		return (true);
	if (list->prev)
	{
		if (list->prev->type == HERE_DOC)
			return (true);
	}
	return (false);
}

int	handle_red_heredoc_empty(char *line, t_data *data)
{
	if (!line)
	{
		ft_perror(HERE_DOC_EOF, NULL, 0, data);
		return (0);
	}
	return (1);
}
