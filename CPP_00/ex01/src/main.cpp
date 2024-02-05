/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:12:07 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/31 12:17:14 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MyAwesomePhonebook.hpp"

int main(void)
{
	Phonebook	phonebook;
	std::string	input;
	// Check if std::cin is connected to a terminal or a pipe
	bool		is_interactive = isatty(fileno(stdin));

	while (is_interactive || std::getline(std::cin, input))
	{
		if(std::cin.eof())
			break ;
		std::cout << "\033[34mCommand [ADD, SEARCH or EXIT]: \033[0m";
		
		// FOR TESTING PURPOSES
		if(is_interactive)
			std::getline(std::cin, input);

		if (input == "ADD")
			phonebook.create_new_contact();
		else if (input == "SEARCH")
			phonebook.display_phonebook();
		else if (input == "EXIT")
			break ;
	}
}

std::string getValidInput(const std::string& prompt)
{
	std::string input;
	while (true)
	{
		std::cout << "\033[34m" << prompt << ":\t \033[0m";
		std::getline(std::cin, input);
		if(std::cin.eof())
			break ;
		clean_string(input);
		if (!(input.find_first_not_of(' ') == std::string::npos))
			break ;
	}
	return (input);
}

void clean_string(std::string& str)
{
	for (std::size_t i = 0; i < str.size(); ++i)
	{
		if (str.at(i) >= 9 && str.at(i) <= 13)
			str.at(i) = ' ';
	}
}

