/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:03:41 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/06 13:33:54 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <iostream>
#include <string>
#include "./Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = (_nbAccounts++);
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::_displayTimestamp()
{
  	time_t rawtime;
  	struct tm * ptm;
	
	time(&rawtime);
	ptm = gmtime(&rawtime);
	std::cout << "[";
	std::cout << ptm->tm_year + 1900;
	if (ptm->tm_mon <= 9)
		std::cout << 0;
	std::cout << ptm->tm_mon + 1;
	if (ptm->tm_mday <= 9)
		std::cout << 0;
	std::cout << ptm->tm_mday << "_";
	std::cout << ptm->tm_hour;
	if (ptm->tm_min <= 9)
		std::cout << 0;
	std::cout << ptm->tm_min;
	if (ptm->tm_sec <= 9)
		std::cout << 0;
	std::cout << ptm->tm_sec << "] ";
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	_nbDeposits += 1;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	_amount += deposit;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	if (_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (0);
	}
	std::cout << withdrawal << ";";
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	_nbWithdrawals += 1;
	_amount -= withdrawal;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return (1);
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}
