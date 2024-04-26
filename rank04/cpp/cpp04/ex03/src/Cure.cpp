/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:52:37 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/26 18:16:21 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure Default Constructor" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "Cure Copy Constructor" << std::endl;
	if (this == &other)
		return ;
	*this = other;
}

Cure& Cure::operator=(const Cure &other)
{
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure Destructor" << std::endl;
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
