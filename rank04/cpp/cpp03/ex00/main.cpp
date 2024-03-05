/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:59 by rvaz              #+#    #+#             */
/*   Updated: 2024/03/05 23:02:11 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	bob("Bob");
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
