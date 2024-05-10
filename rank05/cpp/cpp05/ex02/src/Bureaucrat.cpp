/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:47:54 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/10 12:59:53 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150)
{
	// Nothing to do here
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) :
	_name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException("Grade too high, try a lower value (maximum is 1)");
	if (grade > 150)
		throw GradeTooLowException("Grade too low, try a lower value (minimum is 150)");
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name + " copy")
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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	return (os << b.getName() << ", bureaucrat grade " << b.getGrade());
}

Bureaucrat::~Bureaucrat()
{
	// Nothing to do here
}

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

void	Bureaucrat::signForm(AForm &f)
{
	if (f.getSigned())
	{
		std::cout << _name << ": The form " << f.getName() << " has already been signed!" << std::endl;
		return ;
	}
	try
	{
		f.beSigned(*this);
	}
	catch (std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << _name << " signed " << f.getName() << std::endl;
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	if (!form.getSigned())
		throw (Bureaucrat::FormNotSignedException("Please sign the form before executing"));
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << form.getName() << " " << e.what() << '\n';
	}
}

// Exception classes

// GradeTooHighException
Bureaucrat::GradeTooHighException::GradeTooHighException() throw()
{
	_msg = "GradeTooHighException";
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &msg) throw()
{
	_msg = "GradeTooHighException: " + msg;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	// Nothing to be done
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (_msg.c_str());
}

// GradeTooLowException
Bureaucrat::GradeTooLowException::GradeTooLowException() throw()
{
	_msg = "GradeTooLowException";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &msg) throw()
{
	_msg = "GradeTooLowException: " + msg;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	// Nothing to be done
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (_msg.c_str());
}

// FormNotSignedException
Bureaucrat::FormNotSignedException::FormNotSignedException() throw()
{
	_msg = "FormNotSignedException";
}

Bureaucrat::FormNotSignedException::FormNotSignedException(const std::string &msg) throw()
{
	_msg = "FormNotSignedException: " + msg;
}

Bureaucrat::FormNotSignedException::~FormNotSignedException() throw()
{
	// Nothing to be done
}

const char *Bureaucrat::FormNotSignedException::what() const throw()
{
	return (_msg.c_str());
}
