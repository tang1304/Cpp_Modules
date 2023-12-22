/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:26:58 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/22 10:40:02 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv){
	std::string	file;
	if (argc != 2){
		std::cout << "Error, wrong argument entered" << std::endl;
		return (1);
	}
	BitcoinExchange btc = BitcoinExchange();
	file = std::string(argv[1]);
	btc.readUserFile(file);
}