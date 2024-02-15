/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:22:26 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/15 22:51:50 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << " - ScavTrap - was born by default!" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << " - ScavTrap - " << this->getName() << " was born and says hi!" << std::endl;
	this->setTrapType(" - ScavTrap - ");
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::~ScavTrap()
{
	std::cout << " - ScavTrap - " << this->getName() << " died and says bye... :(" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoints() <= 0)
		std::cout << this->getTrapType() << this->getName() << " has no hitPoints left to attack" << std::endl;
	if (this->getEnergyPoints() <= 0)
		std::cout << this->getTrapType() << this->getName() << " has no energyPoints left to attack" << std::endl;
	else
	{
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << this->getTrapType() << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage! What a strike!" << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << this->getTrapType() << this->getName() << " is now in Gate Keeper mode" << std::endl;
}

std::ostream	&operator<<(std::ostream &stream, ScavTrap const &scavTrap)
{
	stream << scavTrap.getTrapType() << scavTrap.getName()
			  << ", hitPoints: " << scavTrap.getHitPoints()
			  << ", energyPoints: " << scavTrap.getEnergyPoints()
			  << ", attackDamage: " << scavTrap.getAttackDamage() << std::endl;
	return (stream);
}
