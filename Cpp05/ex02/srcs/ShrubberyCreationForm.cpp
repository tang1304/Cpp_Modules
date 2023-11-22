/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:49:17 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/22 18:51:46 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("shrubberyCreationForm", 145, 137), 
_target("none"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("shrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &old): AForm(old){
	*this = old;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &old){
	if (this != &old){
		this->_target = old._target;
		this->setSigned(old.getSigned());
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
	if (!this->getSigned())
		throw FormNotSigned();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLow();
	std::ofstream outfile(this->_target.c_str());
	if (!outfile.is_open()){
		std::cout << "Error while trying to open the file" << std::endl;
		return ;
	}
	outfile <<
"          &&& &&  & &&\n"
"      && &\/&\|& ()|/ @, &&\n"
"      &\/(/&/&||/& /_/)_&/_&\n"
"   &() &\/&|()|/&\/ '%/ &  0\n"
"  &_\_&&_\ |& |&&/&__%_/_& &&\n"
"&&   && & &| &| /& & % ()& /&&\n"
" ()&_---()&\&\|&&-&&--%---()~\n"
"     &&     \|||\n"
"             |||\n"
"             |||\n"
"             |||\n"
"       , -=-~  .-^- _\n"
	}
}
