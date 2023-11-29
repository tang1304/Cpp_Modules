/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:45:03 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/29 15:17:15 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Serializer.hpp"

Serializer::Serializer(){
}

Serializer::Serializer(const Serializer &old){
	*this = old;
}

Serializer::~Serializer(){
}

Serializer	&Serializer::operator=(const Serializer &old){
	(void)old;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));
}