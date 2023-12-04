/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:55:34 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/04 15:02:48 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>

class Array{
private:

	T	*_list;
	unsigned int	_size;

public:

	Array();
	Array(unsigned int n);
	Array(const Array &old);
	~Array();
	Aray &operator=(const Array &old);

	unsigned int	size();

	class BadAccess: public std::exception{
		public:
		const char *what const throw();
	};
};

#endif