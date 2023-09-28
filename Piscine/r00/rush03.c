/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:55:16 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/11 14:02:17 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
void	ft_putchar(char c);
void	rush(int x, int y);
void    ft_first_or_last_row(int x, int y, int i, int j);
void    ft_first_or_last_row(int x, int y, int i, int j);
*/

int	main(void)
{
	rush(5, 5);
	return (0);
}

void	rush(int x, int y)
{
	int	i; // columns counter
	int	j; // row counter
	char	c;

	i = 1;
	j = 1;
	
	while (j <= y) // iterate over all rows
	{	
		// print row if first or last row
		while (j == 1 || j == y)
		{
			while (i <= x)
			{
				if (i == 1)
				{
					write(1, "A", 1);
				}
				else if (i == x)
				{
					write (1, "C", 1);
				}
				else
				{
					write (1, "B", 1);
				}
				i++;
			}
			j++;
			i = 1;
			write (1, "\n", 1);
		} 
		ft_first_or_last_row(x, y, i, j);
		
	}
}

void	ft_first_or_last_row(int x, int y, int i, int j)
{

}

void    ft_mid_row(int x, int y, int i, int j)
{
	// print B and spaces if middle lines 
	while (j > 1 && j < y)
	{
		while (i <= x)
		{
			if (i == 1 || i == x)
			{
				write(1, "B", 1);
			}
			else
			{
				write(1, " ", 1);
			}
			i++;
		}
		j++;
		i = 1;
		write(1, "\n", 1);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
