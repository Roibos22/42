/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:06:56 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/05 20:02:36 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringRef = string;

	std::cout << "Address of string        : " << &string << std::endl;
	std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of stringREF     : " << &stringRef << std::endl;

	std::cout << "Value of string          : " << string << std::endl;
	std::cout << "Value of stringPTR       : " << *stringPTR << std::endl;
	std::cout << "Value of stringREF       : " << stringRef << std::endl;
}