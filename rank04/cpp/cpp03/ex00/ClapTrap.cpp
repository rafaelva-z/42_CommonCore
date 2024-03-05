/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:55 by rvaz              #+#    #+#             */
/*   Updated: 2024/03/05 20:51:25 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//	Orthodox Canonical Form

ClapTrap::ClapTrap()
	: _name("Default Name")
	, _hitPoints(10)
	, _energyPoints(10)
	, _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) 
	: _name(name)
	, _hitPoints(10)
	, _energyPoints(10)
	, _attackDamage(0)
{
	std::cout << "ClapTrap name constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy constructor called." << std::endl;
	*this = other;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy Assignment operator called." << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called." << std::endl;
}

//	Getters
const std::string&	ClapTrap::getName(void) const
{
	return (_name);
}
int			ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}
int			ClapTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}
int			ClapTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}
//	Setters
void	ClapTrap::setName(const std::string& name)
{
	_name = name;
}
void	ClapTrap::setHitPoints(int hitPoints)
{
	_hitPoints = hitPoints;
}
void	ClapTrap::setEnergyPoints(int energyPoints)
{
	_energyPoints = energyPoints;
}
void	ClapTrap::setAttackDamage(int attackDamage)
{
	_attackDamage = attackDamage;
}

//	Actions
void	ClapTrap::attack(const std::string &target)
{
	if (isDead() || isTired())
		return ;
	std::cout	<< "ClapTrap " << _name << " attacks " << target
				<< " causing " << _attackDamage << " points of damage!"
				<< std::endl;
	_energyPoints--;
}

void	ClapTrap::attack(ClapTrap &target)
{
	if (isDead() || isTired())
		return ;
	attack(target._name);
	target.takeDamage(_attackDamage);
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (isDead() || isTired())
		return ;
	std::cout	<< "ClapTrap " << _name << " is repaired for "
				<< amount << " hit points!" << std::endl;
	_hitPoints += amount;
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (isDead())
	{
		std::cout	<< "ClapTrap " << _name << "'s dead body was hit for "
					<< amount << " points of damage!" << std::endl;
		return ;
	}
	_hitPoints -= amount;
	std::cout	<< "ClapTrap " << _name << " takes "
				<< amount << " points of damage!" << std::endl;
	if (isDead())
	{
		_hitPoints = 0;
		printDeath();
	}
}

//	Checks
bool	ClapTrap::isDead()
{
	if (_hitPoints <= 0)
		return true;
	return false;
}

bool	ClapTrap::isTired()
{
	if (_energyPoints <= 0)
	{
		printTired();
		return true;
	}
	return false;
}

//	Prints
void	ClapTrap::printDeath(void)
{
	std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
}
void	ClapTrap::printTired(void)
{
	std::cout << "ClapTrap " << _name << " is tired!" << std::endl;
}

void	ClapTrap::printStats(void)
{
	std::string cyan = "\033[96m";
	std::string red = "\033[0;31m";
	std::string blue = "\033[0;34m";
	std::string reset = "\033[0m";

	std::cout	<< blue << "ClapTrap " << _name << " stats: " << std::endl
				<< cyan << "Hit Points: " << _hitPoints << std::endl
				<< "Energy Points: " << _energyPoints << std::endl
				<< "Attack Damage: " << _attackDamage << reset << std::endl;
}
