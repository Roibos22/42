/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:13:33 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/03/01 09:13:47 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_point(point_struct p)
{
	write(1, "x: ", 3);
	ft_putnbr(p.x);
	write(1, "\n", 1);
	write(1, "y: ", 3);
	ft_putnbr(p.y);
	write(1, "\n", 1);
	write(1, "value: ", 7);
	ft_putnbr(p.value);
	write(1, "\n", 1); // add a newline after each string
}