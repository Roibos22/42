/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:54:40 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/23 14:56:24 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdio.h>

int	base_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	validate_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[i + 1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (base[i] != '-' && base[i] != '+' && (base[i] > 31 && base [i] < 127))
		i++;
	if (base[i] == '\0')
		return (1);
	else
		return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nb;

	nb = nbr;
	if (validate_base(base) == 1)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = nb * (-1);
		}
		while (nb >= base_length(base))
		{
			ft_putnbr_base(nb / base_length(base), base);
			nb = nb % base_length(base);
		}
		write(1, &base[nb], 1);
	}
}
/*
int main(void)
{
    int nbr = -2147483648;
    ft_putnbr_base(nbr, "012\n456789");
    printf("\n");
    ft_putnbr_base(nbr, "0123456789ABCDEF");
    printf("\n");
    ft_putnbr_base(nbr, "01");
    printf("\n");
    ft_putnbr_base(nbr, "poneyvif");
    printf("\n");
    ft_putnbr_base(nbr, "p");
    printf("\n");
    ft_putnbr_base(nbr, "pafp");
    printf("\n");
    ft_putnbr_base(nbr, "pa-+fp");
    printf("\n");
}
*/
