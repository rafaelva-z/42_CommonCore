/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:10:57 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/21 13:27:03 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main()
{
	Data* data0 = new Data(50);
	Data* data1 = NULL;
	uintptr_t uint_ptr;

	std::cout << "data0: " <<  data0->getData() << std::endl;

	uint_ptr =	Serializer::serialize(data0);
	data1 = Serializer::deserialize(uint_ptr);
	
	if (data1 == data0)
		std::cout << "These pointers have the same address!" << std::endl;
	else 
		std::cout << "These pointers have different addresses!" << std::endl;

	if (data1)
		std::cout << "data1: " << data1->getData() << std::endl;
	delete (data0);
}