/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:15:32 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/12 12:08:28 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

std::string cyan = "\033[96m";
std::string red = "\033[0;31m";
std::string reset = "\033[0m";
std::string tag = cyan + "[Harl2.0] " + reset;

Harl::Harl(void) : _filter(-1)
{
	_fLevel[0] = &Harl::debug;
	_fLevel[1] = &Harl::info;
	_fLevel[2] = &Harl::warning;
	_fLevel[3] = &Harl::error;
	_level[0] = "DEBUG";
	_level[1] = "INFO";
	_level[2] = "WARNING";
	_level[3] = "ERROR";
}

Harl::~Harl(void) {}

void	Harl::debug(void)
{
	std::cout	<< tag + red + "DEBUG COMPLAINT" + reset << std::endl
				<< "I love having extra bacon for my " 
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				<< "I really do!" << std::endl;
}
void	Harl::info(void)
{
	std::cout	<< tag + red + "INFO COMPLAINT" + reset << std::endl
				<< "I cannot believe adding extra bacon costs more money."
				<< "You didn’t put enough bacon in my burger! " 
				<< "If you did, I wouldn’t be asking for more!" << std::endl;
}
void	Harl::warning(void)
{
	std::cout	<< tag + red + "WARNING COMPLAINT" + reset << std::endl
				<< "I think I deserve to have some extra bacon for free. " 
				<< "I’ve been coming for years whereas you started working " 
				<< "here since last month." << std::endl;
}
void	Harl::error(void)
{
	std::cout	<< tag + red + "ERROR COMPLAINT" + reset << std::endl
				<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}

void	Harl::complain(std::string const &level)
{
	int		i;
	short	print;

	i = _filter - 1;
	print = 0;
	if (_filter == -1)
		std::cout 	<< "[ Probably complaining about insignificant problems ]" << std::endl;
	else
	{
		while (++i < 4)
		{
			if (level == _level[i])
				print = 1;
			if (print)
				(this->*_fLevel[i])();
		}
	}
}

void	Harl::set_filter(std::string const &level)
{
	int i;

	for (i = 0; _level[i] != level && i < 4; i++)
		;
	switch (i)
	{
		case 0:
			_filter = 0;
			break;
		case 1:
			_filter = 1;
			break;
		case 2:
			_filter = 2;
			break;
		case 3:
			_filter = 3;
			break;
		default:
			return ;
	}
}