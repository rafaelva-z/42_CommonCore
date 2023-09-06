/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:02:11 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/06 15:31:09 by rvaz             ###   ########.fr       */
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
	std::string name;
	Weapon weapon;
	
	public:
	HumanA(std::string name, Weapon weapon);
	~HumanA();
	void	attack();
	void	setWeapon(Weapon weapon);
};

#endif
