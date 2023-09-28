/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:13:13 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/13 12:39:46 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	add_seperator(int n);
void	write_number(int n, int o, int p);

void	ft_print_comb(void)
{
	int	n;
	int	o;
	int	p;	

	n = 48;
	o = 49;
	p = 50;
	while (n < 56)
	{	
		o = n + 1;
		while (o < 57)
		{	
			p = o + 1;
			while (p < 58)
			{
				write_number(n, o, p);
				p++;
			}
			o++;
		}
		n++;
	}
}

void	write_number(int n, int o, int p)
{
	if (n != o && n != p && p != o)
	{
		write(1, &n, 1);
		write(1, &o, 1);
		write(1, &p, 1);
		add_seperator(n);
	}
}

void	add_seperator(int n)
{
	if (n != 55)
	{
		write(1, ", ", 2);
	}
}
