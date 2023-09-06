/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:39:30 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/06 13:40:02 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main()
{
	int hordeSize;

	hordeSize = 5;
	Zombie* horde;

	horde = zombieHorde(hordeSize, "Zombie Guy");
	for (int i = 0; i < hordeSize; i++)
	{
		horde[i].announce();	
	}
	delete[] horde;
}