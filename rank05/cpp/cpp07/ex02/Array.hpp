#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array {
private:
	T		*_array;
	unsigned int	_arr_size;

public:
	Array() : _array(NULL), _arr_size(0)
	{
		// Nothing to be done
	}

	Array(unsigned int n) : _array(new T[n]), _arr_size(n)
	{
		// Initialize values
		for (unsigned int i = 0; i < n; i++)
			_array[i] = T();
	}

	Array(const Array &other): _array(NULL), _arr_size(0)
	{
		*this = other;
	}

	~Array()
	{
		delete[] _array;
	}
	
	Array &operator=(const Array &other)
	{
		if (this == &other)
			return (*this);
		delete[] _array;
		_array = NULL;
		if (other._array)
		{
			T *new_array = new T[other._arr_size];

			for (unsigned int i = 0; i < other._arr_size; i++)
			{
				new_array[i] = other._array[i];
			}
			_array = new_array;
		}
		_arr_size = other._arr_size;
		return (*this);
	}

	T& operator[](unsigned int index)
	{
		if (index >= _arr_size)
			throw std::out_of_range("Index is out of range!");
		return (_array[index]);
	}

	unsigned int get_size() const
	{
		return (_arr_size);
	}

	void	print_values() const
	{
		std::cout << "{ ";
		if (_array && _arr_size > 0)
		{
			for (unsigned int i = 0; i < _arr_size; i++)
			{
				std::cout << _array[i] << " ";
			}
		}
		else
			std::cout << "empty ";
		std::cout << "} ";
		std::cout << _arr_size << " values" << std::endl;
	}
};

#endif