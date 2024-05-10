/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:42:01 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/10 11:49:32 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>

class Bureaucrat
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
		Bureaucrat(const std::string &name, const int &grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat();
		//	Getters
		const std::string&	getName(void) const;
		const unsigned int&	getGrade(void) const;
		//	Other Methods
		void				incrementGrade(void);
		void				decrementGrade(void);
	private:
		const std::string	_name;
		unsigned int		_grade;
		/* Bureaucrat Default constructor is inaccessible because
		* the name is constant, to avoid confusion */
		Bureaucrat();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
