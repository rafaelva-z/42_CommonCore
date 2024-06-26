/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:14:21 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/29 22:54:59 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string.h>
# include "ICharacter.hpp"
# include "AMateria.hpp"

# define MATERIA_SLOTS 4

class AMateria;

class Character : public ICharacter
{
	private:
	std::string	name;
	AMateria	*materia_inventory[MATERIA_SLOTS];

	public:
	Character();
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();

	Character(const std::string &name);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif