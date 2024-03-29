/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:28:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/15 15:31:31 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	{
		ClapTrap	a("Trappy");
		std::cout << std::endl;

		ScavTrap	b("Scavvy");
		std::cout << std::endl;

		std::cout << b << a << std::endl;

		//a.guardGate();
		b.guardGate();
		std::cout << b << a << std::endl;

		a.attack("Target");
		b.attack("Target");
		std::cout << b << a << std::endl;

		a.takeDamage(5);
		b.takeDamage(5);
		std::cout << b << a << std::endl;

		a.beRepaired(10);
		b.beRepaired(10);
		std::cout << b << a << std::endl;
	}
}