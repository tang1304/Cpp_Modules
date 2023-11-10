/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:20:49 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/10 10:26:08 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (){
	std::string	nameA = "CL4P-TP";
	std::string	nameB = "R2D2";
	std::string nameC = "W1Z4RD-TP";

	ClapTrap	alpha(nameA);
	ClapTrap	beta(nameB);
	ScavTrap	gamma(nameC);
	ScavTrap	omega(gamma);

	alpha.setAttackDamage(3);
	beta.setAttackDamage(6);

	alpha.attack(beta.getName());
	beta.takeDamage(alpha.getAttackDamage());
	beta.attack(alpha.getName());
	alpha.takeDamage(beta.getAttackDamage());
	alpha.beRepaired(3);

	gamma.attack(beta.getName());
	beta.takeDamage(gamma.getAttackDamage());
	beta.setAttackDamage(beta.getAttackDamage() * 2);
	beta.attack(alpha.getName());
	alpha.attack(omega.getName());
	alpha.beRepaired(3);
	gamma.guardGate();
	beta.attack(gamma.getName());
	omega.setName("SC4V-TP");
	omega.setEnergyPoints(0);
	omega.guardGate();
}