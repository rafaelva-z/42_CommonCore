/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:57 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/11 17:49:49 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
	private:
	std::string		name;
	int				hitPoints;
	int				energyPoints;
	int				attackDamage;
	
	public:
	// Orthodox Canonical Form
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap &other);
	ClapTrap&	operator=(const ClapTrap& other);
	~ClapTrap();
	//	Getters
	const std::string&	getName(void);
	int			getHitPoints(void);
	int			getEnergyPoints(void);
	int			getAttackDamage(void);
	//	Setters
	void		setName(const std::string& name);
	void		setHitPoints(int hitPoints);
	void		setEnergyPoints(int energyPoints);
	void		setAttackDamage(int attackDamage);
	//	Actions
	void		attack(const std::string &target);
	void		attack(ClapTrap &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	//	Checks
	bool		isDead(void);
	bool		isTired(void);
	//	Prints
	void		printStats(void);
	void		printDeath(void);
	void		printTired(void);
};

#endif