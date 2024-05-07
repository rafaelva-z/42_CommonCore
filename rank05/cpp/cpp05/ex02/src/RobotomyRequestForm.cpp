/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:54:12 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/07 23:17:02 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45)
{
	// Nothing to do here
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other.getName() + " copy", 72, 45)
{
	*this = other;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &f)
{
	return (os << "Form: "		<< f.getName()
		<< ", Sign status: "	<< f.getSigned()
		<< ", GradeToExecute: "	<< f.getGradeToExecute())
		<< ", GradeToSign: "	<< f.getGradeToSign();
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// Nothing to do here
}

// Other Methods

void	RobotomyRequestForm::executeForm() const
{
	if (rand() % 2)
		std::cout << _target << "has been robotomized successfully" << std::endl;
	else
		std::cout << "the robotomy of " << _target << " failed successfully" << std::endl;
}

