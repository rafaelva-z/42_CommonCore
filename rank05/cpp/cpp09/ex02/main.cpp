#include "PmergeMe.hpp"
#include <cstdlib>
#include <list>

int main(int argc, char **argv)
{
	PmergeMe Pmme;

	if (argc <= 2)
	{
		std::cerr << "Invalid syntax. Try ./PmergeMe [Values]" << std::endl;
		return (1);
	}
	try
	{
		std::list<int> values;
		char	**iterator = &argv[1];
		for (int i = 0; iterator[i] != '\0'; i++)
		{
			std::string	arg(*iterator);
			int	value = atoi(iterator[i]);
			if (value < 0)
				throw (std::invalid_argument("Negative numbers not allowed"));
			
			values.push_back(1);
		}
		Pmme.execute();
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}