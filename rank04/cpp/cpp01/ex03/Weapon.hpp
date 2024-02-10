/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:02:19 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/09 20:50:37 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	private:
	std::string	type;
	
	public:
	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);
	void				setType(std::string type);
	const std::string	&getType(void);
};

#endif
