/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:11:39 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/13 12:42:14 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_number(int n);
void	write_seperator(int i);
void	ft_print_comb2(void);

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 100)
	{	
		while (i < j)
		{
			while (j < 100)
			{
				write_number(i);
				write(1, " ", 1);
				write_number(j);
				write_seperator(i);
				j++;
			}
			j = 0;
			i++;
		}
		j++;
	}
}

void	write_number(int n)
{
	char	first;
	char	second;

	first = n / 10 + '0';
	second = n % 10 + '0';
	write(1, &first, 1);
	write(1, &second, 1);
}

void	write_seperator(int i)
{
	if (i != 98)
	{
		write(1, ", ", 2);
	}
}
