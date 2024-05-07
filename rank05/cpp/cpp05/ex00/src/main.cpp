/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:33:24 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/06 16:02:49 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

#define B_AMOUNT 10

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
	Bureaucrat	*b[B_AMOUNT];

	for (int i = 0; i < B_AMOUNT; i++)
		b[i] = 0;

	// Test 0
	print_header("Bureaucrat class test");
	print_info("Constructors");
	/* Default constructor is inaccessible because the names would all be the same
	*  and that would be confusing */
	b[9] = new Bureaucrat("b9", 1);
	b[8] = new Bureaucrat(*b[9]);
	b[7] = new Bureaucrat("b7", 42);
	
	print_info("insertion operator");
	std::cout << *b[9] << std::endl;
	std::cout << *b[8] << std::endl;
	std::cout << *b[7] << std::endl;
	
	print_info("assignment operator");
	*b[7] = *b[8];
	std::cout << *b[7] << std::endl;
	
	print_info("Methods");
	std::cout << "getName() Method (b[7]):	" << b[7]->getName() << std::endl;
	std::cout << "getGrade() Method (b[7]):	" << b[7]->getGrade() << std::endl;
	b[7]->decrementGrade();
	std::cout << "decrementGrade Method (b[7]):	" << b[7]->getGrade() << std::endl;
	b[7]->incrementGrade();
	std::cout << "incrementGrade Method (b[7]):	" << b[7]->getGrade() << std::endl;

	// Test 1
	print_header("Exception tests");

	print_info("No exeption");
	try
	{
		b[0] = new Bureaucrat("b0", 10);
	}
	catch (std::exception& e)
	{
		print_error("This should not be printed");
		std::cout << e.what() << std::endl;
		return 1;
	}
	if (b[0])
		std::cout << *b[0] << std::endl;

	print_info("GradeTooHighException");
	try
	{
		b[1] = new Bureaucrat("b3", 160);
		print_error("This should not be printed");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	print_info("GradeTooLowException");
	try
	{
		b[2] = new Bureaucrat("b4", -100);
		print_error("This should not be printed");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	print_info("End of tests");
	
	for (int i = 0; i < B_AMOUNT; i++)
		if (b[i])
			delete b[i];
}