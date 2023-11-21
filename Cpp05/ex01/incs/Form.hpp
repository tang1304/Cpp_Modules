/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:50:25 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/21 15:25:13 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define DARK_GREY "\033[30m"
# define WHITE "\033[0m"

class Form{
private:

	const std::string	_name;
	bool				_signed;
	int					_execGrade;
	int					_signGrade;
	Form();

public:

	Form(std::string name, int signGrade, int execGrade);
	Form(const Form &old);
	~Form();
	Form &operator=(const Form &old);

	std::string	getName() const;
	bool		getSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

	void		beSigned(Bureaucrat &bur);
	class GradeTooHigh: public std::exception{
		public:
		const char *what() const throw();
	};
	class GradeTooLow: public std::exception{
		public:
		const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const Form &rhs);

#endif