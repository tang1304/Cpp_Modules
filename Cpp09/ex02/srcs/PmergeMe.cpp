/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:41:42 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/27 17:32:38 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(int argc, char **args){
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
	if (isSorted(_vecResolution.begin(), _vecResolution.end()))
		throw (std::invalid_argument("Error, the sequence is already sorted"));
	int prev1 = 0, prev2 = 1;
	int jacobNb = prev1 + 2 * prev2;
	for (int j = 1; j < argc; j++){
// 		jacobNb = prev2 + 2 * prev1;
// 		if (j == jacobNb){
// 			prev1 = prev2;
// 			prev2 = jacobNb;
// 			_jacobsthalNb.push_back(j);
// std::cout << j << std::endl;
		// }
		jacobNb = prev2 + 2 * prev1;
		if (j == jacobNb){
			_jacobsthalNb.push_back(j);
			std::cout << "jacob " << j << std::endl;
			prev1 = prev2;
			prev2 = jacobNb;
		}
		else{
			for (int k = jacobNb - 1; k > prev1; k--) {
				_jacobsthalNb.push_back(k);
				std::cout << k << std::endl;
			}
		}
	}
}

PmergeMe::~PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe &other){
	*this = other;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other){
	if (this != &other){
		_vecResolution = other._vecResolution;
		_lstResolution = other._lstResolution;
		_jacobsthalNb = other._jacobsthalNb;
	}
	return (*this);
}

bool	PmergeMe::isSorted(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	std::vector<int>::iterator	it = begin;
	std::vector<int>::iterator	it2 = begin + 1;

	while (it2 != end){
		if (*it > *it2)
			return (false);
		it++;
		it2++;
	}
	return (true);
}

void	PmergeMe::displaySequence(){
	std::cout << "Vector: ";
	for (std::vector<int>::iterator it = _vecResolution.begin(); it != _vecResolution.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::FJsortVec(){
	std::vector<std::pair<int, int> >	vecPairs;
	vecPairs = makePairsVec();
	vecPairs = FJsortPairsVec(vecPairs);
}

std::vector<std::pair<int, int> >	PmergeMe::FJsortPairsVec(std::vector<std::pair<int, int> > vecPairs){
	if (vecPairs.size() == 1)
		return (vecPairs);

	std::vector<std::pair<int, int> >::iterator	mid = vecPairs.begin() + vecPairs.size() / 2;
	std::vector<std::pair<int, int> >	leftVec(vecPairs.begin(), mid);
	std::vector<std::pair<int, int> >	rightVec(mid, vecPairs.end());
	
	std::vector<std::pair<int, int> >	leftSorted = FJsortPairsVec(leftVec);
	std::vector<std::pair<int, int> >	rightSorted = FJsortPairsVec(rightVec);

	std::vector<std::pair<int, int> >	mergedVec;
	std::merge(leftSorted.begin(), leftSorted.end(), rightSorted.begin(), rightSorted.end(), mergedVec.begin());
	return (mergedVec);
}

std::vector<std::pair<int, int> >	PmergeMe::makePairsVec(){
	std::vector<std::pair<int, int> >	_vecPairs;
	for (std::vector<int>::iterator it = _vecResolution.begin(); it != _vecResolution.end(); it += 2){
		if (it + 1 != _vecResolution.end()){
			if (*it < *(it + 1)){
				_vecPairs.push_back(std::make_pair(*it, *(it + 1)));
std::cout << "pair: " << *it << " " << *(it + 1) << std::endl;
			}
			else{
				_vecPairs.push_back(std::make_pair(*(it + 1), *it));
std::cout << "pair: " << *(it + 1) << " " << *it << std::endl;
			}
		}
		else{
			_vecPairs.push_back(std::make_pair(*it, -1));
std::cout << "pair: " << *it << " -1" << std::endl;
			break ;
		}
	}
	return (_vecPairs);
}