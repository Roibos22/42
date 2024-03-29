/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:28:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/15 16:19:57 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	{
		ClapTrap	a("Trappy");
		std::cout << a;
		a.attack("Target");
		a.takeDamage(5);
		std::cout << a;
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		std::cout << a;
		a.beRepaired(5);
		std::cout << a;
		a.attack("Target");
		a.beRepaired(1);
	}	
}