/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:28:54 by tgellon           #+#    #+#             */
/*   Updated: 2024/01/04 13:35:23 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "btc.h"

class BitcoinExchange{
private:

	std::map<std::string , float>	_btcPrices;

	void		result(const std::string &date, const float &multiplier);
	std::string	checkDate(std::string &content);
	float		checkMultiplier(const std::string &content);
	int			yearCheck(std::string year);
	int			monthCheck(std::string month);
	void		dayCheck(std::string day, int month, int year);
	
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	void		readUserFile(const std::string &fileName);
};

#endif