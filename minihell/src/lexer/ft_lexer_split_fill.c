/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_split_fill.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:49:57 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/11 18:21:44 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Copies all strings in the line into the result array
 * @param *lh pointer to lexer_help struct
*/
void	ft_fill_tokens_array(t_lexer_help *lh, t_data *data)
{
	lh->in_quotes = 0;
	lh->result = malloc(sizeof(char *) * (lh->size + 1));
	if (lh->result)
		return ;
	while (lh->line[lh->i] != '\0')
	{
		if (lh->line[lh->i] == ' ' && !lh->in_quotes)
		{
			if (lh->i > lh->start)
				ft_copy_next_token_string(lh, data, lh->i - lh->start);
			lh->start = lh->i + 1;
		}
		else if (lh->line[lh->i] == '"' || lh->line[lh->i] == '\'')
			ft_fill_tokens_array_quote(lh);
		lh->i++;
	}
	if (lh->i > lh->start)
		ft_copy_next_token_string(lh, data, lh->i - lh->start);
	lh->result[lh->curr_t] = NULL;
	ft_remember_red_strings(lh, data);
}

/**
 * gets only actual next string and copies it into res array
*/
void	ft_copy_next_token_string(t_lexer_help *lh, t_data *data, int length)
{
	if (lh->line[lh->start] == '"' || lh->line[lh->start] != '\'')
	{
		lh->temp = (char *)malloc(sizeof(char) * (length + 1));
		ft_strlcpy(lh->temp, lh->line + lh->start, length + 1);
		if (ft_str_has_operator(lh->temp) && lh->in_quotes == 0 \
		&& lh->temp[0] != '\"' && lh->temp[0] != '\'')
		{
			ft_split_operator_str(lh, 0, 0, data);
			return (free (lh->temp));
		}
		else
		{
			lh->result[lh->curr_t] = malloc(sizeof(char) * (length + 1));
			ft_strlcpy(lh->result[lh->curr_t], lh->temp, \
			ft_strlen(lh->temp) + 1);
			ft_expander(lh, data);
			lh->curr_t++;
			return (free (lh->temp));
		}
		free (lh->temp);
	}
	lh->result[lh->curr_t] = (char *)malloc(sizeof(char) * (length + 1));
	ft_strlcpy(lh->result[lh->curr_t], lh->line + lh->start, length + 1);
	ft_expander(lh, data);
	lh->curr_t++;
}

/**
 * Recursively splits a string that contains operators (<, <<, > or >>) 
 * without deliminator into seperate tokens
 * @param *lh lexer_help struct that contains all necessary information
 * @param start start index of the rest of the string (recursivity)
*/
void	ft_split_operator_str(t_lexer_help *lh, int start, int i, t_data *data)
{
	if (ft_split_just_operator_str(lh, start, data) == 0)
		return ;
	while (lh->temp[i])
	{
		if (lh->temp[i] == '<' || lh->temp[i] == '>' || lh->temp[i] == '|')
		{
			if (i - start > 0) 
				ft_split_op_str_next(lh, start, i, data);
			start = i;
			if (lh->temp[i] == lh->temp[i + 1])
				i++;
			i++;
			lh->result[lh->curr_t] = malloc(sizeof(char) * (i - start + 1));
			ft_strlcpy(lh->result[lh->curr_t], lh->temp + start, i - start + 1);
			ft_expander(lh, data);
			lh->curr_t++;
			if (!lh->temp[i])
				return ;
			start = i;
		}
		i++;
	}
	if (i - start > 0)
		ft_split_op_str_next(lh, start, i, data);
}

/**
 * After creating the array, we creat a seperate array in the data struct
 * that tells us if the strings consist of solely an operator 
 * (needed for tokenization)
*/
void	ft_remember_red_strings(t_lexer_help *lh, t_data *data)
{
	int	i;

	i = 0;
	data->tok_is_red_str = malloc(sizeof(char) * (lh->size + 1));
	while (lh->result[i])
	{
		ft_remember_red_strings_set(lh, data, i);
		i++;
	}
	data->tok_is_red_str[i] = '\0';
}

/**
 * Sets the values in the data->tok_is_red_string array
*/
void	ft_remember_red_strings_set(t_lexer_help *lh, t_data *data, int i)
{
	if (ft_strncmp(lh->result[i], "\"<\"", 3) == 0)
		data->tok_is_red_str[i] = '1';
	else if (ft_strncmp(lh->result[i], "\'<\'", 3) == 0)
		data->tok_is_red_str[i] = '1';
	else if (ft_strncmp(lh->result[i], "\">\"", 3) == 0)
		data->tok_is_red_str[i] = '1';
	else if (ft_strncmp(lh->result[i], "\'>\'", 3) == 0)
		data->tok_is_red_str[i] = '1';
	else if (ft_strncmp(lh->result[i], "\"<<\"", 4) == 0)
		data->tok_is_red_str[i] = '1';
	else if (ft_strncmp(lh->result[i], "\'<<\'", 4) == 0)
		data->tok_is_red_str[i] = '1';
	else if (ft_strncmp(lh->result[i], "\">>\"", 4) == 0)
		data->tok_is_red_str[i] = '1';
	else if (ft_strncmp(lh->result[i], "\'>>\'", 4) == 0)
		data->tok_is_red_str[i] = '1';
	else if (ft_strncmp(lh->result[i], "\"|\"", 3) == 0)
		data->tok_is_red_str[i] = '1';
	else if (ft_strncmp(lh->result[i], "\'|\'", 3) == 0)
		data->tok_is_red_str[i] = '1';
	else
		data->tok_is_red_str[i] = '0';
}
