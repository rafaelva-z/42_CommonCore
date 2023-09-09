/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:39:07 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/09 20:39:18 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int	main()
{
	// Colors
	std::string cyan = "\033[96m";
	std::string red = "\033[0;31m";
	std::string reset = "\033[0m";
	std::string tag = cyan + "[Harl2.0] " + reset;

	Harl harl;

	std::cout << tag + red + "DEBUG COMPLAINT" + reset << std::endl;
	harl.complain("DEBUG");
	std::cout << tag + red + "INFO COMPLAINT" + reset << std::endl;
	harl.complain("INFO");
	std::cout << tag + red + "WARNING COMPLAINT" + reset << std::endl;
	harl.complain("WARNING");
	std::cout << tag + red + "ERROR COMPLAINT" + reset << std::endl;
	harl.complain("ERROR");
}
