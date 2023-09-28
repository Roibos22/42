/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:11:55 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/18 17:10:31 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
		{
			i++;
		}
		else if (str[i] <= 'z' && str[i] >= 'a')
		{
			str[i] = str[i] - 32;
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
    char l[] = "fd4324 ASDF dfsdaf 32423 '32;';sfsaF";
    char *i = ft_strupcase(l);
    printf("%s", i);
}
*/
