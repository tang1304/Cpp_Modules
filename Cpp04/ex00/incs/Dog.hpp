/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:19:16 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/14 13:25:18 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
# define Dog_HPP

# include "../incs/Animal.hpp"

class Dog : public Animal{

public:
	Dog();
	Dog(const Dog &old);
	virtual ~Dog();
	Dog &operator=(const Dog &old);

	void	makeSound() const;
};

#endif