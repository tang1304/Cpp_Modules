/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:50:25 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/06 11:26:07 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define DARK_GREY "\033[30m"
# define WHITE "\033[0m"

class AForm{
private:

	const std::string	_name;
	bool				_signed;
	const int			_execGrade;
	const int			_signGrade;
	AForm();

public:

	AForm(std::string name, const int signGrade, const int execGrade);
	AForm(const AForm &old);
	virtual ~AForm();
	AForm &operator=(const AForm &old);

	std::string		getName() const;
	bool			getSigned() const;
	int				getSignGrade() const;
	int				getExecGrade() const;
	void			setSigned(bool b);
	void			beSigned(Bureaucrat &bur);
	virtual void	execute(Bureaucrat const &executor) const = 0;

	class GradeTooHigh: public std::exception{
		public:
		const char *what() const throw();
	};
	class GradeTooLow: public std::exception{
		public:
		const char *what() const throw();
	};
	class FormNotSigned: public std::exception{
		public:
		const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const AForm &rhs);

#endif