/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:46:29 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/14 13:56:20 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define DARK_GREY "\033[30m"
# define DEFAULT_COLOR "\033[0m"

class Brain{
private:

	std::string	_ideas[100];

public:

	Brain();
	Brain(const Brain &old);
	virtual ~Brain();
	Brain &operator=(const Brain &old);

	void	setIdea(int n);
};

#endif