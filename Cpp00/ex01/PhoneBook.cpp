/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:33:05 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/13 14:09:55 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	this->_index = 0;
	return ;
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

Contact	PhoneBook::getContact(int index){
	return (this->_contacts[index]);
}

void	PhoneBook::printHeader(void){
	std::cout << std::right << std::setw(10) << std::setfill  (' ') << "INDEX" << "|";
	std::cout << std::right << std::setw(10) << std::setfill  (' ') << "FIRST NAME" << "|";
	std::cout << std::right << std::setw(10) << std::setfill  (' ') << "LAST NAME" << "|";
	std::cout << std::right << std::setw(10) << std::setfill  (' ') << "NICKNAME" << "|";
	std::cout << std::endl;
	return ;
}

void	PhoneBook::searchContact(void){
	if (this->_index == 0){
		std::cout << "Phonebook empty, add a contact first" << std::endl;
		return ;
	}
	this->printHeader();
	for (int i = 0; i < this->_index; i++){
		std::cout << std::right << std::setw(10) << std::setfill  (' ') << i << "|";
		this->getContact(i).printInfos();
	}
	return ;
}