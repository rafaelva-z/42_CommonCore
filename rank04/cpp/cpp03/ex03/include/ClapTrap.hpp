/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:57 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/29 16:56:28 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
	protected:
	std::string		_name;
	int				_hitPoints;
	int				_energyPoints;
	int				_attackDamage;
	
	public:
	// Orthodox Canonical Form
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	ClapTrap&	operator=(const ClapTrap& other);
	~ClapTrap();
	//	Getters
	const std::string&	getName(void) const;
	int			getHitPoints(void) const;
	int			getEnergyPoints(void) const;
	int			getAttackDamage(void) const;
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