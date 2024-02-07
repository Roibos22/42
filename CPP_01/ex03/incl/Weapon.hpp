/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:26:29 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/06 13:59:32 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(std::string type);
		~Weapon();

		const std::string	getType();
		void				setType(std::string type);
};

#endif