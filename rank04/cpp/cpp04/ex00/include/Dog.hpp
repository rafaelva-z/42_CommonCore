/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:17:37 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/29 22:13:01 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
	//	Orthodox Canonical Form
	Dog();
	Dog(const Dog &other);
	Dog&	operator=(const Dog& other);
	~Dog();
	//	Functions
	void	makeSound() const;
};

#endif
