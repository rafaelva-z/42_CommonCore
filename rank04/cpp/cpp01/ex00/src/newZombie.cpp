/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:39:42 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/04 20:03:19 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie*	Zombie::newZombie(std::string name)
{
	Zombie* zombie;
	
	zombie = new Zombie;
	zombie->name = name;
	return (zombie);
}
