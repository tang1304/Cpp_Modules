/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:30:57 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/16 10:03:55 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact _contacts[8];
	int		_index;
	int		_nbrOfContacts;
public:
	PhoneBook(void);
	~PhoneBook(void);

	void	addContact();
	Contact	getContact(int index);
	void	printHeader();
	void	searchContact();
};

#endif