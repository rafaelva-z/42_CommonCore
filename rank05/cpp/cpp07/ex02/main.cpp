#include <Array.hpp>
#include <iostream>
# include <stdlib.h> // for Array.cpp provided in the subject

#define MAX_VAL 750
int main(int, char**)
{
	{
		Array<int> def_const;
		Array<int> def_const1;
		Array<int> def_const2;
		Array<int> param_zero(0);
		Array<int> param_any(42);
		Array<int> copy_const_empty(def_const);
		Array<int> copy_const0(param_zero);
		Array<int> copy_const_any(param_any); 

		std::cout << "--- My tests ---" << std::endl;

		// Default constructor
		std::cout << "Default Constructor values:" << std::endl;
		def_const.print_values();

		// Parameterized constructor
		std::cout << "Parameter Constructor (0) values:" << std::endl;
		param_zero.print_values();

		std::cout << "Parameter Constructor (42) values:" << std::endl;
		param_any.print_values();

		// Copy constructor
		std::cout << "copy constructor values (copy from empty):" << std::endl;
		copy_const_empty.print_values();

		std::cout << "copy constructor values (0):" << std::endl;
		copy_const0.print_values();

		std::cout << "copy constructor values (42 (any value)):" << std::endl;
		copy_const_any.print_values();

		// Operator=
		def_const1 = def_const;
		std::cout << "Operator= (empty = empty) values:" << std::endl;
		def_const1.print_values();

		def_const = param_any;
		std::cout << "Operator= (empty = 42 (any value)) values:" << std::endl;
		def_const.print_values();

		def_const = param_any;
		std::cout << "Operator= (42 (any value) = 42 (any value)) values:" << std::endl;
		def_const.print_values();

		param_any = def_const2;
		std::cout << "Operator= (42 (any value) = empty) values:" << std::endl;
		def_const.print_values();

		std::cout << "--- Set value--- " << std::endl;
		def_const[10] = 100;

		std::cout << "--- Acess value--- " << std::endl;
		std::cout << def_const[10] << std::endl;
	}
	{
		std::cout << std::endl << "--- File Provided on intra ---" << std::endl;
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
		return 0;
	}
}