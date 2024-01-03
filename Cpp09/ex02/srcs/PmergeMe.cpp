/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:41:42 by tgellon           #+#    #+#             */
/*   Updated: 2024/01/03 10:55:42 by tgellon          ###   ########lyon.fr   */
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
		_deqResolution.push_back(value);
	}
	if (isSorted(_vecResolution.begin(), _vecResolution.end()))
		throw (std::invalid_argument("Error, the sequence is already sorted"));
	JacobsthalInit(argc);
}

PmergeMe::~PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe &other){
	*this = other;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other){
	if (this != &other){
		_vecResolution = other._vecResolution;
		_deqResolution = other._deqResolution;
		_jacobsthalNb = other._jacobsthalNb;
	}
	return (*this);
}

void	PmergeMe::JacobsthalInit(int argc){
	int prev1 = 0, prev2 = 1;
	int jacobNb = 0;
	while (jacobNb < ((argc - 1) / 2) + 1){
		if (jacobNb != 0){
			_jacobsthalNb.push_back(jacobNb);
			for (int j = jacobNb - 1; j > prev1; j--) {
				_jacobsthalNb.push_back(j);
			}
		}
		jacobNb = prev2 + 2 * prev1;
		prev1 = prev2;
		prev2 = jacobNb;
	}
	for (int k = *(std::max_element(_jacobsthalNb.begin(), _jacobsthalNb.end())) + 1 ; k < (argc / 2) + 1; k++){
		_jacobsthalNb.push_back(k);
	}
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
	for (std::vector<int>::iterator it = _vecResolution.begin(); it != _vecResolution.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::displaySequenceDeq(){
	for (std::deque<int>::iterator it = _deqResolution.begin(); it != _deqResolution.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::FJsortVec(){
	std::vector<std::pair<int, int> >	vecPairs;

	vecPairs = makePairsVec();
// for (size_t i = 0; i < vecPairs.size(); i++){ // to show the pairs
// 	std::cout << vecPairs[i].first << " " << vecPairs[i].second << std::endl;
// }
	vecPairs = FJsortPairsVec(vecPairs);
// for (size_t i = 0; i < vecPairs.size(); i++){ // to show the pairs sorted by their highest number
// 	std::cout << vecPairs[i].first << " " << vecPairs[i].second << std::endl;
// }
	_vecResolution.clear();
	for (std::vector<std::pair<int, int> >::iterator it = vecPairs.begin(); it != vecPairs.end(); ++it){
		if ((it->first) != -1){
			_vecResolution.push_back(it->first);
		}
	}
	std::vector<int>::iterator itJacob = _jacobsthalNb.begin();
	for (size_t j = 0; j < vecPairs.size(); j++){
		insertSortVec(vecPairs[*(itJacob) - 1].second, this->_vecResolution.size());
		itJacob++;
	}
	return ;
}

std::vector<std::pair<int, int> >	PmergeMe::FJsortPairsVec(std::vector<std::pair<int, int> > vecPairs){
	if (vecPairs.size() <= 1)
		return (vecPairs);

	std::vector<std::pair<int, int> >::iterator	mid = vecPairs.begin() + vecPairs.size() / 2;
	std::vector<std::pair<int, int> >			leftVec(vecPairs.begin(), mid);
	std::vector<std::pair<int, int> >			rightVec(mid, vecPairs.end());
	
	std::vector<std::pair<int, int> >	leftSorted = FJsortPairsVec(leftVec);
	std::vector<std::pair<int, int> >	rightSorted = FJsortPairsVec(rightVec);

	std::vector<std::pair<int, int> >	mergedVec;
	std::merge(leftSorted.begin(), leftSorted.end(), rightSorted.begin(), rightSorted.end(), std::back_inserter(mergedVec));
	return (mergedVec);
}

std::vector<std::pair<int, int> >	PmergeMe::makePairsVec(){
	std::vector<std::pair<int, int> >	_vecPairs;

	for (std::vector<int>::iterator it = _vecResolution.begin(); it != _vecResolution.end(); it += 2){
		if (it + 1 != _vecResolution.end()){
			if (*it > *(it + 1))
				_vecPairs.push_back(std::make_pair(*it, *(it + 1)));
			else
				_vecPairs.push_back(std::make_pair(*(it + 1), *it));
		}
		else{
			_vecPairs.push_back(std::make_pair(-1, *it));
			break ;
		}
	}
	return (_vecPairs);
}

void	PmergeMe::insertSortVec(int n, size_t size){
	std::vector<int>::iterator	mid = _vecResolution.begin() + size / 2;
	std::vector<int>::iterator	left = _vecResolution.begin();
	std::vector<int>::iterator	right = _vecResolution.end() - 1;

	while (left <= right){
		mid = left + (right - left) / 2;
		if (n == *mid){
			this->_vecResolution.insert(mid, n);
			return ;
		}
		if (n < *mid){
			right = mid - 1;
			continue ;
		}
		else{
			left = mid + 1;
			continue ;
		}
	}
	this->_vecResolution.insert(left, n);
	return ;
}



void	PmergeMe::FJsortDeq(){
	std::deque<std::pair<int, int> >	deqPairs;

	deqPairs = makePairsDeq();
	deqPairs = FJsortPairsDeq(deqPairs);
	_deqResolution.clear();
	for (std::deque<std::pair<int, int> >::iterator it = deqPairs.begin(); it != deqPairs.end(); ++it){
		if ((it->first) != -1){
			_deqResolution.push_back(it->first);
		}
	}
	std::vector<int>::iterator itJacob = _jacobsthalNb.begin();
	for (size_t j = 0; j < deqPairs.size(); j++){
		insertSortDeq(deqPairs[*(itJacob) - 1].second, this->_deqResolution.size());
		itJacob++;
	}
	return ;
}

std::deque<std::pair<int, int> >	PmergeMe::FJsortPairsDeq(std::deque<std::pair<int, int> > deqPairs){
	if (deqPairs.size() <= 1)
		return (deqPairs);

	std::deque<std::pair<int, int> >::iterator	mid = deqPairs.begin() + deqPairs.size() / 2;
	std::deque<std::pair<int, int> >			leftDeq(deqPairs.begin(), mid);
	std::deque<std::pair<int, int> >			rightDeq(mid, deqPairs.end());
	
	std::deque<std::pair<int, int> >	leftSorted = FJsortPairsDeq(leftDeq);
	std::deque<std::pair<int, int> >	rightSorted = FJsortPairsDeq(rightDeq);

	std::deque<std::pair<int, int> >	mergedDeq;
	std::merge(leftSorted.begin(), leftSorted.end(), rightSorted.begin(), rightSorted.end(), std::back_inserter(mergedDeq));
	return (mergedDeq);
}

std::deque<std::pair<int, int> >	PmergeMe::makePairsDeq(){
	std::deque<std::pair<int, int> >	_deqPairs;

	for (std::deque<int>::iterator it = _deqResolution.begin(); it != _deqResolution.end(); it += 2){
		if (it + 1 != _deqResolution.end()){
			if (*it > *(it + 1))
				_deqPairs.push_back(std::make_pair(*it, *(it + 1)));
			else
				_deqPairs.push_back(std::make_pair(*(it + 1), *it));
		}
		else{
			_deqPairs.push_back(std::make_pair(-1, *it));
			break ;
		}
	}
	return (_deqPairs);
}

void	PmergeMe::insertSortDeq(int n, size_t size){
	std::deque<int>::iterator	mid = _deqResolution.begin() + size / 2;
	std::deque<int>::iterator	left = _deqResolution.begin();
	std::deque<int>::iterator	right = _deqResolution.end() - 1;

	while (left <= right){
		mid = left + (right - left) / 2;
		if (n == *mid){
			this->_deqResolution.insert(mid, n);
			return ;
		}
		if (n < *mid){
			right = mid - 1;
			continue ;
		}
		else{
			left = mid + 1;
			continue ;
		}
	}
	this->_deqResolution.insert(left, n);
	return ;
}