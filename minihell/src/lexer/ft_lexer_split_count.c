/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_split_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:30:44 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/11 17:18:22 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Counts the number of tokens in a line. Operators outside of quotes 
 * without deliminators are taken into account.
 * @param *lh pointer to lexer_help struct
*/
void	ft_get_no_of_tokens(t_lexer_help *lh)
{
	while (lh->line[lh->i])
	{
		if (lh->line[lh->i] == ' ' && !lh->in_quotes)
		{
			if (lh->i > lh->start)
				lh->size++;
			lh->start = lh->i + 1;
		}
		else if (lh->line[lh->i] == '"' || lh->line[lh->i] == '\'')
			ft_get_no_of_tokens_quote(lh);
		else if ((lh->line[lh->i] == '<' || lh->line[lh->i] == '>' \
		|| lh->line[lh->i] == '|') && !lh->in_quotes)
			ft_get_no_of_tokens_operator(lh);
		lh->i++;
	}
	if (lh->i > lh->start)
		lh->size++;
}

/**
 * sets the quotes_type and in_quotes variable of the
 * lexer_help struct when quotes are encountered
*/
void	ft_get_no_of_tokens_quote(t_lexer_help *lh)
{
	if (!lh->in_quotes)
	{
		lh->in_quotes = 1;
		lh->quotes_type = lh->line[lh->i];
	}
	else if (lh->line[lh->i] == lh->quotes_type)
		lh->in_quotes = 0;
}

/**
 * sets the start and size variable of the
 * lexer_help struct when operator is encountered
*/
void	ft_get_no_of_tokens_operator(t_lexer_help *lh)
{
	if (lh->i > lh->start)
	{
		lh->size++;
		lh->start = lh->i;
	}
	if (lh->line[lh->i] == lh->line[lh->i + 1])
		lh->i++;
	if (lh->line[lh->i + 1] != ' ' && lh->line[lh->i + 1] != '\0')
	{
		lh->size++;
		lh->start = lh->i + 1;
	}
}
