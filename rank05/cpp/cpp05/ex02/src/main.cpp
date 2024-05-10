/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:33:24 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/10 12:59:04 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <sstream>
#include <exception>

#define B_AMOUNT 16
#define F_AMOUNT 10

// Colors for better readability on terminal
#define CYAN "\033[96m";
#define RED "\033[0;31m";
#define BLUE  "\033[1;94m";
#define RESET "\033[0m";

void	print_info(std::string s)
{
	std::cout << std::endl;
	std::cout << CYAN; 
	std::cout << "- "<< s;
	std::cout << RESET
	std::cout << std::endl;
}

void	print_header(std::string s)
{
	static int head_count;
	std::cout << std::endl;
	std::cout << BLUE; 
	std::cout << "---- " << head_count << " " << s << " ----";
	std::cout << RESET
	std::cout << std::endl;
	head_count++;
}

void	print_error(std::string s)
{
	std::cout << std::endl;
	std::cout << RED; 
	std::cout << "!! " << s << " !!";
	std::cout << RESET
	std::cout << std::endl;
}

int	main()
{
	// Main for ex01
	{
		Bureaucrat			*bureaucrat[B_AMOUNT];
		AForm				*form[F_AMOUNT];
		std::stringstream	ss;
		std::string			b_name;

		print_header("Bureaucrat Factory (Bureaucraft)");
		for (int i = 0; i < B_AMOUNT; i++)
		{
			ss.str(std::string());
			ss << "B" << i;
			b_name = ss.str();
			if (i != 0)
				bureaucrat[i] = new Bureaucrat(b_name, i * 10);
			else
				bureaucrat[i] = new Bureaucrat(b_name, 1);
			std::cout << "Name:	" << bureaucrat[i]->getName()
			<< "	|	Grade:	" << bureaucrat[i]->getGrade() << std::endl;
		}
		for (int i = 0; i < F_AMOUNT; i++)
			form[i] = 0;

		print_header("Form class test");
		print_info("Constructors (check the main)");
		form[0] = new ShrubberyCreationForm("SCF0");
		form[1] = new ShrubberyCreationForm("SCF1");
		form[2] = new PresidentialPardonForm("PPF2");
		form[3] = new PresidentialPardonForm("PPF3");
		form[4] = new RobotomyRequestForm("RRF4");
		form[5] = new RobotomyRequestForm("RRF4");

		print_info("Copy constructor");
		ShrubberyCreationForm *SCF = new ShrubberyCreationForm("aaaa");
		PresidentialPardonForm *PPF = new PresidentialPardonForm("bbb");
		RobotomyRequestForm *RRF = new RobotomyRequestForm("ccc") ;
		form[6] = new ShrubberyCreationForm(*SCF);
		form[7] = new PresidentialPardonForm(*PPF);
		form[8] = new RobotomyRequestForm(*RRF);

		print_info("Insertion operator");
		std::cout << *form[6] << std::endl;
		std::cout << *form[7] << std::endl;
		std::cout << *form[8] << std::endl;

		print_header("Exception tests");
		print_info("Signing GradeTooLow exception");
		bureaucrat[15]->signForm(*form[0]);
		bureaucrat[3]->signForm(*form[2]);
		bureaucrat[8]->signForm(*form[4]);

		print_info("Signing Sucessfuly");
		bureaucrat[14]->signForm(*form[0]);
		bureaucrat[2]->signForm(*form[2]);
		bureaucrat[7]->signForm(*form[4]);

		print_info("Executing GradeTooLow exception");
		bureaucrat[14]->executeForm(*form[0]);
		bureaucrat[1]->executeForm(*form[2]);
		bureaucrat[5]->executeForm(*form[4]);

		print_info("Executing Form not signed");
		form[9] = new ShrubberyCreationForm("FormNotSigned");
		try
		{
			bureaucrat[13]->executeForm(*form[9]);
			print_error("This should not be printed");
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		print_info("Executing Sucessfuly");
		bureaucrat[13]->executeForm(*form[0]);
		bureaucrat[0]->executeForm(*form[2]);
		bureaucrat[4]->executeForm(*form[4]);
		bureaucrat[4]->executeForm(*form[4]);

		print_info("Assignment operator");
		std::cout << *form[1] << std::endl;
		std::cout << *form[3] << std::endl;
		std::cout << *form[5] << std::endl;
		*form[1] = *form[0];
		*form[3] = *form[2];
		*form[5] = *form[4];
		std::cout << *form[1] << std::endl;
		std::cout << *form[3] << std::endl;
		std::cout << *form[5] << std::endl;

		print_info("End of tests");

		for (int i = 0; i < B_AMOUNT; i++)
			if (bureaucrat[i])
				delete bureaucrat[i];
		for (int i = 0; i < F_AMOUNT; i++)
			if (form[i])
				delete form[i];
		delete SCF;
		delete PPF;
		delete RRF;
	}
}