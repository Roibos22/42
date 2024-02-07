/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:52:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/07 03:37:48 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	{
		Weapon	club = Weapon("crude spiked club");

		HumanB	jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	
	return 0;
}