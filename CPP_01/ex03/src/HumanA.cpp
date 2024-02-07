/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:33:08 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/06 14:18:55 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {};

HumanA::~HumanA()
{
	
}

void	HumanA::attack()
{
	std::string	type = this->_weapon.getType();

	std::cout << this->_name << " attacks with their " << type << std::endl;
}
