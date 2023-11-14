/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:34:54 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/14 15:11:07 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/AAnimal.hpp"

AAnimal::AAnimal(){
	std::cout << GREEN << "AAnimal default constructor called" << DEFAULT_COLOR << std::endl;
	this->_type = "none";
}

AAnimal::AAnimal(const AAnimal &old){
	std::cout << GREEN << "AAnimal copy constructor called" << DEFAULT_COLOR << std::endl;
	*this = old;
}

AAnimal::~AAnimal(){
	std::cout << RED << "AAnimal default destructor called" << DEFAULT_COLOR << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &old){
	this->_type = old.getType();
	return (*this);
}

std::string	AAnimal::getType() const{
	return (this->_type);
}
