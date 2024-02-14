/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:22:26 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/14 19:56:58 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap Constructor called" << std::endl;
	this = ScavTrap(name);
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " has no hitPoints left to attack" << std::endl;
	if (this->_energyPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " has no energyPoints left to attack" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "ScavTrap " << this->_name << " took " << amount << " hitPoints damage" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
		std::cout  << "ScavTrap " << this->_name << " has no hitPoints left to repair" << std::endl;
	if (this->_energyPoints <= 0)
		std::cout  << "ScavTrap " << this->_name << " has no energyPoints left to repair" << std::endl;
	else
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "ScavTrap " << this->_name << " is being repaired and gains " << amount << "  hitPoints" << std::endl;
	}
}

void	ScavTrap::printClapTrap()
{
	std::cout << "ScavTrap " << this->_name
			  << ", hitPoints: " << this->_hitPoints
			  << ", energyPoints: " << this->_energyPoints
			  << ", attackDamage: " << this->_attackDamage << std::endl;

}