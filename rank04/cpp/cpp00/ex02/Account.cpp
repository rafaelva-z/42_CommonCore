/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:03:41 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/06 10:42:54 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int initial_deposit)
{
	_accountIndex = (_nbAccounts++) - 1;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount -= _amount;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();

}

void	Account::makeDeposit(int deposit)
{
	_totalAmount += deposit;
	_amount += deposit;
	_totalNbDeposits += 1;
	_nbDeposits += 1;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_totalNbWithdrawals += 1;
	_nbWithdrawals += 1;
	return (0); // if condition check amount
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
	//std::cout << "index:" << _accountIndex << ";";
	//std::cout << "amount:" << _amount << ";";
	//std::cout << "deposits:" << _nbDeposits << ";";
	//std::cout << "withdrawals:" << _nbWithdrawals << ";" << std::endl
}
