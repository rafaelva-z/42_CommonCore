#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>

PmergeMe::PmergeMe()
{
	// Nothing to do here
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	_containerVector = other._containerVector;
	_containerList = other._containerList;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_containerVector = other._containerVector;
		_containerList = other._containerList;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	// Nothing to do here
}

void	PmergeMe::execute()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _containerVector.size(); i++)
		std::cout << _containerVector[i] << " ";
	std::cout << std::endl;

	// Vector sort
	clock_t	start = clock();
	handleVector(_containerVector);
	clock_t	end = clock();
	double	vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	// List sort
	start = clock();
	handleList(_containerList);
	end = clock();
	double	listTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
	for (size_t i = 0; i < _containerVector.size(); i++)
		std::cout << _containerVector[i] << " ";
	std::cout << std::endl;

	// Print timing information
	std::cout << "Time to process a range of " << _containerVector.size() 
		<< " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _containerList.size() 
		<< " elements with std::list : " << listTime << " us" << std::endl;
}

void	PmergeMe::handleVector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;

	std::vector<int> lesser, greater;
	
	// Merge sort
	for (size_t i = 0; i < vec.size() - 1; i += 2)
	{
		if (vec[i] < vec[i + 1])
		{
			lesser.push_back(vec[i]);
			greater.push_back(vec[i + 1]);
		}
		else
		{
			lesser.push_back(vec[i + 1]);
			greater.push_back(vec[i]);
		}
	}

	if (vec.size() % 2 != 0)
		lesser.push_back(vec.back());

	handleVector(lesser);

	// Insertion sort
	for (size_t i = 0; i < greater.size(); ++i)
		insertSortedVector(lesser, greater[i]);

	vec = lesser;
}

void	PmergeMe::insertSortedVector(std::vector<int>&vec, int value)
{
	std::vector<int>::iterator it = std::upper_bound(vec.begin(), vec.end(), value);
	vec.insert(it, value);
}

void	PmergeMe::handleList(std::list<int> &lst)
{
	if (lst.size() <= 1)
		return;

	std::list<int> lesser, greater;
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator next;
	
	// Merge sort
	while (it != lst.end())
	{
		next = it;
		next++;
		if (next == lst.end())
			break;
			
		if (*it < *next)
		{
			lesser.push_back(*it);
			greater.push_back(*next);
		}
		else
		{
			lesser.push_back(*next);
			greater.push_back(*it);
		}
		it++;
		it++;
	}

	if (lst.size() % 2 != 0)
		lesser.push_back(lst.back());

	handleList(lesser);

	// Insertion sort
	for (std::list<int>::iterator it = greater.begin(); it != greater.end(); ++it)
		insertSortedList(lesser, *it);

	lst = lesser;
}

void	PmergeMe::insertSortedList(std::list<int>&lst, int value)
{
	std::list<int>::iterator it = std::upper_bound(lst.begin(), lst.end(), value);
	lst.insert(it, value);
}

void	PmergeMe::reset()
{
	_containerVector.clear();
	_containerList.clear();
}


void	PmergeMe::parseArgs(const char **argv)
{
	reset();

	const char			**iterator;
	const char			*str;
	long				number;

	iterator = argv + 1;
	while (*iterator)
	{
		str = *iterator;
		number = 0;
		
		if (!str || *str == '\0')
			throw std::invalid_argument("Empty argument. Arguments should be positive integers.");
		if (*str == '+')
			str++;
		if (*str == '\0')
			throw std::invalid_argument("Invalid number format. Use a sequence of positive integers as arguments.");

		while (*str)
		{
			if (*str < '0' || *str > '9')
				throw std::invalid_argument("Invalid character in numbers. Arguments should be positive integers.");
			number = number * 10 + (*str - '0');
			if (number > INT_MAX)
				throw std::out_of_range("Number too large");
			str++;
		}
		_containerVector.push_back(static_cast<int>(number));
		_containerList.push_back(static_cast<int>(number));

		iterator++;
	}
}
