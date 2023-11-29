/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:59:04 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/29 14:12:29 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &old){
	*this = old;
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &old){
	(void)old;
	return (*this);
}

const char	*ScalarConverter::InputEmpty::what() const throw(){
	return ("Error, the input is empty");
}

const char	*ScalarConverter::WrongInput::what() const throw(){
	return ("Error, wrong input");
}

bool	ScalarConverter::isChar(std::string input){
	if (input.length() == 1 && (isprint(input[0]) && !isdigit(input[0])))
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(std::string input){
	for (size_t i = 0; i < input.length(); i++){
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			continue ;
		if (input[i] < '0' || input[i] > '9')
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat(std::string input){
	size_t	dott = input.find_first_of('.', 0);
	if (!dott || input.find_first_of('f', input.length() - 1) <= dott + 1 \
			|| input.find_first_of('f', input.length() - 1) > input.length())
		return (false);
	for (size_t i = 0; i < dott; i++){
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			continue ;
		if (input[i] < '0' || input[i] > '9')
			return (false);
	}
	for (size_t i = dott + 1; i < input.length() - 1; i++){
		if (input[i] < '0' || input[i] > '9')
			return (false);
	}
	(void)dott;
	return (true);
}

bool	ScalarConverter::isDouble(std::string input){
	size_t	dott = input.find_first_of('.', 0);
	if (!dott)
		return (false);
	for (size_t i = 0; i < dott; i++){
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			continue ;
		if (input[i] < '0' || input[i] > '9')
			return (false);
	}
	for (size_t i = dott + 1; i <= input.length() - 1; i++){
		if (input[i] < '0' || input[i] > '9')
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isPseudoFloat(std::string input){
	std::string tab[4] = {"-inff", "inff", "+inff", "nanf"};
	for (int i = 0; i < 4; i++){
		if (input == tab[i])
			return (true);
	}
	return (false);
}

bool	ScalarConverter::isPseudoDouble(std::string input){
	std::string tab[4] = {"-inf", "inf", "+inf", "nan"};
	for (int i = 0; i < 4; i++){
		if (input == tab[i])
			return (true);
	}
	return (false);
}

int	ScalarConverter::typeCheck(const std::string input){
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

void	ScalarConverter::convert(const std::string literal){
	ScalarConverter	converter;

	if (literal.empty())
		throw ScalarConverter::InputEmpty();
	int	type ;
	type = converter.typeCheck(literal);
	switch (type){
		case (WRONG):{
			throw ScalarConverter::WrongInput();
			break ;
		}
		case (CHAR):{
			std::cout << BLUE << "char" << WHITE << std::endl;
			std::cout << "char: " << literal[0] << std::endl;
			std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
			std::cout << "float: " << static_cast<float>(literal[0]) << ".0f" <<std::endl;
			std::cout << "double: " << static_cast<double>(literal[0]) << ".0" << std::endl;
			break ;
		}
		case (INT):{
			std::cout << BLUE << "int" << WHITE << std::endl;
			long long	longNb = std::strtol(literal.c_str(), NULL, 10);
			double	doubleNb = std::strtod(literal.c_str(), NULL);
			if (longNb > 32 && longNb < 127)
				std::cout << "char: (" << static_cast<char>(longNb) << ")" << std::endl;
			else if ((longNb >= 0 && longNb <= 32) || longNb == 127)
				std::cout << "char: non displayable" << std::endl;
			else
				std::cout << "char: impossible" << std::endl;
			if (longNb <= INT_MAX && longNb >= INT_MIN)
				std::cout << "int: " << static_cast<int>(longNb) << std::endl;
			else
				std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << static_cast<float>(doubleNb) << "f" <<std::endl;
			std::cout << "double: " << static_cast<double>(doubleNb) << std::endl;
			break ;
		}
		case (FLOAT):{
			std::cout << BLUE << "float" << WHITE << std::endl;
			float	floatNb = std::strtof(literal.c_str(), NULL);
			if (floatNb > 32 && floatNb < 127)
				std::cout << "char: (" << static_cast<char>(floatNb) << ")" << std::endl;
			else if ((floatNb >= 0 && floatNb <= 32) || floatNb == 127)
				std::cout << "char: non displayable" << std::endl;
			else
				std::cout << "char: impossible" << std::endl;
			if (floatNb <= INT_MAX && floatNb >= INT_MIN)
				std::cout << "int: " << static_cast<int>(floatNb) << std::endl;
			else
				std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << static_cast<float>(floatNb) << "f" <<std::endl;
			std::cout << "double: " << static_cast<double>(floatNb) << std::endl;
			break ;
		}
		case (DOUBLE):{
			std::cout << BLUE << "double" << WHITE << std::endl;
			double	doubleNb = std::strtod(literal.c_str(), NULL);
			if (doubleNb > 32 && doubleNb < 127)
				std::cout << "char: (" << static_cast<char>(doubleNb) << ")" << std::endl;
			else if ((doubleNb >= 0 && doubleNb <= 32) || doubleNb == 127)
				std::cout << "char: non displayable" << std::endl;
			else
				std::cout << "char: impossible" << std::endl;
			if (doubleNb <= INT_MAX && doubleNb >= INT_MIN)
				std::cout << "int: " << static_cast<int>(doubleNb) << std::endl;
			else
				std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << static_cast<float>(doubleNb) << "f" <<std::endl;
			std::cout << "double: " << static_cast<double>(doubleNb) << std::endl;
			break ;
		}
		case (P_FLOAT):{
			std::cout << BLUE << "pseudo float" << WHITE << std::endl;
			float	floatNb = std::strtof(literal.c_str(), NULL);
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << static_cast<float>(floatNb) << "f" <<std::endl;
			std::cout << "double: " << static_cast<double>(floatNb) <<std::endl;
			break;
		}
		case (P_DOUBLE):{
			std::cout << BLUE << "pseudo double" << WHITE << std::endl;
			double	doubleNb = std::strtod(literal.c_str(), NULL);
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << static_cast<float>(doubleNb) << "f" <<std::endl;
			std::cout << "double: " << static_cast<double>(doubleNb) <<std::endl;
			break ;
		}
	}
}
