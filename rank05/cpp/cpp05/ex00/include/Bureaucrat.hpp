/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:42:01 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/04 22:10:41 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{
	class GradeTooHighException : public std::exception
	{
		public:
		GradeTooHighException(const std::string& msg) throw();
		~GradeTooHighException() throw();
		const char *what() const throw();
		
		private:
		std::string	_msg;
	};

	class GradeTooLowException : public std::exception
	{
		public:
		GradeTooLowException(const std::string& msg) throw();
		~GradeTooLowException() throw();
		const char *what() const throw();
		
		private:
		std::string	_msg;
	};

	private:
	const std::string	_name;
	unsigned int		_grade;
	Bureaucrat();
	
	public:
	Bureaucrat(const std::string &name, const int &grade);
		//throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
	Bureaucrat(const Bureaucrat &other);
		//throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
	Bureaucrat&	operator=(const Bureaucrat& other);
	virtual	~Bureaucrat();
	//	Getters
	const std::string&	getName(void) const;
	const unsigned int&	getGrade(void) const;
	//	Other Methods
	void				incrementGrade(void);
	void				decrementGrade(void);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
