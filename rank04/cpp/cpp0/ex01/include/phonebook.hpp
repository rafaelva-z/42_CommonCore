/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:26:26 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/02 20:00:38 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "utils.hpp"
#include "contact.hpp"
#include "console.hpp"

class	Phonebook
{
	private:
	std::string	inpt;
	int			lastAdded;
	int			fieldWidth;
	Contact		contacts[8];
	char		separator;
	
	public:
	int		contactAmt;

	Phonebook();
	~Phonebook();
	void	query(Contact& contact);
	void	register_contact(Contact& contact);
	void	add_contact();
	void	display_contacts();
};

#endif
