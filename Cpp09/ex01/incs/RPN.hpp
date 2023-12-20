/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:08:48 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/20 17:31:59 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>
# include <limits>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define CLEAR "\033[0m"

# define TOKEN "Error, you must have at least two numbers before having this operation token"
# define OVERFLOW "Error, would be using values superior to integer max/min. Overflow risk"

class RPN{
private:

	std::stack<long long>	_calculator;
	RPN();

public:

	RPN(std::string input);
	~RPN();
	RPN(const RPN &other);
	RPN	&operator=(const RPN &other);
};

#endif