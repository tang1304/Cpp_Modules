/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:59:23 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/20 11:22:16 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Character.hpp"
#include "../incs/Cure.hpp"
#include "../incs/Ice.hpp"
#include "../incs/MateriaSource.hpp"

int main (){
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure()); // test you can't store more than 4 MateriaSources

	ICharacter* me = new Character("me");
	AMateria* tmp;
	AMateria *meGarbage[5];

	tmp = src->createMateria("fire"); // test a non existing MateriaSource
	me->equip(tmp);
	for (int i = 0; i < 4; i++){
		tmp = src->createMateria("ice");
		me->equip(tmp);
		meGarbage[i] = tmp;
	}
	tmp = src->createMateria("cure");
	me->equip(tmp); // test trying to equip a 5th materia;

	ICharacter* bob = new Character("bob");
	bob->equip(tmp);
	me->use(1, *bob);// test you can use a materia while it's equiped
	me->use(1, *bob);// test you can use a materia while it's equiped
	me->use(6, *bob);// test with a wrong inventory slot
	me->unequip(0);
	delete (meGarbage[0]);
	me->use(1, *bob);// trying to use an empty slot
	bob->use(0, *me);

	//test that an unequiped materia, returns can be equiped again if the AMateria tmp is not replaced
	tmp = src->createMateria("ice");
	bob->equip(tmp);
	me->equip(tmp); // test trying to equip a materia to several Characters
	bob->use(1, *me);
	bob->unequip(1);
	bob->equip(tmp);
	bob->use(1, *me);

	Character jack;
	{
		// Character james = jack; // testing copy construtor
		Character james;
		james = jack; // testing operator =
	}

	delete src;
	delete me;
	delete bob;
	return 0;
}