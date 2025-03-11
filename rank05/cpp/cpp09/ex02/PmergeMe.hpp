#ifndef PMERMERGEME_HPP
# define PMERMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <exception>

class PmergeMe {

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);
		~PmergeMe();

		void	execute(std::vector<int> &list);
	private:
		std::vector<int>	_containerVector;
		std::list<int>		_containerList;

		void				handleVector()
		void				handleList();
		void				printResults();	
};

#endif