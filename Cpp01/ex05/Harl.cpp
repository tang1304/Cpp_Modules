/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:00:05 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/02 16:54:58 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
	_choices[0] = "DEBUG";
	_choices[1] = "INFO";
	_choices[2] = "WARNING";
	_choices[3] = "ERROR";
	functionSelect[0] = &Harl::_debug;
	functionSelect[1] = &Harl::_info;
	functionSelect[2] = &Harl::_warning;
	functionSelect[3] = &Harl::_error;
}

Harl::~Harl(){
}

void	Harl::_debug(void){
	std::cout << GREEN << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << DEFAULT_COLOR << std::endl;
}

void	Harl::_info(void){
	std::cout << PINK << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << DEFAULT_COLOR << std::endl;
}

void	Harl::_warning(void){
	std::cout << BLUE << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << DEFAULT_COLOR << std::endl;
}

void	Harl::_error(void){
	std::cout << YELLOW << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << DEFAULT_COLOR << std::endl;
}

void	Harl::complain(std::string level){
	for (int i = 0; i < 4 ; i++){
		if (this->_choices[i] == level){
			(this->*functionSelect[i])();
			return ;
		}
	}
	std::cout << RED << "No level named " << level << DEFAULT_COLOR << std::endl;
	return ;
}

