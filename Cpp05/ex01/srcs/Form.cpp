/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:49:17 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/21 14:40:10 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Form.hpp"

Form::Form(){
}

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _signed(0){
	if (signGrade < 1 || execGrade < 1)
		throw (Form::GradeTooHigh());
	if (signGrade > 150 || execGrade > 150)
		throw (Form::GradeTooLow());
	this->_execGrade = execGrade;
	this->_signGrade = signGrade;
	std::cout << GREEN << this->_name << " created with signing grade " << this->_signGrade ;
	std::cout << " and executing grade " << this->_execGrade << WHITE << std::endl;
}

Form::Form(const Form &old):
_name(old._name), _signed(old._signed), _execGrade(old._execGrade), _signGrade(old._signGrade)
{
	*this = old;
	std::cout << GREEN << this->_name << " created by copy with signing grade " << this->_signGrade ;
	std::cout << " and executing grade " << this->_execGrade << WHITE << std::endl;
}

Form::~Form(){
}

Form &Form::operator=(const Form &old){
	if (this != &old){
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
	else
		throw (GradeTooLow());
}

const char	*Form::GradeTooHigh::what() const throw(){
	return ("Error, grade is higher than 1");
}

const char	*Form::GradeTooLow::what() const throw(){
	return ("Error, grade is lower than 150");
}

std::ostream	&operator<<(std::ostream &out, const Form &rhs){
	out << rhs.getName() << " form, is signed ? " << rhs.getSignGrade();
	out << "Signin grade is at least " << rhs.getSignGrade() << ", executing grade is at least " << rhs.getExecGrade();
	return (out);
}