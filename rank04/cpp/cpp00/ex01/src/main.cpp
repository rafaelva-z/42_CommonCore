/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:26:23 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/04 17:40:56 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"
#include "../include/console.hpp"
#include "../include/phonebook.hpp"

int	main()
{
	Phonebook	MAPB;
	std::string	inpt;

	while (1)
	{
		printWelcome();
		while (1)
		{
			tag();
			std::getline(std::cin, inpt);
			if (inpt.empty())
				continue;
			else if (inpt == "ADD")
				MAPB.add_contact();
			else if (inpt == "SEARCH")
			{
				MAPB.display_contact_list();
				MAPB.select_contact();
			}
			else if (inpt != "EXIT")
				continue;
			break;
		}
		if (inpt == "EXIT")
			break;
	}
	std::cout << "Thank you for using My Awesome PhoneBook!" << std::endl;
}
