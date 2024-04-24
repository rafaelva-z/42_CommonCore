/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:59 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/24 19:23:38 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int	main(void)
{
	ScavTrap	bob("Bob");
	ClapTrap	harry("Harry");
	std::cout << "garry" << std::endl;
	ScavTrap	garry;
	
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
	bob.guardGate();
}
