/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:55:46 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/16 15:57:11 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define DARK_GREY "\033[30m"
# define DEFAULT_COLOR "\033[0m"

# include <iostream>
# include "../incs/ICharacter.hpp"

class ICharacter;

class AMateria{
protected:

	std::string	_type;
	bool		_equiped;

public:

	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &old);
	virtual ~AMateria();
	AMateria &operator=(const AMateria &old);

	void				setEquiped(bool b);
	bool				getEquiped() const;
	std::string const	&getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

};

#endif