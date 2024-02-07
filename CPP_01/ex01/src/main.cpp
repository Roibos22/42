/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:52:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/05 19:04:37 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		n;

	n = 0;
	horde = zombieHorde(n, "HordeZombie");
	for (int i = 0; i < n; i++)
	{
		horde[i].announce();
	}
	delete [] horde;

	n = 1;
	horde = zombieHorde(n, "HordeZombie");
	for (int i = 0; i < n; i++)
	{
		horde[i].announce();
	}
	delete [] horde;

	n = 5;
	horde = zombieHorde(n, "HordeZombie");
	for (int i = 0; i < n; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
}