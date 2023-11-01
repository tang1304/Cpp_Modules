/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:07:54 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/01 10:33:19 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int	nb = 5;

	Zombie	*horde = zombieHorde(nb, "dummy");
	for (int i = 0; i < nb; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}