/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:52:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/07 03:30:08 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *heapZombie = newZombie("Heapy");
	heapZombie->announce();
	delete(heapZombie);

	heapZombie = newZombie("HeapyRegen");
	heapZombie->announce();
	delete(heapZombie);

	randomChump("Stacky");
	randomChump("StackyRegen");
}