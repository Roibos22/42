/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:54:10 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/12 14:38:52 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);

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
