/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:44:49 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/09 15:02:48 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->_whole = 0;
}

Fixed::Fixed(const int wholeNbr){
	std::cout << "Int value constructor called" << std::endl;
	this->_whole = wholeNbr << this->_bits;
}

Fixed::Fixed(const float floatNbr){
	std::cout << "Float value constructor called" << std::endl;
	this->_whole = roundf(floatNbr * (1 << this->_bits));
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

float	Fixed::toFloat() const{
	return (static_cast<float>(this->getRawBits()) / (1 << this->_bits));
}

int	Fixed::toInt() const{
	return (this->getRawBits() >> this->_bits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &nbr){
	out << nbr.toFloat();
	return (out);
}