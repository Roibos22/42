/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:28:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/14 19:47:24 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	{
		ClapTrap	a("Trappy");
		a.printClapTrap();
		a.attack("Target");
		a.takeDamage(5);
		a.printClapTrap();
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.printClapTrap();
		a.beRepaired(5);
		a.printClapTrap();
		a.attack("Target");
		a.beRepaired(1);
	}
	
}