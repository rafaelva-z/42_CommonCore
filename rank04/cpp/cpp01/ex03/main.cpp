/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:59:29 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/11 19:22:42 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main()
{
	{
		std::cout << "= Test 1 - HumanA" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		std::cout << std::endl << "= Test 2 - HumanB" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		std::cout << std::endl << "= Test 3 - HumanB" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB rob("Rob");
		rob.attack();
		rob.setWeapon(club);
		rob.attack();
		rob.setWeapon();
		rob.attack();
	}
	return 0;
}
