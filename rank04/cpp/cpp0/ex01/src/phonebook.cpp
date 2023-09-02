/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:24:08 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/02 19:49:51 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

Phonebook::Phonebook()
{
	contactAmt = 0;
	lastAdded = -1;
	fieldWidth = 10;
	separator = '|';
};
Phonebook::~Phonebook()
{
};

void	Phonebook::query(Contact& contact)
{	
	getInput("First Name:", contact.first_name);
    getInput("Last Name:", contact.last_name);
    getInput("Nickname:", contact.nickname);
    getInput("Phone Number:", contact.phone_number);
    getInput("Darkest Secret:", contact.secret);
}

void	Phonebook::register_contact(Contact& contact)
{
	if (lastAdded == 7)
	{
		contacts[0] = contact;
		lastAdded = 0;
	}
	else
	{
		contacts[lastAdded + 1] = contact;
		lastAdded++;
	}
}

void	Phonebook::add_contact()
{
	Contact contact;
	query(contact);
	if (contactAmt < 8)
		contactAmt++;
	register_contact(contact);
};

void	Phonebook::display_contacts()
{
	std::string input;
	clearScreen();
	std::cout << "My Awesome PhoneBoook!" << std::endl;
	if (contactAmt == 0)
		std::cout << "You have no contacts. Try adding one! Press enter to continue.";
	else
	{
		displayField("Index", fieldWidth);
		std::cout << separator;
		displayField("First Name", fieldWidth);
		std::cout << separator;
		displayField("Last Name", fieldWidth);
		std::cout << separator;
		displayField("Nickname", fieldWidth);
		std::cout << std::endl;
		std::cout << std::string(fieldWidth * 4 + 3, '-') << std::endl;
		for (int i = 0; i < contactAmt; i++)
		{
			displayField(itos(i + 1), fieldWidth);
			std::cout << separator;
			displayField(contacts[i].first_name, fieldWidth);
			std::cout << separator;
			displayField(contacts[i].last_name, fieldWidth);
			std::cout << separator;
			displayField(contacts[i].nickname, fieldWidth);
			std::cout << std::endl;
		}
		std::cout << "Enter the index of the contact you want to search." << std::endl;
		std::getline(std::cin, input);
		if (/*number between 1-8*/1 == 0)
		{
			//display contact
		}
		else
		{
			std::cout << "Invalid input. Press enter to continue.";
		}
	}
	std::getline(std::cin, input);
};
