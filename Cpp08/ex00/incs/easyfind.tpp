/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:33:41 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/15 09:58:11 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &elemT, int elemInt){
	typename T::iterator it;

	it = std::find(elemT.begin(), elemT.end(), elemInt);
	if (it == elemT.end()){
		throw (std::logic_error("Not in container"));
	}
	return (it);
}