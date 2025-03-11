#include "RPN.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <exception>

RPN::RPN()
{
	// Nothing to do here
}

RPN::RPN(const RPN &other)
{
	_stack = other._stack;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}
RPN::~RPN()
{
	// Nothing to do here
}

void	RPN::reset()
{
	while (!_stack.empty())
		_stack.pop();
	_inputString.clear();
}

void	RPN::trim(std::string &str)
{
	str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
	str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);
}

void	RPN::calculate(std::string &str)
{
	reset();
	// Trim whitespace from both ends of the string
	trim(str);
	std::stringstream	ss(str);
	std::string			token;

	if (str.empty())
		throw (std::invalid_argument("Input string is empty"));
	while (!ss.eof())
	{
		if (ss >> token)
		{
			if (token.size() != 1)
				throw (std::invalid_argument("Invalid value, too many characters"));
			if (std::isdigit(token[0]))
				_stack.push(atoi(token.c_str()));
			else if (token.find_first_not_of("-+*/") == std::string::npos)
				operation(token[0]);
			else
				throw (std::invalid_argument("Invalid value, not a number or operator"));

		}
		else if (ss.fail())
			throw (std::invalid_argument("Unexpected error"));
	}
	if (_stack.size() != 1)
			throw (std::invalid_argument("Invalid input sequence"));
	std::cout << get_result() << std::endl;
}

void	RPN::operation(char &operand)
{
	if (_stack.empty())
		throw (std::invalid_argument("Invalid input sequence"));
	int value1 =_stack.top();
	_stack.pop();
	if (_stack.empty())
		throw (std::invalid_argument("Invalid input sequence"));
	int value2 = _stack.top();
	_stack.pop();

	switch (operand)
	{
		case '+':
			_stack.push(value1 + value2);
			break;
		case '-':
			_stack.push(value2 - value1);
			break;
		case '/':
			if (value1 == 0)
				throw std::runtime_error("Division by zero");
			_stack.push(value2 / value1);
			break;
		case '*':
			_stack.push(value1 * value2);
			break;
		default:
			throw std::invalid_argument("Unsupported operation");
	}
}

int		RPN::get_result()
{
	return (_stack.top());
}