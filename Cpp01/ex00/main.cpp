/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:07:54 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/30 17:16:36 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*zomb_1 = newZombie("alpha");
	Zombie	*zomb_2 = newZombie("beta");

	zomb_1->announce();
	zomb_2->announce();
	randomChump("Charlie");

	delete zomb_1;
	delete zomb_2;

	return (0);
}