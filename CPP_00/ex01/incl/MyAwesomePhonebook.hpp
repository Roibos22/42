/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhonebook.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:57:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/31 12:17:00 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_AWESOME_PHONEBOOK_HPP
# define MY_AWESOME_PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <unistd.h>
# include <cstdio>

# include "Contact.hpp"
# include "Phonebook.hpp"

std::string	getValidInput(const std::string& prompt);
void		clean_string(std::string& str);

#endif