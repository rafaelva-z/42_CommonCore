#pragma once

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <set>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void			addNumber(int number);
		template<typename InputIterator>
		void	addNumbers(InputIterator begin, InputIterator end)
		{
			size_t distance = std::distance(begin, end);
			if (container.size() + distance > maxSize)
				throw std::out_of_range("Cannot add more numbers, container will exceed max size");
			container.insert(begin, end);
		}
		void			printNumbers();
		unsigned int	shortestSpan();
		unsigned int	longestSpan();


	private:
		unsigned int maxSize;
		std::set<int> container;
		
		Span();
};
