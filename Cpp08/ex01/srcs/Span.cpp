/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:46:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/08 16:57:42 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"

Span::Span(): _N(0){
}

Span::Span(unsigned int N): _N(N){
	try{
		_vContainer.reserve(N);
		// test with _vContainer.maxsize()
	}
	catch (std::bad_alloc &e){
		std::cout << RED << "Not enough memory" << WHITE << std::endl;
		// std::vector<int>().swap(_vContainer);
		throw ;
	}
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
	unsigned int	min = INT_MAX;
	int	prev;
	std::vector<int>::iterator	it;
	std::vector<int> cpy = this->_vContainer;

	if (this->_N <= 1 || this->_vContainer.size() <= 1)
		throw (NotEnoughElements());
	std::sort(cpy.begin(), cpy.end());
	it = cpy.begin();
	while (it != cpy.end() - 1){
		prev = *it;
		it += 1;
		if (static_cast<unsigned int>(abs(*it - prev)) < min)
			min = abs(*it - prev);
	}
	return (min);
}

unsigned int	Span::longestSpan(){
	int minElem;
	int maxElem;

	if (this->_N <= 1 || this->_vContainer.size() <= 1)
		throw (NotEnoughElements());
	minElem = *std::min_element(this->_vContainer.begin(), this->_vContainer.end());
	maxElem = *std::max_element(this->_vContainer.begin(), this->_vContainer.end());
	return (abs(maxElem - minElem));
}

void	Span::fillSpan(unsigned int nbrElements, int val){
	if ((this->_vContainer.size() + nbrElements) > this->_N)
		throw (TooMuchElements());
	this->_vContainer.insert(this->_vContainer.end(), nbrElements, val);
}

std::vector<int>	Span::getVector() const{
	return (this->_vContainer);
}

const char	*Span::TooMuchElements::what() const throw(){
	return ("Error, there is already the maximum number of elements");
}

const char	*Span::NotEnoughElements::what() const throw(){
	return ("Error, there is not enough elements to find a span");
}