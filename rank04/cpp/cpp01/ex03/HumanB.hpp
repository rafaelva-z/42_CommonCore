/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:02:17 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/10 15:41:01 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
	std::string	name;
	Weapon		*weapon;
	
	public:
	HumanB(const std::string name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon &weapon);
	void	setWeapon(void);
};

#endif
