/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:42:25 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/14 20:36:12 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point();
		~Point();
		Point(const Point &point);
		Point(float x, float y);
		Point &operator=(const Point &point);

		Fixed	get_x(void) const;
		Fixed	get_y(void) const;
};


bool	bsp( Point const a, Point const b, Point const c, Point const point);
std::ostream &operator<<(std::ostream &o, Point const &i);

#endif