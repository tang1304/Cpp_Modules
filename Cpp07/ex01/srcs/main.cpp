/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:29:45 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/01 15:13:21 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/iter.hpp"

void	increment(){
	;
}

template  <typename T>
void	print(T* array, int len){
	std::cout << "Values :" << std::endl;
	for (int i = 0; i < len; i++){
		std::cout << array[i] << ", ";
	}
	std::cout << std::endl;
}

int	main( void ) {
	int intArray[5] = {1, 3, 5, 7, 9};
	char charArray[5] = {'s', 'a', 'l', 'u', 't'};

	print(intArray, 5);
	print(charArray, 5);
}