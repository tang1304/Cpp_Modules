/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:44:56 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/29 15:20:41 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

# define GREEN "\033[32m"
# define WHITE "\033[0m"

class Data;

class Serializer{
private:

	Serializer();
	Serializer(const Serializer &old);
	~Serializer();
	Serializer &operator=(const Serializer &old);

public:

	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);

};

#endif