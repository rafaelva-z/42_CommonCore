/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:24:08 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/04 18:01:21 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

Phonebook::Phonebook(void)
{
	contactAmt = 0;
	lastAdded = -1;
	fieldWidth = 10;
	separator = '|';
};
Phonebook::~Phonebook(void)
{
};

void	Phonebook::writeLine(void)
{
	std::cout << std::string(fieldWidth * 4 + 3, '-') << std::endl;
}

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

void	Phonebook::add_contact(void)
{
	Contact contact;
	query(contact);
	if (contactAmt < 8)
		contactAmt++;
	register_contact(contact);
};

void	Phonebook::display_contact(int id)
{
	std::cout << "Displaying contact " << id-- << std::endl;
	writeLine();
	std::cout << "First Name: " << contacts[id].first_name << std::endl;
	std::cout << "Last Name: " << contacts[id].last_name << std::endl;
	std::cout << "Nickname: " << contacts[id].nickname << std::endl;
	std::cout << "Phone Number: " << contacts[id].phone_number << std::endl;
	std::cout << "Darkest Secret: " << contacts[id].secret << std::endl;
	writeLine();
}

void	Phonebook::display_contact_list(void)
{
	clearScreen();
	std::cout << "My Awesome PhoneBoook!" << std::endl;
	if (contactAmt == 0)
	{
		std::cout << "You have no contacts. Try adding one!" << std::endl;
		std::cout << "Press enter to continue." << std::endl;
		tag();
		std::getline(std::cin, input);	
	}
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
		writeLine();
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
		writeLine();
	}

};

void	Phonebook::select_contact(void)
{
	int id;

	if (contactAmt)
	{
		std::cout << "Enter the index of the contact you want to display." << std::endl;
		tag();
		std::getline(std::cin, input);
		id = ft_stoi(input);
		if (id > 0 && id <= contactAmt)
		{
			clearScreen();
			display_contact(id);
		}
		else
		{
			std::cout << "Invalid index. ";
		}
		std::cout << "Press enter to continue." << std::endl;
		tag();
		std::getline(std::cin, input);
	}
}
