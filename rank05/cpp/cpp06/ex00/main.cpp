/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:47 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/20 13:30:58 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

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

int	main(int argc, char** argv)
{
	if (argc > 2)
	{
		std::cout << "Invalid number of arguments (do ./ScalarConverter or"
			<< " ./ScalarConverter <value>)";
		return (1);
	}
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
	{
		print_header("Subject");
		ScalarConverter::convert(std::string("0"));
		ScalarConverter::convert("nan");
		ScalarConverter::convert("*");
		std::cin.get();

		print_header("Pseudo");
		ScalarConverter::convert("+inf");
		ScalarConverter::convert("+inff");
		ScalarConverter::convert("-inf");
		ScalarConverter::convert("-inff");
		ScalarConverter::convert("nan");
		std::cin.get();

		print_header("Chars");
		ScalarConverter::convert("c");
		ScalarConverter::convert("A");
		ScalarConverter::convert("_");
		ScalarConverter::convert("!");
		ScalarConverter::convert(std::string(1, char(-10)));
		ScalarConverter::convert(std::string(1, char(2)));
		ScalarConverter::convert(std::string(1, char(31)));
		std::cin.get();
		
		print_header("Int");
		ScalarConverter::convert("-42");
		ScalarConverter::convert("42");
		ScalarConverter::convert("2147483647");
		ScalarConverter::convert("-2147483648");
		std::cin.get();
		
		print_header("Float"); 
		ScalarConverter::convert("4.2f");
		std::cin.get();
		
		print_header("Double");
		ScalarConverter::convert("4.321");
		std::cin.get();

		print_header("Oher invalid input");
		ScalarConverter::convert("");
		ScalarConverter::convert("Hello");
		ScalarConverter::convert("123 42");
		ScalarConverter::convert("123f11");
		ScalarConverter::convert("1.1ff");

		print_header("End of tests");
	}
}
