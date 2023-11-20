/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:04:07 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/20 10:15:09 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cat.hpp"

Cat::Cat(){
	std::cout << GREEN << "Cat default constructor called" << DEFAULT_COLOR << std::endl;
	this->_type = "Cat";
	_brain = new Brain;
}

Cat::Cat(const Cat &old) : Animal(old){
	std::cout << GREEN << "Cat copy constructor called" << DEFAULT_COLOR << std::endl;
	this->_type = old.getType();
	this->_brain = new Brain(*old.getBrain());
}

Cat::~Cat(){
	delete _brain;
	std::cout << RED << "Cat default destructor called" << DEFAULT_COLOR << std::endl;
}

Cat &Cat::operator=(const Cat &old){
	if (this != &old)
	{
		delete this->_brain;
		this->_type = old.getType();
		this->_brain = new Brain(*old.getBrain());
	}
	return (*this);
}

void	Cat::makeSound() const{
	std::cout << BLUE << this->_type << " makes : meow" << DEFAULT_COLOR <<std::endl;
}

Brain	*Cat::getBrain() const{
	return (this->_brain);
}