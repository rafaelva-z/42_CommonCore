/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:02:11 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/10 15:45:33 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
	private:
	std::string	name;
	Weapon		weapon; //"Weapon &weapon"
	
	public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack();
	void	setWeapon(Weapon &weapon);
};

#endif
