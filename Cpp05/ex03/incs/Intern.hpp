/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:39:05 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/06 13:56:50 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define DARK_GREY "\033[30m"
# define WHITE "\033[0m"

# include <iostream>
#include "../incs/PresidentialPardonForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"

class AForm;

class Intern{

public:

	Intern();
	Intern(Intern const &old);
	~Intern();
	Intern	&operator=(Intern const &old);

	AForm	*makeForm(std::string formName, std::string target);
	class NoForm: public std::exception{
		public:
		const char *what() const throw();
	};
};

#endif