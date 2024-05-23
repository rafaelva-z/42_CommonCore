/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:10:57 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/23 13:21:01 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main()
{
	Data		dataStruct;
	Data*		data1;
	uintptr_t	uint_ptr;

	dataStruct.data = 50;

	std::cout << "dataStruct ptr:\t" << &dataStruct << " | content: " << dataStruct.data << std::endl;

	uint_ptr = Serializer::serialize(&dataStruct);
	data1 = Serializer::deserialize(uint_ptr);
	
	if (data1 == &dataStruct)
		std::cout << "These pointers have the same address!" << std::endl;
	else 
		std::cout << "These pointers have different addresses!" << std::endl;

	if (data1)
		std::cout << "data1 ptr:\t" << data1 << " | content: " << data1->data << std::endl;
}
