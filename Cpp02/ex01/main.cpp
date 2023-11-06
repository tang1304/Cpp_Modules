/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:43:59 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/06 13:23:45 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(){
	FixedPointNbr	a;
	FixedPointNbr	const b(10);
	FixedPointNbr	const c(42.42f);
	FixedPointNbr	const d(b);

	a = FixedPointNbr (1234.4321f);
	
	std::cout << BLUE << "a nbr is : " << a.getRawBits() << DEFAULT_COLOR << std::endl;
	std::cout << GREEN << "b nbr is : " << b.getRawBits() << DEFAULT_COLOR << std::endl;
	std::cout << YELLOW << "c nbr is : " << c.getRawBits() << DEFAULT_COLOR << std::endl;
	std::cout << RED << "d nbr is : " << d.getRawBits() << DEFAULT_COLOR << std::endl;

	std::cout << BLUE << "a nbr is : " << a.toInt() << " as integer" DEFAULT_COLOR << std::endl;
	std::cout << GREEN << "b nbr is : " << b.toInt() << " as integer" << DEFAULT_COLOR << std::endl;
	std::cout << YELLOW << "c nbr is : " << c.toInt() << " as integer" << DEFAULT_COLOR << std::endl;
	std::cout << RED << "d nbr is : " << d.toInt() << " as integer" << DEFAULT_COLOR << std::endl;
}