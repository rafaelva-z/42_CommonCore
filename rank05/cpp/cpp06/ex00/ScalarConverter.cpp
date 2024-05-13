/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:11:36 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/13 20:12:04 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>

/* Private: */

ScalarConverter::ScalarConverter()
{
	// Nothing to be done
}

ScalarConverter::ScalarConverter(ScalarConverter &other)
{
	if (this == &other)
		return ;
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
	// Nothing to be done
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &other)
{
	(void)other;
	return (*this);
}

/* Public: */

static void print_input(int type)
{
	std::cout << "char:\t"		<< BAD_CONVERSION << std::endl;
	std::cout << "int:\t"		<< BAD_CONVERSION << std::endl;
	switch (type)
	{
		case TYPE_NEG_INF:
			std::cout << "float:\t"		<< STR_NEG_INFF << std::endl;
			std::cout << "double:\t"	<< STR_NEG_INF << std::endl;
			return ;
		case TYPE_INF:
			std::cout << "float:\t"		<< STR_INFF << std::endl;
			std::cout << "double:\t"	<< STR_INF << std::endl;
			return ;
		case TYPE_NAN:
			std::cout << "float:\t"		<< STR_NANF << std::endl;
			std::cout << "double:\t"	<< STR_NAN << std::endl;
			return ;
		default:
			std::cout << "float:\t"		<< BAD_CONVERSION << std::endl;
			std::cout << "double:\t"	<< BAD_CONVERSION << std::endl;
			return ;
	}
	
}

void	ScalarConverter::convert(std::string str)
{
	int					type;
	std::stringstream	ss(str);
	std::string			clean_str;
	std::string			test_str;

	type = 0;
	if (str.empty())
	{
		std::cerr << "Error: string is empty!" << std::endl;
		print_input(type);
		return ;
	}
	// clear white space
	ss >> clean_str;
	ss >> test_str;
	if (test_str.size() > 0)
	{
		std::cerr << "Error: multiple words on input!" << std::endl;
		print_input(type);
		return ;
	}
	std::cout << "input: >" << clean_str << std::endl << std::endl;
	// check for pseudo literals
	if (str == STR_NEG_INF || str == STR_NEG_INFF)
		type = TYPE_NEG_INF;
	else if (str == STR_INF || str == STR_INFF)
		type = TYPE_INF;
	else if (str == STR_NAN || str == STR_NANF)
		type = TYPE_NAN;
	if (type)
	{
		print_input(type);
		return ;
	}
	// check type
	if (clean_str.size() == 1 && !isdigit(clean_str[0]))
	{
		type = TYPE_CHAR;
	}
	else
	{
		// int		i = 0;
		// bool	sign;

		// sign = (clean_str[0] != '-');
		// if (clean_str[i] == '+' || clean_str[i] == '-')
		// 	i++;		
		// if (clean_str.find_first_not_of("0123456789.f")) // This is not working
		// {
		// 	type = 0;
		// 	print_input(type);
		// 	return ;
		// }
		// while (isdigit(clean_str[i]))
		// 	i++;
		// if (clean_str[i] == 'f')
		// 	type = 0;
		// if (!clean_str[i] && i != 0)
		// 	type = TYPE_INT;
		// if (clean_str[i] == '.')
		// 	i++;
		// while (isdigit(clean_str[i]))
		// 	i++;
		
	}
	// Conversion

	// Print
	std::cout << "char:\t"		<< static_cast<char>(clean_str[0]) << std::endl;
	std::cout << "int:\t"		<< static_cast<int>(clean_str[0]) << std::endl;
	std::cout << "float:\t"		<< static_cast<float>(clean_str[0]) << std::endl;
	std::cout << "double:\t"	<< static_cast<double>(clean_str[0]) << std::endl;
}
