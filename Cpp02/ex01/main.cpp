/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:43:59 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/09 12:55:33 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(){
	Fixed	a;
	Fixed	const b(10);
	Fixed	const c(42.42f);
	Fixed	const d(b);

	a = Fixed (1234.4321f);

	std::cout << BLUE << "a nbr is : " << a << DEFAULT_COLOR << std::endl;
	std::cout << GREEN << "b nbr is : " << b << DEFAULT_COLOR << std::endl;
	std::cout << GREEN << "b raw is : " << b.getRawBits() << DEFAULT_COLOR << std::endl;
	std::cout << YELLOW << "c nbr is : " << c << DEFAULT_COLOR << std::endl;
	std::cout << YELLOW << "c raw is : " << c.getRawBits() << DEFAULT_COLOR << std::endl;
	std::cout << RED << "d nbr is : " << d << DEFAULT_COLOR << std::endl;

	std::cout << BLUE << "a nbr is : " << a.toInt() << " as integer" DEFAULT_COLOR << std::endl;
	std::cout << GREEN << "b nbr is : " << b.toInt() << " as integer" << DEFAULT_COLOR << std::endl;
	std::cout << YELLOW << "c nbr is : " << c.toInt() << " as integer" << DEFAULT_COLOR << std::endl;
	std::cout << RED << "d nbr is : " << d.toInt() << " as integer" << DEFAULT_COLOR << std::endl;
}