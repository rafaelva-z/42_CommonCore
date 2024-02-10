/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:39:42 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/10 13:05:01 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* zombieHorde;
	
	zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombieHorde[i].setName(name);
	return (zombieHorde);
}
