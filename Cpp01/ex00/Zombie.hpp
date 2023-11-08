/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:43:20 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/08 11:01:03 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define DEFAULT_COLOR "\033[0m"

class Zombie{
private:
	std::string	_name;

public:
	Zombie(std::string name);
	~Zombie();

	void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif