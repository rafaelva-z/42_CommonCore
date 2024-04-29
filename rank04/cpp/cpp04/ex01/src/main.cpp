/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:41:55 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/29 23:20:21 by rvaz             ###   ########.fr       */
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

	/* Test 01 - Array of Animals, 50/50 dogs and cats */
	std::cout << red + "----Test 01----" + reset << std::endl;

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

	std::cout << cyan + "-Animal Sounds-" + reset << std::endl;
	for (int i = 0; i < GROUP_SIZE; i++)
	{
		std::cout << blue << "Animal [" << i << "]" << reset << std::endl;
		AnimalGroup[i]->makeSound();
	}

	std::cout << std::endl << cyan + "-Destructors-" + reset << std::endl;
	for (int i = 0; i < GROUP_SIZE; i++)
	{
		std::cout << blue << "Animal [" << i << "]" << reset << std::endl;
		delete AnimalGroup[i];
	}

	/* Test 02 - Copy another Animal's ideas (also known as copyright infringement)*/
	std::cout << std::endl << red + "----Test 02----" + reset << std::endl;
	
	std::cout << std::endl << cyan + "-Constructors-" + reset << std::endl;
	Dog PhiloDog;
	Dog CopyDog;

	std::cout << std::endl << cyan + "-PhiloDog Original Ideas-" + reset << std::endl;
	PhiloDog.getBrain().setIdea(0, "I am a dog");
	PhiloDog.getBrain().setIdea(1, "I bark");
	PhiloDog.getBrain().setIdea(2, "A dog I am");
	PhiloDog.getBrain().setIdea(3, "Oh, a ball!!");
	for (int i = 4; i < IDEAS_SIZE; i++)
		PhiloDog.getBrain().setIdea(i, "Chase the ball!");
	for (int i = 0; i < 10 /*IDEAS_SIZE*/; i++)
		std::cout << blue << "[Idea " << i << "]" << reset << PhiloDog.getBrain().getIdea(i) << std::endl;
	std::cout << "..." << std::endl;
	for (int i = 95; i < IDEAS_SIZE; i++)
		std::cout << blue << "[Idea " << i << "]" << reset << PhiloDog.getBrain().getIdea(i) << std::endl;
	std::cout << std::endl;
	
	CopyDog = PhiloDog;

	std::cout << std::endl << cyan + "-Deepcopy proof-" + reset << std::endl;
	PhiloDog.getBrain().setIdea(4, "I believe someone is copying my ideas...");
	std::cout << blue << "[Idea " << 4 << "]" << reset << PhiloDog.getBrain().getIdea(4) << std::endl;
	std::cout << "PhiloDog Idea 0 addr: " << &PhiloDog.getBrain().getIdea(0) << std::endl;
	std::cout << "CopyDog Idea 0 addr: " << &CopyDog.getBrain().getIdea(0) << std::endl;

	std::cout << std::endl << cyan + "-CopyDog Stolen Ideas-" + reset << std::endl;
	for (int i = 0; i < 10 /*IDEAS_SIZE*/; i++)
		std::cout << blue << "[Idea " << i << "]" << reset << CopyDog.getBrain().getIdea(i) << std::endl;
	std::cout << "..." << std::endl;
	for (int i = 95; i < IDEAS_SIZE; i++)
		std::cout << blue << "[Idea " << i << "]" << reset << CopyDog.getBrain().getIdea(i) << std::endl;
	std::cout << std::endl << cyan + "-Destructors-" + reset << std::endl;
}
