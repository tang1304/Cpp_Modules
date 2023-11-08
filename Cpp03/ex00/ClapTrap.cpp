/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:21:23 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/08 16:23:43 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
}

ClapTrap::ClapTrap(std::string name){
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &cpy){
	*this = cpy;
}

ClapTrap::~ClapTrap(){
}

void	ClapTrap::attack(const std::string &target){
	if (this->_hitPoints <= 0){
		std::cout << RED << this->_name << " is unable to attack : out of life points" << DEFAULT_COLOR<< std::endl;
		return ;
	}
	if (this->_energyPoints <= 0){
		std::cout << RED << this->_name << " is unable to attack : out of energy points" << DEFAULT_COLOR<< std::endl;
		return ;
	}
	if (!&target)
		std::cout << RED << "The target doesn't exist" << DEFAULT_COLOR<< std::endl;
		return ;
	std::cout << this->_name << " attacks" << &target << ", causing" << this->_attackDamage << " damage point(s)" << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount){
	;
}

void	ClapTrap::beRepaired(unsigned int amount){
	;
}