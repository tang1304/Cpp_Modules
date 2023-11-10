/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:34:38 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/10 11:02:09 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	_name = "...";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name){
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy){
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = cpy;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &oldScav){
	this->_name = oldScav.getName();
	this->_hitPoints = oldScav.getHitPoints();
	this->_energyPoints = oldScav.getEnergyPoints();
	this->_attackDamage = oldScav.getAttackDamage();
	return (*this);
}

void	ScavTrap::attack(const std::string &target){
	if (this->_hitPoints <= 0){
		std::cout << RED << "Scavtrap " << this->_name << " is unable to attack : out of life points." << std::endl;
		std::cout << DEFAULT_COLOR << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0){
		std::cout << RED << this->_name << " is unable to attack : out of energy points." << std::endl;
		std::cout << DEFAULT_COLOR << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << PINK << "Scavtrap " << this->_name << " attacks " << target << ", causing ";
	std::cout << this->_attackDamage << " damage point(s)." << std::endl;
	std::cout << this->_energyPoints << " energy points left." << DEFAULT_COLOR << std::endl;
	std::cout << std::endl;
}

void	ScavTrap::guardGate(){
	if (this->_hitPoints <= 0){
		std::cout << RED << this->_name << " is unable to guard : out of life points." << std::endl;
		std::cout << DEFAULT_COLOR << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0){
		std::cout << RED << this->_name << " is unable to guard : out of energy points." << std::endl;
		std::cout << DEFAULT_COLOR << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << BLUE << this->_name << " now guards : 'YOU SHALL NOT PASS !'" <<std::endl;
	std::cout << this->_energyPoints << " energy points left." << DEFAULT_COLOR << std::endl;
	std::cout << std::endl;
}