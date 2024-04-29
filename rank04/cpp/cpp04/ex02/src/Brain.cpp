/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:57:18 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/29 23:22:26 by rvaz             ###   ########.fr       */
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
	if (this == &other)
		return (*this);
	for (int i = 0; i < IDEAS_SIZE; i++)
		_ideas[i] = other._ideas[i];
	return (*this);
}

// Other functions
const std::string	&Brain::getIdea(int index) const
{
	if (index > 99)
		return (_ideas[99]);
	if (index < 0)
		return (_ideas[0]);
	return (_ideas[index]);
}

void	Brain::setIdea(int index, const std::string &new_idea)
{
	if (index < 0 || index >= IDEAS_SIZE)
	{
		std::cout << "My brain can't handle that information" << std::endl;
		return ;
	}
	_ideas[index] = new_idea;
}
