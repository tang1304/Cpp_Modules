/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:54:51 by tgellon           #+#    #+#             */
/*   Updated: 2024/01/03 10:21:14 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

RPN::RPN(){
}

RPN::RPN(std::string input){
	long			value1;
	long			value2;
	long			result;

	for (size_t	i = 0; i < input.length(); i++){
		if ((input[i] >= '0' && input[i] <= '9') && i > 0){
			if (input[i - 1] >= '0' && input[i] <= '9')
				throw (std::invalid_argument("Error, number higher than 9"));
		}
		if (input[i] == ' ' || input[i] == '\t')
			continue ;
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
			if (_calculator.size() < 2)
				throw (std::invalid_argument(TOKEN));
			if (input[i] == '-' && (input[i + 1] >= '0' && input[i + 1] <= '9'))
				throw (std::invalid_argument("Error, negative number found"));
			value2 = _calculator.top();
			_calculator.pop();
			value1 = _calculator.top();
			_calculator.pop();
			if (input[i] == '+')
				result = value1 + value2;
			else if (input[i] == '-')
				result = value1 - value2;
			else if (input[i] == '*')
				result = value1 * value2;
			else if (input[i] == '/' && value2 != 0)
				result = value1 / value2;
			else
				throw (std::invalid_argument("Error, would be dividing by 0"));
			if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
				throw (std::invalid_argument(OVERFLOW));
			else
				_calculator.push(result);
		}
		else if (input[i] < '0' || input[i] > '9')
			throw (std::invalid_argument("Error, must be a digit or an operation token"));
		else {
			long	digit = (input[i] - 48);
			_calculator.push(digit);
		}
	}
	if (_calculator.size() == 0)
		throw (std::invalid_argument("Error, empty argument"));
	if (_calculator.size() > 1)
		throw (std::invalid_argument("Too much numbers compared to operation token"));
	std::cout << GREEN << "Result is : " << _calculator.top() << CLEAR << std::endl;
}

RPN::~RPN(){
}

RPN::RPN(const RPN &other): _calculator(other._calculator){
	*this = other;
}

RPN	&RPN::operator=(const RPN &other){
	if (this != &other){
		_calculator = other._calculator;
	}
	return (*this);
}