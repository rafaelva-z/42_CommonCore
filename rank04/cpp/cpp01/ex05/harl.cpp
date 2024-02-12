/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:39:16 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/12 12:08:38 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

Harl::Harl(void)
{
	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;
	f_name[0] = "DEBUG";
	f_name[1] = "INFO";
	f_name[2] = "WARNING";
	f_name[3] = "ERROR";
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout	<< "I love having extra bacon for my " 
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				<< "I really do!" << std::endl;
}
void	Harl::info(void)
{
	std::cout	<< "I cannot believe adding extra bacon costs more money."
				<< "You didn’t put enough bacon in my burger! " 
				<< "If you did, I wouldn’t be asking for more!" << std::endl;
}
void	Harl::warning(void)
{
	std::cout	<< "I think I deserve to have some extra bacon for free. " 
				<< "I’ve been coming for years whereas you started working " 
				<< "here since last month." << std::endl;
}
void	Harl::error(void)
{
	std::cout 	<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
		if (level == f_name[i])
			(this->*f[i])();
}
	