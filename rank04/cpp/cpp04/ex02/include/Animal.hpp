/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:58:27 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/19 14:58:37 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
	std::string		type;
	
	public:
	// Orthodox Canonical Form
	Animal();
	Animal(const Animal &other);
	Animal&	operator=(const Animal& other);
	virtual	~Animal();
	//	Getters
	const std::string&	getType(void) const;
	//	Other Functions
	virtual void makeSound() const = 0;
};

#endif