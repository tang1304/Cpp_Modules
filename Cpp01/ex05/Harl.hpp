/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:00:13 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/08 12:40:56 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
# define HARL_CPP

# include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define DEFAULT_COLOR "\033[0m"

class Harl{
private:

	std::string _choices[4];
	void	(Harl::*functionSelect[4])();

	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);

public:

	Harl();
	~Harl();

	void	complain(std::string level);
};

#endif