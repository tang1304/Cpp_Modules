/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:31:32 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/15 15:33:44 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cure.hpp"

Cure::Cure(): AMateria("cure"){
}

Cure::Cure(const Cure &old): AMateria(old){
	*this = old;
}

Cure::~Cure(){
}

Cure	&Cure::operator=(const Cure &old){
	this->_type = old._type;
	return (*this);
}

AMateria*	Cure::clone() const{
	Cure	*newCure;

	newCure = new Cure(*this);
	return (newCure);
}

void	Cure::use(ICharacter& target){
	std::cout << YELLOW << "* heals " << target.getName() << "'s wounds *" << DEFAULT_COLOR << std::endl;
}