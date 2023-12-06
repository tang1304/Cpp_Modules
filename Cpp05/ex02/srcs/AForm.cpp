/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:49:17 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/06 15:41:52 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/AForm.hpp"

AForm::AForm(): _name("none"), _signed(false), _execGrade(0), _signGrade(0){
}

AForm::AForm(std::string name, const int signGrade, const int execGrade):
	_name(name), _signed(0), _execGrade(execGrade), _signGrade(signGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw (Bureaucrat::GradeTooHigh());
	if (signGrade > 150 || execGrade > 150)
		throw (Bureaucrat::GradeTooLow());
	std::cout << GREEN << this->_name << " form created with signing grade " << this->_signGrade ;
	std::cout << " and executing grade " << this->_execGrade << WHITE << std::endl;
}

AForm::AForm(const AForm &old):
_name(old._name), _signed(old._signed), _execGrade(old._execGrade), _signGrade(old._signGrade)
{
	std::cout << GREEN << this->_name << " form created by copy with signing grade " << this->_signGrade ;
	std::cout << " and executing grade " << this->_execGrade << WHITE << std::endl;
}

AForm::~AForm(){
}

AForm &AForm::operator=(const AForm &old){
	if (this != &old){
		this->_signed = old.getSigned();
	}
	return (*this);
}

std::string	AForm::getName() const{
	return (this->_name);
}

bool	AForm::getSigned() const{
	return (this->_signed);
}

int	AForm::getExecGrade() const{
	return (this->_execGrade);
}

int	AForm::getSignGrade() const{
	return (this->_signGrade);
}

void	AForm::setSigned(bool b){
	this->_signed = b;
}

void	AForm::beSigned(Bureaucrat &bur){
	if (bur.getGrade() <= this->_signGrade)
		this->_signed = 1;
	else{
		std::cout << YELLOW << bur.getName() << " couldn't sign " << this->_name;
		std::cout << " form because " << WHITE << std::endl;
		throw (AForm::GradeTooHigh());
	}
}

const char	*AForm::GradeTooHigh::what() const throw(){
	return ("form's grade is too high");
}

const char	*AForm::GradeTooLow::what() const throw(){
	return ("form's grade is too low");
}

const char	*AForm::FormNotSigned::what() const throw(){
	return ("Form is not signed");
}

std::ostream	&operator<<(std::ostream &out, const AForm &rhs){
	out << rhs.getName() << " form is signed ? " << rhs.getSigned() << std::endl;
	out << "Signin grade is at least " << rhs.getSignGrade() << ", executing grade is at least " << rhs.getExecGrade();
	return (out);
}