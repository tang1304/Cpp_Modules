/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:12:00 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/07 16:53:40 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"

int	main(){
	try{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout <<sp.shortestSpan() << std::endl;
		std::cout <<sp.longestSpan() << std::endl;

		Span	sp2 = Span(10000);
		sp2.fillSpan(10000, 42);
		
		std::cout <<sp2.shortestSpan() << std::endl;
		std::cout <<sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << WHITE << std::endl;
		return (1);
	}
}