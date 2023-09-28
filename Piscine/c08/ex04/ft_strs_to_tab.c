/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:45:05 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/27 18:22:55 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*dest;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dest = (char *) malloc((len + 1) * sizeof(char));
	if (dest == 0)
	{
		return (0);
	}
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int argc, char *argv[])
{
	t_stock_str	*array;
	int			i;

	i = 0;
	array = malloc(sizeof(t_stock_str) * (argc + 1));
	if (!array)
	{
		return (0);
	}
	while (i < argc)
	{
		array[i].str = argv[i];
		array[i].copy = argv[i];
		array[i].size = ft_strlen(argv[i]);
		i++;
	}
	array[i].str = 0;
	return (array);
}
