/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:43:28 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/16 10:19:18 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# define SLOTS 4

# include "../incs/IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
private:

	AMateria	*_slots[SLOTS];

public:

	MateriaSource();
	MateriaSource(const MateriaSource &old);
	~MateriaSource();
	MateriaSource &operator=(const MateriaSource &old);

	void		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);
};

#endif