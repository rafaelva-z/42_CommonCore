/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:22:55 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/29 21:13:45 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//	Orthodox Canonical Form
WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat Default constructor called." << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat Copy constructor called." << std::endl;
	if (this == &other)
		return ;
	*this = other;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat Copy Assignment operator called." << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Woof!... i mean, meow!" << std::endl;
}
