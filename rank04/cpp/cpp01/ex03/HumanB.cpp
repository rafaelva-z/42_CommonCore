/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:02:24 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/11 19:29:28 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name): _name(name), _weapon(NULL)
{}

HumanB::~HumanB() {}

void	HumanB::attack()
{
	if (!_weapon)
		std::cout << _name << " is unarmed and defenseless";
	else
	{
		std::cout << _name << " attacks with their ";
		std::cout << _weapon->getType();
	}
	std::cout << std::endl;
}
void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void	HumanB::setWeapon(void)
{
	_weapon = NULL;
}