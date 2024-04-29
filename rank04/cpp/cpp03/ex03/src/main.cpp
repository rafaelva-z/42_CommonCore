/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:59 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/29 17:19:34 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"


int	main(void)
{
	std::cout << std::endl << "-Constructors-" << std::endl;
	DiamondTrap Diam("Diamie");
	DiamondTrap D2("Carlos");

	std::cout << std::endl << "-Stats-" << std::endl;
	Diam.whoAmI();
	Diam.printStats();

	D2.whoAmI();
	D2.printStats();

	std::cout << std::endl << "-Destructors-" << std::endl;
}
