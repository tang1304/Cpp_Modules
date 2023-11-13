/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:56:01 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/13 11:20:27 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	_hitPoints = FragTrap::getHitPoints();
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name){
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hitPoints = FragTrap::getHitPoints();
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpy) : ClapTrap(cpy), FragTrap(cpy), ScavTrap(cpy){
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = cpy;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &oldDiamond){
	this->_name = oldDiamond.getName();
	this->_hitPoints = oldDiamond.getHitPoints();
	this->_energyPoints = oldDiamond.getEnergyPoints();
	this->_attackDamage = oldDiamond.getAttackDamage();
	return (*this);
}

void	DiamondTrap::whoAmI(){
	if (this->_hitPoints <= 0){
		std::cout << RED << this->_name << " is unable to tell who it is : out of life points." << std::endl;
		std::cout << DEFAULT_COLOR << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0){
		std::cout << RED << this->_name << " is unable to tell who it is : out of energy points." << std::endl;
		std::cout << DEFAULT_COLOR << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << WHITE << "Diamondtrap name is: " << this->_name << ", Claptrap name is: " << ClapTrap::_name << std::endl;
	std::cout << this->_energyPoints << " energy points left." << std::endl;
	std::cout << DEFAULT_COLOR << std::endl;
}