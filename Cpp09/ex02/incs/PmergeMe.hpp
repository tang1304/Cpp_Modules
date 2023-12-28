/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:35:10 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/28 14:32:26 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "PmergeMe.h"

class PmergeMe{
private:

	std::vector<int>	_vecResolution;
	std::list<int>		_lstResolution;
	std::vector<int>	_jacobsthalNb;
	PmergeMe();

public:

	PmergeMe(int argc, char **args);
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	bool	isSorted(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	void	displaySequence();
	void	FJsortVec();
	std::vector<std::pair<int, int> >	FJsortPairsVec(std::vector<std::pair<int, int> >);
	std::vector<std::pair<int, int> >	makePairsVec();
	void	insertSortVec(int n, size_t size);
	
};

#endif