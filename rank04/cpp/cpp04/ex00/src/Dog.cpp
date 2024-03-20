/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:59:45 by rvaz              #+#    #+#             */
/*   Updated: 2024/03/14 18:06:05 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

//	Orthodox Canonical Form
Dog::Dog()
{
	std::cout << "Dog Default constructor called." << std::endl;
	_type = "Dog";
}

Dog::Dog(const std::string &type) 
	: Animal::_type(type)
{
	std::cout << "Dog Parameter constructor called." << std::endl;
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog Copy constructor called." << std::endl;
	*this = other;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog Copy Assignment operator called." << std::endl;
	_type = other._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
};
