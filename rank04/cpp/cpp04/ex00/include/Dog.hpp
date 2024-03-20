/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:17:37 by rvaz              #+#    #+#             */
/*   Updated: 2024/03/15 15:16:32 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "./Animal.hpp"

class Dog : public Animal
{
	public:
	//	Orthodox Canonical Form
	Dog();
	Dog(const std::string &name);
	Dog(const Dog &other);
	Dog&	operator=(const Dog& other);
	~Dog();
	//	Functions
	void	makeSound() const;
};

#endif