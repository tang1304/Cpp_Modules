/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:59:23 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/08 13:22:45 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <ctype.h>
# include <cstdlib>
# include <climits>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define DARK_GREY "\033[30m"
# define WHITE "\033[0m"
# define WRONG 0
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4
# define P_FLOAT 5
# define P_DOUBLE 6

class ScalarConverter{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &old);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &old);

public:

	static void	convert(const std::string literal);

	class InputEmpty: public std::exception{
		public:
		const char *what() const throw();
	};
	class WrongInput: public std::exception{
		const char *what() const throw();
	};
};

#endif