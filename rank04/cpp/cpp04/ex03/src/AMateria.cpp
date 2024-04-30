/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:47:19 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/30 16:58:33 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria Default constructor called." << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "AMateria Copy constructor called." << std::endl;
	if (this == &other)
		return ;
	*this = other;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria Assignmet operator called." << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria Default destructor called." << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "AMateria Type constructor called." << std::endl;
}

std::string const &AMateria::getType() const
{
	return (type);
}
