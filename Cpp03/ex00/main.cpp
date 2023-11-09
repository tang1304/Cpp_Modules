/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:20:49 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/09 10:24:39 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (){
	std::string	nameA = "CL4P-TP";
	std::string	nameB = "R2D2";

	ClapTrap	alpha("nameA");
	ClapTrap	beta("nameB");
	ClapTrap	gamma;

	gamma = alpha;

	
}