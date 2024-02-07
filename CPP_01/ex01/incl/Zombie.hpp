/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:50:09 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/05 19:04:08 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string	_name;
		int			_index;

	public:
		Zombie();
		~Zombie();

		void	announce(void);
		void	set_name(std::string name);
		void	set_index(int index);
};

Zombie* zombieHorde( int N, std::string name );

#endif