/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:18:03 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/13 13:59:48 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){
}

Contact::Contact(std::string infos[5])
	: _firstName(infos[0]), _lastName(infos[1]), _nickname(infos[2]),
	_phoneNumber(infos[3]), _darkestSecret(infos[4]) {}

Contact::~Contact(void){
}

std::string	Contact::truncateInfo(std::string info){
	if (info.size() > 9)
		return (info.substr(0, 9) + '.');
	return (info);
}

void	Contact::printInfos(){
	std::cout <<  std::right << std::setw(10) << this->truncateInfo(this->_firstName) << "|";
	std::cout <<  std::right << std::setw(10) << this->truncateInfo(this->_lastName) << "|";
	std::cout <<  std::right << std::setw(10) << this->truncateInfo(this->_nickname) << "|";
	std::cout << std::endl;
}

void	Contact::setFirstName(std::string str){
	this->_firstName = str;
}

void	Contact::setLastName(std::string str){
	this->_lastName = str;
}

void	Contact::setNickname(std::string str){
	this->_nickname = str;
}

void	Contact::setPhoneNumber(std::string str){
	this->_phoneNumber = str;
}

void	Contact::setDarkestSecret(std::string str){
	this->_darkestSecret = str;
}

std::string	Contact::getFirstName(void) const{
	return (this->_firstName);
}

std::string	Contact::getLastName(void) const{
	return (this->_lastName);
}

std::string	Contact::getNickname(void) const{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void) const{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const{
	return (this->_darkestSecret);
}