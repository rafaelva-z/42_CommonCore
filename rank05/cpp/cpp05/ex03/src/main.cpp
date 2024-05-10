/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:33:24 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/10 13:09:12 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <sstream>
#include <exception>

#define B_AMOUNT 16
#define F_AMOUNT 9

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
	Intern someRandomIntern;
	AForm* rrf = NULL;
	AForm* ppf = NULL;
	AForm* scf = NULL;
	AForm* noForm = NULL;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	ppf = someRandomIntern.makeForm("shrubbery creation", "Fender");
	scf = someRandomIntern.makeForm("presidential pardon", "Xender");
	noForm = someRandomIntern.makeForm("not a form", "Lender");
	noForm = someRandomIntern.makeForm("", "Lender");

	std::cout << std::endl;
	if (rrf)
	std::cout << *rrf << std::endl;
	if (ppf)
	std::cout << *ppf << std::endl;
	if (scf)
	std::cout << *scf << std::endl;
	if (noForm)
		std::cout << *noForm << std::endl;

	if (rrf)
		delete rrf;
	if (ppf)
		delete ppf;
	if (scf)
		delete scf;
	if (noForm)
		delete noForm;
}