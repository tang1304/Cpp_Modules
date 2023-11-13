/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:04:56 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/13 16:04:12 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal{

public:
	Cat();
	Cat(std::string type);
	Cat(const Cat &old);
	virtual ~Cat();
	Cat &operator=(const Cat &old);

	void	makeSound() const;
};

#endif