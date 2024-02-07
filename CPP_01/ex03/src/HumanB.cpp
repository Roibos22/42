/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:52:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/06 15:12:20 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB()
{
	
}

void	HumanB::attack()
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " failed to attack " << std::endl;
	else
	{
		std::string	type = this->_weapon->getType();
		std::cout << this->_name << " attacks with their " << type << std::endl;
	}
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
