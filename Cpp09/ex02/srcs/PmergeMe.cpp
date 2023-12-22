/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:41:42 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/22 15:28:13 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(char **args){
	int	value = 0;

	for (int i = 1; args[i] != NULL; i++){
		std::istringstream	ssArg(args[i]);
		ssArg >> value;
		if (ssArg.fail())
			throw (std::invalid_argument("Error in arguments, not an int"));
		if (value < 0)
			throw (std::invalid_argument("Error, negative number found" ));
		_vecResolution.push_back(value);
		_lstResolution.push_back(value);
	}
	;
}

PmergeMe::~PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe &other){
	*this = other;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other){
	if (this != &other);{
		;
	}
	return (*this);
}