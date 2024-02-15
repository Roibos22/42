/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:22:26 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/15 19:24:19 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->_trapType = " - ClapTrap - ";
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << " - ClapTrap - " << this->getName() << " was born!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << " - ClapTrap - " << this->getName() << " died... :(" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
		std::cout << this->getTrapType() << this->getName() << " has no hitPoints left to attack" << std::endl;
	if (this->_energyPoints <= 0)
		std::cout << this->getTrapType() << this->getName() << " has no energyPoints left to attack" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << this->getTrapType() << this->getName() << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << this->getTrapType() << this->getName() << " took " << amount << " hitPoints damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
		std::cout  << this->getTrapType() << this->getName() << " has no hitPoints left to repair" << std::endl;
	if (this->_energyPoints <= 0)
		std::cout  << this->getTrapType() << this->getName() << " has no energyPoints left to repair" << std::endl;
	else
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << this->getTrapType() << this->getName() << " is being repaired and gains " << amount << "  hitPoints" << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &stream, ClapTrap const &clapTrap)
{
	stream << clapTrap.getTrapType() << clapTrap.getName()
			  << ", hitPoints: " << clapTrap.getHitPoints()
			  << ", energyPoints: " << clapTrap.getEnergyPoints()
			  << ", attackDamage: " << clapTrap.getAttackDamage()<< std::endl;
	return (stream);
}

// GETTERS
std::string	ClapTrap::getTrapType() const
{
	return(this->_trapType);
}

std::string	ClapTrap::getName() const
{
	return(this->_name);
}

int			ClapTrap::getHitPoints() const
{
	return(this->_hitPoints);
}

int			ClapTrap::getEnergyPoints() const
{
	return(this->_energyPoints);
}

int			ClapTrap::getAttackDamage() const
{
	return(this->_attackDamage);
}


// SETTERS
void		ClapTrap::setTrapType(std::string trapType)
{
	this->_trapType = trapType;
}

void		ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void		ClapTrap::setHitPoints(int amount)
{
	this->_hitPoints = amount;
}

void		ClapTrap::setEnergyPoints(int amount)
{
	this->_energyPoints = amount;
}

void		ClapTrap::setAttackDamage(int amount)
{
	this->_attackDamage = amount;
}
