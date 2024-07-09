#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdlib.h> // for Array.cpp provided in the subject

template<typename T>
class Array {
private:
    T				*array = NULL;
	unsigned int	arr_size;

public:
    Array() : array(new T()), arr_size(0) {}
	Array(unsigned int n) : array(new T[n]), arr_size(n) {}
	Array(const Array &other)
	{
		*this = other;
	}
	~Array()
	{
		delete[] array;
	}
	
	Array &operator=(const Array &other)
	{
		if (this == &other)
			return (*this);
		// if (array)
		// 	delete[] array;
		T *new_array = new T[other.arr_size];

		for (unsigned int i = 0; i < other.arr_size; i++)
			new_array[i] = other.array[i];
		delete[] array;

		array = new_array;
		arr_size = other.arr_size;

		// arr_size = other.arr_size;
		// array = new T[arr_size];
		// for (unsigned int i = 0; i < arr_size; i++)
		// {
		// 	array[i] = other.array[i]; 
		// 	// std::cout << "cat" << std::endl;
		// }
		return (*this);
	}

    T& operator[](unsigned int index)
	{
		if (index >= arr_size)
			throw std::out_of_range("Index is out of range!");
		return array[index];
    }

    unsigned int size() const
	{
		return arr_size;
    }
};

#endif