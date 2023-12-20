/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:54:51 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/20 17:57:08 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/RPN.hpp"

RPN::RPN(){
}

RPN::RPN(std::string input){
	long long			value1;
	long long			value2;
	long long			result;

	for (size_t	i = 0; i < input.length(); i++){
		if (input[i] == ' ' || input[i] == '\t')
			continue ;
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
			if (_calculator.size() < 2)
				throw (std::invalid_argument(TOKEN));
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
			long long	digit = (input[i] - 48);
std::cout << digit << std::endl;
std::cout << input[i] << std::endl;
			_calculator.push(digit);
		}
	}
	if (_calculator.size() != 1)
		throw (std::invalid_argument("Too much numbers compared to operation token"));
	std::cout << "Result is : " << _calculator.top() << std::endl;
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