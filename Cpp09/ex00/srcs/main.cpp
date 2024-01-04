/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:26:58 by tgellon           #+#    #+#             */
/*   Updated: 2024/01/04 10:20:41 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv){
	std::string	file;
	if (argc != 2){
		std::cout << "Error, wrong argument entered" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange btc = BitcoinExchange();
		file = std::string(argv[1]);
		btc.readUserFile(file);
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << CLEAR << std::endl;
		return (1);
	}
}