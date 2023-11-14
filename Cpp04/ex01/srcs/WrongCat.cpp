/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:01:11 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/14 10:46:49 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/WrongCat.hpp"

WrongCat::WrongCat(){
	std::cout << GREEN << "WrongCat default constructor called" << DEFAULT_COLOR << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(std::string type){
	this->_type = type;
	std::cout << GREEN << "WrongCat constructor called" << DEFAULT_COLOR << std::endl;
}

WrongCat::WrongCat(const WrongCat &old) : WrongAnimal(old){
	std::cout << GREEN << "WrongCat copy constructor called" << DEFAULT_COLOR << std::endl;
	*this = old;
}

WrongCat::~WrongCat(){
	std::cout << RED << "WrongCat default destructor called" << DEFAULT_COLOR << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &old){
	this->_type = old.getType();
	return (*this);
}

void	WrongCat::makeSound() const{
	std::cout << BLUE << this->_type << " makes : meow" << DEFAULT_COLOR <<std::endl;
}