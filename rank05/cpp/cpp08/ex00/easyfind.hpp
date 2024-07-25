#pragma once

#include <iostream>
#include <algorithm>
#include <stdexcept>

template<typename T>
int	easyfind(T &container, int value)
{
	typename T::iterator	result = std::find(container.begin(), container.end(), value);

	if (result != container.end())
		return *result;
	else
		throw  std::out_of_range("Value not found in the container");
};
