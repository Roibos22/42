/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:55:16 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/11 12:17:55 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rush(int x, int y);
void	ft_first_letter(int i, int x, int j, int y);
void	ft_mid_letter(int i, int x, char c, int j, int y);
void	ft_last_letter(int i, int x, int j, int y);

int	main(void)
{
	rush(0, 0);
	return (0);
}

void	rush(int x, int y)
{
	int	i;
	int	j;
	char	c;

	i = 0;
	j = 0;
	c = 'A';
	while (j < y)
	{
		ft_first_letter(i, x, j, y);
		if (j == 0 || j + 1 == y)
		{	
			c = 'B';
			ft_mid_letter(i, x, c, j, y);
		}
		else
		{
			c = ' ';
			ft_mid_letter(i, x, c, j, y);
		}
		ft_last_letter(i, x, j, y);
		j++;
	}
}

void	ft_first_letter(int i, int x, int j, int y)
{
	if (j == 0 || j + 1 == y)
	{
		ft_putchar('A');
	}
	else
	{
		ft_putchar('B');
	}
}

void	ft_mid_letter(int i, int x, char c, int j, int y)
{
	if (x != 1)
	{
		while (i < x - 2)
		{
			if (j == 0 || j == y - 1)
			{
				ft_putchar('B');
			}
			else
			{
				ft_putchar(' ');
			}
			i++;
		}
	}
}

void	ft_last_letter(int i, int x, int j, int y)
{
	if (x != 1)
	{
		if (j == 0 || j + 1 == y)
		{
			ft_putchar('C');
		}
		else 
		{
			ft_putchar('B');
		}
	}
	write(1, "\n", 1);
}

void    ft_putchar(char c)
{
	write(1, &c, 1);
}
