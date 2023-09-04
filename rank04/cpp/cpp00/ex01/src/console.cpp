/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:52:42 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/04 17:12:51 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/console.hpp"

void	clearScreen()
{
	std::cout << "\x1B[2J\x1B[H";
}

void printCommands()
{
	std::cout << "	ADD	- save a new contact to Your Awesome PhoneBook " << std::endl;
	std::cout << "	SEARCH	- display a specific contact" << std::endl;
	std::cout << "	EXIT	- The program quits and the contacts are lost forever!" << std::endl;
}

void printWelcome()
{
	clearScreen();
	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	std::cout << "Here's what you can do:" << std::endl;
	printCommands();
}

void	displayField(const std::string& text, int fieldWidth)
{
	std::cout << alignRight(text, (long unsigned int)fieldWidth);
}

void	tag(void)
{
	std::cout << "MyPhoneBook>";
}
