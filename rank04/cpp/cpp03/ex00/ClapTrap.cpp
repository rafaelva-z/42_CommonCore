/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:55 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/11 17:59:52 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//	Orthodox Canonical Form
ClapTrap::ClapTrap(const std::string& name) : name(name)
{
	std::cout << "ClapTrap Default constructor called." << std::endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy constructor called." << std::endl;
	*this = other;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy Assignment operator called." << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called." << std::endl;
}

//	Getters
const std::string&	ClapTrap::getName(void)
{
	return (this->name);
}
int			ClapTrap::getHitPoints(void)
{
	return (this->hitPoints);
}
int			ClapTrap::getEnergyPoints(void)
{
	return (this->energyPoints);
}
int			ClapTrap::getAttackDamage(void)
{
	return (this->attackDamage);
}
//	Setters
void	ClapTrap::setName(const std::string& name)
{
	this->name = name;
}
void	ClapTrap::setHitPoints(int hitPoints)
{
	this->hitPoints = hitPoints;
}
void	ClapTrap::setEnergyPoints(int energyPoints)
{
	this->energyPoints = energyPoints;
}
void	ClapTrap::setAttackDamage(int attackDamage)
{
	this->attackDamage = attackDamage;
}

//	Actions
void	ClapTrap::attack(const std::string &target)
{
	if (isDead() || isTired())
		return ;
	std::cout	<< "ClapTrap " << this->name << " attacks " << target
				<< " causing " << this->attackDamage << " points of damage!"
				<< std::endl;
	this->energyPoints--;
}

void	ClapTrap::attack(ClapTrap &target)
{
	if (isDead() || isTired())
		return ;
	this->attack(target.name);
	target.takeDamage(this->attackDamage);
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (isDead() || isTired())
		return ;
	std::cout	<< "ClapTrap " << this->name << " is repaired for "
				<< amount << " hit points!" << std::endl;
	this->hitPoints += amount;
	this->energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (isDead())
	{
		std::cout	<< "ClapTrap " << this->name << "'s dead body was hit for "
					<< amount << " points of damage!" << std::endl;
		return ;
	}
	ClapTrap::hitPoints -= amount;
	std::cout	<< "ClapTrap " << this->name << " takes "
				<< amount << " points of damage!" << std::endl;
	if (isDead())
	{
		ClapTrap::hitPoints = 0;
		printDeath();
	}
}

//	Checks
bool	ClapTrap::isDead()
{
	if (this->hitPoints <= 0)
		return true;
	return false;
}

bool	ClapTrap::isTired()
{
	if (this->energyPoints <= 0)
	{
		printTired();
		return true;
	}
	return false;
}

//	Prints
void	ClapTrap::printDeath(void)
{
	std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
}
void	ClapTrap::printTired(void)
{
	std::cout << "ClapTrap " << this->name << " is tired!" << std::endl;
}

void	ClapTrap::printStats(void)
{
	std::string cyan = "\033[96m";
	std::string red = "\033[0;31m";
	std::string blue = "\033[0;34m";
	std::string reset = "\033[0m";

	std::cout	<< blue << "ClapTrap " << this->name << " stats: " << std::endl
				<< cyan << "Hit Points: " << this->hitPoints << std::endl
				<< "Energy Points: " << this->energyPoints << std::endl
				<< "Attack Damage: " << this->attackDamage << reset << std::endl;
}
