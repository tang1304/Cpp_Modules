/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:40:47 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/23 13:32:27 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <ctime>
# include <cstdlib>

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class RobotomyRequestForm: public AForm{

private:

	std::string	_target;
	RobotomyRequestForm();

public:

	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &old);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &old);

	void	execute(Bureaucrat const &executor) const;

};

#endif