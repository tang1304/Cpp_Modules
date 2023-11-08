/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:21:57 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/08 16:00:54 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define DEFAULT_COLOR "\033[0m"

class ClapTrap{
	
private:

	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

public:

	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &cpy);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &cpy);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

};

#endif