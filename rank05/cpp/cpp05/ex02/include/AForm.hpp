/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:54:42 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/07 23:23:38 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException() throw();
			GradeTooHighException(const std::string& msg) throw();
			~GradeTooHighException() throw();
			const char *what() const throw();
		private:
			std::string	_msg;
	};
	class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException() throw();
			GradeTooLowException(const std::string& msg) throw();
			~GradeTooLowException() throw();
			const char *what() const throw();
		private:
			std::string	_msg;
	};

	public:
		AForm(const std::string &name, const int &gradeToSign,
			const int &gradeToExecute);
		AForm(const AForm &other);
		AForm&	operator=(const AForm& other);
		virtual ~AForm();
		//	Getters
		const std::string&	getName(void) const;
		const unsigned int&	getGradeToSign(void) const;
		const unsigned int&	getGradeToExecute(void) const;
		const bool&			getSigned(void) const;
		const std::string&	getTarget(void) const;
		// Other Methods
		void				beSigned(const Bureaucrat &b);
		void				execute(Bureaucrat const & executor) const;
	protected:
		std::string	_target;
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;
		AForm();
		virtual void		executeForm() const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &b);

#endif