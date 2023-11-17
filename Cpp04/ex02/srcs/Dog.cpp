/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:18:30 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/17 15:56:55 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Dog.hpp"

Dog::Dog(){
	std::cout << GREEN << "Dog default constructor called" << DEFAULT_COLOR << std::endl;
	this->_type = "Dog";
	_brain = new Brain;
}

Dog::Dog(const Dog &old) : AAnimal(old){
	std::cout << GREEN << "Dog copy constructor called" << DEFAULT_COLOR << std::endl;
	this->_type = old.getType();
	this->_brain = new Brain(*old.getBrain());
}

Dog::~Dog(){
	delete _brain;
	std::cout << RED << "Dog default destructor called" << DEFAULT_COLOR << std::endl;
}

Dog &Dog::operator=(const Dog &old){
	if (this != &old)
	{
		delete this->_brain;
		this->_type = old.getType();
		this->_brain = new Brain(*old.getBrain());
	}
	return (*this);
}

void	Dog::makeSound() const{
	std::cout << BLUE << this->_type << " makes : woof" << DEFAULT_COLOR <<std::endl;
}

Brain	*Dog::getBrain() const{
	return (this->_brain);
}