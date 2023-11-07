/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:43:59 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/07 15:42:01 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(){
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	c = b;
	
	std::cout << BLUE << "a nbr is : " << a.getRawBits() << DEFAULT_COLOR << std::endl;
	std::cout << GREEN << "b nbr is : " << b.getRawBits() << DEFAULT_COLOR << std::endl;
	std::cout << YELLOW << "c nbr is : " << c.getRawBits() << DEFAULT_COLOR << std::endl;
}