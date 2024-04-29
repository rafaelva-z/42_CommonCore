/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:17:37 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/29 22:12:58 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
	//	Orthodox Canonical Form
	Cat();
	Cat(const Cat &other);
	Cat&	operator=(const Cat& other);
	~Cat();
	//	Functions
	void	makeSound() const;
};

#endif
