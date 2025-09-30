/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:08:24 by nefimov           #+#    #+#             */
/*   Updated: 2025/09/30 18:08:24 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>
/*
// Get timestamp filename for .log file
static std::string getTimestampStringFname() {
	std::time_t now = std::time(0);
	std::tm* localtm = std::localtime(&now);
	std::stringstream ss;
	ss << 1900 + localtm->tm_year
		<< std::setw(2) << std::setfill('0') << 1 + localtm->tm_mon
		<< std::setw(2) << std::setfill('0') << localtm->tm_mday
		<< "_"
		<< std::setw(2) << std::setfill('0') << localtm->tm_hour
		<< std::setw(2) << std::setfill('0') << localtm->tm_min
		<< std::setw(2) << std::setfill('0') << localtm->tm_sec
		<< ".log";
	return ss.str();
}

// Redirect cout to file
static std::ofstream account_log_stream(getTimestampStringFname().c_str());
struct CoutRedirector {
	CoutRedirector() { std::cout.rdbuf(account_log_stream.rdbuf()); }
	~CoutRedirector() { std::cout.rdbuf(orig_buf); }
	static std::streambuf* orig_buf;
};
std::streambuf* CoutRedirector::orig_buf = std::cout.rdbuf();
static CoutRedirector redirector;
*/

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	_displayTimestamp();
	std::cout <<
		"index:"	<< _accountIndex	<< ";" <<
		"amount:"	<< _amount			<< ";" <<
		"created"	<< std::endl;
}

Account::~Account ( void ) {
	_nbAccounts -= 1;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	
	_displayTimestamp();
	std::cout <<
		"index:"	<< _accountIndex	<< ";" <<
		"amount:"	<< _amount			<< ";" <<
		"closed"	<< std::endl;
}

int		Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int		Account::getTotalAmount( void ) {
	return _totalAmount;
}

int		Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int		Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout <<
		"accounts:"		<< _nbAccounts			<< ";" <<
		"total:"		<< _totalAmount			<< ";" <<
		"deposits:"		<< _totalNbDeposits 	<< ";" <<
		"withdrawals:"	<< _totalNbWithdrawals 	<< std::endl;
}

void	Account::_displayTimestamp( void ) {
	std::time_t now = std::time(0);
	std::tm* localtm = std::localtime(&now);
	std::cout <<
		"[" << 
		1900 + localtm->tm_year  << 
		std::setw(2) << std::setfill('0') << 1 + localtm->tm_mon << 
		std::setw(2) << std::setfill('0') << localtm->tm_mday <<
		"_" <<
		std::setw(2) << std::setfill('0') << localtm->tm_hour << 
		std::setw(2) << std::setfill('0') << localtm->tm_min << 
		std::setw(2) << std::setfill('0') << localtm->tm_sec << 
		"] ";
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout <<
		"index:"		<< _accountIndex	<< ";" <<
		"p_amount:"		<< _amount			<< ";" <<
		"deposit:"		<< deposit			<< ";" ;

	_amount += deposit;
	_totalAmount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;
	
	std::cout <<
		"amount:"		<< _amount		<< ";" <<
		"nb_deposits:"	<< _nbDeposits	<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout <<
		"index:"		<< _accountIndex	<< ";" <<
		"p_amount:"		<< _amount			<< ";" ;
	
	if (withdrawal > _amount) {
		std::cout <<
		"withdrawal:"	<< "refused" 		<< std::endl;
		return (false);
	}
	
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	++_nbWithdrawals;
	++_totalNbWithdrawals;
	
	std::cout <<
		"withdrawal:"		<< withdrawal 		<< ";" <<
		"amount:"			<< _amount			<< ";" <<
		"nb_withdrawals:"	<< _nbWithdrawals	<< std::endl;
	
	return true;
}

int		Account::checkAmount( void ) const {
	return _amount;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout <<
		"index:"		<< _accountIndex	<< ";" <<
		"amount:"		<< _amount			<< ";" <<
		"deposits:"		<< _nbDeposits		<< ";" <<
		"withdrawals:"	<< _nbWithdrawals	<< std::endl;
}