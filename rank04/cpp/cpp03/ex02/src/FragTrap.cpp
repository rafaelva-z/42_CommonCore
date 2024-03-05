/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:16:40 by rvaz              #+#    #+#             */
/*   Updated: 2024/03/05 21:28:49 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap " << _name << " default constructor." << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap " << _name << " name constructor." << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " default destructor." << std::endl;
}

void	FragTrap::attack(ClapTrap &target)
{
	if (isDead() || isTired())
		return ;
	attack(target.getName());
	target.takeDamage(_attackDamage);
}

void	FragTrap::attack(const std::string &target)
{
	if (isDead() || isTired())
		return ;
	std::cout	<< "FragTrap " << _name << " attacks " << target
				<< " causing " << _attackDamage << " points of damage!"
				<< std::endl;
	_energyPoints--;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests at least one high five." << std::endl;
}