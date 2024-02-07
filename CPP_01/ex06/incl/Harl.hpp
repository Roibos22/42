/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:26:29 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/07 01:24:55 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

#define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
#define INFO_MSG "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn't be asking for more!"
#define WARN_MSG "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month"
#define ERR_MSG "This is unacceptable! I want to speak to the manager now."

class Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public:
		Harl();
		~Harl();

		void	complain(std::string level);
};

#endif