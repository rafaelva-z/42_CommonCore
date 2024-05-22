/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:11:36 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/22 15:33:52 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <math.h>

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

static void printChar(const double d)
{
	std::cout << "char:\t";
	if (d <= std::numeric_limits<char>::max() 
		&& d >= std::numeric_limits<char>::min()
		&& isprint(static_cast<char>(d)))
		std::cout << static_cast<char>(d) << std::endl;
	else 
		std::cout << "non displayable" << std::endl;
}

static void printInt(const double d)
{
	std::cout << "int:\t";
	if (d <= std::numeric_limits<int>::max()
		&& d >= std::numeric_limits<int>::min())
		std::cout << static_cast<int>(d) << std::endl;
	else
		std::cout << BAD_CONVERSION << std::endl;
}

static void printFloat(const float f)
{
	std::cout << "float:\t";
	if (std::isinf(f))
	{
		if (f > 0)
			std::cout << std::fixed << STR_INFF << std::endl;
		else if (f < 0)
			std::cout << std::fixed << STR_NEG_INFF << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

static void printDouble(const double d)
{
	std::cout << "double:\t";
	if (std::isinf(d))
	{
		if (d > 0)
			std::cout << std::fixed << STR_INF << std::endl;
		else if (d < 0)
			std::cout << std::fixed << STR_NEG_INF << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}


static void print_input(int type)
{
	std::cout << "char:\t"		<< BAD_CONVERSION << std::endl;
	std::cout << "int:\t"		<< BAD_CONVERSION << std::endl;
	switch (type)
	{
		case TYPE_NEG_INF:
			std::cout << "float:\t"		<< STR_NEG_INFF << std::endl;
			std::cout << "double:\t"	<< STR_NEG_INF << std::endl;
			break ;
		case TYPE_INF:
			std::cout << "float:\t"		<< STR_INFF << std::endl;
			std::cout << "double:\t"	<< STR_INF << std::endl;
			break ;
		case TYPE_NAN:
			std::cout << "float:\t"		<< STR_NANF << std::endl;
			std::cout << "double:\t"	<< STR_NAN << std::endl;
			break ;
		default:
			std::cout << "float:\t"		<< BAD_CONVERSION << std::endl;
			std::cout << "double:\t"	<< BAD_CONVERSION << std::endl;
			break ;
	}
	std::cout << std::endl;
}

static int	checkPseudoLiterals(std::string &str)
{
	if (str == STR_NEG_INF || str == STR_NEG_INFF)
		return (TYPE_NEG_INF);
	else if (str == STR_INF || str == STR_INFF)
		return (TYPE_INF);
	else if (str == STR_NAN || str == STR_NANF)
		return (TYPE_NAN);
	return (TYPE_ERROR);
}

static int	checkNbType(std::string &str)
{
	double	nb;

	nb = strtod(str.c_str(), NULL);
	if (nb <= std::numeric_limits<int>::max() && nb >= std::numeric_limits<int>::min())
		return (TYPE_INT);
	return (TYPE_DOUBLE);
}

static int	checkNb(std::string &str)
{
	int			i = 0;
	size_t		f_pos;

	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!isdigit(str[i]))
	{
		std::cerr << "Error: Bad character at the start (index 0 or 1)" << std::endl;
		return (TYPE_ERROR);
	}
	while (isdigit(str[i]))
		i++;
	if (!str[i])
		return (TYPE_NUMBER);
	f_pos = str.find_first_of("f");
	if (str[i] == 'f' && !(f_pos < str.size() - 1))
		return (TYPE_FLOAT);
	else if (str[i] == 'f')
	{
		std::cerr << "Error: f out of place" << std::endl;
		return (TYPE_ERROR);
	}
	if (str[i] == '.')
		i++;
	if (!isdigit(str[i]))
	{
		std::cerr << "Error: bad character on string" << std::endl;
		return (TYPE_ERROR);
	}
	while (isdigit(str[i]))
		i++;
	if (!str[i])
		return (TYPE_DOUBLE);
	if (str[i] == 'f' && !(f_pos < str.size() - 1))
		return (TYPE_FLOAT);
	else if (str[i] == 'f')
	{
		std::cerr << "Error: f out of place on second segment" << std::endl;
		return (TYPE_ERROR);
	}
	std::cerr << "Error: invalid number" << std::endl;
	return (TYPE_ERROR);
}

static void printConversionInt(std::string &str)
{
	int	value;

	value = atoi(str.c_str());
	printChar(static_cast<double>(value));
	std::cout << "int:\t"		<< value << std::endl;
	std::cout << "float:\t"		<< std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double:\t"	<< std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
	std::cout << std::endl;
}

static void printConversionChar(std::string &str)
{
	printChar(static_cast<double>(str[0]));
	std::cout << "int:\t"		<< static_cast<int>(str[0]) << std::endl;
	std::cout << "float:\t"		<< std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << "f" << std::endl;
	std::cout << "double:\t"	<< std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
	std::cout << std::endl;
}

static void printConversionFloat(std::string &str)
{
	double	value;

	value = strtod(str.c_str(), NULL);
	printChar(value);
	printInt(value);
	printFloat(strtof(str.c_str(), NULL));
	printDouble(value);
	std::cout << std::endl;
}

static void	printConversionDouble(std::string &str)
{
	double	value;

	value = strtod(str.c_str(), NULL);
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
	std::cout << std::endl;
}


static void	printConversion(int type, std::string &str)
{
	switch (type)
	{
		case TYPE_CHAR:
			printConversionChar(str);
			break ;
		case TYPE_FLOAT:
			printConversionFloat(str);
			break ;
		case TYPE_INT:
			printConversionInt(str);
			break ;
		case TYPE_DOUBLE:
			printConversionDouble(str);
			break ;
		default:
			print_input(type);
			break;
	}
}

void	ScalarConverter::convert(const std::string &str)
{
	int					type;
	std::stringstream	ss(str);
	std::string			clean_str;
	std::string			test_str;

	type = TYPE_ERROR;
	if (str.empty())
	{
		std::cerr << "Error: string is empty!" << std::endl;
		print_input(TYPE_ERROR);
		return ;
	}
	// clear white space
	ss >> clean_str;
	ss >> test_str;
	if (test_str.size() > 0)
	{
		std::cerr << "Error: multiple words on input!" << std::endl;
		print_input(TYPE_ERROR);
		return ;
	}
	// check for pseudo literals
	type = checkPseudoLiterals(clean_str);
	// check type
	if (!type)
	{
		if (clean_str.size() == 1 && !isdigit(clean_str[0]))
			type = TYPE_CHAR;
		else
			type = checkNb(clean_str);
		if (type == TYPE_NUMBER)
			type = checkNbType(clean_str);
	}
	// Conversion/Print
	printConversion(type, clean_str);
}
