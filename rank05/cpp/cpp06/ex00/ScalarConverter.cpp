/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:11:36 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/16 16:57:40 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <limits>

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

static int	checkPseudoLiterals(std::string str)
{
	if (str == STR_NEG_INF || str == STR_NEG_INFF)
		return (TYPE_NEG_INF);
	else if (str == STR_INF || str == STR_INFF)
		return (TYPE_INF);
	else if (str == STR_NAN || str == STR_NANF)
		return (TYPE_NAN);
	return (TYPE_ERROR);
}

static int	checkNbType(std::string str)
{
	long	nb;

	nb = atol(str.c_str());
	if (nb <= std::numeric_limits<int>::max() && nb >= std::numeric_limits<int>::min())
		return (TYPE_INT);
	if (nb <= std::numeric_limits<long>::max() && nb >= std::numeric_limits<double>::min())
		return (TYPE_DOUBLE);
	return TYPE_ERROR;
}

static int	checkNb(std::string str)
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
		std::cerr << "Error: Bad character on string" << std::endl;
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
	std::cerr << "Error: end of number" << std::endl;
	return (TYPE_ERROR);
}

static void printConversionInt(std::string &str)
{
	float value;

	value = atoi(str.c_str());
	std::cout << "char:\t";
	if (value <= std::numeric_limits<char>::max() 
		&& value >= std::numeric_limits<char>::min()
		&& isprint(static_cast<char>(value)))
		std::cout << static_cast<char>(value) << std::endl;
	else 
		std::cout << "non displayable" << std::endl;
	std::cout << "int:\t"		<< value << std::endl;
	std::cout << "float:\t"		<< static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double:\t"	<< static_cast<double>(value) << ".0" << std::endl;
}

static void printConversionChar(std::string &str)
{
	if (isprint(str[0]))
		std::cout << "char:\t"	<< str[0] << std::endl;
	else
		std::cout << "char:\t"	<< "non displayable" << std::endl;
	std::cout << "int:\t"		<< static_cast<int>(str[0]) << std::endl;
	std::cout << "float:\t"		<< static_cast<float>(str[0]) << ".0f" << std::endl;
	std::cout << "double:\t"	<< static_cast<double>(str[0]) << ".0" << std::endl;
}

static void printConversionFloat(std::string &str)
{
	float value;

	value = strtof(str.c_str(), NULL);
	std::cout << "char:\t";
	if (value <= std::numeric_limits<char>::max()
		&& value >= std::numeric_limits<char>::min()
		&& isprint(static_cast<char>(value)))
		std::cout << static_cast<char>(value) << std::endl;
	else 
		std::cout << "non displayable" << std::endl;
	std::cout << "int:\t"		<< static_cast<int>(value) << std::endl;
	std::cout << "float:\t"		<< value;
	if (value == static_cast<int>(value))
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	std::cout << "double:\t"	<< static_cast<double>(value);	
	if (value == static_cast<int>(value))
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

static void	printConversionDouble(std::string &str)
{
	float value;

	value = strtod(str.c_str(), NULL);
	std::cout << "char:\t";
	if (value <= std::numeric_limits<char>::max()
		&& value >= std::numeric_limits<char>::min()
		&& isprint(static_cast<char>(value)))
		std::cout << static_cast<char>(value) << std::endl;
	else 
		std::cout << "non displayable" << std::endl;
	std::cout << "int:\t";
	if (value <= std::numeric_limits<int>::max()
		&& value >= std::numeric_limits<int>::min())
		std::cout << static_cast<int>(value) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float:\t";
	if (static_cast<float>(value) <= std::numeric_limits<float>::max()
		&& static_cast<float>(value) >= std::numeric_limits<float>::min())
	{
		std::cout << static_cast<float>(value);
		if (value == static_cast<int>(value))
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
	else
		std::cout << BAD_CONVERSION << std::endl;
	std::cout << "double:\t"	<< value;	
	if (value == static_cast<int>(value))
		std::cout << ".0" << std::endl;
	else
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

void	ScalarConverter::convert(std::string str)
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
	// check other type
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
