#include "Span.cpp"
#include <vector>
#include <set>
#include <list>
#include <cstdlib> 

int main()
{
	Span sp_empty(0);
	Span sp1 = Span(5);

	Span sp2(10);
	Span sp3(3);
	Span sp4(1000);

	int arr[] = {135, 10, 6};

	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);
	try {
		sp1.addNumber(11);
	} catch (const std::exception &e) {
		std::cout << "Exeption sp1: " << e.what() << std::endl;
	}

	sp2 = sp1;

	sp3.addNumbers(arr, arr + 3);

	for (int i = 0; i < 1000; ++i)
	{
		sp4.addNumber(std::rand());
	}

	std::cout << "=== Stored Values ===" << std::endl;
	std::cout << "sp_empty\t";
	sp_empty.printNumbers();
	std::cout << "sp1\t\t";
	sp1.printNumbers();
	std::cout << "sp2\t\t";
	sp2.printNumbers();
	std::cout << "sp3\t\t";
	sp3.printNumbers();
	std::cout << "sp4\t\t";
	sp4.printNumbers();

	std::cout << std::endl << "=== Shortest/Longest Span ===" << std::endl;
	std::cout << "sp1, Shortest span:\t" << sp1.shortestSpan() << std::endl;
	std::cout << "sp1, Longest span:\t" << sp1.longestSpan() << std::endl;

	std::cout << "sp2, Shortest span:\t" << sp2.shortestSpan() << std::endl;
	std::cout << "sp2, Longest span:\t" << sp2.longestSpan() << std::endl;

	std::cout << "sp4, Shortest span:\t" << sp4.shortestSpan() << std::endl;
	std::cout << "sp4, Longest span:\t" << sp4.longestSpan() << std::endl;
}
