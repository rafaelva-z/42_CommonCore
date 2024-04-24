/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:55 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/24 17:32:06 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main()
{
	// Colors for better readability on terminal
	std::string cyan = "\033[96m";
	std::string red = "\033[0;31m";
	std::string blue = "\033[0;34m";
	std::string reset = "\033[0m";

	std::cout << cyan + "-Constructors-" + reset << std::endl;
	/* Valid instatiations */
	Dog aDog;
	Dog *aDogptr = new Dog();
	Cat aCat;
	Cat *aCatptr = new Cat();
	Animal* AnimalGroup[2];
	AnimalGroup[0] = aDogptr;
	AnimalGroup[1] = aCatptr;


	/* avoid compilation warnings */
	(void)aDog;
	(void)aDogptr;
	(void)aCat;
	(void)aCatptr;
	(void)AnimalGroup;

	/* Invalid instatiations */
	// Animal aAnimal;
	// Animal* aAnimalptr = new Animal();
	std::cout << cyan + "-Destructors-" + reset << std::endl;
}