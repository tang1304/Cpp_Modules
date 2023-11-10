/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:21:23 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/10 09:36:05 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("..."), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy){
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &oldClap){
	this->_name = oldClap.getName();
	this->_hitPoints = oldClap.getHitPoints();
	this->_energyPoints = oldClap.getEnergyPoints();
	this->_attackDamage = oldClap.getAttackDamage();
	return (*this);
}

void	ClapTrap::attack(const std::string &target){
	if (this->_hitPoints <= 0){
		std::cout << RED << this->_name << " is unable to attack : out of life points." << DEFAULT_COLOR << std::endl;
		std::cout << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0){
		std::cout << RED << this->_name << " is unable to attack : out of energy points." << DEFAULT_COLOR << std::endl;
		std::cout << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << PINK << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " damage point(s)." << std::endl;
	std::cout << this->_energyPoints << " energy points left." << DEFAULT_COLOR << std::endl;
	std::cout << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << YELLOW << this->_name << " received " << amount << " damage points." << std::endl;
	std::cout << this->_hitPoints << " life points left." << DEFAULT_COLOR << std::endl;
	std::cout << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPoints <= 0){
		std::cout << RED << this->_name << " is unable to repaire itself : out of life points." << DEFAULT_COLOR << std::endl;
		std::cout << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0){
		std::cout << RED << this->_name << " is unable to repaire itself : out of energy points." << DEFAULT_COLOR << std::endl;
		std::cout << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << GREEN << this->_name << " repaired itself. Now have " << this->_hitPoints << " life points." << std::endl;
	std::cout << this->_energyPoints << " energy points left." << DEFAULT_COLOR << std::endl;
	std::cout << std::endl;
}

void	ClapTrap::setName(std::string name){
	this->_name = name;
}

void	ClapTrap::setHitPoints(int hp){
	this->_hitPoints = hp;
}

void	ClapTrap::setEnergyPoints(unsigned int ep){
	this->_energyPoints = ep;
}

void	ClapTrap::setAttackDamage(unsigned int attack){
	this->_attackDamage = attack;
}

std::string ClapTrap::getName() const{
	return (this->_name);
}

int ClapTrap::getHitPoints() const{
	return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints() const{
	return (this->_energyPoints);
}

unsigned int ClapTrap::getAttackDamage() const{
	return (this->_attackDamage);
}