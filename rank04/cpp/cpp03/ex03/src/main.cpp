/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:59 by rvaz              #+#    #+#             */
/*   Updated: 2024/03/05 21:08:35 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

int	main(void)
{
	ScavTrap	bob("Bob");
	ClapTrap	harry("Harry");
	
	std::cout << "Atack Tests" << std::endl;
	harry.printStats();
	bob.attack("The World");
	bob.setAttackDamage(5);
	bob.attack(harry);
	harry.printStats();
	harry.beRepaired(1);
	for (int i = 0; i < 9; i++)
		bob.attack(harry);
	bob.beRepaired(5);
	harry.beRepaired(5);
}
