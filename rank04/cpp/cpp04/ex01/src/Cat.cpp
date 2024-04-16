/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:22:55 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/15 20:02:02 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//	Orthodox Canonical Form
Cat::Cat() : Animal(), brain(new Brain)
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
	type = other.type;
	brain = other.brain;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called." << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
