/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:17:54 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/01 11:52:34 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type){
	this->_type = type;
}

Weapon::~Weapon(){
}

void	Weapon::setType(std::string type){
	this->_type = type;
}

std::string	Weapon::getType() const{
	return (this->_type);
}