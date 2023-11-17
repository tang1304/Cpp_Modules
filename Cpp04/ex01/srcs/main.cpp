/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:28:06 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/17 13:29:10 by tgellon          ###   ########lyon.fr   */
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