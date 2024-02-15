/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:18:29 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/15 15:17:51 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>

class	ClapTrap
{
	private:
		std::string	_trapType;
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		// DE/CONSTRUCTORS
		ClapTrap(std::string name);
		~ClapTrap();

		// METHODS
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		// GETTERS
		std::string	getTrapType() const;
		std::string	getName() const;
		int			getHitPoints() const;
		int			getEnergyPoints() const;
		int			getAttackDamage() const;

		// SETTERS
		void		setTrapType(std::string trapType);
		void		setName(std::string name);
		void		setHitPoints(int amount);
		void		setEnergyPoints(int amount);
		void		setAttackDamage(int amount);
};

std::ostream	&operator<<(std::ostream &stream, ClapTrap const &clapTrap);

#endif