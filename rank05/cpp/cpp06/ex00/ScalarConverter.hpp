/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:11:43 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/15 12:28:43 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <string>

#define BAD_CONVERSION	"impossible"
#define STR_INF			"+inf"
#define STR_INFF		"+inff"
#define STR_NEG_INF		"-inf"
#define STR_NEG_INFF	"-inff"
#define STR_NAN			"nan"
#define STR_NANF		"nanf"
#define TYPE_ERROR		0
#define TYPE_CHAR		1
#define TYPE_INT		2
#define TYPE_FLOAT		3
#define TYPE_DOUBLE		4
#define TYPE_NUMBER		10
#define TYPE_INF		101
#define TYPE_NEG_INF	102
#define TYPE_NAN		103	

class ScalarConverter
{
	public:
		static void	convert(std::string str);
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &other);
		ScalarConverter &operator=(ScalarConverter &other);
		~ScalarConverter();
		// static int	checkNb(std::string str);
		// static int	checkPseudoLiterals(std::string str);

};

#endif
