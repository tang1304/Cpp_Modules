/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:18:30 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/13 15:38:51 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
	std::cout << GREEN << "Dog default constructor called" << DEFAULT_COLOR << std::endl;
	this->_type = "Dog";
}

Dog::Dog(std::string type){
	this->_type = type;
	std::cout << GREEN << "Dog constructor called" << DEFAULT_COLOR << std::endl;
}

Dog::Dog(const Dog &old) : Animal(old){
	std::cout << GREEN << "Dog copy constructor called" << DEFAULT_COLOR << std::endl;
	*this = old;
}

Dog::~Dog(){
	std::cout << RED << "Dog default destructor called" << DEFAULT_COLOR << std::endl;
}

Dog &Dog::operator=(const Dog &old){
	this->_type = old.getType();
	return (*this);
}

void	Dog::makeSound(){
	std::cout << BLUE << this->_type << " makes : woof" << DEFAULT_COLOR <<std::endl;
}