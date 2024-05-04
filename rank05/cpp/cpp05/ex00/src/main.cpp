/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:33:24 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/04 17:04:08 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main()
{
	Bureaucrat b1("Bobreaucrat", 10);

	std::cout << b1 << std::endl;

	Bureaucrat b2("Jackreaucrat", 0);

	try
	{
		Bureaucrat b2("Jackreaucrat", 0);
		std::cout << "This should not be printed" << std::endl;
	}
	catch (std::exception& e)
	{
		Bureaucrat b2("Jackreaucrat", 1);
		std::cout << e.what() << std::endl;
	}

	
}