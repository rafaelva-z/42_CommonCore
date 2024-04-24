/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:00:16 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/24 19:01:40 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string.h>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Cure
{
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif