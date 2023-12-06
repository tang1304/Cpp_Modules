/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:39:01 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/06 14:03:01 by tgellon          ###   ########lyon.fr   */
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
			return (new PresidentialPardonForm(target));
			break;
		}
		case (1):{
			return (new RobotomyRequestForm(target));
			break;
		}
		case (2):{
			return (new ShrubberyCreationForm(target));
			break;
		}
		default:{
			throw (NoForm());
		}
	}
}

const char *Intern::NoForm::what() const throw(){
	return ("Error, no form named like this");
}