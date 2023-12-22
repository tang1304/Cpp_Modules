/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:28:54 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/22 10:38:45 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "BitcoinExchange.h"

class BitcoinExchange{
private:

	std::map<std::string , float>	_btcPrices;

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	void		readUserFile(const std::string &fileName);
	void		result(const std::string &date, const float &multiplier);
	std::string	checkDate(std::string &content);
	float		checkMultiplier(const std::string &content);
	int			yearCheck(std::string year);
	int			monthCheck(std::string month);
	int			dayCheck(std::string day, int month, int year);
};

#endif