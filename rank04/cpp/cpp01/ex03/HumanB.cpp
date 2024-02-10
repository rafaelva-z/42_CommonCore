/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:02:24 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/10 15:41:17 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB(){}

void	HumanB::attack()
{
	if (!this->weapon)
		std::cout << this->name << " is unarmed and defenseless";
	else
	{
		std::cout << this->name << " attacks with their ";
		std::cout << this->weapon->getType();
	}
	std::cout << std::endl;
}
void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::setWeapon(void)
{
	this->weapon = NULL;
}