/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:43:59 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/08 10:50:25 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(){
	Fixed			a;
	Fixed const		b(Fixed(5.05f) * Fixed(2));
	
	std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a * b: " << a * b << std::endl;
    std::cout << "b * a: " << b * a << std::endl;
    std::cout << "a / b: " << a / b << std::endl;
    std::cout << "b / a: " << b / a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    Fixed c = a + b;
    std::cout << "c: " << c << std::endl;
    std::cout << "c - a: " << c - a << std::endl;
	
	std::cout << "max: " << Fixed::max(a, b) << std::endl;
	std::cout << "min: " << Fixed::min(a, b) << std::endl;
	
	return (0);
	
}