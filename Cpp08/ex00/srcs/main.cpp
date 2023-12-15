/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:33:09 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/15 09:52:47 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/easyfind.hpp"
#include "../incs/easyfind.tpp"
#include <list>
#include <vector>

int main(){
	try{
		std::list<int>		lst;
		std::vector<int>	vec;

		for (int i = 0; i < 5; i++){
			lst.push_back(i * 2);
		}
		std::cout << *easyfind(lst, 2) << std::endl;
		std::cout << *easyfind(lst, 8) << std::endl;
		std::cout << *easyfind(lst, 10) << std::endl;

		std::cout << std::endl;
		for (int i = 0; i < 5; i++){
			vec.push_back(i * 3);
		}
		std::cout << *easyfind(vec, 3) << std::endl;
		std::cout << *easyfind(vec, 2) << std::endl;
		std::cout << *easyfind(vec, 9) << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}