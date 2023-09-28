/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:58:49 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/27 16:57:58 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int	main(void)
{
	printf("%i\n", ft_is_prime(2147483647));
	printf("%i\n", ft_is_prime(1));
	printf("%i\n", ft_is_prime(2));
	printf("%i\n", ft_is_prime(6));
	printf("%i\n", ft_is_prime(13));
}
