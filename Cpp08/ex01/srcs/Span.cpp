/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:46:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/06 16:07:39 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"

Span::Span(): _N(0){
}

Span::Span(unsigned int N): _N(N){
}

Span::Span(const Span &old): _N(old._N){
}

Span::~Span(){
}

Span	&Span::operator=(const Span &old){
	return (*this);
}

void	Span::addNumber(){
	;
}

unsigned int	Span::shortestSpan(){
	;
}

unsigned int	Span::longestSpan(){
	;
}

const char	*Span::TooMuchElements::what() const throw(){
	return ("There is already the maximum number of elements");
}

const char	*Span::NotEnoughElements::what() const throw(){
	return ("There is not enough elements to find a span");
}