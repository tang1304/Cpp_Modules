/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:52:46 by tgellon           #+#    #+#             */
/*   Updated: 2024/01/11 13:09:12 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Array.hpp"
#include "../incs/Array.tpp"

int	main(){
	try{
		Array<int>	intArr(3);
		Array<char>	charArr;

		for (unsigned int i = 0; i < intArr.size(); i++){
			intArr[i] = i + 10;
			std::cout << intArr[i] << std::endl;
		}
		std::cout << "intArr size: " << intArr.size() << std::endl;
		std::cout << "charArr size: " << charArr.size() << std::endl;
Array<int>	test(5);
intArr = test;
		Array<int>	cpyArr(intArr); // test cpy constructor
		// Array<int>	cpyArr; // test operator =
		// cpyArr = intArr;
		std::cout << "cpyArr[1] = " << cpyArr[1] << std::endl;
		cpyArr[1] = 42;
		std::cout << "cpyArr[1] = " << cpyArr[1] << std::endl;
		std::cout << "intArr[1] = " << intArr[1] << std::endl;

		// std::cout << intArr[5] << std::endl; // test operator [] and exception;
	}
	catch (std::exception &e){
		std::cout << YELLOW << e.what() << WHITE << std::endl;
		return(1);
	}
	return (0);
}