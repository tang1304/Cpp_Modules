/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:44:49 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/09 15:01:33 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->_whole = 0;
}

Fixed::Fixed(const Fixed &oldNbr){
	std::cout << "Copy assignment operator called" << std::endl;
	*this = oldNbr;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &nbr){
	std::cout << "Operator overload called" << std::endl;
	this->setRawBits(nbr.getRawBits());
	return (*this);
}

void	Fixed::setRawBits(int const raw){
	this->_whole = raw;
}

int	Fixed::getRawBits() const{
	return (this->_whole);
}