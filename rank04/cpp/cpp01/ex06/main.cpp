/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:15:36 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/09 20:58:15 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int	main(int argc, char **argv)
{
	// Colors
	std::string cyan = "\033[96m";
	std::string red = "\033[0;31m";
	std::string reset = "\033[0m";
	std::string tag = cyan + "[Harl2.0] " + reset;

	int			case_int;
	std::string	arg;
	Harl		harl;

	if (argc != 2)
		return 0;
	arg = argv[1];
	case_int = 0;
	while (harl.f_name[case_int] != arg && case_int < 4)
		case_int++;
	switch (case_int) 
	{
		case 0:
			harl.filter = 0;
			break;
		case 1:
			harl.filter = 1;
			break;
		case 2:
			harl.filter = 2;
			break;
		case 3:
			harl.filter = 3;
			break;
		default:
			std::cout 	<< "[ Probably complaining about insignificant problems ]"
						<< std::endl;
			return 0;
	}
	
	// Tests
	std::cout << tag + red + "DEBUG COMPLAINT" + reset << std::endl;
	harl.complain("DEBUG");
	std::cout << tag + red + "INFO COMPLAINT" + reset << std::endl;
	harl.complain("INFO");
	std::cout << tag + red + "WARNING COMPLAINT" + reset << std::endl;
	harl.complain("WARNING");
	std::cout << tag + red + "ERROR COMPLAINT" + reset << std::endl;
	harl.complain("ERROR");
}
