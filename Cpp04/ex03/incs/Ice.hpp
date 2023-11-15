/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:28:22 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/15 15:34:36 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria{

public:

	Ice();
	Ice(const Ice &old);
	~Ice();
	Ice &operator=(const Ice &old);

	AMateria*	clone() const;
	void		use(ICharacter& target);
};

#endif