/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:00:35 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/08 13:44:09 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Serializer.hpp"
#include "../incs/Data.hpp"

int	main(){
	Data	data = {42};
	Data	*dataPtr = &data;

	std::cout << "Content of data : " << dataPtr->nb << std::endl;
	std::cout << "first ptr: " << GREEN << dataPtr << WHITE << std::endl;

	uintptr_t uintTest = Serializer::serialize(dataPtr);
	std::cout << "After serialize: " << &uintTest << std::endl;

	Data *secondPtr = Serializer::deserialize(uintTest);
	std::cout << "2nd ptr, after deserialize: " << GREEN << secondPtr << WHITE << std::endl;
	std::cout << "Content of 2nd ptr : " << secondPtr->nb << std::endl;
}