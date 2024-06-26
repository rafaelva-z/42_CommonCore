/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:22:55 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/29 13:34:52 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//	Orthodox Canonical Form
Cat::Cat() : Animal()
{
	std::cout << "Cat Default constructor called." << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat Copy constructor called." << std::endl;
	if (this == &other)
		return ;
	*this = other;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat Copy Assignment operator called." << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "I'm a cat and I don't bark!" << std::endl;
}
