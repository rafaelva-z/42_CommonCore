#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <exception>

class RPN {

	public:
		RPN();
		RPN(const RPN &other);
		RPN	&operator=(const RPN &other);
		~RPN();

		void	operation(char &operand);
		void	calculate(std::string &str);
		int		get_result();
	
	private:
		std::stack<int>	_stack;
		std::string		_inputString;


};

#endif