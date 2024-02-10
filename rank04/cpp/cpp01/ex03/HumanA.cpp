/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:02:21 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/10 15:45:46 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) // : _weapon(myWeapon) what is this?
{
	this->name = name;
	this->weapon = weapon; 
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon.getType() << std::endl;
}
void	HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = weapon;
}
