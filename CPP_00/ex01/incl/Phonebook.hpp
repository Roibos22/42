/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:12:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/26 18:20:20 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "MyAwesomePhonebook.hpp"

class Phonebook
{
	private:
		Contact		contacts[8];
		int			contactsCount;

	public:
		Phonebook();
		~Phonebook();

		void		add_contact(Contact contact);
		void		create_new_contact(void);
		void		display_phonebook(void);
};

#endif