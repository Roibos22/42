/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:11:55 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/18 17:10:08 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 'z' && str[i] >= 'a')
		{	
			i++;
		}
		else if (str[i] <= 'Z' && str[i] >= 'A')
		{
			str[i] = str[i] + 32;
			i++;
		}	
		else
		{
			i++;
		}
	}
	return (str);
}
/*
int main(void)
{
    char l[] = "A 323 ASFDF  daf ';;; aBbYyZz";
    char *i = ft_strlowcase(l);
    printf("%s", i);
}
*/
