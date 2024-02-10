/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:39:30 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/10 13:22:08 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int hordeSize;

	hordeSize = 5;
	Zombie* horde;

	horde = zombieHorde(hordeSize, "Zombie Guy");
	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();
	delete[] horde;
}