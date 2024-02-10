/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:02:27 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/10 13:30:05 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

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
