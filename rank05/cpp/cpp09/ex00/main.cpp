#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BitcoinExchange.hpp"

int	print_error(const char *msg)
{
	std::cout << "Error: ";
	std::cout << msg << std::endl;
	return (1);
}

int main(int argc, char **argv)
{
    if (argc <= 1 || argc >= 3)
		return (print_error("Invalid syntax: Try ./btc \"input_file\" (\"output_file\")"));
	
	std::ifstream input_file(argv[1]);
	if (!input_file.is_open())
		return (print_error("Couldn't open input file"));
	if (argc == 3)
	{
		std::ifstream output_file(argv[2]);
		if (!output_file.is_open())
			return (print_error("Couldn't open output file"));
	}


}