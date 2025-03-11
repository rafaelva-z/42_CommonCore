#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// Nothing to be done
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	if (this == &other)
		return ;
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
		return (*this);
	_db = other._db;
	return (*this);
}


BitcoinExchange::~BitcoinExchange()
{
	// Nothing to be done
}

int BitcoinExchange::importDb(const char *db_filename)
{
	std::ifstream	db_file(db_filename);
	if (!db_file.is_open())
		throw (std::runtime_error("Parsing: Couldn't open db file"));

	std::string		line;
	std::getline(db_file, line);
	line = removeSpaces(line);
	if (line != "date,exchange_rate")
	{
		db_file.close();
		throw (std::runtime_error("Parsing: db file: header invalid. First line should be: date,exchange_rate"));
	}

	while (std::getline(db_file, line))
	{
		std::stringstream	ss(line);
		std::string			date;
		double				value;

		std::getline(ss, date, ',');
		if (ss.fail() || !(ss >> value))
		{
			db_file.close();
			throw (std::runtime_error("Parsing: Invalid data format in db file"));
		}
		if (this->checkDate(date))
		{
			db_file.close();
			throw (std::runtime_error("Parsing: Invalid date on db file"));
		}
		_db.insert(std::pair<std::string, double>(date, value));
	}

	db_file.close();
	if (_db.empty())
		throw (std::runtime_error("Parsing: couldn't import db file data, maybe it's empty?"));
	return (0);
}

int BitcoinExchange::checkDate(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (print_error("Invalid date format: valid format is yyyy-mm-dd"));
	
	for (size_t i = 0; i < date.size(); i++)
	{
		if (!isdigit(date[i]) && i != 4 && i != 7)
			return (print_error("Invalid date format: valid format is yyyy-mm-dd"));
	}

	short	month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	short	year = atoi(&date[0]);
	short	month = atoi(&date[5]);
	short	day = atoi(&date[8]);
	
	if (!(year % 4))
		month_days[1] = 29;
	if (year < 2009)
		return (print_error("Invalid date: Invalid year, minimum year is 2009")); // Bitcoin launched in 2009
	if (month <= 0 || month > 12)
		return (print_error("Invalid date: Invalid month"));
	if (day <= 0 || day > month_days[month - 1])
		return (print_error("Invalid date: Invalid day"));

	return (0);
}

int BitcoinExchange::checkValue(std::stringstream &ss, double *i_value)
{
	if (!(ss >> *i_value))
	{
		print_error("No input value");
		return (1);
	}
	if (*i_value >= 1000)
	{
		print_error("Invalid input: value is not less than 1000");
		return (1);
	}
	if (*i_value <= 0)
	{
		print_error("Invalid input: value not a positive number");
		return (1);
	}
	std::string a;
	if (ss >> a)
	{
		print_error("Invalid input: bad characters or value");
		return (1);
	}
	return (0);
}

int	BitcoinExchange::outputResults(const char *input_file)
{
	if (_db.empty())
		throw (std::runtime_error("No data on _db"));

	std::ifstream	data_file(input_file);
	if (!data_file.is_open())
		throw (std::runtime_error("Couldn't open data file"));

	std::string	line;
	std::getline(data_file, line);
	line = removeSpaces(line);
	if (line != "date|value")
	{
		data_file.close();
		throw (std::runtime_error("Parsing: data file header invalid. First line should be: date | value"));
	}
	while (std::getline(data_file, line))
	{
		if (line.empty())
			continue ;
		line = removeSpaces(line);
		std::stringstream	ss(line);
		std::string			i_date;
		double				i_value;

		std::getline(ss, i_date, '|');
		if (this->checkDate(i_date))
			continue ;
		if (this->checkValue(ss, &i_value))
			continue ;
		std::map<std::string, double>::iterator db_it;

		db_it = _db.find(i_date);
		if (db_it == _db.end())
		{
			for (db_it = _db.begin(); db_it != _db.end(); db_it++)
			{
				if (db_it->first > i_date)
					break;
			}
			db_it--;
		}
		double	result = (db_it->second * i_value);
		std::cout << i_date << " => " << i_value << " = " << result << std::endl; 
	}
	data_file.close();
	return (0);
}

int	print_error(const char *msg)
{
	std::cerr << "Error: ";
	std::cerr << msg << std::endl;
	return (1);
}

int	print_error(const std::string &msg)
{
	std::cerr << "Error: ";
	std::cerr << msg << std::endl;
	return (1);
}

std::string	removeSpaces(const std::string &str)
{
	std::string	result;
	result.reserve(str.size()); // to avoid multiple allocations of the result string

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (*it != ' ')
			result += *it;
	}

    return result;
}
