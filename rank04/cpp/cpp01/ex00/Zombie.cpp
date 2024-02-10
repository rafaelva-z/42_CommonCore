/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:26:09 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/10 13:02:58 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name_c)
{
	name = name_c;
}

Zombie::~Zombie()
{
	std::cout << "~" << this->name << " Destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

