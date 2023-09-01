/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:26:23 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/01 19:37:25 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sys/time.h>
#include "contact.class.hpp"
#include "phonebook.class.hpp"

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

int	main()
{
	Phonebook	MAPB;
	std::string	inpt;

	while (1)
	{
		printWelcome();
		std::cout << "MyPhoneBook>";
		std::cin >> inpt;
		if (inpt == "ADD")
			MAPB.add_contact();
		else if (inpt == "SEARCH")
			MAPB.display_contacts();
		else if (inpt == "EXIT")
			break;
	}
	std::cout << "Thank you for using My Awesome PhoneBook!" << std::endl;
}