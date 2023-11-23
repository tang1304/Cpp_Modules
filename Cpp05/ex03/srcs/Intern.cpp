/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:39:01 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/23 15:42:51 by tgellon          ###   ########lyon.fr   */
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
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target){
	std::string forms[3] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
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
			std::cout << YELLOW << "No form named like this" << WHITE << std::endl;
			return (NULL);
		}
	}
}