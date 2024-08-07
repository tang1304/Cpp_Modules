/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:28:13 by tgellon           #+#    #+#             */
/*   Updated: 2024/01/05 14:24:37 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	std::ifstream	file;
	std::string		content;
	std::string		key;
	std::string		valueStr;
	float			value;
	size_t			i = 0;

	file.open("data.csv", std::fstream::in);
	if (!file.is_open()){
		throw (std::invalid_argument("Error while trying to open data.csv"));
	}
	while (!file.eof()){
		std::getline(file, content);
		if (content.empty())
			continue ;
		if (content == "date,exchange_rate")
			continue ;
		i = content.find(',');
		key = content.substr(0, i);
		valueStr = content.substr(i + 1, content.size() - i);
		std::istringstream	ss(valueStr);
		ss >> value;
		this->_btcPrices[key] = value;
	}
	file.close();
}

BitcoinExchange::~BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _btcPrices(other._btcPrices){
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other){
		_btcPrices = other._btcPrices;
	}
	return (*this);
}

void	BitcoinExchange::readUserFile(const std::string &fileName){
	std::ifstream	file;
	std::string		content;
	std::string		date;
	float			multiplier;

	file.open(fileName.c_str(), std::fstream::in);
	if (!file.is_open()){
		std::cout << "Error while trying to open " << fileName << std::endl;
		return ;
	}
	while (!file.eof()){
		try{
			std::getline(file, content);
			if (content.empty() || content.find("date | value") != content.npos)
				continue ;
			date = checkDate(content);
			multiplier = checkMultiplier(content);
			result(date, multiplier);
		}
		catch (std::exception &e){
			std::cout << RED << e.what() << CLEAR << std::endl;
		}
	}
}

void	BitcoinExchange::result(const std::string &date, const float &multiplier){
	std::map<std::string, float>::const_iterator	it;
	it = this->_btcPrices.lower_bound(date);
	if (it == this->_btcPrices.end())
		it--;
	else if (it->first != date && it != this->_btcPrices.begin())
		it--;
	std::cout << GREEN << date << " => " << multiplier << " = " << multiplier * it->second << CLEAR << std::endl;
}

float	BitcoinExchange::checkMultiplier(const std::string &content){
	size_t		i = 0;
	std::string	multiplier;
	float		multiplierNb;
	bool		dott = 0;
	bool		space = 0;

	i = content.find('|');
	multiplier = content.substr(i + 2, content.size() - (i + 1));

	std::istringstream	ssMultiplier(multiplier);
	ssMultiplier >> multiplierNb;
	if (ssMultiplier.fail())
		throw (std::invalid_argument("Error in multiplier"));
	for (size_t j = 0; j < multiplier.size(); j++){
		if ((multiplier.c_str()[j] < '0' || multiplier.c_str()[j] > '9') && multiplier.c_str()[j] != ' '){
			if (multiplier.c_str()[j] == '.' && dott == 0)
				dott = 1;
			else if (multiplier.c_str()[0] == '+')
				continue ;
			else if (multiplier.c_str()[0] == '-')
				throw (std::invalid_argument("Error in multiplier, negative number"));
			else if (space == 1)
				throw (std::invalid_argument("Error in multiplier, too many arguments"));
			else
				throw (std::invalid_argument("Error in multiplier, not a float"));
		}
		else if (multiplier.c_str()[j] == ' ')
			space = 1;
		else if (space == 1)
			throw (std::invalid_argument("Error in multiplier, too many arguments"));
	}
	if (multiplierNb < 0 || multiplierNb > 1000)
		throw (std::invalid_argument("Error, multiplier must be between 0 and 1000"));
	return (multiplierNb);
}

std::string	BitcoinExchange::checkDate(std::string &content){
	size_t		i = 0;
	size_t		start = 0;
	std::string	date;
	std::string	year;
	std::string	month;
	std::string	day;
	std::string	pipe;
	struct tm	time;

	i = content.find('|');
	if (i == content.npos)
		throw (std::invalid_argument("Wrong date and value separator"));
	pipe = content.substr(i - 1, 3);
	if (pipe != " | ")
		throw (std::invalid_argument("Wrong date and value separator"));
	if (!strptime(content.c_str(), "%Y-%m-%d |", &time))
		throw (std::invalid_argument("Wrong date format, must be YYYY-MM-DD"));
	i = content.find_first_of('-');
	if (i < 4 || i == content.npos)
		throw (std::invalid_argument("Wrong date format, must be YYYY-MM-DD"));
	start = i - 4;
	year = content.substr(i - 4, 4);
	int	yearNb = yearCheck(year);
	i = content.find('-', i + 1);
	if (i == content.npos)
		throw (std::invalid_argument("Wrong date format, must be YYYY-MM-DD"));
	month = content.substr(i - 2, 2);
	int	monthNb = monthCheck(month);
	day = content.substr(i + 1, 2);
	dayCheck(day, monthNb, yearNb);
	i = content.find('|');
	return (content.substr(start, i - 1));
}

int	BitcoinExchange::yearCheck(std::string year){
	std::istringstream	ssYear(year);
	int					yearNb;

	for (int i = 0; i < 4; i++){
		if (year.c_str()[i] < '0' || year.c_str()[i] > '9')
			throw (std::invalid_argument("Error in year, not an int"));
	}
	ssYear >> yearNb;
	if (ssYear.fail())
		throw (std::invalid_argument("Error in year, not an int"));
	if (yearNb < 2009)
		throw (std::invalid_argument("Error, the values start from 2009-01-02"));
	if (yearNb > 2022)
		throw (std::invalid_argument("Error, the database stops in 2022"));
	return (yearNb);
}

int	BitcoinExchange::monthCheck(std::string month){
	std::istringstream	ssMonth(month);
	int					monthNb;

	for (int i = 0; i < 2; i++){
		if (month.c_str()[i] < '0' || month.c_str()[i] > '9')
			throw (std::invalid_argument("Error in month, not a double digit int"));
	}
	ssMonth >> monthNb;
	if (ssMonth.fail())
		throw (std::invalid_argument("Error in month, not a double digit int"));
	if (monthNb < 1 || monthNb > 12)
		throw (std::invalid_argument("Error, not a valid month"));
	return (monthNb);
}

void	BitcoinExchange::dayCheck(std::string day, int month, int year){
	std::istringstream	ssDay(day);
	int					dayNb;

	for (int i = 0; i < 2; i++){
		if (day.c_str()[i] < '0' || day.c_str()[i] > '9')
			throw (std::invalid_argument("Error in day, not a double digit int"));
	}
	ssDay >> dayNb;
	if (ssDay.fail())
		throw (std::invalid_argument("Error in day, not a double digit int"));
	if (dayNb < 1 || dayNb > 31)
		throw (std::invalid_argument("Error, not a valid day"));
	if (dayNb == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
		throw (std::invalid_argument("Error, there are not 31 days in this month"));
	if (dayNb == 30 && month == 2)
		throw (std::invalid_argument("Error, there are not 30 days in February"));
	if (dayNb > 28 && month == 2 && year % 4 != 0)
		throw (std::invalid_argument("Error, there are not 29 days in February this year"));
	if (year == 2009 && month == 01 && dayNb == 01)
		throw (std::invalid_argument("Error, the values start from 2009-01-02"));
}
