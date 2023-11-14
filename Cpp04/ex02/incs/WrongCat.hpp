/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:01:35 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/14 11:44:24 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "../incs/WrongAnimal.hpp"

class WrongCat : public WrongAnimal{

public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(const WrongCat &old);
	virtual ~WrongCat();
	WrongCat &operator=(const WrongCat &old);

	void	makeSound() const;
};

#endif