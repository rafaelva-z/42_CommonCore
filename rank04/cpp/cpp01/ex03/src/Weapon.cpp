/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:02:27 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/09 20:52:59 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::Weapon(void)
{
}

Weapon::~Weapon(void)
{
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string &Weapon::getType(void)
{
	return (type);
}
