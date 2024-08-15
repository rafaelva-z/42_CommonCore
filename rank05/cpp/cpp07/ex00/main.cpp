#include <header.hpp>
#include <iostream>

int main()
{
	std::cout << "--- Subject Tests (int, std::string) ---" << std::endl;

	int a = 2;
	int b = 3;

	swap( a, b );
	std::cout << "Values: a = " << a << "; b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "Values: c = " << c << "; d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "swap( c, d )" << std::endl;
	swap( c, d );
	std::cout << "Values: c = " << c << "; d = " << d << std::endl << std::endl;

	std::cout << "--- My Tests ---" << std::endl;
	std::cout << "--- double ---" << std::endl;

	double e = 1.11;
	double f = 0.42;

	std::cout << "Values: e = " << e << "; f = " << f << std::endl;
	std::cout << "Min of " << e << " and " << f << " is " << min<double>(e, f) << std::endl;
	std::cout << "Max of " << e << " and " << f << " is " << max<double>(e, f) << std::endl;
	std::cout << "swap(e, f)" << std::endl;
	swap(e, f);
	std::cout << "Values: e = " << e << "; f = " << f << std::endl << std::endl;

	std::cout << "--- float ---" << std::endl;

	float g = 999.25;
	float h = 999;

	std::cout << "Values: g = " << g << "; h = " << h << std::endl;
	std::cout << "Min of " << g << " and " << h << " is " << min<float>(g, h) << std::endl;
	std::cout << "Max of " << g << " and " << h << " is " << max<float>(g, h) << std::endl;
	std::cout << "swap(g, h)" << std::endl;
	swap(g, h);
	std::cout << "Values: g = " << g << "; h = " << h << std::endl;
}
