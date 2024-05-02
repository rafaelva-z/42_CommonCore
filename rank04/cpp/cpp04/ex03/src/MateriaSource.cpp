/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:49:43 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/02 18:25:18 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << " MateriaSource Default Constructor" << std::endl;
	for (int i = 0; i < MATERIA_TEMPLATE_SLOTS; i++)
		mat_inventory[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << " MateriaSource Copy Constructor" << std::endl;
	if (this == &other)
		return ;
	*this = other;
}

MateriaSource & MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource Assignement Operator" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < MATERIA_TEMPLATE_SLOTS; i++)
	{
		if (mat_inventory[i])
		{
			delete (mat_inventory[i]);
			mat_inventory[i] = 0;
		}
		if (other.mat_inventory[i])
			mat_inventory[i] = other.mat_inventory[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i < MATERIA_TEMPLATE_SLOTS; i++)
		if (mat_inventory[i])
			delete mat_inventory[i];
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
	{
		std::cout << "MateriaSource could not learn materia!" << std::endl;
		return ;
	}
	for (int i = 0; i < MATERIA_TEMPLATE_SLOTS; i++)
	{
		if (!mat_inventory[i])
		{
			mat_inventory[i] = materia->clone();
			std::cout << "MateriaSource of type " << materia->getType() << " Learned " << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource could not learn materia!" << std::endl;
}
AMateria*	MateriaSource::createMateria(std::string const & type) 
{
	for (int i = 0; i < MATERIA_TEMPLATE_SLOTS; i++)
		if (mat_inventory[i] && mat_inventory[i]->getType() == type)
			return (mat_inventory[i]->clone());
	return (0);
}
