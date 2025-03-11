#include "PmergeMe.hpp"

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

void	execute(std::vector<int> &list)
{

}

void	handleVector()
{

}

void	handleList()
{

}

void	printResults()
{

}
