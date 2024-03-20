/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:58:27 by rvaz              #+#    #+#             */
/*   Updated: 2024/03/14 18:04:38 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal
{
	protected:
	std::string		_type;
	
	public:
	// Orthodox Canonical Form
	Animal();
	Animal(const std::string &name);
	Animal(const Animal &other);
	Animal&	operator=(const Animal& other);
	~Animal();
	//	Getters
	const std::string&	getType(void) const;
	//	MakeSound
	void makeSound() const;
};

#endif