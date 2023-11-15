/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:09:04 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/15 14:02:24 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/AMateria.hpp"

AMateria::AMateria(): _type("none"){
}

AMateria::AMateria(std::string const & type): _type(type){
}

AMateria::AMateria(const AMateria &old){
	*this = old;
}

AMateria::~AMateria(){
}

AMateria	&AMateria::operator=(const AMateria &old){
	this->_type = old._type;
	return (*this);
}

std::string	const &AMateria::getType() const{
	return (this->_type);
}

void	AMateria::use(ICharacter& target){
	;
}