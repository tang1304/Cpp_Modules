/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:42:49 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/15 09:25:25 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <climits>
# include <algorithm>
# include <vector>
# include <iterator>

# define RED "\033[31m"
# define WHITE "\033[0m"

class Span{
private:

	const unsigned int	_N;
	std::vector<int>	_vContainer;
	Span();

public:

	Span(unsigned int N);
	Span(const Span &old);
	~Span();
	Span &operator=(const Span &old);

	void			addNumber(int n);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	void			fillSpan(unsigned int nbrElements, int val);
	std::vector<int>	getVector() const;

	class TooManyElements: public std::exception{
		public:
		const char *what() const throw();
	};
	class NotEnoughElements: public std::exception{
		public:
		const char *what() const throw();
	};
};

#endif