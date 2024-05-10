/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:54:12 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/10 12:55:45 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :
	_name("Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	// Nothing to do here
}

AForm::AForm(const std::string &name, const int &gradeToSign,
	const int &gradeToExecute) :
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1)
		throw AForm::GradeTooHighException("gradeToSign too high, try a lower value (maximum is 1)");
	if (gradeToExecute < 1)
		throw AForm::GradeTooHighException("gradeToExecute too high, try a lower value (maximum is 1)");
	if (gradeToSign > 150)
		throw AForm::GradeTooLowException("gradeToSign too low, try a higher value (minimum is 150)");
	if (gradeToExecute > 150)
		throw AForm::GradeTooLowException("gradeToExecute too low, try a higher value (minimum is 150)");
}

AForm::AForm(const AForm &other):
	_name(other._name + " copy"), _signed(other._signed),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	if (this == &other)
		return ;
	*this = other;
}

AForm&	AForm::operator=(const AForm& other)
{
	if (this == &other)
		return (*this);
	_signed = other._signed;
	_target = other._target;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	return (os << "Form: " << f.getName() << ", Sign status: " << f.getSigned() << ", GradeToExecute: "
		<< f.getGradeToExecute()) << ", GradeToSign: " << f.getGradeToSign() << ", Target: "
		<< f.getTarget();
}

AForm::~AForm()
{
	// Nothing to do here
}

//	Getters
const std::string&	AForm::getName(void) const
{
	return (_name);
}

const unsigned int&	AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

const unsigned int&	AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

const bool&			AForm::getSigned(void) const
{
	return (_signed);
}

const std::string&			AForm::getTarget(void) const
{
	return (_target);
}

// Other Methods
void				AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException("Grade too low to sign the form");
	_signed = true;
}

void				AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException("Grade too low to execute the form");
	executeForm();
}

// Exception classes

// GradeTooHighException
AForm::GradeTooHighException::GradeTooHighException() throw()
{
	_msg = "GradeTooHighException";
}

AForm::GradeTooHighException::GradeTooHighException(const std::string &msg) throw()
{
	_msg = "GradeTooHighException: " + msg;
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
	// Nothing to be done
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return (_msg.c_str());
}

// GradeTooLowException
AForm::GradeTooLowException::GradeTooLowException() throw()
{
	_msg = "GradeTooLowException";
}

AForm::GradeTooLowException::GradeTooLowException(const std::string &msg) throw()
{
	_msg = "GradeTooLowException: " + msg;
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
	// Nothing to be done
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return (_msg.c_str());
}
