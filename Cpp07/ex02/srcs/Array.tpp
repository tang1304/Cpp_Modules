/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:38:37 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/04 15:58:50 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Array.hpp"

template<typename T>
Array::Array(){
	_list = new T[0];
	size = 0;
}

Array::Array(unsigned int n){
	_list = new T[n];
	size = n;
}

Array::Array(const Array &old){
	*this = old;
}

Array::~Array(){
	if (this->_list)
		delete [] this->_list;
}

Array	&Array::operator=(const Array &old){
	if (this != old){
		this->_list = new T[size()];
		this->_size = old._size;
		for (int i = 0; i < size; i++){
			this->_list = old._list;
		}
	}
	return (*this);
}

unsigned int	Array::size(){
	return (this->_size);
}

const char *Array::BadAccess::what() const throw(){
	return ("Error, trying to access an element out of range");
}