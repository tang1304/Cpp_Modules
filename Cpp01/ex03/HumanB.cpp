/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:24:13 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/01 14:16:44 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB(){
}

void	HumanB::attack(){
	if (this->_weapon)
		std::cout << this->_name << " attacks with " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " doesn't have any weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon){
	this->_weapon = &newWeapon;
}