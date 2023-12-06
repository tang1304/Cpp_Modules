/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:17:45 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/06 11:09:22 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardon", 25, 5), 
_target("none"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardon", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &old): AForm(old){
	*this = old;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &old){
	if (this != &old){
		this->_target = old._target;
		this->setSigned(old.getSigned());
	}
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const{
	if (!this->getSigned())
		throw FormNotSigned();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooHigh();
	std::cout << BLUE << this->_target << " has been pardonned by Zaphod Beeblebrox" << WHITE << std::endl;
}