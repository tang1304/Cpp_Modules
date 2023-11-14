/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:54:21 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/14 09:59:19 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define DARK_GREY "\033[30m"
# define DEFAULT_COLOR "\033[0m"

class WrongAnimal{
protected:

	std::string	_type;

public:

	WrongAnimal();
	WrongAnimal(const WrongAnimal &old);
	virtual ~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &old);

	std::string		getType() const;
	void	makeSound() const;
};

#endif