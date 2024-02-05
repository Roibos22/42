/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:27:15 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/05 17:24:41 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		for (int j = 0; j < (int)(arg.length()); j++)
			std::cout << (char)toupper(argv[i][j]);
		std::cout << ' ';
	}
	std::cout << std::endl;
	return 0;
}