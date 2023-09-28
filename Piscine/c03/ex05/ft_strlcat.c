/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:43:29 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/22 11:05:16 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <bsd/string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	destl;
	unsigned int	srcl;

	destl = ft_strlen(dest);
	srcl = ft_strlen(src);
	i = 0;
	j = destl;
	if (size == 0 || size <= destl)
	{
		return (srcl + size);
	}
	while (src[i] != '\0' && i < size - destl - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (destl + srcl);
}
/*
int main(void)
{
    char d1[30] = "ABC ";
	char d2[30] = "ABC ";
    char s1[30] = "XYZ!";
	char s2[30] = "XYZ!";
	unsigned int i = ft_strlcat(d1, s1, 30);
	unsigned int j = strlcat(d2, s2, 30);
	printf("mine:\n dest:%s return:%i\n", d1, i);
	printf("true:\n dest:%s return:%i\n", d2, j);
}
*/
