/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:40:49 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/06 11:18:04 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("robotomy request", 72, 45), 
_target("none"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("robotomy request", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &old): AForm(old){
	*this = old;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &old){
	if (this != &old){
		this->_target = old._target;
		this->setSigned(old.getSigned());
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	if (!this->getSigned())
		throw FormNotSigned();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooHigh();
	std::cout << BLUE << "Makes some drilling noises" << WHITE << std::endl;
	srand(std::time(NULL));
	if (rand() % 2 == 0)
		std::cout << GREEN << this->_target << " has been succesfully robotomized !" << WHITE << std::endl;
	else
		std::cout << YELLOW << this->_target << " has not been robotomized..." << WHITE << std::endl;
}