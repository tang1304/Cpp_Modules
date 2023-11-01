/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:14:34 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/01 13:43:40 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB{
private:
	std::string	_name;
	Weapon		*_weapon;

public:
	HumanB(std::string name);
	~HumanB();

	void	attack();
	void	setWeapon(Weapon &newWeapon);
};

#endif