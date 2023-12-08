/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:39:01 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/08 13:05:34 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Intern.hpp"

Intern::Intern(){
}

Intern::Intern(const Intern &old){
	*this = old;
}

Intern::~Intern(){
}

Intern	&Intern::operator=(const Intern &old){
	(void)old;
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target){
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int	i;
	for (i = 0; i < 3; i++){
		if (forms[i] == formName)
			break;
	}
	switch (i){
		case (0):{
			std::cout << "Intern creates form " << formName << std::endl;
			return (new PresidentialPardonForm(target));
		}
		case (1):{
			std::cout << "Intern creates form " << formName << std::endl;
			return (new RobotomyRequestForm(target));
		}
		case (2):{
			std::cout << "Intern creates form " << formName << std::endl;
			return (new ShrubberyCreationForm(target));
		}
		default:{
			throw (NoForm());
		}
	}
}

const char *Intern::NoForm::what() const throw(){
	return ("Error, no form named like this");
}