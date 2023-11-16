/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:09:04 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/16 15:57:14 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/AMateria.hpp"

AMateria::AMateria(): _type("none"), _equiped(0){
}

AMateria::AMateria(std::string const & type): _type(type), _equiped(0){
}

AMateria::AMateria(const AMateria &old){
	*this = old;
}

AMateria::~AMateria(){
}

AMateria	&AMateria::operator=(const AMateria &old){
	this->_type = old._type;
	this->_equiped = 0;
	return (*this);
}

void	AMateria::setEquiped(bool b){
	this->_equiped = b;
}

bool	AMateria::getEquiped() const{
	return (this->_equiped);
}

std::string	const &AMateria::getType() const{
	return (this->_type);
}

void	AMateria::use(ICharacter& target){
	(void)target;
}