/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:33:41 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/05 16:07:59 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/easyfind.hpp"

template <typename T>
int easyfind(T elemT, int elemInt){
	typename T::iterator it;
	
	it = std::find(elemT.begin(), elemT.end(), elemInt);
	if (it == elemT.end())
		return (-1);
	return (*it);
}