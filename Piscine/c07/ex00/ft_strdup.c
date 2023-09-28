/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:04:48 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/27 13:36:52 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

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
	if (dest == NULL)
	{
		return (NULL);
	}
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include<stdio.h>
int	main(void)
{
	char	src[] = "Hello";
	//ft_strdup(src);
	printf("duplicate: %s\n", ft_strdup(src));
	printf("original: %s\n", src);
	return (0);
}
*/
