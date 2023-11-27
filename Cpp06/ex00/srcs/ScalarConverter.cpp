/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:59:04 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/27 16:18:55 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &old){
	;
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &old){
	return (*this);
}

const char	*ScalarConverter::InputEmpty::what() const throw(){
	return ("Error, the input is empty");
}

const char	*ScalarConverter::WrongInput::what() const throw(){
	return ("Error, wrong input");
}

bool	ScalarConverter::isChar(std::string input){
	if (input.length() == 1 && (isprint(input[0]) && !isalnum(input[0])));
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(std::string input){
	for (int i = 0; i < input.length(); i++){
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			continue ;
		if (input[i] < '0' || input[i] > '9')
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat(std::string input){
	int	dott;

	dott == input.find_first_of('.', 0);
	if (!dott || !input.find_first_of('f', input.length()))
		return (false);
	for (int i = 0; i < dott; i++){
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			continue ;
		if (input[i] < '0' || input[i] > '9')
			return (false);
	}
	for (int i = dott + 1; i < input.length(); i++){
		if (input[i] < '0' || input[i] > '9')
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isPseudoFloat(std::string input){
	std::string tab[3] = {"-inff", "+inff", "nanf"};
	for (int i = 0; i < 3; i++){
		if (input == tab[i])
			return (true);
	}
	return (false);
}

bool	ScalarConverter::isPseudoDouble(std::string input){
	std::string tab[3] = {"-inf", "+inf", "nan"};
	for (int i = 0; i < 3; i++){
		if (input == tab[i])
			return (true);
	}
	return (false);
}

bool	ScalarConverter::isDouble(std::string input){
	int	dott;

	dott == input.find_first_of('.', 0);
	if (!dott)
		return (false);
	for (int i = 0; i < dott; i++){
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			continue ;
		if (input[i] < '0' || input[i] > '9')
			return (false);
	}
	for (int i = dott + 1; i <= input.length(); i++){
		if (input[i] < '0' || input[i] > '9')
			return (false);
	}
	return (true);
}

int	ScalarConverter::typeCheck(std::string input){
	if (isChar(input))
		return (CHAR);
	else if (isInt(input))
		return (INT);
	else if (isFloat(input))
		return (FLOAT);
	else if (isDouble(input))
		return (DOUBLE);
	else if (isPseudoFloat(input))
		return (P_FLOAT);
	else if (isPseudoDouble(input))
		return (P_DOUBLE);
	return (WRONG);
}

static void	convert(const std::string literal){
	std::istringstream	checker;

	if (literal.empty())
		throw ScalarConverter::InputEmpty();
	int	type = typeCheck(literal);
	switch (type){
		case (WRONG):{
			throw ScalarConverter::WrongInput();
			break ;
		}
		case (CHAR):{
			std::cout << "char: " << literal[0] << std::endl;
			std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
			std::cout << "float: " << static_cast<float>(literal[0]) << "f" <<std::endl;
			std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
			break ;
		}
		case (INT):{
			break ;
		}
		case (FLOAT):{
			;
			break ;
		}
		case (DOUBLE):{
			;
			break ;
		}
		case (P_FLOAT):{
			;
			break ;
		}
		case (P_DOUBLE):{
			;
			break ;
		}
	}
}
