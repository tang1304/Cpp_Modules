/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:43:20 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/31 10:12:21 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define DEFAULT_COLOR "\033[0m"

class Zombie
{
private:
	std::string	_name;

public:
	Zombie();
	~Zombie();

	void	announce(void);
	void	setName(std::string name);
};

Zombie	*zombieHorde(int n, std::string name);

#endif