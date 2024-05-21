/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:28:06 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/21 13:21:28 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/* Public */
Data::Data() : data(0)
{
	// Nothing to be done
}

Data::Data(int data) : data(data)
{
	// Nothing to be done
}

Data::~Data()
{
	// Nothing to be done
}

Data::Data(Data &other)
{
	if (this == &other)
		return ;
	*this = other;
}

Data&	Data::operator=(Data &other)
{
	data = other.data;
	return (*this);
}

int		Data::getData() const
{
	return (data);
}

void	Data::setData(int d)
{
	this->data = d;
}
