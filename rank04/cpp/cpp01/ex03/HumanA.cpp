/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:02:21 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/11 19:15:11 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon.getType() << std::endl;
}
void	HumanA::setWeapon(Weapon &weapon)
{
	_weapon = weapon;
}
