/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:34:49 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/10 13:02:25 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap{
public:

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &cpy);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &cpy);

	void	attack(const std::string &target);
	void	guardGate();
};

#endif