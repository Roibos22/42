/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:44:13 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/14 20:36:44 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) { }

Point::Point(const Point &point) : _x(point._x), _y(point._y) { }

Point::~Point() { }

Point::Point(float x, float y) : _x(x), _y(y) { }

Fixed	Point::get_x(void) const
{
	return(this->_x);
}

Fixed	Point::get_y(void) const
{
	return(this->_y);
}

Point	&Point::operator=( Point const &point )
{
	if (this == &point)
		return *this;
	return *this;
}

std::ostream & operator<<( std::ostream & stream, Point const &fixed ) {
	stream << "x: " << fixed.get_x() << " y: " << fixed.get_y();
	return (stream);
}