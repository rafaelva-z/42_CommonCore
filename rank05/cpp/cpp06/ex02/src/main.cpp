/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:36:26 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/21 19:30:55 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#define ARR_SIZE 10

int main()
{
	Base *baseArr[ARR_SIZE];
	Base *baseNull = NULL;

	std::cout << "Identify NULL Ptr" << std::endl;
	identify(baseNull);

	std::cout << "Identify ptr" << std::endl;
	for (int i = 0; i < ARR_SIZE; i++)
	{
		baseArr[i] = generate();
		identify(baseArr[i]);
	}
	std::cout << std::endl;
	
	std::cout << "Identify ref" << std::endl;
	for (int i = 0; i < ARR_SIZE; i++)
		identify(*baseArr[i]);

	for (int i = 0; i < ARR_SIZE; i++)
		delete (baseArr[i]);
}