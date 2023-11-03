/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:07:54 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/03 10:27:12 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*zomb_1 = newZombie("Alpha");
	Zombie	*zomb_2 = newZombie("Beta");

	zomb_1->announce();
	randomChump("Gamma");
	zomb_2->announce();

	delete zomb_1;
	delete zomb_2;

	return (0);
}