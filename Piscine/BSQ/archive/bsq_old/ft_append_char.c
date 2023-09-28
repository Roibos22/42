/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:12:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/03/01 09:20:36 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char    *ft_append_char(char *dest, char src)
{
	int i;
	//int destlen = ft_strlen(dest);
	//char *destr = malloc(destlen + 2);
	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	dest[i] = src;
	i++;
	dest[i] = '\0';
	return (dest);
}
