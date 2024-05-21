/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:36:11 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/21 19:30:17 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	// Nothing to be done
}

Base*	generate(void)
{
	int	randomNb = rand() % 3;
	
	if (randomNb == 0)
		return (new A());
	else if (randomNb == 1)
		return (new B());
	else if (randomNb == 2)
		return (new C());
	else
		return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Ptr of type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Ptr of type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Ptr of type C" << std::endl;
	else
		std::cerr << "Couldn't identify Ptr type" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Ref of type A\n";
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Ref of type B\n"; 
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Ref of type C\n"; 
		return ;
	}
	catch(const std::exception& e){}
	std::cerr << "Couldn't identify Ref type" << std::endl;
		
}
