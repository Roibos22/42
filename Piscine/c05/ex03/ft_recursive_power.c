/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:09:06 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/22 15:44:51 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	if (power > 0)
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
	return (1);
}
/*
int main(void)
{
	printf("0^0=1 -> %i\n", ft_recursive_power(0, 0));
	printf("2^0=1 -> %i\n", ft_recursive_power(2, 0));
	printf("0^2=0 -> %i\n", ft_recursive_power(0, 2));
	printf("2^2=4 -> %i\n", ft_recursive_power(2, 2));
	printf("-2^2=4 -> %i\n", ft_recursive_power(-2, 2));
	printf("2^-2=0 -> %i\n", ft_recursive_power(2, -2));
	return (0);
}
*/
