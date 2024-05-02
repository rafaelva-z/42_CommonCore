/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:47:24 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/02 18:23:42 by rvaz             ###   ########.fr       */
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
	std::cout << std::endl << cyan + "-Mostly Constructors-" + reset << std::endl;
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(ice);
	src->learnMateria(cure);
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");

	std::cout << std::endl << cyan + "-Bob is attacked just as in the subject-" + reset << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	
	std::cout << std::endl << cyan + "-Character Copy-" + reset << std::endl;
	Character *char1 = new Character();
	tmp = src->createMateria("ice");
	char1->equip(tmp);
	tmp = src->createMateria("cure");
	char1->equip(tmp);
	tmp = src->createMateria("ice");
	char1->equip(tmp);
	tmp = src->createMateria("cure");
	char1->equip(tmp);
	Character *char2 = new Character(*char1);
	char2->use(3, *char1);


	std::cout << std::endl << cyan + "-Destructors-" + reset << std::endl;
	delete bob;
	delete me;
	delete src;
	delete char1;
	delete char2;

	std::cout << std::endl << red + "--MateriaSource Tests--" + reset << std::endl;
	IMateriaSource* matSrc = new MateriaSource();
	matSrc->learnMateria(ice);
	matSrc->learnMateria(ice);
	matSrc->learnMateria(cure);
	matSrc->learnMateria(cure);
	matSrc->learnMateria(cure);
	matSrc->learnMateria(ice);

	// FIX LEAKS ON MAIN AND LEAVE THEM ON CLASS!!
	
	delete ice;
	delete cure;
	delete matSrc;
}
