/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:26:26 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/04 17:45:03 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "utils.hpp"
#include "contact.hpp"
#include "console.hpp"

class	Phonebook
{
	private:
	std::string	input;
	int			lastAdded;
	int			fieldWidth;
	Contact		contacts[8];
	char		separator;
	int			contactAmt;

	public:
	Phonebook();
	~Phonebook();
	void	query(Contact& contact);
	void	register_contact(Contact& contact);
	void	add_contact();
	void	display_contact_list();
	void	select_contact(void);
	void	display_contact(int id);
	void	writeLine();
};

#endif
