/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:35:24 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/13 13:14:52 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define DARK_GREY "\033[30m"
# define DEFAULT_COLOR "\033[0m"

class Animal{
protected:

	std::string	_type;

public:

	Animal();
	Animal(const Animal &old);
	~Animal();
	Animal &operator=(const Animal &old);

	std::string	getType() const;
	void		makeSound();
};

#endif