/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:49:43 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/25 16:12:51 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << " MateriaSource Default Constructor" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << " MateriaSource Destructor" << std::endl;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	
}
AMateria* createMateria(std::string const & type) 
{
	for (int i = 0; i < MATERIA_TEMPLATE_SLOTS; i++)
	{
		if (materia_template_iventory[i] == type)
		
	}
}
