/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:47 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/13 18:00:26 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments (do ./ScalarConverter <value>)"
			<< std::endl;
		return (1);
	}
	ScalarConverter::convert(std::string(argv[1]));
}