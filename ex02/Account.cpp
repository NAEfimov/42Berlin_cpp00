/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:08:24 by nefimov           #+#    #+#             */
/*   Updated: 2025/09/30 17:02:12 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Account::Account( void ) {}

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
	// std::cout << "call Account::displayAccountsInfos( void )" << std::endl;
	// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
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
// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	_displayTimestamp();
	std::cout <<
		"index:"		<< _accountIndex	<< ";" <<
		"p_amount:"		<< _amount			<< ";" <<
		"deposit:"		<< deposit			<< ";" ;

	_amount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;
	
	std::cout <<
		"amount:"		<< _amount		<< ";" <<
		"nb_deposits:"	<< _nbDeposits	<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
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
	// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout <<
		"index:"		<< _accountIndex	<< ";" <<
		"amount:"		<< _amount			<< ";" <<
		"deposits:"		<< _nbDeposits		<< ";" <<
		"withdrawals:"	<< _nbWithdrawals	<< std::endl;
}