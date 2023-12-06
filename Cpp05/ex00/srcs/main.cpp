/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:35:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/06 10:04:37 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"

int	main(){
	try{
		Bureaucrat	bill = Bureaucrat("Bill", 1);
		Bureaucrat john = Bureaucrat("John", 150);
		Bureaucrat jack = Bureaucrat(john);
		// Bureaucrat jim = Bureaucrat("Jim", -12); test at construction
		// Bureaucrat jim = Bureaucrat("Jim", 151); test at construction

		bill.decrement();
		std::cout << bill << std::endl;
		john.increment();
		std::cout << john << std::endl;
		// bill.increment();
		// bill.increment();
		// std::cout << bill << std::endl;
		john.decrement();
		std::cout << john << std::endl;
		john.decrement();
		std::cout << john << std::endl;
	}
	catch (Bureaucrat::GradeTooHigh &e){
		std::cout << RED << e.what() << WHITE << std::endl;
		return (1);
	}
	catch (Bureaucrat::GradeTooLow &e){
		std::cout << RED << e.what() << WHITE << std::endl;
		return (1);
	}
	return (0);
}