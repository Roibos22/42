/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:40:47 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/22 15:43:16 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}
/*
int main(void)
{
    printf("-4!=0 -> %i\n", ft_recursive_factorial(-4));
    printf("0!=1 -> %i\n", ft_recursive_factorial(0));
    printf("1!=1 -> %i\n", ft_recursive_factorial(1));
    printf("3!=6 -> %i\n", ft_recursive_factorial(3));
}
*/