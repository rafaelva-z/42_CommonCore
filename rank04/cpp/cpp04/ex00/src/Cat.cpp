/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:22:55 by rvaz              #+#    #+#             */
/*   Updated: 2024/03/14 18:24:14 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

//	Orthodox Canonical Form
Cat::Cat()
{
	std::cout << "Cat Default constructor called." << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat Copy constructor called." << std::endl;
	*this = other;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat Copy Assignment operator called." << std::endl;
	_type = other._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
};
