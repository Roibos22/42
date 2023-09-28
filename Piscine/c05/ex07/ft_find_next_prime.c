/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:03:25 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/22 15:53:52 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	d;

	d = 2;
	if (nb <= 1)
		return (0);
	while (d < nb)
	{
		if (nb % d == 0)
		{
			return (0);
		}
		d++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) != 1)
	{
		nb++;
	}
	return (nb);
}
/*
int	main(void)
{
	printf("%i\n", ft_find_next_prime(-2));
	printf("%i\n", ft_find_next_prime(0));
	printf("%i\n", ft_find_next_prime(1));
	printf("%i\n", ft_find_next_prime(2));
	printf("%i\n", ft_find_next_prime(5));
	printf("%i\n", ft_find_next_prime(50));
}
*/
