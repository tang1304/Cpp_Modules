/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:39:10 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/14 14:16:43 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/MutantStack.hpp"

int	main(){
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite){
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl;
	MutantStack<int> cpy;
	cpy = mstack;
	it = cpy.begin();
	ite = cpy.end();
	while (it != ite){
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl;
	MutantStack<char>	mstackChar;

	mstackChar.push(56);
	mstackChar.push(117);
	std::cout << mstackChar.top() << std::endl;

	mstackChar.pop();
	std::cout << mstackChar.size() << std::endl;

	mstackChar.push(75);
	mstackChar.push(45);
	mstackChar.push(124);
	mstackChar.push(0);
	MutantStack<char>::iterator itChar = mstackChar.begin();
	MutantStack<char>::iterator iteChar = mstackChar.end();

	++itChar;
	--itChar;
	while (itChar != iteChar){
		std::cout << *itChar << std::endl;
		++itChar;
	}

	std::cout << std::endl;
	MutantStack<std::string>	mstackString;

	mstackString.push("hello");
	mstackString.push("world");
	std::cout << mstackString.top() << std::endl;

	mstackString.pop();
	std::cout << mstackString.size() << std::endl;

	mstackString.push("75");
	mstackString.push("AbCd");
	mstackString.push("hi");
	MutantStack<std::string>::iterator itString = mstackString.begin();
	MutantStack<std::string>::iterator iteString = mstackString.end();

	++itString;
	--itString;
	while (itString != iteString){
		std::cout << *itString << std::endl;
		++itString;
	}

	std::cout << std::endl;
	std::list<int>	ls;
	ls.push_back(5);
	ls.push_back(17);
	std::cout << ls.back() << std::endl;

	ls.pop_back();
	std::cout << ls.size() << std::endl;

	ls.push_back(3);
	ls.push_back(5);
	ls.push_back(737);
	ls.push_back(0);

	std::list<int>::iterator	i = ls.begin();
	while (i != ls.end()){
		std::cout << *i << std::endl;
		++i;
	}

	return 0;
}