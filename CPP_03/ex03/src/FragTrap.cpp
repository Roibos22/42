/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:22:26 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/15 22:51:44 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << " - FragTrap - was born by default!" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

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
	std::cout << " - FragTrap - " << this->getName() << " died and says tschuss... :(" << std::endl;
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

std::ostream	&operator<<(std::ostream &stream, FragTrap const &fragTrap)
{
	stream << fragTrap.getTrapType() << fragTrap.getName()
			  << ", hitPoints: " << fragTrap.getHitPoints()
			  << ", energyPoints: " << fragTrap.getEnergyPoints()
			  << ", attackDamage: " << fragTrap.getAttackDamage()<< std::endl;
	return (stream);
}