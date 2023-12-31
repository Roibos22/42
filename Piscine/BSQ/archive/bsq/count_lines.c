/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:17:53 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/03/01 09:18:07 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	count_lines(char *str)
{
	int	i;
	int	k;
	
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			k++;
		i++;
	}
	return (k);
}