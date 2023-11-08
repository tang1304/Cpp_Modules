/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:21:57 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/08 13:34:10 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{
	
private:

	std::string	_name;
	int			_hitPoints = 10;
	int			_energyPoints = 10;
	int			_AttackDamage = 0;

public:

	ClapTrap();
	ClapTrap(const ClapTrap &cpy);
	~ClapTrap();

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	ClapTrap &operator=(const ClapTrap &cpy);
};

#endif