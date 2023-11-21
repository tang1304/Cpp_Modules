/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:04:13 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/21 11:37:20 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"

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

Bureaucrat::Bureaucrat(const Bureaucrat &old){
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
	if (this->_grade - 1 < 1)
		throw (GradeTooHigh());
	else
		this->_grade -= 1;
	std::cout << "Incrementing" << std::endl;
	return ;
}

void	Bureaucrat::decrement(){
	if (this->_grade + 1 > 150)
		throw (GradeTooLow());
	else
		this->_grade += 1;
	std::cout << "Decrementing" << std::endl;
	return ;
}

const char	*Bureaucrat::GradeTooHigh::what() const throw(){
	return ("Error, grade is higher than 1");
}

const char	*Bureaucrat::GradeTooLow::what() const throw(){
	return ("Error, grade is lower than 150");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &rhs){
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (out);
}