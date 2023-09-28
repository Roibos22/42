/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:40:47 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/22 15:42:57 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	res = nb;
	while (nb > 1)
	{
		res = res * (nb - 1);
		nb--;
	}
	return (res);
}
/*
int main(void)
{
	printf("-4!=0 -> %i\n", ft_iterative_factorial(-4));
	printf("0!=1 -> %i\n", ft_iterative_factorial(0));
	printf("1!=1 -> %i\n", ft_iterative_factorial(1));
	printf("3!=6 -> %i\n", ft_iterative_factorial(3));
}
*/