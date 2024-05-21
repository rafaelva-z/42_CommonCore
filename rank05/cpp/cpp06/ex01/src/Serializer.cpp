/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:37:00 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/21 13:29:04 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <stdint.h>

/* Public */
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

/* Private */
Serializer::Serializer()
{
	// Nothing to do here
}

Serializer::~Serializer()
{
	// Nothing to do here
}

Serializer::Serializer(Serializer &other)
{
	if (this == &other)
		return ;
	*this = other;
}

Serializer& Serializer::operator=(Serializer &other)
{
	(void)other;
	return (*this);
}
