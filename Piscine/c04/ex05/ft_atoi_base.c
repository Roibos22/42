/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:55:09 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/23 14:57:05 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	str_to_number(char str[])
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (str[i] != 0)
	{
		if (str[i] < 48 || str[i] > 57)
		{
			return (-1);
		}
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number);
}

int	base_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;

	nbr = str_to_number(str);
	while (nbr >= base_length(base))
	{
		ft_atoi_base(nbr / base_length(base), base);
		nbr = nbr % base_length(base);
	}
}
/*
int	main(void)
{
	printf("%i", ft_atoi_base("10", "01"));
	return (0);
}
*/
