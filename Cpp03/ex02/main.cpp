/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:20:49 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/10 11:30:13 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (){
	std::string	nameA = "CL4P-TP";
	std::string	nameB = "R2D2";
	std::string nameC = "W1Z4RD-TP";
	std::string nameD = "FR4G-TP";

	ClapTrap	alpha(nameA);
	ClapTrap	beta(nameB);
	ScavTrap	gamma(nameC);
	FragTrap	omega(nameD);
	FragTrap	delta(omega);

	alpha.setAttackDamage(3);
	beta.setAttackDamage(6);

	alpha.attack(omega.getName());
	omega.takeDamage(alpha.getAttackDamage());
	beta.attack(alpha.getName());
	alpha.takeDamage(beta.getAttackDamage());
	omega.beRepaired(3);
	omega.attack(gamma.getName());
	gamma.takeDamage(omega.getAttackDamage());
	gamma.guardGate();
	omega.highFiveGuys();
	beta.attack(gamma.getName());
	delta.setName("B00T-STR4P");
	delta.setEnergyPoints(0);
	delta.highFiveGuys();
}