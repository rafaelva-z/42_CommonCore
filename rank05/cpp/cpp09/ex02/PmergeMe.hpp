#ifndef PMERMERGEME_HPP
# define PMERMERGEME_HPP

#include <iostream>
#include <string>
#include <exception>
#include <climits>
#include <algorithm>
#include <ctime>
#include <list>
#include <vector>

class PmergeMe {

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);
		~PmergeMe();

		void				execute();
		void				parseArgs(const char **argv);
	private:
		std::vector<int>	_containerVector;
		std::list<int>		_containerList;

		void				handleVector(std::vector<int> &vec);
		void				insertSortedVector(std::vector<int>&arr, int value);

		void				handleList(std::list<int> &lst);
		void				insertSortedList(std::list<int>&lst, int value);

		void				reset();
		void				printResults();	
};

#endif
