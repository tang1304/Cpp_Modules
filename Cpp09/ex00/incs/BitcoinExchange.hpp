/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:28:54 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/20 10:02:30 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

# define RED "\033[31m"
# define CLEAR "\033[0m"

class BitcoinExchange{
private:

	std::map<std::string , float>	_btcPrices;

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	void		readUserFile(std::string fileName);
	std::string	checkDate(std::string content);
	int			checkMultiplier(std::string content);
	int			yearCheck(std::string year);
	int			monthCheck(std::string month);
	int			dayCheck(std::string day, int month, int year);
};

#endif