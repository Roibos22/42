/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:47:00 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/31 12:00:48 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MyAwesomePhonebook.hpp"

Phonebook::Phonebook(void)
{
	//std::cout << "Phonebook constructed" << std::endl;
	this->contactsCount = 0;
}

Phonebook::~Phonebook(void)
{
	//std::cout << "Phonebook deconstructed" << std::endl;
}

void	Phonebook::add_contact(Contact contact)
{
	if (this->contactsCount < 8)
	{
		this->contacts[contactsCount] = contact;
		this->contactsCount++;
	} else 
	{
		for (int i = 0; i < 7; i++)
			this->contacts[i] = this->contacts[i + 1];
		this->contacts[7] = contact;
	}
}

void Phonebook::create_new_contact(void)
{
	Contact new_contact;
	
	new_contact.setFirstName(getValidInput("First Name"));
	new_contact.setLastName(getValidInput("Last Name"));
	new_contact.setNickname(getValidInput("Nickname"));
	new_contact.setPhoneNumber(getValidInput("Phone Number"));
	new_contact.setDarkestSecret(getValidInput("Darkest Secret"));

	add_contact(new_contact);
}

void	Phonebook::display_phonebook(void)
{
	if (this->contactsCount == 0)
	{
		std::cout << "\033[31mThe Phone Book is empty. Please add Contacts first.\033[0m" << std::endl;
		return ;
	}

	std::cout << "\033[32m|-------------------------------------------|" << std::endl;
	std::cout << "|                PHONE  BOOK                |" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < this->contactsCount; i++)
		this->contacts[i].display_contact_short(i);
	std::cout << "|-------------------------------------------|\033[0m" << std::endl;

	while (42)
	{
		std::string input;
		std::cout << "\033[34mEnter Index of contact to display:\033[0m\t ";
		std::getline(std::cin, input);
		if(std::cin.eof())
			break ;
		int index = atoi(input.c_str()) - 1;
		if (index >= 0 && index < this->contactsCount)
		{
			this->contacts[index].display_contact_full(index);
			break ;
		}
		else
			std::cout << "\033[31mError: Index out of range\033[0m\t " <<  std::endl;
	}
}
