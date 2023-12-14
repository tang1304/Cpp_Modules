/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:13:51 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/14 14:06:58 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <list>
# include <stack>
# include <iterator>

template<typename T>
class MutantStack: public std::stack<T>{

public:

	MutantStack(){};
	MutantStack(const MutantStack &old){
		*this = old;
	};
	~MutantStack(){};
	MutantStack &operator=(const MutantStack &old){
		if (this != &old)
			this->c = old.c;
		return (*this);
	};

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator	begin(){
		return (this->c.begin());
	}
	iterator	end(){
		return (this->c.end());
	}
};

#endif