/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:15:04 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/20 16:54:07 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RPN.hpp"

int	main(int argc, char **argv){
	std::string	input;
	if (argc != 2){
		std::cout << "Error, wrong argument entered" << std::endl;
		return (1);
	}
	input = std::string(argv[1]);
	try{
		RPN	calculator = RPN(input);
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << CLEAR << std::endl;
	}
}