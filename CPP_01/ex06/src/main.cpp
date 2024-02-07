/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:52:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/07 03:48:21 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define USAGE_ERR "Usage: ./harlFilter DEBUG, INFO, WARNING or ERROR"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << USAGE_ERR << std::endl;
		return (1);
	}

	std::string str = argv[1];
	if (str != "DEBUG" && str != "INFO" && str != "WARNING" && str != "ERROR")
	{
		std::cerr << USAGE_ERR << std::endl;
		return (2);
	}

	Harl	harl;
	char	c = argv[1][0];

	switch (c)
	{
		case 'D':
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
		case 'I':
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
		case 'W':
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
		case 'E':
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			break ;
		default:
			std::cerr << USAGE_ERR << std::endl;
	}

	return 0;
}