/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:28:06 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/14 13:50:26 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cat.hpp"
#include "../incs/Dog.hpp"
#include "../incs/WrongCat.hpp"

int	main(){
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound();
j->makeSound();
meta->makeSound();

delete (meta);
delete (i);
delete (j);
std::cout << std::endl;

const WrongAnimal* wrongMeta = new WrongAnimal();
const WrongAnimal* k = new WrongCat();

std::cout << k->getType() << " " << std::endl;
k->makeSound();
wrongMeta->makeSound();

delete (wrongMeta);
delete (k);

return (0);
}