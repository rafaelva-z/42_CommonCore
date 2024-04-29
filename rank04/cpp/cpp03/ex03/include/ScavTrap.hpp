/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:15:43 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/29 17:11:52 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	protected:
	static const int scavHP;
	static const int scavAD;

	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap &other);
		ScavTrap&	operator=(const ScavTrap& other);
		~ScavTrap();
		void	attack(const std::string &target);
		void	attack(ClapTrap &target);
		void	guardGate(void);
};


#endif