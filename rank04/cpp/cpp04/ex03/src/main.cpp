/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:47:24 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/29 18:23:26 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"


int main()
{
	// Colors for better readability on terminal
	std::string cyan = "\033[96m";
	std::string red = "\033[0;31m";
	std::string blue = "\033[0;34m";
	std::string reset = "\033[0m";

	std::cout << red + "--Subject Main--" + reset << std::endl;

	std::cout << cyan + "-Mostly Constructors-" + reset << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");

	std::cout << cyan + "-Bob is attacked-" + reset << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	
	std::cout << cyan + "-Destructors-" + reset << std::endl;
	delete bob;
	delete me;
	delete src;

	std::cout << red + "--MateriaSource Tests--" + reset << std::endl;
	IMateriaSource* matSrc = new MateriaSource();
	matSrc->learnMateria(new Ice());
	matSrc->learnMateria(new Ice());
	matSrc->learnMateria(new Cure());
	matSrc->learnMateria(new Cure());
	matSrc->learnMateria(new Ice());
	matSrc->learnMateria(new Cure());



}
