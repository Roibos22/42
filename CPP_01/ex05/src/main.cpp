/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:52:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/07 01:26:15 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	harl.complain("DEBUG");
	harl.complain("DEBUG");
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("INFO");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("WARNING");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("ERROR");
	harl.complain("ERROR");
	harl.complain("FALSE");
	harl.complain("FALSE");
	harl.complain("FALSE");
	return 0;
}