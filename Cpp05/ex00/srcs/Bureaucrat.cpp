/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:04:13 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/20 15:31:09 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name){
	if (grade < 1)
		throw (GradeTooHigh);
	else if (grade > 150)
		;
	
	try{
		if (this->_grade < 1 || this->_grade > 150)
			throw std::exception();
	}
	catch(std::exception e){
		std::cout << RED << "The bureacrat's grade is not betwenn 1 and 150" << DEFAULT_COLOR << std::endl;
		return ;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &old){
	*this = old;
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
	;
}

void	Bureaucrat::decrement(){
	;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &rhs){
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (out);
}