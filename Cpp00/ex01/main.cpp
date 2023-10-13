/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:10:31 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/13 15:13:56 by tgellon          ###   ########lyon.fr   */
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
		else if (prompt == "SEARCH")
			phonebook.searchContact();
		else if (prompt == "EXIT")
			return (0);
		else{
			std::cout << "You can only enter one of these command :" << std::endl;
			std::cout << " -ADD" << std::endl;
			std::cout << " -SEARCH" << std::endl;
			std::cout << " -EXIT" << std::endl;
			std::cout << std::endl;
		}
	}
	return (0);
}