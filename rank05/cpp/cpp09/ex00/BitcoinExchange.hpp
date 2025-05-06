#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <cctype>
#include <ctime>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange	&operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		int	importDb(const char *db_filename);
		int	outputResults(const char *input_file);

	private:
		std::map<std::string, double>	_db;

		int	checkDate(const std::string &date);
		int	checkValue(std::stringstream &ss, double *i_value);

		void reset();
};

int			print_error(const char *msg);
int			print_error(const std::string &msg);
std::string	removeSpaces(const std::string &str);

#endif
