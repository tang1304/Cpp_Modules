/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:59:58 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/08 12:48:19 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv){
	if (argc != 2){
		std::cout << "Please enter one argument" << std::endl;
		return (1);
	}
	Harl	harl;
	std::string level = std::string(argv[1]);
	harl.complain(level);
	return (0);
}