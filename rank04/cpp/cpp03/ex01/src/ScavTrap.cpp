/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:16:40 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/29 16:00:05 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap " << _name << " default constructor." << std::endl;
	ClapTrap::_hitPoints = 100;
	ClapTrap::_energyPoints = 50;
	ClapTrap::_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << _name << " name constructor." << std::endl;
	ClapTrap::_hitPoints = 100;
	ClapTrap::_energyPoints = 50;
	ClapTrap::_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << _name << " Copy constructor." << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap " << _name << " Assign operator." << std::endl;
	if (this == &other)
		return (*this);
	ClapTrap::_name = other._name;
	ClapTrap::_hitPoints = other._hitPoints;
	ClapTrap::_energyPoints = other._energyPoints;
	ClapTrap::_attackDamage = other._attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " Destructor." << std::endl;
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
	ClapTrap::_energyPoints--;
}
