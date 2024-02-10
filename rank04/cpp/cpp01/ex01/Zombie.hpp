/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:27:18 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/06 13:29:35 by rvaz             ###   ########.fr       */
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
	
	void	setName(std::string name);
	void	announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif