/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:35:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/07 16:47:08 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/PresidentialPardonForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/Intern.hpp"

int	main(){
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
		john.executeForm(jackForm);

		john.signForm(billForm);
		billForm.execute(john);

		Intern	someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		// rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		// rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		john.signForm(*rrf);
		rrf->execute(john);
		delete (rrf);
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << WHITE << std::endl;
		return(1);
	}
	return (0);
}