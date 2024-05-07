/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:33:24 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/07 15:45:16 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <sstream>
#include <exception>

#define B_AMOUNT 15
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
	// Main from ex00
	{
	Bureaucrat	*bureaucrat[B_AMOUNT];

	for (int i = 0; i < B_AMOUNT; i++)
		bureaucrat[i] = 0;

	// Test 0
	print_header("Bureaucrat class test");
	print_info("Constructors (check the main)");
	bureaucrat[9] = new Bureaucrat("b9", 1);
	bureaucrat[8] = new Bureaucrat(*bureaucrat[9]);
	bureaucrat[7] = new Bureaucrat("b7", 42);
	
	print_info("insertion operator");
	std::cout << *bureaucrat[9] << std::endl;
	std::cout << *bureaucrat[8] << std::endl;
	std::cout << *bureaucrat[7] << std::endl;
	
	
	print_info("assignment operator");
	*bureaucrat[7] = *bureaucrat[8];
	std::cout << *bureaucrat[7] << std::endl;
	print_info("Methods");
	std::cout << "getName() Method (bureaucrat[7]):	" << bureaucrat[7]->getName() << std::endl;
	std::cout << "getGrade() Method (bureaucrat[7]):	" << bureaucrat[7]->getGrade() << std::endl;
	bureaucrat[7]->decrementGrade();
	std::cout << "decrementGrade Method (bureaucrat[7]):	" << bureaucrat[7]->getGrade() << std::endl;
	bureaucrat[7]->incrementGrade();
	std::cout << "incrementGrade Method (bureaucrat[7]):	" << bureaucrat[7]->getGrade() << std::endl;

	// Test 1
	print_header("Exception tests");

	print_info("No exeption");
	try
	{
		bureaucrat[0] = new Bureaucrat("b0", 10);
	}
	catch (std::exception& e)
	{
		print_error("This should not be printed");
		std::cout << e.what() << std::endl;
		return 1;
	}
	if (bureaucrat[0])
		std::cout << *bureaucrat[0] << std::endl;

	print_info("GradeTooHighException");
	try
	{
		bureaucrat[1] = new Bureaucrat("b3", 160);
		print_error("This should not be printed");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	print_info("GradeTooLowException");
	try
	{
		bureaucrat[2] = new Bureaucrat("b4", -100);
		print_error("This should not be printed");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	print_info("End of tests");
	
	for (int i = 0; i < B_AMOUNT; i++)
		if (bureaucrat[i])
			delete bureaucrat[i];
	}
	// Main for ex01
	{
		Bureaucrat	*bureaucrat[B_AMOUNT];
		Form		*form[F_AMOUNT];
		std::stringstream	ss;
		std::string			b_name;

		print_header("Bureaucrat Factory (Bureaucraft)");
		for (int i = 0; i < B_AMOUNT; i++)
		{
			ss.str(std::string());
			ss << "B" << i;
			b_name = ss.str();
			bureaucrat[i] = new Bureaucrat(b_name, (i * 10) + 1);
			std::cout << "Name:	" << bureaucrat[i]->getName()
			<< "	|	Grade:	" << bureaucrat[i]->getGrade() << std::endl;
		}
		for (int i = 0; i < F_AMOUNT; i++)
			form[i] = 0;

		// Test 0
		print_header("Form class test");
		print_info("Constructors (check the main)");
		form[0] = new Form("F0", 50, 60);
		form[1] = new Form("F1", 20, 55);
		form[2] = new Form(*form[1]);
		
		print_info("Insertion operator");
		std::cout << *form[0] << std::endl;
		std::cout << *form[1] << std::endl;
		std::cout << *form[2] << std::endl;
		
		print_info("Methods");
		bureaucrat[1]->signForm(*form[2]);
		bureaucrat[1]->signForm(*form[2]);

		print_info("Assignment operator");
		*form[1] = *form[2];
		std::cout << *form[1] << std::endl;

		// Test 1
		print_info("grade too low to sign form");
		print_header("Exception tests");
		std::cout << "Form Signed status: " << form[0]->getSigned() << std::endl;
		bureaucrat[5]->signForm(*form[0]);
		std::cout << "Form Signed status: " << form[0]->getSigned() << std::endl;
		bureaucrat[4]->signForm(*form[0]);
		std::cout << "Form Signed status: " << form[0]->getSigned() << std::endl;
		print_info("gradeToSign too high to instatiate");
		try
		{
			form[3] = new Form("F1", -100, 55);
			print_error("This should not be printed");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		print_info("gradeToSign too low to instatiate");
		try
		{
			form[4] = new Form("F1", 1000000, 55);
			print_error("This should not be printed");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		print_info("gradeToExecute too high to instatiate");
		try
		{
			form[5] = new Form("F1", 1, -100);
			print_error("This should not be printed");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		print_info("gradeToExecute too low to instatiate");
		try
		{
			form[6] = new Form("F1", 1, 12345);
			print_error("This should not be printed");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		print_info("End of tests");
		
		for (int i = 0; i < B_AMOUNT; i++)
			if (bureaucrat[i])
				delete bureaucrat[i];
		for (int i = 0; i < F_AMOUNT; i++)
			if (form[i])
				delete form[i];
	}
}