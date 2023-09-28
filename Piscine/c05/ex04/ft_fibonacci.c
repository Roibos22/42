/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:56:52 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/22 15:47:45 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index <= 1)
		return (index);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
int	main(void)
{
	printf("%i\n", ft_fibonacci(-2));
	printf("%i\n", ft_fibonacci(0));
	printf("%i\n", ft_fibonacci(1));
	printf("%i\n", ft_fibonacci(2));
	printf("%i\n", ft_fibonacci(3));
	printf("%i\n", ft_fibonacci(4));
	printf("%i\n", ft_fibonacci(5));
}
*/