/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:43:56 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/23 14:52:25 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

int	ft_atoi(char *str)
{	
	int			i;
	long int	number;
	int			multiplier;

	number = 0;
	i = 0;
	multiplier = 1;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			multiplier = multiplier * (-1);
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (multiplier * number);
}
/*
int	main(void)
{
	char	test1[] = "   \n ---+--2147483648fdsdfafsd";

	printf("%i\n", ft_atoi(test1));
	printf("%i\n", atoi(test1));
	return (0);
}
*/
