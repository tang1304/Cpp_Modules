/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:43:59 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/06 10:25:33 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(){
	FixedPointNbr	a;
	FixedPointNbr	b(a);
	FixedPointNbr	c;

	c = b;
	
	std::cout << BLUE << "a nbr is : " << a.getRawBits() << DEFAULT_COLOR << std::endl;
	std::cout << GREEN << "b nbr is : " << b.getRawBits() << DEFAULT_COLOR << std::endl;
	std::cout << YELLOW << "c nbr is : " << c.getRawBits() << DEFAULT_COLOR << std::endl;
}