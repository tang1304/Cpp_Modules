/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:54:10 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/14 10:46:45 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << GREEN << "WrongAnimal default constructor called" << DEFAULT_COLOR << std::endl;
	this->_type = "none";
}

WrongAnimal::WrongAnimal(const WrongAnimal &old){
	std::cout << GREEN << "WrongAnimal copy constructor called" << DEFAULT_COLOR << std::endl;
	*this = old;
}

WrongAnimal::~WrongAnimal(){
	std::cout << RED << "WrongAnimal default destructor called" << DEFAULT_COLOR << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &old){
	this->_type = old.getType();
	return (*this);
}

std::string	WrongAnimal::getType() const{
	return (this->_type);
}

void	WrongAnimal::makeSound() const{
	std::cout << BLUE << "WrongAnimal makes strange sound" << DEFAULT_COLOR << std::endl;
}