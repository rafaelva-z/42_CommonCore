/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:27:19 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/29 17:16:27 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	ClapTrap::_name = "DefName_clap_name";
	DiamondTrap::_name = "DefName";
	_hitPoints = 100;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << _name << " default constructor." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : FragTrap(name), ScavTrap(name)
{
	ClapTrap::_name = name + "_clap_name";
	DiamondTrap::_name = name;
	_hitPoints = ScavTrap::scavHP;
	_attackDamage = ScavTrap::scavAD;
	std::cout << "DiamondTrap " << _name << " name constructor." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : FragTrap(other), ScavTrap(other)
{
	if (this == &other)
		return ;
	*this = other;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this == &other)
		return (*this);
	DiamondTrap::_name = other.DiamondTrap::_name;
	ClapTrap::_name = other.ClapTrap::_name;
	_hitPoints = other._hitPoints;
	_attackDamage = other._attackDamage;
	_energyPoints = other._energyPoints;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " default destructor." << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap Name:\t" << _name << std::endl;
	std::cout << "ClapTrap Name:\t\t" << ClapTrap::_name << std::endl;
}