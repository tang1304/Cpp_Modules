/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:04:07 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/13 15:38:39 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	std::cout << GREEN << "Cat default constructor called" << DEFAULT_COLOR << std::endl;
	this->_type = "cat";
}

Cat::Cat(std::string type){
	this->_type = type;
	std::cout << GREEN << "Cat constructor called" << DEFAULT_COLOR << std::endl;
}

Cat::Cat(const Cat &old) : Animal(old){
	std::cout << GREEN << "Cat copy constructor called" << DEFAULT_COLOR << std::endl;
	*this = old;
}

Cat::~Cat(){
	std::cout << RED << "Cat default destructor called" << DEFAULT_COLOR << std::endl;
}

Cat &Cat::operator=(const Cat &old){
	this->_type = old.getType();
	return (*this);
}

void	Cat::makeSound() const{
	std::cout << BLUE << this->_type << " makes : meow" << DEFAULT_COLOR <<std::endl;
}