/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:32:06 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/15 15:36:39 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria{

public:

	Cure();
	Cure(const Cure &old);
	~Cure();
	Cure &operator=(const Cure &old);

	AMateria*	clone() const;
	void		use(ICharacter& target);
};

#endif