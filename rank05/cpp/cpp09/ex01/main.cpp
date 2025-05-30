#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN rpn;

	if (argc != 2)
	{
		std::cerr << "Invalid syntax. Try ./RPN [string]" << std::endl;
		return (1);
	}
	try
	{
		std::string	input(argv[1]);
		rpn.calculate(input);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}


// TESTS 

// int main()
// {
// 	RPN rpn;

// 	std::cout << "\nError Tests" << std::endl;

// 	try {
// 		std::string	input("");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input(" ");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input("-");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input("- / + *");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input("A");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input("1a");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input("2 0 /");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input("2 3 - 2");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input("3 4 6 - - -");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input("+ 3 4");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	std::cout << "\nValid Tests" << std::endl;

// 	try {
// 		std::string	input("1 2 +");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input("4 2 /");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input("3 2 -");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input("9 9 *");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input("1 2 3 + +");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input("1 2 3 4 5 6 7 8 9 + + + + + + + +");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input("8 9 * 9 - 9 - 9 - 4 - 1 +");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input("9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	try {
// 		std::string	input("1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /");
// 		rpn.calculate(input);	
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	return (0);
// }
