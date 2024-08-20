#include "Span.hpp"
#include <limits>
#include <set>

Span::Span()
{
	// Nothing to be done
}

Span::Span(unsigned int N): maxSize(N)
{
	// Nothing to be done
}

Span::Span(const Span &other)
{
	if (this == &other)
		return ;
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	maxSize = other.maxSize;
	container = other.container;
	return (*this);
}

Span::~Span()
{
	// Nothing to be done
}

void			Span::addNumber(int number)
{
	if (container.size() >= maxSize)
		throw  (std::out_of_range("Could not add number, Span is full."));
	container.insert(number);
}

void			Span::printNumbers()
{
	std::cout << "Stored values: ";
	for (std::set<int>::iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;	
}

unsigned int	Span::shortestSpan()
{
	unsigned int	shortSpan;

	if (container.size() < 2)
		throw std::logic_error("Not enough elements to find a span");
	shortSpan = std::numeric_limits<int>::max();
	for (std::set<int>::iterator it = container.begin(); it != container.end(); it++)
	{
		std::set<int>::iterator next_it = it;
		next_it++;
		unsigned int span = *next_it - *it;
		if (span < shortSpan)
			shortSpan = span;
	}
	return (shortSpan);
}

unsigned int	Span::longestSpan()
{
	if (container.size() < 2)
		throw std::logic_error("Not enough elements to find a span");
	return (*container.rbegin() - *container.begin());

}
