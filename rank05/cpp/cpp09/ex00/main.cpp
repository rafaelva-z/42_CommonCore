#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <cctype>
#include <exception>
#include "BitcoinExchange.hpp"

#define DB_FILENAME "data.csv"

int main(int argc, char **argv)
{
	BitcoinExchange	btcE;

	if (argc != 2)
		return (print_error("Invalid syntax: Try ./btc [input_file]"));
	try
	{
		btcE.importDb(DB_FILENAME);;
		btcE.outputResults(argv[1]);
	}
	catch (std::exception &e)
	{
		return (print_error(e.what()));
	}
}