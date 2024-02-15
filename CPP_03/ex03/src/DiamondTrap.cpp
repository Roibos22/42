/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:22:26 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/15 22:50:50 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	setTrapType(" - DiamTrap - ");
	this->_name = name;
	FragTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(50);
	FragTrap::setAttackDamage(30);
	std::cout << " - DiamTrap - " << DiamondTrap::getName() << " was born and says good morning!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << " - DiamTrap - " << this->_name << " died and says good night... :(" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	 std::cout << " - WhoAmI?? - I am a DiamondTrap named " << this->_name
			   << ", ClapTrap name: " << ClapTrap::getName() << std::endl;
}

/* std::string	DiamondTrap::getName() const
{
	return(this->_name);
} */

std::ostream	&operator<<(std::ostream &stream, DiamondTrap const &diamondTrap)
{
	stream << diamondTrap.getTrapType() << diamondTrap.getName()
			  << ", hitPoints: " << diamondTrap.getHitPoints()
			  << ", energyPoints: " << diamondTrap.getEnergyPoints()
			  << ", attackDamage: " << diamondTrap.getAttackDamage()<< std::endl;
	return (stream);
}