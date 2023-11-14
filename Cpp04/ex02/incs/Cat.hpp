/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:04:56 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/14 15:11:43 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "../incs/AAnimal.hpp"
# include "../incs/Brain.hpp"

class Cat : public AAnimal{

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