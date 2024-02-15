/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:22:26 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/15 19:32:50 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << " - FragTrap - " << this->getName() << " was born and says moin!" << std::endl;
	this->setTrapType(" - FragTrap - ");
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::~FragTrap()
{
	std::cout << " - ScavTrap - " << this->getName() << " died and says tschuss... :(" << std::endl;
}

void	FragTrap::attack(const std::string& target)
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

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->getTrapType() << this->getName() << " is requesting a HighFive from the evaluator!" << std::endl;
}
