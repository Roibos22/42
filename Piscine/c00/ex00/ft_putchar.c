/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:29:44 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/12 14:04:49 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
	The char variable saves the value and address of the value in 1 bit
	The write function expects a buffer that points to a specific place in memory
	The & before the char variable points to the address of the variable
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
