/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:55 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/15 20:05:52 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

# define GROUP_SIZE 10

int main()
{
	// Colors for better readability on terminal
	std::string cyan = "\033[96m";
	std::string red = "\033[0;31m";
	std::string blue = "\033[0;34m";
	std::string reset = "\033[0m";

	std::cout << cyan + "-Constructors-" + reset << std::endl;
	Animal* AnimalGroup[GROUP_SIZE];
	
	for (int i = 0; i < GROUP_SIZE; i++)
	{
		std::cout << blue << "Animal [" << i << "]" << reset << std::endl;
		if (i < GROUP_SIZE / 2)
			AnimalGroup[i] = new Cat();
		else
			AnimalGroup[i] = new Dog();
	}

	std::cout << cyan + "-Destructors-" + reset << std::endl;
	for (int i = 0; i < GROUP_SIZE; i++)
	{
		std::cout << blue << "Animal [" << i << "]" << reset << std::endl;
		delete AnimalGroup[i];
	}
	return (0);
}