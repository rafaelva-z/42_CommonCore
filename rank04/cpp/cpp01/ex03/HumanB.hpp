/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:02:17 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/11 19:11:47 by rvaz             ###   ########.fr       */
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
	std::string	_name;
	Weapon		*_weapon;
	
	public:
	HumanB(const std::string name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon &weapon);
	void	setWeapon(void);
};

#endif
