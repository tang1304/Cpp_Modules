/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:13:51 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/13 16:21:22 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <queue>
# include <stack>


template<typename T>
class MutantStack: public std::stack<T>{

public:

	MutantStack();
	MutantStack(const MutantStack &old);
	~MutantStack();
	MutantStack &operator=(const MutantStack &old);


};

# include "MutantStack.tpp"

#endif