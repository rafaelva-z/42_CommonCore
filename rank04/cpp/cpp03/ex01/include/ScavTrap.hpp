/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:15:43 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/11 18:17:44 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap &other);
		ScavTrap&	operator=(const ScavTrap& other);
		~ScavTrap();
		void	guardGate(void);
};


#endif