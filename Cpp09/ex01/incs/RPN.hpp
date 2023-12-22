/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:08:48 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/22 14:57:51 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include "RPN.h"

class RPN{
private:

	std::stack<long>	_calculator;
	RPN();

public:

	RPN(std::string input);
	~RPN();
	RPN(const RPN &other);
	RPN	&operator=(const RPN &other);
};

#endif