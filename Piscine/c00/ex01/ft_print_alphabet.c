/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:32:54 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/12 14:08:44 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
	we create an int with value of 97, which transforms to char "a"
	as decimal number 122 represents char "z" we iterate until 122
*/

void	ft_print_alphabet(void)
{
	int	n;

	n = 97;
	while (n <= 122)
	{
		write(1, &n, 1);
		n++;
	}
}
