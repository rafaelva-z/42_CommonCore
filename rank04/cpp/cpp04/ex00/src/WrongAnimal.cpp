/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:59:45 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/15 18:42:59 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//	Orthodox Canonical Form
WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal Copy constructor called." << std::endl;
	*this = other;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal Copy Assignment operator called." << std::endl;
	type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called." << std::endl;
}

// Getters

const std::string&	WrongAnimal::getType(void) const
{
	return (type);
}

// Other Functions

void WrongAnimal::makeSound() const
{
	std::cout << "Default WrongAnimal Sound!" << std::endl;
};
