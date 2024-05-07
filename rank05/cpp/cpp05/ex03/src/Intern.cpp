/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:27:45 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/07 23:43:22 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	// Nothing to do here
}

Intern::Intern(const Intern &other)
{
	// Nothing to do here
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	// Nothing to do here
	(void)other;
	return (*this);
}

Intern::~Intern()
{
	// Nothing to do here
}


AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	(void)target;
	std::cout << "Intern tried his best but couldn't create a Form named " << name
		<< "!" << std::endl;
	return NULL;
}