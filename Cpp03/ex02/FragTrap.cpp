/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:35:11 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/10 11:33:20 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){
	_name = "...";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name){
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap(cpy){
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = cpy;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &oldFrag){
	this->_name = oldFrag.getName();
	this->_hitPoints = oldFrag.getHitPoints();
	this->_energyPoints = oldFrag.getEnergyPoints();
	this->_attackDamage = oldFrag.getAttackDamage();
	return (*this);
}

void	FragTrap::attack(const std::string &target){
	if (this->_hitPoints <= 0){
		std::cout << RED << "Fragtrap " << this->_name << " is unable to attack : out of life points." << std::endl;
		std::cout << DEFAULT_COLOR << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0){
		std::cout << RED << "Fragtrap" << this->_name << " is unable to attack : out of energy points." << std::endl;
		std::cout << DEFAULT_COLOR << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << PINK << "Fragtrap " << this->_name << " attacks " << target << ", causing ";
	std::cout << this->_attackDamage << " damage point(s)." << std::endl;
	std::cout << this->_energyPoints << " energy points left." << DEFAULT_COLOR << std::endl;
	std::cout << std::endl;
}

void	FragTrap::highFiveGuys(){
	if (this->_hitPoints <= 0){
		std::cout << RED << this->_name << " is unable to high five : out of life points." << std::endl;
		std::cout << DEFAULT_COLOR << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0){
		std::cout << RED << this->_name << " is unable to high five : out of energy points." << std::endl;
		std::cout << DEFAULT_COLOR << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << OTHER << this->_name << " raises his hand : 'High five guys ! ........'" << std::endl;
	std::cout << "'Guys ? ........'" << std::endl;
	std::cout << this->_name << " feels a bit lonely..." << std::endl;
	std::cout << this->_energyPoints << " energy points left." << DEFAULT_COLOR << std::endl;
	std::cout << std::endl;
}