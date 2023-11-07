/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:44:49 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/07 16:23:23 by tgellon          ###   ########lyon.fr   */
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

Fixed::Fixed(const Fixed &newNbr){
	std::cout << "Copy assignment operator called" << std::endl;
	*this = newNbr;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
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


Fixed	&Fixed::min(Fixed &n1, Fixed &n2){
	if (n1.toFloat() < n2.toFloat())
		return (n1);
	return (n2);
}

Fixed	&Fixed::max(Fixed &n1, Fixed &n2){
	if (n1.toFloat() > n2.toFloat())
		return (n1);
	return (n2);
}

const Fixed	&Fixed::min(const Fixed &n1, const Fixed &n2){
	if (n1.toFloat() < n2.toFloat())
		return (n1);
	return (n2);
}

const Fixed	&Fixed::max(const Fixed &n1, const Fixed &n2){
	if (n1.toFloat() > n2.toFloat())
		return (n1);
	return (n2);
}


Fixed	&Fixed::operator=(const Fixed &newNbr){
	std::cout << "Operator overload called" << std::endl;
	this->setRawBits(newNbr.getRawBits());
	return (*this);
}

bool	Fixed::operator==(const Fixed &newNbr){
	return (this->toFloat() == newNbr.toFloat());
}

bool	Fixed::operator!=(const Fixed &newNbr){
	return (this->toFloat() != newNbr.toFloat());
}

bool	Fixed::operator>(const Fixed &newNbr){
	return (this->toFloat() > newNbr.toFloat());
}

bool	Fixed::operator<(const Fixed &newNbr){
	return (this->toFloat() < newNbr.toFloat());
}

bool	Fixed::operator>=(const Fixed &newNbr){
	return (this->toFloat() >= newNbr.toFloat());
}

bool	Fixed::operator<=(const Fixed &newNbr){
	return (this->toFloat() <= newNbr.toFloat());
}

std::ostream &operator<<(std::ostream &out, Fixed const &nbr){
	out << nbr.toFloat();
	return (out);
}