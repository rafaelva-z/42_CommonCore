/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:59 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/29 16:01:58 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int	main(void)
{
	ScavTrap	bob("Bob");
	ClapTrap	harry("Harry");
	std::cout << "garry" << std::endl;
	
	std::cout << "-TrapStats-" << std::endl;
	harry.printStats();
	bob.printStats();
	
	std::cout << std::endl << "-LotsOfAttacks-" << std::endl;
	bob.attack("The World");
	bob.setAttackDamage(5);
	bob.attack(harry);
	harry.printStats();
	harry.beRepaired(1);
	for (int i = 0; i < 9; i++)
		bob.attack(harry);
	bob.beRepaired(5);
	harry.beRepaired(5);

	ScavTrap	garry (bob);
	garry.setName("Garry");
	
	std::cout << std::endl << "-TrapStats-" << std::endl;
	harry.printStats();
	bob.printStats();
	garry.printStats();

	std::cout << std::endl << "-Guard Gate-" << std::endl;
	bob.guardGate();
	
	std::cout << std::endl << "-Destructors-" << std::endl;
}
