/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:28:51 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/07 01:25:29 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void	Harl::debug( void )
{
	std::cout << DEBUG_MSG << std::endl;
}

void	Harl::info( void )
{
	std::cout << INFO_MSG << std::endl;
}

void	Harl::warning( void )
{
	std::cout << WARN_MSG << std::endl;
}

void	Harl::error( void )
{
	std::cout << ERR_MSG << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*funcPtr[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			(this->*funcPtr[i])();
	}
}

