/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:13:51 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/08 16:32:00 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>

class MutantStack: public std::stack{
private:

	;

public:

	MutantStack();
	MutantStack(const MutantStack &old);
	~MutantStack();
	MutantStack &operator=(const MutantStack &old);

};

#endif