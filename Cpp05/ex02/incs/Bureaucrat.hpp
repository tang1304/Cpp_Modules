/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:57:46 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/06 14:56:12 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define DARK_GREY "\033[30m"
# define WHITE "\033[0m"

# include <iostream>

class AForm;

class Bureaucrat{
private:

	const std::string	_name;
	int	_grade;
	Bureaucrat();

public:

	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &old);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &old);

	std::string	getName() const;
	int			getGrade() const;
	void		increment();
	void		decrement();
	void		signForm(AForm &form);
	void		executeForm(const AForm &form);

	class GradeTooHigh: public std::exception{
		public:
		const char *what() const throw();
	};
	class GradeTooLow: public std::exception{
		public:
		const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif