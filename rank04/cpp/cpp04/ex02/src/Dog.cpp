/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:59:45 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/04 15:10:55 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//	Orthodox Canonical Form
Dog::Dog() : Animal(), brain(new Brain())
{
	std::cout << "Dog Default constructor called." << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(other.getBrain()))
{
	std::cout << "Dog Copy constructor called." << std::endl;
	if (this == &other)
		return ;
	*this = other;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog Copy Assignment operator called." << std::endl;
	if (this == &other)
		return (*this);
	this->Animal::operator=(other);
	if (brain)
		delete brain;
	type = other.type;
	brain = new Brain();
	*brain = *other.brain;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called." << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}

Brain& Dog::getBrain() const
{
	return (*brain);
}
