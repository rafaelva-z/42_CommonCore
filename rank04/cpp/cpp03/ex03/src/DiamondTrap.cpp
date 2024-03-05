/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:27:19 by rvaz              #+#    #+#             */
/*   Updated: 2024/03/05 23:35:21 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	_name = "Default dTrap";
	std::cout << "DiamondTrap " << _name << " default constructor." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : FragTrap(name + "_name")
{
	_energyPoints = ScavTrap::_energyPoints;
	_hitPoints = FragTrap::_hitPoints;
	_attackDamage = FragTrap::_attackDamage;
	//ClapTrap::_name = name + "_clap_name";
	std::cout << "DiamondTrap " << _name << " name constructor." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other) {}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " default destructor." << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << _name << std::endl;
	std::cout << ClapTrap::_name << std::endl;
}