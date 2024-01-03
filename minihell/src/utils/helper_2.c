/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 04:03:04 by smargine          #+#    #+#             */
/*   Updated: 2023/12/08 15:22:02 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_quote(char c, char quote, int *counter, int *in_quote)
{
	if (c == quote)
	{
		(*counter)++;
		*in_quote = !*in_quote;
		return (true);
	}
	return (false);
}

bool	ft_no_open_quotes(char *str)
{
	int		i;
	bool	in_d_quotes;
	bool	in_s_quotes;

	i = 0;
	in_d_quotes = false;
	in_s_quotes = false;
	while (str[i])
	{
		if (str[i] == '\"' && !in_s_quotes)
			in_d_quotes = !in_d_quotes;
		else if (str[i] == '\'' && !in_d_quotes)
			in_s_quotes = !in_s_quotes;
		i++;
	}
	return (!in_d_quotes && !in_s_quotes);
}
