/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:43:15 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/16 15:15:24 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < SLOTS; i++)
		this->_slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &old){
	*this = old;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < SLOTS; i++){
		if (this->_slots[i])
			delete (this->_slots[i]);
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &old){
	for (int i = 0; i < SLOTS; i++){
		if (this->_slots[i])
			delete (this->_slots[i]);
	}
	for (int i = 0; i < SLOTS; i++)
		this->_slots[i] = old._slots[i];
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m){
	int	i = 0;

	while (i < SLOTS){
		if (this->_slots[i] == NULL)
			break ;
		i++;
	}
	if (i == SLOTS){
		std::cout << "Can't stock " << m->getType() << " : source full" << std::endl;
		delete (m);
		return ;
	}
	this->_slots[i] = m;
}

AMateria*	MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < SLOTS; i++){
		if (this->_slots[i] && this->_slots[i]->getType() == type)
			return (this->_slots[i]->clone());
	}
	std::cout << type << " not available" << std::endl;
	return (NULL);
}