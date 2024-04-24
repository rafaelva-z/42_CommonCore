/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:07:17 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/24 17:58:04 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string.h>

class AMateria
{
	protected:
		std::string	type;

	public:
	AMateria();
	AMateria(const AMateria &other);
	AMateria&	operator=(const AMateria& other);
	virtual ~AMateria();
	AMateria(std::string const & type);


	std::string const & getType() const; //Returns the materia type

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) = 0;
};

#endif