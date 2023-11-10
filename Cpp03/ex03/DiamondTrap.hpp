/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:55:57 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/10 15:17:40 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
private:

	std::string	_name;

public:

	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &cpy);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &cpy);

	void	attack(const std::string &target);
	void	whoAmI();
};

#endif