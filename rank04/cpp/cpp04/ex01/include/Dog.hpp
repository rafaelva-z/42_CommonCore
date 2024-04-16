/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:17:37 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/15 20:10:02 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
	Brain	*brain;

	public:
	//	Orthodox Canonical Form
	Dog();
	Dog(const Dog &other);
	Dog&	operator=(const Dog& other);
	~Dog();
	//	Functions
	void				makeSound() const;
	const std::string&	getIdea(int index) const;
	void				setIdea(int index, const std::string &new_idea);
};

#endif