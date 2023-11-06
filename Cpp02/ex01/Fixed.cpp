/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:44:49 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/06 11:40:22 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

FixedPointNbr::FixedPointNbr(){
	std::cout << "Default constructor called" << std::endl;
	this->_whole = 0;
}

FixedPointNbr::FixedPointNbr(const int wholeNbr){
	std::cout << "Int value constructor called" << std::endl;
	;
}

FixedPointNbr::FixedPointNbr(const int floatNbr){
	std::cout << "Float value constructor called" << std::endl;
	;
}

FixedPointNbr::FixedPointNbr(const FixedPointNbr &newNbr){
	std::cout << "Copy assignment operator called" << std::endl;
	*this = newNbr;
}

FixedPointNbr::~FixedPointNbr(){
	std::cout << "Destructor called" << std::endl;
}

FixedPointNbr	&FixedPointNbr::operator=(const FixedPointNbr &newNbr){
	std::cout << "Operator overload called" << std::endl;
	this->setRawBits(newNbr.getRawBits());
	return (*this);
}

void	FixedPointNbr::setRawBits(int const raw){
	this->_whole = raw;
}

int	FixedPointNbr::getRawBits() const{
	return (this->_whole);
}

float	FixedPointNbr::toFloat() const{
	;
}

int	FixedPointNbr::toInt() const{
	;
}

std::ostream &operator<<(std::ostream &out, FixedPointNbr const &nbr){
	;
	return (out);
}