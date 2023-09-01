/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:26:26 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/01 20:06:52 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

void	clearScreen();

class	Phonebook
{
	private:
	std::string	inpt;
	int			lastAdded;
	Contact		contacts[9];
	
	public:
	int		contactAmt;

	Phonebook()
	{
		contactAmt = 0;
		lastAdded = 0;
	};
	~Phonebook()
	{
	};

	void	query()
	{
		inpt.clear();
		while (inpt.empty())
		{
			std::cout << "First Name:";
			std::cin >> inpt;
		}
		contacts[0].first_name = inpt;
		inpt.clear();
		while (inpt.empty())
		{
			std::cout << "Last Name:";
			std::cin >> inpt;
		}
		contacts[0].last_name = inpt;
		inpt.clear();
		while (inpt.empty())
		{
			std::cout << "Nickname:";
			std::cin >> inpt;
		}
		contacts[0].nickname = inpt;
		inpt.clear();
		while (inpt.empty())
		{
			std::cout << "Phone Number:";
			std::cin >> inpt;
		}
		contacts[0].phone_number = inpt;
		inpt.clear();
		while (inpt.empty())
		{
			std::cout << "Darkest Secret:";
			std::cin >> inpt;
		}
		contacts[0].secret = inpt;
		inpt.clear();
	}

	void	Phonebook::register_contact(int id)
	{
		contacts[id].first_name = contacts[0].first_name;
		contacts[id].last_name = contacts[0].last_name;
		contacts[id].nickname = contacts[0].nickname;
		contacts[id].phone_number = contacts[0].phone_number;
		contacts[id].secret = contacts[0].secret;
	}

	void	add_contact(int index)
	{
		/* 
		Contact local;
		std::string name = getline("Name");
		std::string name = getline("Name");
		std::string name = getline("Name");
		std::string name = getline("Name");
		
		contacts[index] = crate_contact(name, lastname, nickname);
		 */

		query();
		if (contactAmt < 8)
			contactAmt++;
		register_contact(lastAdded + 1);
		if (lastAdded == 8)
			lastAdded = 1;
		else
			lastAdded++;
	};

	void	display_contacts()
	{
		clearScreen();
		std::cout << "My Awesome PhoneBoook!";
		if (contactAmt == 0)
			std::cout << "You have no contacts! Try adding one!";
		else
		{

		}
		inpt.clear();
		std::cin >> inpt;
	}
};

#endif