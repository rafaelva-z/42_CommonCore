/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:39:30 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/10 13:01:22 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie* z_gandalf;
	
	z_gandalf = newZombie("Gandalf");
	z_gandalf->announce();
	randomChump("Saruman");
	delete z_gandalf;
}