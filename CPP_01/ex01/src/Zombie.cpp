/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:16:09 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/05 19:04:18 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << this->_name << " was killed" << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

void	Zombie::set_index(int index)
{
	this->_index = index;
}

void	Zombie::announce ( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

