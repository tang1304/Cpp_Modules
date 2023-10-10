/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:18:03 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/10 14:58:28 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){
}

Contact::~Contact(void){
}

std::string Contact::getFirstName(void) const{
	return (this->_firstName);
}

std::string Contact::getLastName(void) const{
	return (this->_lasttName);
}

std::string Contact::getNickname(void) const{
	return (this->_nickname);
}

std::string Contact::getPhoneNumber(void) const{
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const{
	return (this->_darkestSecret);
}