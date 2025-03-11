#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe			Pmme;
	std::vector<int>	values;

	if (argc <= 2)
	{
		std::cerr << "Invalid syntax. Use a sequence of positive integers as arguments." << std::endl;
		std::cerr << "Example: ./PmergeMe 1 23 1234" << std::endl;
		return (1);
	}

	try
	{
		Pmme.parseArgs((const char **)argv);
		Pmme.execute();
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}
