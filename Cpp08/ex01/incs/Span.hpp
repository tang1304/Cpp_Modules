/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:42:49 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/06 12:57:28 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

class Span{
private:

	unsigned int _N;

public:

	Span();
	Span(const Span &old);
	~Span();
	Span &operator=(const Span &old);

	void			addNumber();
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	
	class TooMuchElements: public std::exception{
		public:
		const char *what() const throw();
	};
	class 
};

#endif