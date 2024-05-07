/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:54:12 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/06 18:35:09 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
	_name("Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	// Nothing to do here
}

Form::Form(const std::string &name, const int &gradeToSign,
	const int &gradeToExecute) :
	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1)
		throw Form::GradeTooHighException("gradeToSign too high, try a lower value (maximum is 1)");
	if (gradeToExecute < 1)
		throw Form::GradeTooHighException("gradeToExecute too high, try a lower value (maximum is 1)");
	if (gradeToSign > 150)
		throw Form::GradeTooLowException("gradeToSign too low, try a higher value (minimum is 150)");
	if (gradeToExecute > 150)
		throw Form::GradeTooLowException("gradeToExecute too low, try a higher value (minimum is 150)");
	_signed = false;
}

Form::Form(const Form &other): _name(other._name + " copy"), _signed(other._signed),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	if (this == &other)
		return ;
	*this = other;
}

Form&	Form::operator=(const Form& other)
{
	if (this == &other)
		return (*this);
	_signed = other._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	return (os << "Form: " << f.getName() << ", Sign status: " << f.getSigned() << ", GradeToExecute: "
		<< f.getGradeToExecute()) << ", GradeToSign: " << f.getGradeToSign();
}

Form::~Form()
{
	// Nothing to do here
}

//	Getters
const std::string&	Form::getName(void) const
{
	return (_name);
}

const unsigned int&	Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

const unsigned int&	Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

const bool&			Form::getSigned(void) const
{
	return (_signed);
}

// Other Methods
void				Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException("Grade too low to sign the form");
	_signed = true;
}

// Exception classes

// GradeTooHighException
Form::GradeTooHighException::GradeTooHighException() throw()
{
	_msg = "GradeTooHighException";
}

Form::GradeTooHighException::GradeTooHighException(const std::string &msg) throw()
{
	_msg = "GradeTooHighException: " + msg;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	// Nothing to be done
}

const char *Form::GradeTooHighException::what() const throw()
{
	return (_msg.c_str());
}

// GradeTooLowException
Form::GradeTooLowException::GradeTooLowException() throw()
{
	_msg = "GradeTooLowException";
}

Form::GradeTooLowException::GradeTooLowException(const std::string &msg) throw()
{
	_msg = "GradeTooLowException: " + msg;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	// Nothing to be done
}

const char *Form::GradeTooLowException::what() const throw()
{
	return (_msg.c_str());
}
