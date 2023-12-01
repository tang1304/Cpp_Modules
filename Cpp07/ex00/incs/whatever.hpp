/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:40:43 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/01 14:18:55 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void	swap(T &a, T &b){
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(T &a, T &b){
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T	max(T &a, T &b){
	if (a < b)
		return (b);
	return (a);
}

#endif