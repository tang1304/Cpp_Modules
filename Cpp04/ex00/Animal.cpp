/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:34:54 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/13 13:14:51 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
	std::cout << GREEN << "Animal default constructor called" << DEFAULT_COLOR << std::endl;
	this->_type = "none";
}

Animal::Animal(const Animal &old){
	std::cout << GREEN << "Animal copy constructor called" << DEFAULT_COLOR << std::endl;
	*this = old;
}

Animal::~Animal(){
	std::cout << RED << "Animal default destructor called" << DEFAULT_COLOR << std::endl;
}

Animal &Animal::operator=(const Animal &old){
	this->_type = old.getType();
	return (*this);
}

std::string	Animal::getType() const{
	return (this->_type);
}

void	Animal::makeSound(){
	std::cout << BLUE << "Animal makes unrecognizable sound" << DEFAULT_COLOR << std::endl;
}