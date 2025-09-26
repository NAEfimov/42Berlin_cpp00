/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:08:24 by nefimov           #+#    #+#             */
/*   Updated: 2025/09/26 20:38:35 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

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
	std::cout << 	"index:"	<< _accountIndex <<
					";amount:"	<< _amount <<
					";created"	<< std::endl;
}

Account::~Account ( void ) {
	_nbAccounts -= 1;
	_totalAmount += _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
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
	std::cout << "call Account::displayAccountsInfos( void )" << std::endl;
}

void	Account::_displayTimestamp( void ) {
	std::cout << "[timestamp] ";
}

void	makeDeposit( int deposit ) {
	
}

bool	makeWithdrawal( int withdrawal ) {
	return true;
}

int		Account::checkAmount( void ) const {
	return _amount;
}

void	Account::displayStatus( void ) const {
	
}