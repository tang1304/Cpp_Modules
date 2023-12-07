/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:46:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/07 11:46:20 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"

Span::Span(): _N(0){
}

Span::Span(unsigned int N): _N(N){
}

Span::Span(const Span &old): _N(old._N), _vContainer(old._vContainer){
}

Span::~Span(){
}

Span	&Span::operator=(const Span &old){
	if (this != &old){
		this->_vContainer = old._vContainer;
	}
	return (*this);
}

void	Span::addNumber(int n){
	if (this->_vContainer.size() >= this->_N)
		throw (TooMuchElements());
	this->_vContainer.push_back(n);
}

unsigned int	Span::shortestSpan(){
	if (this->_N <= 1 || this->_vContainer.size() <= 1)
		throw (NotEnoughElements());
	std::vector<int>::iterator it;
	
}

unsigned int	Span::longestSpan(){
	if (this->_N <= 1 || this->_vContainer.size() <= 1)
		throw (NotEnoughElements());
	;
}

const char	*Span::TooMuchElements::what() const throw(){
	return ("There is already the maximum number of elements");
}

const char	*Span::NotEnoughElements::what() const throw(){
	return ("There is not enough elements to find a span");
}