/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:04:56 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/14 14:17:31 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "../incs/Animal.hpp"
# include "../incs/Brain.hpp"

class Cat : public Animal{

private:

	Brain	*_brain;

public:

	Cat();
	Cat(const Cat &old);
	virtual ~Cat();
	Cat &operator=(const Cat &old);

	void	makeSound() const;
	Brain	*getBrain() const;
};

#endif