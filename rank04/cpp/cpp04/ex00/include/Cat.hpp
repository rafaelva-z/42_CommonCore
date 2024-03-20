/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:17:37 by rvaz              #+#    #+#             */
/*   Updated: 2024/03/15 15:16:27 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "./Animal.hpp"

class Cat : public Animal
{
	public:
	//	Orthodox Canonical Form
	Cat();
	Cat(const std::string &name);
	Cat(const Cat &other);
	Cat&	operator=(const Cat& other);
	~Cat();
	//	Functions
	void	makeSound() const;
};

#endif