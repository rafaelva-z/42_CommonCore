/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:02:25 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/24 19:12:12 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"

AMateria* Ice::clone() const
{
	Ice *newMateria = new Ice();
	return (newMateria);
}

void Ice::use(ICharacter& target)
{
	
}