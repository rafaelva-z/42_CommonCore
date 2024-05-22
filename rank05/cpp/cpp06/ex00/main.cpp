/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:47 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/22 15:28:53 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

// Colors for better readability on terminal
#define CYAN "\033[96m";
#define RED "\033[0;31m";
#define BLUE  "\033[1;94m";
#define GREEN "\033[32m"
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


#include <limits>

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
		ScalarConverter::convert("0");
		ScalarConverter::convert("nan");
		ScalarConverter::convert("*");

		print_header("Pseudo literals");
		std::cin.get();
		std::cout << GREEN << "✅ Valid Pseudo literals:" << std::endl;
		std::cout << RESET;
		ScalarConverter::convert("+inf");
		ScalarConverter::convert("+inff");
		ScalarConverter::convert("-inf");
		ScalarConverter::convert("-inff");
		ScalarConverter::convert("nan");
		std::cout << RED;
		std::cout << "❌ Invalid pseudo literals:" << std::endl;
		std::cout << RESET;
		ScalarConverter::convert("+infff");
		ScalarConverter::convert("+in");
		ScalarConverter::convert("nana");
		ScalarConverter::convert("-inff1");

		print_header("Chars");
		std::cin.get();
		std::cout << GREEN << "✅ Valid Chars:" << std::endl;
		std::cout << RESET;
		ScalarConverter::convert("c");
		ScalarConverter::convert("A");
		ScalarConverter::convert("_");
		ScalarConverter::convert("!");
		std::cout << RED;
		std::cout << "❌ Non-displayable Chars:" << std::endl;
		std::cout << RESET;
		ScalarConverter::convert(std::string(1, char(-10)));
		ScalarConverter::convert(std::string(1, char(2)));
		ScalarConverter::convert(std::string(1, char(31)));
		ScalarConverter::convert("300");
		
		print_header("Int");
		std::cin.get();
		std::cout << GREEN << "✅ Valid Ints:" << std::endl;
		std::cout << RESET;
		ScalarConverter::convert("-42");
		ScalarConverter::convert("+42");
		ScalarConverter::convert("2147483647");
		ScalarConverter::convert("-2147483648");
		ScalarConverter::convert("0");
		ScalarConverter::convert("+0000000");
		ScalarConverter::convert("-0000000");

		std::cout << RED;
		std::cout << "❌ Invalid Ints:" << std::endl;
		std::cout << RESET;
		ScalarConverter::convert("2147483648");
		ScalarConverter::convert("-2147483649");
		ScalarConverter::convert("--0");
		ScalarConverter::convert("++0");

		
		print_header("Float"); 
		std::cin.get();
		std::cout << GREEN << "✅ Valid floats:" << std::endl;
		std::cout << RESET;
		ScalarConverter::convert("4f");
		ScalarConverter::convert("4.2f");
		ScalarConverter::convert("+42.42f");
		ScalarConverter::convert("-424.242f");
		ScalarConverter::convert("1234567.891234f");
		ScalarConverter::convert("0f");
		ScalarConverter::convert("000.00000f");
		ScalarConverter::convert("-000.0f");
		std::cout << RED;
		std::cout << "❌ Invalid/inf Floats:" << std::endl;
		std::cout << RESET;
		// Here we can see that the "double" value will be very imprecise due to the size of the number
		ScalarConverter::convert("++0f");
		ScalarConverter::convert("+f");
		ScalarConverter::convert("++0f");
		ScalarConverter::convert("10000000000000000000000000000000000000000f");
		ScalarConverter::convert("-10000000000000000000000000000000000000000f");

		
		print_header("Double");
		std::cin.get();
		std::cout << GREEN << "✅ Valid Doubles:" << std::endl;
		std::cout << RESET;
		ScalarConverter::convert("4.321");
		ScalarConverter::convert("123456789.0123456");
		ScalarConverter::convert("+42.42");
		ScalarConverter::convert("-24.24");
		std::cout << RED;
		std::cout << "❌ Invalid/inf Doubles:" << std::endl;
		std::cout << RESET;
		ScalarConverter::convert("1111.2222.3333");
		ScalarConverter::convert("++123.456");
		ScalarConverter::convert("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
		ScalarConverter::convert("-10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");

		print_header("More invalid inputs");
		std::cin.get();
		ScalarConverter::convert("");
		ScalarConverter::convert("Hello");
		ScalarConverter::convert("123 42");
		ScalarConverter::convert("123f11");
		ScalarConverter::convert("1.1ff");

		print_header("End of tests");
	}
}
