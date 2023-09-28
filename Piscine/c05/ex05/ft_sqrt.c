/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:33:17 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/22 15:49:47 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

int	ft_sqrt(int nb)
{
	int	n;
	int	s;

	n = 0;
	s = 1;
	while (nb > 0)
	{
		nb = nb - s;
		s = s + 2;
		n++;
	}
	if (nb == 0)
		return (n);
	return (0);
}
/*
int	main(void)
{
	printf("sqrt(-4)=0 ->%i\n", ft_sqrt(-4));
	printf("sqrt(0)=0 ->%i\n", ft_sqrt(0));
	printf("sqrt(3)=0 ->%i\n", ft_sqrt(3));
	printf("sqrt(16)=4 ->%i\n", ft_sqrt(16));
}
*/
