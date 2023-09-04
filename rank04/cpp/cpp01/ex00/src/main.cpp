/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:39:30 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/04 20:19:01 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main()
{
	Zombie zombie;
	
	zombie = zombie.newZombie("Gandalf");
	zombie->announce();
	delete zombie;
}