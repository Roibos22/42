/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_split_fill_help.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:25:55 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/11 17:30:35 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Checks if a string contains an operator <, <<, >, >> or |
 * @param *str string to go through
*/
bool	ft_str_has_operator(char *str)
{
	if (ft_strnstr(str, "<", ft_strlen(str)))
		return (true);
	if (ft_strnstr(str, "<<", ft_strlen(str)))
		return (true);
	if (ft_strnstr(str, ">>", ft_strlen(str)))
		return (true);
	if (ft_strnstr(str, ">", ft_strlen(str)))
		return (true);
	if (ft_strnstr(str, "|", ft_strlen(str)))
		return (true);
	return (false);
}

/**
 * Checks if a string contains consists of only and operator 
 * <, <<, >, >> or | and returns its size
 * @param *str string to go through
*/
int	ft_is_just_operator_str(char *str)
{
	if (ft_strncmp(str, "\"<\"", 4) == 0)
		return (4);
	else if (ft_strncmp(str, "\'<\'", 4) == 0)
		return (4);
	else if (ft_strncmp(str, "\">\"", 4) == 0)
		return (4);
	else if (ft_strncmp(str, "\'>\'", 4) == 0)
		return (4);
	else if (ft_strncmp(str, "\"<<\"", 5) == 0)
		return (5);
	else if (ft_strncmp(str, "\'<<\'", 5) == 0)
		return (5);
	else if (ft_strncmp(str, "\">>\"", 5) == 0)
		return (5);
	else if (ft_strncmp(str, "\'>>\'", 5) == 0)
		return (5);
	else if (ft_strncmp(str, "\"|\"", 4) == 0)
		return (4);
	else if (ft_strncmp(str, "\'|\'", 4) == 0)
		return (4);
	else
		return (0);
}

/**
 * handles strings with operators
*/
void	ft_split_op_str_next(t_lexer_help *lh, int start, int i, t_data *data)
{
	lh->result[lh->curr_t] = (char *)malloc(sizeof(char) * (i - start + 1));
	if (lh->result[lh->curr_t])
		return ;
	ft_strlcpy(lh->result[lh->curr_t], lh->temp + start, i - start + 1);
	ft_expander(lh, data);
	lh->curr_t++;
}

/**
 * sets the quotes_type and in_quotes variable of the
 * lexer_help struct when quotes are encountered
*/
void	ft_fill_tokens_array_quote(t_lexer_help *lh)
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
 * handles the edge case where only an operator in quotes
 * was encountered, that needs to be handeled as string
 * 
*/
int	ft_split_just_operator_str(t_lexer_help *lh, int start, t_data *data)
{
	int	op_str_size;

	op_str_size = ft_is_just_operator_str(lh->temp + start);
	if (op_str_size != 0)
	{
		lh->result[lh->curr_t] = (char *)malloc(sizeof(char) * op_str_size);
		if (lh->result[lh->curr_t])
			return (0);
		ft_strlcpy(lh->result[lh->curr_t], lh->temp + start, op_str_size);
		ft_expander(lh, data);
		lh->curr_t++;
		return (0);
	}
	return (1);
}
