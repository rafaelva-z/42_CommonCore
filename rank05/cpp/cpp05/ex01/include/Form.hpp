/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:54:42 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/06 18:34:46 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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
		Form(const std::string &name, const int &gradeToSign,
			const int &gradeToExecute);
		Form(const Form &other);
		Form&	operator=(const Form& other);
		~Form();
		//	Getters
		const std::string&	getName(void) const;
		const unsigned int&	getGradeToSign(void) const;
		const unsigned int&	getGradeToExecute(void) const;
		const bool&			getSigned(void) const;
		// Other Methods
		void				beSigned(const Bureaucrat &b);

	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;
		Form();
};

std::ostream &operator<<(std::ostream &os, const Form &b);

#endif