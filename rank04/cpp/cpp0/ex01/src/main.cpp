/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:26:23 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/02 19:57:18 by rvaz             ###   ########.fr       */
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
		std::cout << "MyPhoneBook>";
		std::getline(std::cin, inpt);
		if (inpt.empty())
        	continue;
		else if (inpt == "ADD")
			MAPB.add_contact();
		else if (inpt == "SEARCH")
			MAPB.display_contacts();
		else if (inpt == "EXIT")
			break;
	}
	std::cout << "Thank you for using My Awesome PhoneBook!" << std::endl;
}
