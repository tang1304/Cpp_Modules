/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:46:23 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/17 16:15:10 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Character.hpp"

Character::Character(): _name("none"){
	for (int i = 0; i < SLOTS; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name): _name(name){
	for (int i = 0; i < SLOTS; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &old){
	*this = old;
}

Character::~Character(){
	for (int i = 0; i < SLOTS; i++){
		if (this->_inventory[i])
			delete (this->_inventory[i]);
	}
}

Character &Character::operator=(const Character &old){
	this->_name = old._name;
	for (int i = 0; i < SLOTS; i++){
		if (this->_inventory[i])
			delete (this->_inventory[i]);
	}
	for (int i = 0; i < SLOTS; i++)
		this->_inventory[i] = old._inventory[i];
	return (*this);
}

std::string const & Character::getName() const{
	return (this->_name);
}

void	Character::equip(AMateria* m){
	int	i = 0;

	if (!m)
		return ;
	if (m->getEquiped() == true){
		std::cout << "Materia already equiped" << std::endl;
		return ;
	}
	while (i < SLOTS){
		if (this->_inventory[i] == NULL)
			break ;
		i++;
	}
	if (i == SLOTS){
		std::cout << this->_name << " can't equip " << m->getType() << ": inventory full" << std::endl;
		return ;
	}
	m->setEquiped(1);
	this->_inventory[i] = m;
	
}

void	Character::unequip(int idx){
	if (idx < 0 || idx >= SLOTS){
		std::cout << idx << " is not a valid slot index" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx]->setEquiped(0);
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx >= SLOTS){
		std::cout << idx << " is not a valid slot index" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx]->use(target);
}