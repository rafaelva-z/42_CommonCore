/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:59:45 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/24 17:29:24 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//	Orthodox Canonical Form
Animal::Animal()
{
	std::cout << "Animal Default constructor called." << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal Copy constructor called." << std::endl;
	if (this == &other)
		return ;
	*this = other;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal Copy Assignment operator called." << std::endl;
	type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called." << std::endl;
}

// Getters

const std::string&	Animal::getType(void) const
{
	return (type);
}
