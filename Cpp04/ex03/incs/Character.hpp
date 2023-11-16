/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:46:07 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/16 14:20:03 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "../incs/ICharacter.hpp"
# include <iostream>

# define SLOTS 4

class Character : public ICharacter{
protected:

	AMateria	*_inventory[SLOTS];
	std::string	_name;

public:

	Character();
	Character(std::string name);
	Character(const Character &old);
	~Character();
	Character &operator=(const Character &old);

	std::string const & getName() const;

	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);
};

#endif