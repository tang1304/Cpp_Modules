/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:41:12 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/22 15:00:03 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

int main(int argc, char **argv){
	std::string	input;
	if (argc < 3){
		std::cout << "Error, wrong argument entered" << std::endl;
		return (1);
	}
	PmergeMe	obj(argv);
}