/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:21:13 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/03/01 09:21:26 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char validate_string(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] == c)
	{
		i++;
	}
	if (str[i] == '\0')
	{
		return ('1');
	}
	ft_append_char(str, '\0');
	return ('0');
}