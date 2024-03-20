/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:59:45 by rvaz              #+#    #+#             */
/*   Updated: 2024/03/14 18:06:05 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

//	Orthodox Canonical Form
Animal::Animal()
{
	std::cout << "Animal Default constructor called." << std::endl;
}

Animal::Animal(const std::string &type) 
	: _type(type)
{
	std::cout << "Animal Parameter constructor called." << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal Copy constructor called." << std::endl;
	*this = other;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal Copy Assignment operator called." << std::endl;
	_type = other._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called." << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Default Animal Sound!" << std::endl;
};
