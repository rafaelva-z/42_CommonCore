/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:27:45 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/10 13:07:44 by rvaz             ###   ########.fr       */
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
	*this = other;
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

AForm		*Intern::createSCF(std::string target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm		*Intern::createRRF(std::string target) const
{
	return (new RobotomyRequestForm(target));
}

AForm		*Intern::createPPF(std::string target) const
{
	return (new PresidentialPardonForm(target));
}


AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string forms[] = 
	{
		"robotomy request",
		"shrubbery creation",
		"presidential pardon"
	};
	AForm *(Intern::*f_func[])(const std::string target) const =
	{
		&Intern::createSCF,
		&Intern::createRRF,
		&Intern::createPPF,
	};

	for (int i = 0; i < 4; i++)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*f_func[i])(target));
		}
	}
	std::cout << "Intern tried his best but couldn't create " << name
			<< "!" << std::endl;
	return (NULL);
}