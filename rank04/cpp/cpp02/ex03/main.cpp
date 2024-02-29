#include "Point.hpp"
#include "bsp.hpp"
#include "Fixed.hpp"

int main( void )
{
	std::string cyan = "\033[96m";
	std::string red = "\033[0;31m";
	std::string blue = "\033[0;34m";
	std::string reset = "\033[0m";

	bool result; 

	Point point(5, 0);
	Point t1(10, 0);
	Point t2(-10, -0.0f);
	Point t3(0, 10.5f);
	
	result = bsp(t1, t2, t3, point);

	std::cout	<< "Point (" << point.getX() << ", " << point.getY() << ") is " 
				<< (result ? cyan + "inside" : red + "outside") << reset << " the triangle" << std::endl;
}
