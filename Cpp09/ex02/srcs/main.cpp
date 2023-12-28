/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:41:12 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/28 15:16:42 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

int main(int argc, char **argv){
	std::string	input;
	if (argc < 3){
		std::cout << "Error, wrong argument entered" << std::endl;
		return (1);
	}
	try{
		PmergeMe obj(argc, argv);
		std::cout << "Before: ";
		obj.displaySequence();
		obj.FJsortVec();
		std::cout << "After: ";
		obj.displaySequence();
	}
	catch(std::exception &e){
		std::cout << RED << "Error: " << e.what() << CLEAR << std::endl;
		return (1);
	}
}