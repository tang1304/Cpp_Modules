/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:41:12 by tgellon           #+#    #+#             */
/*   Updated: 2024/01/05 15:27:31 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

static long	getTime(struct timeval startTime)
{
	long			time;
	struct timeval	newTime;

	if (gettimeofday(&newTime, NULL) < 0)
		return (-1);
	time = (newTime.tv_sec - startTime.tv_sec) * 1000000 + (newTime.tv_usec - startTime.tv_usec);
	return (time);
}

int main(int argc, char **argv){
	std::string		input;
	struct timeval	start;
	long			timeSortVec;
	long			timeSortDeq;

	if (argc < 3){
		std::cout << RED << "wrong argument entered" << CLEAR << std::endl;
		return (1);
	}
	try{
		PmergeMe obj(argc, argv);
		std::cout << "Before: ";
		obj.displaySequence();
		if (gettimeofday(&start, NULL) != 0)
			throw (std::runtime_error("gettimeofday failed"));
		obj.FJsortVec();
		timeSortVec = getTime(start);
		std::cout << "After: ";
		obj.displaySequence();
		if (gettimeofday(&start, NULL) != 0)
			throw (std::runtime_error("gettimeofday failed"));
		obj.FJsortDeq();
		timeSortDeq = getTime(start);
		// std::cout << "Deque: "; // to test the deque order
		// obj.displaySequenceDeq();
		std::cout << "Time to sort with vector : " << timeSortVec << " us" << std::endl;
		std::cout << "Time to sort with deque : " << timeSortDeq << " us" << std::endl;
	}
	catch(std::exception &e){
		std::cout << RED << "Error: " << e.what() << CLEAR << std::endl;
		return (1);
	}
}