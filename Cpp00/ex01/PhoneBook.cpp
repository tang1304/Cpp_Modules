/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:33:05 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/13 16:20:40 by tgellon          ###   ########lyon.fr   */
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
	std::cout << std::right << std::setw(10) << std::setfill (' ') << "INDEX" << "|";
	std::cout << std::right << std::setw(10) << std::setfill (' ') << "FIRST NAME" << "|";
	std::cout << std::right << std::setw(10) << std::setfill (' ') << "LAST NAME" << "|";
	std::cout << std::right << std::setw(10) << std::setfill (' ') << "NICKNAME" << "|";
	std::cout << std::endl;
	std::cout << std::setw(44) << std::setfill ('-');
	std::cout << std::endl;
	return ;
}

void	PhoneBook::searchContact(void){
	std::string	prompt;
	int	index;

	if (this->_index == 0){
		std::cout << "Phonebook empty, add a contact first" << std::endl;
		return ;
	}
	this->printHeader();
	for (int i = 0; i < this->_index; i++){
		std::cout << std::right << std::setw(10) << std::setfill  (' ') << i + 1 << "|";
		this->getContact(i).printInfos();
	}
	while (1){
		std::cout << "Select contact's index : ";
		std::getline(std::cin, prompt);
		std::istringstream	sIndex(prompt);
		sIndex >> index;
		if (index > this->_index || index <= 0){
			std::cout << "You must enter an index between 1 and " << this->_index << std::endl;
			// prompt.clear();
			continue ;
		}
		break ;
	}
	std::cout << "First name : " << this->getContact(index - 1).getFirstName() << std::endl;
	std::cout << "Last name : " << this->getContact(index - 1).getLastName() << std::endl;
	std::cout << "Nickname : " << this->getContact(index - 1).getNickname() << std::endl;
	std::cout << "Phone number : " << this->getContact(index - 1).getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << this->getContact(index - 1).getDarkestSecret() << std::endl;
	return ;
}