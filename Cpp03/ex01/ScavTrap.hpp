/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:34:49 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/09 16:00:40 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{

public:

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(conts ScavTrap &cpy);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &cpy);

	void	guardGate();
};

#endif