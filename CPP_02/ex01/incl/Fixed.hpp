/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:50:09 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/14 20:32:14 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;

	public:
		// Default Constructors
		Fixed();
		~Fixed();

		// Custom Constructors
		Fixed(const Fixed &fixed);	// Copy Construtor
		Fixed(const int value);		// Int Constructor
		Fixed(const float value);	// Float Constructor
		
		// Operator overload
		Fixed	&operator=(const Fixed &fixed);

		// Methods
		int		getRawBits(void) const ;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif