/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:04:19 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/01 17:45:46 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MyAwesomePhonebook.hpp"

Contact::Contact(void)
{
	//std::cout << "Contcact constructed" << std::endl;
}

Contact::~Contact(void)
{
	//std::cout << "Contcact deconsturcted" << std::endl;
}

void Contact::display_contact_short(int index)
{
	std::string	firstName = this->_firstName.length() > 10 ? this->_firstName.substr(0, 9) + "." : this->_firstName;
	std::string	lastName = this->_lastName.length() > 10 ? this->_lastName.substr(0, 9) + "." : this->_lastName;
	std::string	nickname = this->_nickname.length() > 10 ? this->_nickname.substr(0, 9) + "." : this->_nickname;

	std::cout << "|" << std::setw(10) << std::right << index + 1 << "|";
	std::cout << std::setw(10) << std::right << firstName << "|";
	std::cout << std::setw(10) << std::right << lastName << "|";
	std::cout << std::setw(10) << std::right << nickname << "|" << std::endl;
}

void Contact::display_contact_full(int index)
{
	std::cout << "\033[32mIndex:\t\t " << index + 1<< std::endl;
	std::cout << "First Name:\t " << this->_firstName << std::endl;
	std::cout << "Last Name:\t " << this->_lastName << std::endl;
	std::cout << "Nickname:\t " <<this->_nickname << std::endl;
	std::cout << "Phone Number:\t " <<this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret:\t " <<this->_darkestSecret << std::endl;
}


void Contact::setFirstName(std::string first_name)
{
	this->_firstName = first_name;
}

void Contact::setLastName(std::string last_name)
{
	this->_lastName = last_name;
}

void Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phone_number)
{
	this->_phoneNumber = phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret)
{
	this->_darkestSecret = darkest_secret;
}