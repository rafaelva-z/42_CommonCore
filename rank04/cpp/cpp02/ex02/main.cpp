#include "Fixed.hpp"
#include <iostream>


int main( void )
{
	std::string cyan = "\033[96m";
	std::string red = "\033[0;31m";
	std::string blue = "\033[0;34m";
	std::string reset = "\033[0m";

	std::cout << cyan << "--------Some Constructors--------" << reset << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c( 2 );
	
	std::cout << cyan << "--------Increment/Decrement tests--------" << reset << std::endl;
	std::cout << red << "_a: " << a << reset << std::endl;
	std::cout << ++a << std::endl;
	std::cout << red << "_a: " << a << reset << std::endl;
	std::cout << a++ << std::endl;
	std::cout << red << "_a: " << a << reset << std::endl;
	std::cout << a-- << std::endl;
	std::cout << red << "_a: " << a << reset << std::endl;
	std::cout << --a << std::endl;
	std::cout << red << "_a: " << a << reset << std::endl;

	std::cout << cyan << "--------Arithmetic tests--------" << reset << std::endl;
	std::cout << red << "values: a: " << a << " b: " << b << " c: " << c << reset << std::endl;
	std::cout << red << "(b + c)" << reset << std::endl;
	std::cout << (b + c) << std::endl;
	std::cout << red << "(c - b)" << reset << std::endl;
	std::cout << (c - b) << std::endl;
	std::cout << red << "(b * c)" << reset << std::endl;
	std::cout << (b * c) << std::endl;
	std::cout << red << "(b / c)" << reset << std::endl;
	std::cout << (b / c) << std::endl;
	std::cout << red << "(a + b * c + Fixed(1000))" << reset << std::endl;
	std::cout << (a + b * c + Fixed(1000)) << std::endl;

	std::cout << cyan << "--------Min/Max tests--------" << reset << std::endl;
	std::cout << red << "values: a: " << a << " b: " << b << reset << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << red << "values: a: " << a << " c: " << c << reset << std::endl;
	std::cout << Fixed::max( a, c ) << std::endl;
	std::cout << Fixed::min( a, c ) << std::endl;
	std::cout << cyan << "--------Some Destructors--------" << reset << std::endl;
}
