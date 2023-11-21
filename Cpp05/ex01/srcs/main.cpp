/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:35:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/21 15:37:50 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"

int	main(){
	// try{
	// 	Bureaucrat	bill = Bureaucrat("Bill", 1);
	// 	Bureaucrat john = Bureaucrat("John", 150);
	// 	// Bureaucrat jim = Bureaucrat("Jim", -12); test at construction
	// 	// Bureaucrat jim = Bureaucrat("Jim", 151); test at construction

	// 	bill.decrement();
	// 	std::cout << bill << std::endl;
	// 	john.increment();
	// 	std::cout << john << std::endl;
	// 	// bill.increment();
	// 	// bill.increment();
	// 	// std::cout << bill << std::endl;
	// 	// john.decrement();
	// 	// john.decrement();
	// 	// std::cout << john << std::endl;
	// }
	// catch (Bureaucrat::GradeTooHigh &e){
	// 	std::cout << YELLOW << e.what() << WHITE << std::endl;
	// }
	// catch (Bureaucrat::GradeTooLow &e){
	// 	std::cout << YELLOW << e.what() << WHITE << std::endl;
	// }

	try{
		Bureaucrat first = Bureaucrat("Jean", 1);
		std::cout << first;
		// Bureaucrat error = Bureaucrat("fuck", 170);
		// std::cout << error.getName() << ", grade is : " << error.getGrade() << ".\n";
		Bureaucrat last = Bureaucrat("Denis", 150);
		std::cout << last ;		// last.decrement();
		Form firstForm = Form("first", 10, 10);
		std::cout << firstForm << std::endl;
		// firstForm.beSigned(last);
		// std::cout << firstForm << std::endl;
		if (!firstForm.getSigned())
			std::cout << "firstForm not signed.\n";
		else
			std::cout << "firstForm is signed.\n";
		first.signForm(firstForm);
		if (!firstForm.getSigned())
			std::cout << "firstForm not signed.\n";
		else
			std::cout << "firstForm is signed.\n";
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
		return(1);
	}
	return (0);
}