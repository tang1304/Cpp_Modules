/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:04:13 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/06 10:11:43 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"

Bureaucrat::Bureaucrat(){
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name){
	if (grade < 1)
		throw (Bureaucrat::GradeTooHigh());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLow());
	this->_grade = grade;
	std::cout << GREEN << this->_name << " created with grade " << this->_grade << WHITE << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &old) : _name(old._name){
	*this = old;
	std::cout << GREEN << this->_name << " created by copy with grade " << this->_grade << WHITE << std::endl;
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &old){
	if (this != &old)
		this->_grade = old._grade;
	return (*this);
}

std::string	Bureaucrat::getName() const{
	return (this->_name);
}

int	Bureaucrat::getGrade() const{
	return (this->_grade);
}

void	Bureaucrat::increment(){
	std::cout << BLUE << "Incrementing " << this->_name << WHITE << std::endl;
	if (this->_grade - 1 < 1){
		std::cout << YELLOW << "Grade would be " << this->_grade - 1 << WHITE << std::endl;
		throw (GradeTooHigh());
	}
	else
		this->_grade -= 1;
	return ;
}

void	Bureaucrat::decrement(){
	std::cout << BLUE << "Decrementing " << this->_name << WHITE << std::endl;
	if (this->_grade + 1 > 150){
		std::cout << YELLOW << "Grade would be " << this->_grade + 1 << WHITE << std::endl;
		throw (GradeTooLow());
	}
	else
		this->_grade += 1;
	return ;
}

void	Bureaucrat::signForm(Form &form){
	if (form.getSigned()){
		std::cout << YELLOW << this->_name << " couldn't sign " << form.getName();
		std::cout << " because the form is already signed" << WHITE << std::endl;
	}
	try{
		form.beSigned(*this);
		std::cout << BLUE << this->_name << " signed " << form.getName() << WHITE << std::endl;
	}
	catch (Form::GradeTooLow &e){
		std::cout << YELLOW << this->_name << " couldn't sign " << form.getName();
		std::cout << "because the bureaucrat's grade is too low" << WHITE << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHigh::what() const throw(){
	return ("Error, grade is higher than 1");
}

const char	*Bureaucrat::GradeTooLow::what() const throw(){
	return ("Error, grade is lower than 150");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &rhs){
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (out);
}