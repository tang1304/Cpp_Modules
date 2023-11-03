/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:17:54 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/03 13:43:55 by tgellon          ###   ########lyon.fr   */
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

const std::string	&Weapon::getType(){
	return (this->_type);
}