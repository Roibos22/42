/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:14:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/14 20:36:38 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


Fixed	get_triangle_size(Point const a, Point const b, Point const c)
{
	Fixed	res = Fixed(0.5f) *
				  (a.get_x() * (b.get_y() - c.get_y()) +
				  b.get_x() * (c.get_y() - a.get_y()) +
				  c.get_x() * (a.get_y() - b.get_y()));

	if (res < 0)
		res = res * -1;

	return (res);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed triangle_1 = get_triangle_size(a, b, c);
	Fixed triangle_2 = get_triangle_size(a, b, point);
	Fixed triangle_3 = get_triangle_size(a, point, c);
	Fixed triangle_4 = get_triangle_size(point, b, c);

	if (triangle_2 == 0 || triangle_3 == 0 || triangle_4 == 0)
		return (false);

	if ((triangle_2 + triangle_3 + triangle_4) == triangle_1)
		return (true);
	else
		return (false);
}
