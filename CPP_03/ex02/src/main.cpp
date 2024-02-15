/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:28:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/15 16:43:03 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	{
		ClapTrap	a("Trappy");
		std::cout << std::endl;

		ScavTrap	b("Scavvy");
		std::cout << std::endl;

		FragTrap	c("Fraggy");
		std::cout << std::endl;

		std::cout << b << a << c << std::endl;

		//a.guardGate();
		b.guardGate();
		//c.guardGate()
		std::cout << b << a << c << std::endl;

		//a.highFivesGuys();
		//b.highFivesGuys();
		c.highFivesGuys();
		std::cout << b << a << c << std::endl;

		a.attack("Target");
		b.attack("Target");
		c.attack("Target");
		std::cout << b << a << c << std::endl;

		a.takeDamage(5);
		b.takeDamage(5);
		c.takeDamage(5);
		std::cout << b << a << c << std::endl;

		a.beRepaired(10);
		b.beRepaired(10);
		c.beRepaired(10);
		std::cout << b << a << c << std::endl;
	}
}