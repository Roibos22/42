/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:50:09 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/14 13:37:44 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(Fixed &fixed);
		Fixed &operator=(Fixed &fixed);

		int		getRawBits	( void ) const;
		void	setRawBits	( int const raw );
};

#endif