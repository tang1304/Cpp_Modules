/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:28:13 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/15 15:34:46 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
}

BitcoinExchange::~BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other){
		;
	}
	return (*this);
}

