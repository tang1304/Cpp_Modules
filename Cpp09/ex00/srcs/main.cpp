/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:26:58 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/18 16:23:08 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/BitcoinExchange.hpp"

int	main(int argc, char **argv){
	(void)argv;
	std::string	file;
	if (argc != 2){
		std::cout << "Error, wrong argument entered" << std::endl;
		return (1);
	}
	BitcoinExchange btc = BitcoinExchange();
	file = std::string(argv[1]);
	// btc.readUserFile(file);
}