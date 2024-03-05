/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:16:40 by rvaz              #+#    #+#             */
/*   Updated: 2024/03/05 21:28:36 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap " << _name << " default constructor." << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << _name << " name constructor." << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " default destructor." << std::endl;
}
void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(ClapTrap &target)
{
	if (isDead() || isTired())
		return ;
	attack(target.getName());
	target.takeDamage(_attackDamage);
}

void	ScavTrap::attack(const std::string &target)
{
	if (isDead() || isTired())
		return ;
	std::cout	<< "ScavTrap " << _name << " attacks " << target
				<< " causing " << _attackDamage << " points of damage!"
				<< std::endl;
	_energyPoints--;
}
