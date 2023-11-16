/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:20:49 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/16 10:29:49 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main (){
	std::string	nameA = "CL4P-TP";
	std::string	nameB = "R2D2";
	// std::string nameC = "W1Z4RD-TP";
	// std::string nameD = "FR4G-TP";

	ClapTrap	alpha(nameA);
	// ClapTrap	beta(nameB);
	// ScavTrap	gamma(nameC);
	// FragTrap	omega(nameD);
	// FragTrap	delta(omega);
	DiamondTrap	teta(nameB);


	// alpha.setAttackDamage(3);
	// beta.setAttackDamage(6);

	// alpha.attack(omega.getName());
	// omega.takeDamage(alpha.getAttackDamage());
	// beta.attack(alpha.getName());
	// alpha.takeDamage(beta.getAttackDamage());
	// omega.beRepaired(3);
	// omega.attack(gamma.getName());
	// gamma.takeDamage(omega.getAttackDamage());
	// gamma.guardGate();
	// omega.highFiveGuys();
	// beta.attack(gamma.getName());
	// delta.setName("B00T-STR4P");
	// delta.setEnergyPoints(0);
	// delta.highFiveGuys();

	std::cout << "attaque " << teta.getAttackDamage() <<std::endl;
	std::cout << "energy "<< teta.getEnergyPoints() <<std::endl;
	std::cout << "hp "<< teta.getHitPoints() <<std::endl;
	teta.guardGate();
	teta.highFiveGuys();
	teta.attack(alpha.getName());
	teta.whoAmI();
	teta.setHitPoints(0);
	teta.whoAmI();
}