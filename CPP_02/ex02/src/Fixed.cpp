/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:13 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/14 20:34:24 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default Constructors

Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::~Fixed()
{
}

// Custom Constructors

Fixed::Fixed(const int value)
{
	this->_value = value << this->_bits;
}

Fixed::Fixed(float value)
{
	this->_value = roundf(value * (float)(1 << this->_bits));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

// Methods

int		Fixed::getRawBits(void) const
{
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>( (float)this->getRawBits() ) / (float)( 1 << this->_bits ));
}

int		Fixed::toInt(void) const
{
	return ( this->getRawBits() >> this->_bits);
}

// Comparison Operators

Fixed	&Fixed::operator=(const Fixed &copy)
{
	this->_value = copy.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->_value > rhs._value);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->_value < rhs._value);
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_value >= rhs._value);
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_value <= rhs._value);
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->_value == rhs._value);
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_value != rhs._value);
}

// Arithmetic Operators

Fixed	Fixed::operator+(const Fixed &copy) const
{
	return (Fixed(this->toFloat() + copy.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &copy) const
{
	return (Fixed(this->toFloat() - copy.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &copy) const
{
	return (Fixed(this->toFloat() * copy.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &copy) const
{
	return (Fixed(this->toFloat() / copy.toFloat()));
}

// Increment / Decrement Operators

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;

	++(this->_value);
	return(tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;

	--(this->_value);
	return(tmp);
}

Fixed	Fixed::operator++(void)
{
	++(this->_value);
	return(*this);
}

Fixed	Fixed::operator--(void)
{
	--(this->_value);
	return(*this);
}

Fixed&	Fixed::min(Fixed &first, Fixed &second)
{
	return first.getRawBits() > second.getRawBits() ? second : first;
}

Fixed&	Fixed::min(const Fixed &first, const Fixed &second)
{
	return first.getRawBits() > second.getRawBits() ? (Fixed&)second : (Fixed&)first;
}

Fixed&	Fixed::max(Fixed &first, Fixed &second)
{
	return first.getRawBits() < second.getRawBits() ? second : first;
}

Fixed&	Fixed::max(const Fixed &first, const Fixed &second)
{
	return first.getRawBits() < second.getRawBits() ? (Fixed&)second : (Fixed&)first;
}

std::ostream & operator<<( std::ostream & stream, Fixed const &fixed ) {
	stream << fixed.toFloat();
	return (stream);
}
