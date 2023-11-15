/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:30:45 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/15 15:30:50 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Ice.hpp"

Ice::Ice(): AMateria("ice"){
}

Ice::Ice(const Ice &old): AMateria(old){
	*this = old;
}

Ice::~Ice(){
}

Ice	&Ice::operator=(const Ice &old){
	this->_type = old._type;
	return (*this);
}

AMateria*	Ice::clone() const{
	Ice	*newIce;

	newIce = new Ice(*this);
	return (newIce);
}

void	Ice::use(ICharacter& target){
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << DEFAULT_COLOR << std::endl;
}