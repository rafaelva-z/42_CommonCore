/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:47:54 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/04 22:11:19 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
	_name("Bureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) :
	//throw(Bureaucrat::GradeTooHighException) :
	_name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException("Gade too high, try a lower value (maximum is 1)");
	else if (grade > 150)
		throw GradeTooLowException("Gade too low, try a lower value (minimum is 150)");

}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	_name(other._name), _grade(other._grade)
{
	if (this == &other)
		return ;
	*this = other;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return (*this);
	_grade = other._grade;
	return (*this);
}

// Bureaucrat::operator++(const Bureaucrat &other)
// {
// 	Increm
// }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	return (os << b.getName() << ", bureaucrat grade " << b.getGrade());
}

Bureaucrat::~Bureaucrat() {}

// Getters

const std::string&	Bureaucrat::getName(void) const
{
	return (_name);
}

const unsigned int&	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

// Other Methods

void	Bureaucrat::incrementGrade(void)
{
	if (_grade > 1)
		_grade--;
	else
		throw (Bureaucrat::GradeTooHighException("Trying to increment while at maximum grade (1)"));
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade < 150)
		_grade++;
	else
		throw (Bureaucrat::GradeTooLowException("Trying to decrement while at minimum grade (150)"));
}

// Exception classes

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &msg) throw()
{
	if (msg.empty())
		_msg = "GradeTooHighException";
	else
		_msg = "GradeTooHighException: " + msg;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (_msg.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &msg) throw()
{
	if (msg.empty())
		_msg = "GradeTooLowException";
	else
		_msg = "GradeTooLowException: " + msg;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (_msg.c_str());
}
