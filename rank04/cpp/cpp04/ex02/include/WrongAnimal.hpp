/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:58:27 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/19 15:22:42 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
	std::string		type;
	
	public:
	// Orthodox Canonical Form
	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal&	operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();
	//	Getters
	const std::string&	getType(void) const;
	// Other Functions
	virtual void makeSound() const = 0;
};

#endif