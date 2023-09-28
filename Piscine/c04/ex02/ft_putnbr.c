/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:28:01 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/21 15:05:31 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	lnb;
	char		c;

	lnb = nb;
	if (lnb < 0)
	{
		lnb = lnb * (-1);
		write(1, "-", 1);
	}
	c = lnb % 10 + '0';
	if (lnb >= 10)
	{
		ft_putnbr(lnb / 10);
	}
	write (1, &c, 1);
}

/*
int	main(void)
{
	ft_putnbr(-42);
	return (0);
}
*/
