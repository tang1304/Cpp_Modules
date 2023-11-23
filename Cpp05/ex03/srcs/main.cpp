/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:35:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/23 14:37:13 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/PresidentialPardonForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"

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
		Bureaucrat john = Bureaucrat("John", 1);
		// Bureaucrat bob = Bureaucrat("bob", 170);
		Bureaucrat bill = Bureaucrat("Bill", 150);
		PresidentialPardonForm johnForm = PresidentialPardonForm("john");
		RobotomyRequestForm jackForm = RobotomyRequestForm("jack");
		ShrubberyCreationForm billForm = ShrubberyCreationForm("bill");
		// johnForm.beSigned(bill);
		std::cout << johnForm << std::endl;
		john.signForm(johnForm);
		johnForm.execute(john);
		john.signForm(jackForm);
		jackForm.execute(john);
		john.signForm(billForm);
		billForm.execute(john);
	}
	catch (std::exception &e){
		std::cout << YELLOW << e.what() << WHITE << std::endl;
		return(1);
	}
	return (0);
}