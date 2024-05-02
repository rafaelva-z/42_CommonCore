/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:11:11 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/02 18:24:37 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("CharName")
{
	std::cout << name << " Character Default Constructor" << std::endl;
	for (int i = 0; i < MATERIA_SLOTS; i++)
		materia_inventory[i] = 0;
}

Character::Character(const Character &other)
{
	if (this == &other)
		return ;
	for (int i = 0; i < MATERIA_SLOTS; i++)
		materia_inventory[i] = 0;
	std::cout << other.name << "Character Copy Constructor" << std::endl;
	*this = other;
}

Character::Character(const std::string &param_name) : name(param_name)
{
	std::cout << param_name << "Character Name Constructor" << std::endl;
	for (int i = 0; i < MATERIA_SLOTS; i++)
		materia_inventory[i] = 0;
}

Character &Character::operator=(const Character &other) 
{
	std::cout << name << " Character Assignment operator" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < MATERIA_SLOTS; i++)
	{
		if (materia_inventory[i])
		{
			delete (materia_inventory[i]);
			materia_inventory[i] = 0;
		}
		if (other.materia_inventory[i])
			materia_inventory[i] = other.materia_inventory[i]->clone();
	}
	name = other.name;
	return (*this);
}

Character::~Character() 
{
	std::cout << name << " Character Destructor" << std::endl;
	for (int i = 0; i < MATERIA_SLOTS; i++)
		if (materia_inventory[i])
			delete materia_inventory[i];
}

std::string const & Character::getName() const 
{
	return (name);
}

void Character::equip(AMateria* m) 
{
	if (!m)
	{
		std::cout << name << ": cannot equip, materia doesn't exist" << std::endl;
		return ;
	}
	for (int i = 0; i < MATERIA_SLOTS; i++)
	{
		if (!materia_inventory[i])
		{
			materia_inventory[i] = m;
			std::cout << name << ": materia equipped" << std::endl;
			return ;
		}
	}
		std::cout << name << ": cannot equip, inventory full" << std::endl;
	delete m;
}

void Character::unequip(int idx) 
{
	if (idx < 0 || idx >= MATERIA_SLOTS || !materia_inventory[idx])
	{
		std::cout << name << ": cannot unequip" << std::endl;
		return ;
	}
	materia_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target) 
{
	if (idx < 0 || idx >= MATERIA_SLOTS || !materia_inventory[idx])
	{
		std::cout << name << ": cannot use materia" << std::endl;
		return ;
	}
	materia_inventory[idx]->use(target);
}
