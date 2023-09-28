/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:30:36 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/20 12:50:43 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		first;

	i = 0;
	first = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			if (first == 1)
			{
				str[i] = str[i] - 32;
				first = 0;
			}
		}
		else if (str[i] >= 48 && str[i] <= 57)
			first = 0;
		else
			first = 1;
		i++;
	}
	return (str);
}

int	main(void)
{	
    char str[] = "  4salut, COM7MENT_) 2tu +vas";
	printf("%s\n", str);
	ft_strcapitalize(str);
    printf("%s", str);
	return(0);	
}

