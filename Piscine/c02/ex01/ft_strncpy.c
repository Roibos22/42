/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:51:48 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/18 12:26:08 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((src[i] != '\0') && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
int main(void)
{
	char src[] = "Source string.";
	char dest[] = "Destination string.";
	unsigned int n;

	n = 2;

	printf("BEFORE\nsrc: %s\ndes: %s\n", src, dest);

    ft_strncpy(dest, src, n);

	printf("AFTER\nsrc: %s\ndes: %s\n", src, dest);
	return (0);
}
*/
