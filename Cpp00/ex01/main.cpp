/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:10:31 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/12 18:51:40 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void){
	PhoneBook	phonebook;
	std::string	prompt;

	while (1){
		std::cout << "Type your command : ";
		std::getline(std::cin, prompt);
		if (prompt == "ADD")
			phonebook.addContact();
		if (prompt == "SEARCH")
			phonebook.searchContact;
		if (prompt == "EXIT")
			return (0);
	}
	return (0);
}