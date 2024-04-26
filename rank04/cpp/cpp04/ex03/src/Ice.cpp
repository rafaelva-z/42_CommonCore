/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:02:25 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/26 18:14:49 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice Default Constructor" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Ice Copy Constructor" << std::endl;
	if (this == &other)
		return ;
	*this = other;
}

Ice& Ice::operator=(const Ice &other)
{
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice Destructor" << std::endl;
}

Ice* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
