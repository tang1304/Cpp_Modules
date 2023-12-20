/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:28:13 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/20 11:49:36 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	std::ifstream	file;
	std::string		content;
	std::string		key;
	std::string		valueStr;
	float			value;
	size_t			i = 0;

	file.open("data.csv", std::fstream::in);
	if (!file.is_open()){
		std::cout << "Error while trying to open data.csv" << std::endl;
		return ;
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

void	BitcoinExchange::readUserFile(std::string userFile){
	std::ifstream	file;
	std::string		content;
	std::string		date;
	int				multiplier;

	file.open(userFile.c_str(), std::fstream::in);
	if (!file.is_open()){
		std::cout << "Error while trying to open " << userFile << std::endl;
		return ;
	}
	while (!file.eof()){
		try{
			std::getline(file, content);
			if (content.empty() || content.find("date | value") != content.npos){
std::cout << "Line OK" << std::endl; // del
				continue ;
			}
			date = checkDate(content);
			multiplier = checkMultiplier(content);
std::cout << "Line OK" << std::endl; // del
		}
		catch (std::exception &e){
			std::cout << RED << e.what() << CLEAR << std::endl;
		}
	}
}

int	BitcoinExchange::checkMultiplier(std::string content){
	size_t		i = 0;
	std::string	multiplier;
	float		multiplierNb;
	bool		dott = 0;

	i = content.find('|');
	multiplier = content.substr(i + 2, content.size() - (i + 1));
	for (size_t j = 0; j < multiplier.size(); j++){
		if (multiplier.c_str()[j] < '0' || multiplier.c_str()[j] > '9'){
			if (multiplier.c_str()[j] == '.' && dott == 0)
				dott = 1;
			else
				throw (std::invalid_argument("Error in multiplier, not a float"));
		}
	}
	std::istringstream	ssMultiplier(multiplier);
	ssMultiplier >> multiplierNb;
	if (ssMultiplier.fail())
		throw (std::invalid_argument("Error in multiplier, not a float"));
	if (multiplierNb < 0 || multiplierNb > 1000)
		throw (std::invalid_argument("Error, multiplier must be between 0 and 1000"));
std::cout << "multiplier: " << multiplierNb << std::endl; // del
	return (multiplierNb);
}

std::string	BitcoinExchange::checkDate(std::string content){
	size_t		i = 0;
	std::string	date;
	std::string	year;
	std::string	month;
	std::string	day;
	std::string pipe;

	i = content.find('|');
	pipe = content.substr(i - 1, 3);
	if (pipe != " | ")
		throw (std::invalid_argument("Wrong date and value separator"));
	i = content.find_first_of('-');
	if (i < 4)
		throw (std::invalid_argument("Wrong date format, must be YYYY-MM-DD"));
	year = content.substr(i - 4, 4);
std::cout << "year:" << year; //del
	int	yearNb = yearCheck(year);
	i = content.find('-', i + 1);
	month = content.substr(i - 2, 2);
std::cout << " month:" << month; //del
	int	monthNb = monthCheck(month);
	day = content.substr(i + 1, 2);
std::cout << " day:" << day << std::endl; //del
	int	dayNb = dayCheck(day, monthNb, yearNb);
	(void)dayNb;
	i = content.find('|');
	return (content.substr(0, i - 1));
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
		throw (std::invalid_argument("Error, year is earlier than 2009"));
	return (yearNb);
}

int	BitcoinExchange::monthCheck(std::string month){
	std::istringstream	ssMonth(month);
	int					monthNb;

	for (int i = 0; i < 2; i++){
		if (month.c_str()[i] < '0' || month.c_str()[i] > '9')
			throw (std::invalid_argument("Error in month, not an int"));
	}
	ssMonth >> monthNb;
	if (ssMonth.fail())
		throw (std::invalid_argument("Error in month, not an int"));
	if (monthNb < 1 || monthNb > 12)
		throw (std::invalid_argument("Error, not a valid month"));
	return (monthNb);
}

int	BitcoinExchange::dayCheck(std::string day, int month, int year){
	std::istringstream	ssDay(day);
	int					dayNb;

	for (int i = 0; i < 2; i++){
		if (day.c_str()[i] < '0' || day.c_str()[i] > '9')
			throw (std::invalid_argument("Error in day, not an int"));
	}
	ssDay >> dayNb;
	if (ssDay.fail())
		throw (std::invalid_argument("Error in day, not an int"));
	if (dayNb < 1 || dayNb > 31)
		throw (std::invalid_argument("Error, not a valid day"));
	if (dayNb == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
		throw (std::invalid_argument("Error, there are not 31 days in this month"));
	if (dayNb == 30 && month == 2)
		throw (std::invalid_argument("Error, there are not 30 days in February"));
	if (dayNb > 28 && month == 2 && year % 4 != 0)
		throw (std::invalid_argument("Error, there are not 29 days in February this year"));
	return (dayNb);
}
