/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:20:49 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/09 14:26:39 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (){
	std::string	nameA = "CL4P-TP";
	std::string	nameB = "R2D2";

	ClapTrap	alpha(nameA);
	ClapTrap	beta(nameB);
	ClapTrap	gamma;

	alpha.setAttackDamage(3);
	beta.setAttackDamage(6);

	gamma = alpha;

	alpha.attack(beta.getName());
	beta.takeDamage(alpha.getAttackDamage());
	beta.attack(alpha.getName());
	alpha.takeDamage(beta.getAttackDamage());
	alpha.beRepaired(3);

	beta.setAttackDamage(beta.getAttackDamage() * 2);
	beta.attack(alpha.getName());
	alpha.takeDamage(beta.getAttackDamage());
	alpha.attack(beta.getName());
	alpha.beRepaired(3);
	
	beta.setEnergyPoints(0);
	beta.attack(gamma.getName());
}