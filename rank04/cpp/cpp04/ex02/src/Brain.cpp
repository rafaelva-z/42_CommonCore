/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:57:18 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/15 20:06:44 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//	Orthodox Canonical Form
Brain::Brain()
{
	std::cout << "Brain Default constructor called." << std::endl;
}
Brain::~Brain()
{
	std::cout << "Brain Destructor called." << std::endl;
}
Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy constructor called." << std::endl;
	if (this == &other)
		return ;
	*this = other;
}
Brain&	Brain::operator=(const Brain &other)
{
	std::cout << "Brain Copy Assignment operator called." << std::endl;
	for (int i = 0; i < IDEAS_SIZE; i++)
		_ideas[i] = other._ideas[i];
	return (*this);
}

// Other functions
const std::string&	Brain::getIdea(int index) const
{
	if (index < 0 || index >= IDEAS_SIZE)
		throw std::out_of_range("Invalid index");
	return (_ideas[index]);
}

void	Brain::setIdea(int index, const std::string &new_idea)
{
	if (index < 0 || index >= IDEAS_SIZE)
		throw std::out_of_range("Invalid index");
	_ideas[index] = new_idea;
}
