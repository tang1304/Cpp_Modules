/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:55:34 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/05 10:37:02 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

# define YELLOW "\033[33m"
# define WHITE "\033[0m"

template<typename T>
class Array{
private:

	T*	_list;
	unsigned int	_size;

public:

	Array<T>();
	Array<T>(unsigned int n);
	Array<T>(const Array<T> &old);
	~Array<T>();
	Array &operator=(const Array<T> &old);

	unsigned int	size();
	T	&operator[](unsigned int i);

	class BadAccess: public std::exception{
		public:
		const char *what() const throw();
	};
};

#endif