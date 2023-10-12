/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:33:05 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/12 18:52:10 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	return;
}

PhoneBook::~PhoneBook(void){
	return;
}

void	PhoneBook::addContact(){
	std::string	input;

	input = "";
	if (this->_index == 8)
		std::cout << "Writting over " << this->_contacts[this->_index % 8].getFirstName() << std::endl;
	while (input == ""){
		std::cout << "Enter contact's first name : ";
		std::getline(std::cin, input);
		this->_contacts[this->_index % 8].setFirstName(input);
	}
	input = "";
	while (input == ""){
		std::cout << "Enter contact's last name : ";
		std::getline(std::cin, input);
		this->_contacts[this->_index % 8].setLastName(input);
	}
	input = "";
	while (input == ""){
		std::cout << "Enter contact's nickname : ";
		std::getline(std::cin, input);
		this->_contacts[this->_index % 8].setNickname(input);
	}
	input = "";
	while (input == ""){
		std::cout << "Enter contact's phone number : ";
		std::getline(std::cin, input);
		this->_contacts[this->_index % 8].setPhoneNumber(input);
	}
	input = "";
	while (input == ""){
		std::cout << "Enter contact's darkest secret : ";
		std::getline(std::cin, input);
		this->_contacts[this->_index % 8].setDarkestSecret(input);
	}
	this->_index++;
}

void	PhoneBook::searchContact(void){
	;
}