/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:27:18 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/06 12:51:21 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
	std::string name;

	public:
	Zombie(std::string name_c);
	~Zombie();
	
	void	announce(void);
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif