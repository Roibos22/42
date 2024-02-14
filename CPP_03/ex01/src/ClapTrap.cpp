/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:22:26 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/14 19:46:15 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Deconstructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " has no hitPoints left to attack" << std::endl;
	if (this->_energyPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " has no energyPoints left to attack" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "ClapTrap " << this->_name << " took " << amount << " hitPoints damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
		std::cout  << "ClapTrap " << this->_name << " has no hitPoints left to repair" << std::endl;
	if (this->_energyPoints <= 0)
		std::cout  << "ClapTrap " << this->_name << " has no energyPoints left to repair" << std::endl;
	else
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " is being repaired and gains " << amount << "  hitPoints" << std::endl;
	}
}

void	ClapTrap::printClapTrap()
{
	std::cout << "ClapTrap " << this->_name
			  << ", hitPoints: " << this->_hitPoints
			  << ", energyPoints: " << this->_energyPoints
			  << ", attackDamage: " << this->_attackDamage << std::endl;

}