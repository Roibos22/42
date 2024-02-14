/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:24:10 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/14 13:28:31 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point	a(0.0f, 1.0f);
	Point	b(-1.0f, -1.0f);
	Point	c(1.0f, -1.0f);

	std::cout << "Trianlge:" << std::endl
			  <<  "A: " << a << std::endl
			  <<  "B: " << b << std::endl
			  <<  "C: " << c << std::endl << std::endl;

	{
		Point	point1(0, 0);
		if (bsp(a, b, c, point1))
			std::cout << point1 << " lies in triangle" << std::endl;
		else 
			std::cout << point1 << " does not lie in triangle" << std::endl;
	}
	{
		Point	point2(0.0f, 2.0f);
		if (bsp(a, b, c, point2))
			std::cout << point2 << " lies in triangle" << std::endl;
		else 
			std::cout << point2 << " does not lie in triangle" << std::endl;
	}
	{
		Point	point3(0.0f, -1.0f);
		if (bsp(a, b, c, point3))
			std::cout << point3 << " lies in triangle" << std::endl;
		else 
			std::cout << point3 << " does not lie in triangle" << std::endl;
	}
}