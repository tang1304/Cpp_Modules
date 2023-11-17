/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:28:06 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/17 13:30:45 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cat.hpp"
#include "../incs/Dog.hpp"
#include "../incs/WrongCat.hpp"

int	main(){

	// AAnimal	test; // test shows I can't create an AAnimal
	AAnimal	*animals[10];

	for (int i = 0; i < 10; i++){
		if (i < 5)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
	}
	for (int i = 0; i < 10; i++){
		delete (animals[i]);
	}

	Cat basic;
	{
		Cat tmp = basic;
	}
	basic.getBrain()->setIdea(5);

	return (0);
}