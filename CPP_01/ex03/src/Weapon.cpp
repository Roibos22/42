/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:28:51 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/06 15:10:25 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon()
{
	
}

const std::string Weapon::getType()
{
	return (this->_type);
}


void	Weapon::setType(std::string type)
{
	this->_type = type;
}
