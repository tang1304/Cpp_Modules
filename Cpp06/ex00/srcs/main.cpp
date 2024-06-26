/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:37:03 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/29 10:35:06 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScalarConverter.hpp"

int	main(int argc, char **argv){
	try {
		if (argc != 2){
		std::cout << YELLOW << "Please enter only one argument" << WHITE << std::endl;
		return (1);
		}
		const std::string	literal = argv[1];
		ScalarConverter::convert(literal);
	}
	catch (std::exception &e){
		std::cout << YELLOW << e.what() << WHITE << std::endl;
		return(1);
	}
}
