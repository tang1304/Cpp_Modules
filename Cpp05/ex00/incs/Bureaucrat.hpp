/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:57:46 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/17 14:12:58 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat{
private:

	const std::string	_name;
	int	_grade;

public:

	Bureaucrat();
	Bureaucrat(const Bureaucrat &old);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &old);

	std::string	getName() const;
	int			getGrade() const;
};

#endif