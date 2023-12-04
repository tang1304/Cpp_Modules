/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:29:45 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/04 11:50:59 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/iter.hpp"

template  <typename T>
void	print(T* array, int len){
	std::cout << "Values : " ;
	for (int i = 0; i < len; i++){
		std::cout << array[i] << ", ";
	}
	std::cout << std::endl;
}

template <typename T>
void	increment(T &i){
	i++;
}

void	printInt(int &i){
	std::cout << i << ", ";
}

void	printChar(char &c){
	std::cout << c << ", ";
}

void	printString(std::string &str){
	std::cout << str << ", ";
}

int	main( void ){
	int intArray[5] = {1, 3, 5, 7, 9};
	char charArray[5] = {'s', 'a', 'l', 'u', 't'};
	std::string str[2] = {"hello", "world"};

	iter<int>(intArray, 5, printInt);
	std::cout << std::endl;
	iter<char>(charArray, 5, printChar);
	std::cout << std::endl;
	iter<std::string>(str, 2, printString);
	std::cout << std::endl;
	iter<int>(intArray, 5, increment);
	print(intArray, 5);
	iter<char>(charArray, 5, increment);
	print(charArray, 5);
}