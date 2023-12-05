/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:38:37 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/05 11:09:04 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Array.hpp"

template<typename T>
Array<T>::Array(){
	this->_list = new T[0];
	this->_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n){
	this->_list = new T[n];
	this->_size = n;
}

template<typename T>
Array<T>::Array(const Array<T> &old){
	this->_size = old._size;
	this->_list = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_list[i] = old._list[i];
}

template<typename T>
Array<T>::~Array(){
	if (this->_list)
		delete [] this->_list;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array<T> &old){
	if (this->_list)
		delete [] this->_list;
	this->_size = old._size;
	this->_list = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_list[i] = old._list[i];
	return (*this);
}

template<typename T>
T &Array<T>::operator[](unsigned int i){
	if (i >= this->_size)
		throw Array<T>::BadAccess();
	return (this->_list[i]);
}

template<typename T>
unsigned int	Array<T>::size(){
	return (this->_size);
}

template<typename T>
const char *Array<T>::BadAccess::what() const throw(){
	return ("Error, trying to access an element out of range");
}