/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:16:40 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/29 16:51:09 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap " << _name << " Default constructor." << std::endl;
	ClapTrap::_hitPoints = 100;
	ClapTrap::_energyPoints = 100;
	ClapTrap::_attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap " << _name << " Name constructor." << std::endl;
	ClapTrap::_hitPoints = 100;
	ClapTrap::_energyPoints = 100;
	ClapTrap::_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " Copy constructor." << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap " << _name << " Assign operator." << std::endl;
	if (this == &other)
		return (*this);
	ClapTrap::_name = other._name;
	ClapTrap::_hitPoints = other._hitPoints;
	ClapTrap::_energyPoints = other._energyPoints;
	ClapTrap::_attackDamage = other._attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " Destructor." << std::endl;
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
	ClapTrap::_energyPoints--;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " positively requests at least one high five." << std::endl;
}