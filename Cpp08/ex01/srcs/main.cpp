/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:12:00 by tgellon           #+#    #+#             */
/*   Updated: 2024/01/11 15:31:54 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"

int	main(){
	try{
		Span	sp = Span(7);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(-2147483648);
		sp.addNumber(2147483647);

		std::cout << "size: " << sp.getVector().size() << std::endl;
		std::cout << "shortest: " <<sp.shortestSpan() << std::endl;
		std::cout << "longest: " <<sp.longestSpan() << std::endl;

		Span	sp2 = Span(100000);
		sp2.fillSpan(10000, 42);
		sp2.fillSpan(10000, 100);
		sp2.fillSpan(10000, 237);
		sp2.fillSpan(10000, 872);
		sp2.fillSpan(10000, -32248579);
		std::cout << "capacity: " << sp2.getVector().capacity() << std::endl;
		sp2.fillSpan(50000, 9);
		// Span	sp3 = Span(4294967295); //test with unsigned int max elements
		// sp3.fillSpan(4294967295, 9);

		std::cout << "capacity: " << sp2.getVector().capacity() << std::endl;
		std::cout << "size: " << sp2.getVector().size() << std::endl;
		std::cout <<sp2.shortestSpan() << std::endl;
		std::cout <<sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << WHITE << std::endl;
		return (1);
	}
}