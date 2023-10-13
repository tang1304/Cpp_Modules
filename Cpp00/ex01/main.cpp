/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:10:31 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/13 13:02:14 by tgellon          ###   ########lyon.fr   */
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
		if (std::cin.eof())
			return (1);
		if (prompt == "ADD")
			phonebook.addContact();
		if (prompt == "SEARCH")
			phonebook.searchContact();
		if (prompt == "EXIT")
			return (0);
	}
	return (0);
}