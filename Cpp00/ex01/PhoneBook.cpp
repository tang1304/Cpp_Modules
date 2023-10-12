/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:33:05 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/12 14:29:27 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	return;
}

PhoneBook::~PhoneBook(void){
	return;
}

void	addContact(){
	std::string	input;

	if (this->_index == 8)
		;
	while (!std::cin.eof()){
		std::cout << "Enter contact's first name : ";
		std::getline(std::cin, input);
		setFirstName(input);
	}
}