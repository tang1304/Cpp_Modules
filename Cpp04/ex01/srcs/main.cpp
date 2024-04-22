/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:28:06 by tgellon           #+#    #+#             */
/*   Updated: 2024/01/29 13:38:26 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cat.hpp"
#include "../incs/Dog.hpp"
#include "../incs/WrongCat.hpp"

int	main(){

	Animal	*animals[4];

	for (int i = 0; i < 4; i++){
		if (i < 2)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
	}
	animals[2]->makeSound();
	animals[0] = animals[3];
	for (int i = 0; i < 4; i++){
		delete (animals[i]);
	}

	Cat basic;
	{
		Cat tmp = basic;
	}
	basic.getBrain()->setIdea(5);

	return (0);
}