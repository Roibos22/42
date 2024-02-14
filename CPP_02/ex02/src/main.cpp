/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:52:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/14 20:35:29 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* int	main( void ) 
{
	Fixed	a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	Fixed	c( 5.05f );
	Fixed	d(2);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
} */

int	main( void )
{
	Fixed	a;
	a = Fixed( 1234.4321f );
	Fixed const	b( 10 );
	Fixed const	c( 42.42f );
	Fixed const	d( b );

	{
		std::cout << "--- Testing < Operator ---" << std::endl;
		std::cout << "a: " << a.toFloat() << " b: " << b.toFloat() << std::endl;
		if (a < b)
			std::cout << "a is smaller than b" << std::endl << std::endl;
		else
			std::cout << "a is not smaller than b" << std::endl << std::endl;
	}

	{
		std::cout << "--- Testing > Operator ---" << std::endl;
		std::cout << "a: " << a.toFloat() << " b: " << b.toFloat() << std::endl;
		if (a > b)
			std::cout << "a is greater than b" << std::endl << std::endl;
		else
			std::cout << "a is not greater than b" << std::endl << std::endl;
	}

	{
		std::cout << "--- Testing >= Operator ---" << std::endl;
		std::cout << "a: " << a.toFloat() << std::endl;
		if (a >= a)
			std::cout << "a is greater or equal to a" << std::endl << std::endl;
		else
			std::cout << "a is not greater or equal to a" << std::endl << std::endl;
	}

	{
		std::cout << "--- Testing <= Operator ---" << std::endl;
		std::cout << "b: " << b.toFloat() << std::endl;
		if (b <= b)
			std::cout << "b is smaller or equal to b" << std::endl << std::endl;
		else
			std::cout << "b is not smaller or equal to b" << std::endl << std::endl;
	}

	{
		std::cout << "--- Testing + Operator ---" << std::endl;
		std::cout << "a: " << a.toFloat() << " b: " << b.toFloat() << std::endl;
		Fixed	c = a + b;
		std::cout << "c: " << c.toFloat() << std::endl << std::endl;
	}

	{
		std::cout << "--- Testing - Operator ---" << std::endl;
		std::cout << "a: " << a.toFloat() << " b: " << b.toFloat() << std::endl;
		Fixed	c = a - b;
		std::cout << "c: " << c.toFloat() << std::endl << std::endl;
	}

	{
		std::cout << "--- Testing * Operator ---" << std::endl;
		std::cout << "a: " << a.toFloat() << " b: " << b.toFloat() << std::endl;
		Fixed	c = a * b;
		std::cout << "c: " << c.toFloat() << std::endl << std::endl;
	}

	{
		std::cout << "--- Testing / Operator ---" << std::endl;
		std::cout << "a: " << a.toFloat() << " b: " << b.toFloat() << std::endl;
		Fixed	c = a / b;
		std::cout << "c: " << c.toFloat() << std::endl << std::endl;
	}

	{
		std::cout << "--- Testing ++ (post) Operator ---" << std::endl;
		std::cout << "-> Creating b form a++ (bits:" << a.getRawBits() << ")" << std::endl;
		Fixed	b  = a++;
		std::cout << "a flaot value: " << a.toFloat() << " a raw bits: " << a.getRawBits() << std::endl;
		std::cout << "b flaot value: " << b.toFloat() << " b raw bits: " << b.getRawBits() << std::endl << std::endl;
	}

	{
		std::cout << "--- Testing ++ (pre) Operator ---" << std::endl;
		std::cout << "-> Creating b form ++a (bits:" << a.getRawBits() << ")" << std::endl;
		Fixed	b  = ++a;
		std::cout << "a flaot value: " << a.toFloat() << " a raw bits: " << a.getRawBits() << std::endl;
		std::cout << "b flaot value: " << b.toFloat() << " b raw bits: " << b.getRawBits() << std::endl << std::endl;
	}

	{
		std::cout << "--- Testing -- (post) Operator ---" << std::endl;
		std::cout << "-> Creating b form a-- (bits:" << a.getRawBits() << ")" << std::endl;
		Fixed	b  = a--;
		std::cout << "a flaot value: " << a.toFloat() << " a raw bits: " << a.getRawBits() << std::endl;
		std::cout << "b flaot value: " << b.toFloat() << " b raw bits: " << b.getRawBits() << std::endl << std::endl;
	}

	{
		std::cout << "--- Testing -- (post) Operator ---" << std::endl;
		std::cout << "-> Creating b form --a (bits:" << a.getRawBits() << ")" << std::endl;
		Fixed	b  = --a;
		std::cout << "a flaot value: " << a.toFloat() << " a raw bits: " << a.getRawBits() << std::endl;
		std::cout << "b flaot value: " << b.toFloat() << " b raw bits: " << b.getRawBits() << std::endl << std::endl;
	}

	{
		Fixed	e(42.42f);
		Fixed	f(420.420f);
		std::cout << Fixed::max(e, f) << " is the max" << std::endl;
		std::cout << Fixed::min(e, f) << " is the min" << std::endl;
	}

	return (0);
}