/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:29:35 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/06 14:57:49 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon&		_weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void	attack();
};

#endif