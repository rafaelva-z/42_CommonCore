/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:27:18 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/04 20:06:31 by rvaz             ###   ########.fr       */
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
	Zombie();
	~Zombie();
	
	void	announce(void);
	Zombie*	newZombie(std::string name);
	void	randomChump(std::string name);
};

#endif