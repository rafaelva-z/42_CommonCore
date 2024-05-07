/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:09:41 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/07 23:06:36 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5)
{
	// Nothing to do here
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm(other.getName() + " copy", 25, 5)
{
	*this = other;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &f)
{
	return (os << "Form: "		<< f.getName()
		<< ", Sign status: "	<< f.getSigned()
		<< ", GradeToExecute: "	<< f.getGradeToExecute())
		<< ", GradeToSign: "	<< f.getGradeToSign();
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// Nothing to do here
}

// Other Methods

void	PresidentialPardonForm::executeForm() const
{
	std::cout << _target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}