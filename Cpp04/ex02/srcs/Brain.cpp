/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:46:31 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/14 13:57:22 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Brain.hpp"

Brain::Brain(){
	std::cout << GREEN << "Brain default constructor called" << DEFAULT_COLOR << std::endl;
}

Brain::Brain(const Brain &old){
	std::cout << GREEN << "Brain copy constructor called" << DEFAULT_COLOR << std::endl;
	*this = old;
}

Brain::~Brain(){
	std::cout << RED << "Brain default destructor called" << DEFAULT_COLOR << std::endl;
}

Brain &Brain::operator=(const Brain &old){
	for (int i = 0; i < 100; i++){
		this->_ideas[i] = old._ideas[i];
	}
	return (*this);
}

void	Brain::setIdea(int n){
	if (n < 0 || n > 99)
		return ;
	_ideas[n] = "test";
}