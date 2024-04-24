/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:55 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/19 15:21:31 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main()
{
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
}