/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:01:10 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/30 09:18:23 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ){
	static int	id = 0;

	this->_accountIndex = id;
	id++;
	this->_amount = initial_deposit;
	this->_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount \
	<< ";created" << std::endl;
}

Account::~Account( void ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount \
	<< ";closed" << std::endl;
}

int	Account::getNbAccounts( void ){
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ){
	int	p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << p_amount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	int	p_amount = this->_amount;
	_displayTimestamp();
	if (p_amount < withdrawal){
		std::cout << "index:" << this->_accountIndex;
		std::cout << ";p_amount:" << p_amount;
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << p_amount;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawal:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount( void ) const{
	return (this->_amount);
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "accounts:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void ){
	std::time_t	timestamp;
	std::tm		*localTime;

	timestamp = std::time(NULL);
	localTime = std::localtime(&timestamp);
	std::cout << "[" << localTime->tm_year << localTime->tm_mon << localTime->tm_mday \
	<< "_" << localTime->tm_hour << localTime->tm_min << localTime->tm_sec << "] ";
}
