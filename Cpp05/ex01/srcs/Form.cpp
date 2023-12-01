/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:49:17 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/22 17:41:23 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Form.hpp"

Form::Form(){
}

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _signed(0){
	if (signGrade < 1 || execGrade < 1)
		throw (Bureaucrat::GradeTooHigh());
	if (signGrade > 150 || execGrade > 150)
		throw (Bureaucrat::GradeTooLow());
	this->_execGrade = execGrade;
	this->_signGrade = signGrade;
	std::cout << GREEN << this->_name << " form created with signing grade " << this->_signGrade ;
	std::cout << " and executing grade " << this->_execGrade << WHITE << std::endl;
}

Form::Form(const Form &old):
_name(old._name), _signed(old._signed), _execGrade(old._execGrade), _signGrade(old._signGrade)
{
	*this = old;
	std::cout << GREEN << this->_name << " form created by copy with signing grade " << this->_signGrade ;
	std::cout << " and executing grade " << this->_execGrade << WHITE << std::endl;
}

Form::~Form(){
}

Form &Form::operator=(const Form &old){
	if (this != &old){
		this->_signed = old._signed;
		this->_execGrade = old._execGrade;
		this->_signGrade = old._signGrade;
	}
	return (*this);
}

std::string	Form::getName() const{
	return (this->_name);
}

bool	Form::getSigned() const{
	return (this->_signed);
}

int	Form::getExecGrade() const{
	return (this->_execGrade);
}

int	Form::getSignGrade() const{
	return (this->_signGrade);
}

void	Form::beSigned(Bureaucrat &bur){
	if (bur.getGrade() <= this->_signGrade)
		this->_signed = 1;
	else{
		std::cout << YELLOW << bur.getName() << " couldn't sign " << this->_name;
		std::cout << " form because " << WHITE << std::endl;
		throw (Form::GradeTooLow());
	}
}

const char	*Form::GradeTooHigh::what() const throw(){
	return ("form's grade is too high");
}

const char	*Form::GradeTooLow::what() const throw(){
	return ("form's grade is too low");
}

std::ostream	&operator<<(std::ostream &out, const Form &rhs){
	out << rhs.getName() << " form is signed ? " << rhs.getSigned() << std::endl;
	out << "Signin grade is at least " << rhs.getSignGrade() << ", executing grade is at least " << rhs.getExecGrade();
	return (out);
}