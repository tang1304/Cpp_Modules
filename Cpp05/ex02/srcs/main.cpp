/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:35:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/22 14:57:03 by tgellon          ###   ########lyon.fr   */
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
		Bureaucrat john = Bureaucrat("John", 1);
		// Bureaucrat bob = Bureaucrat("bob", 170);
		Bureaucrat bill = Bureaucrat("Bill", 150);
		Form johnForm = Form("2B", 20, 20);
		// johnForm.beSigned(bill);
		std::cout << johnForm << std::endl;
		if (johnForm.getSigned())
			std::cout << "2B form is signed.\n";
		else
			std::cout << "2B form not signed.\n";
		john.signForm(johnForm);
		if (johnForm.getSigned())
			std::cout << "2B form is signed.\n";
		else
			std::cout << "2B form not signed.\n";
	}
	catch (std::exception &e){
		std::cout << YELLOW << e.what() << WHITE << std::endl;
		// return(1);
	}
	return (0);
}