/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:35:02 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/10 13:02:33 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap{
public:

	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &cpy);
	~FragTrap();
	FragTrap &operator=(const FragTrap &cpy);

	void	attack(const std::string &target);
	void	highFiveGuys();
};

#endif