/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:21:23 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/08 13:39:54 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
}

ClapTrap::ClapTrap(const ClapTrap &cpy){
	*this = cpy;
}

ClapTrap::~ClapTrap(){
}

void	ClapTrap::attack(const std::string &target){
	;
}

void	ClapTrap::takeDamage(unsigned int amount){
	;
}

void	ClapTrap::beRepaired(unsigned int amount){
	;
}