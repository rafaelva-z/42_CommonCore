#include <list>
#include "MutantStack.hpp"

int main()
{
	{
		std::cout << " --- subject main ---" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	{
		std::cout << "--- subject main with list instead of MutantStack ---" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		// std::stack<int> s(mstack);	// Can't convert from std::list to std::stack
	}
	std::cout << std::endl;
	{
		std::cout << "--- other tests ---" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::reverse_iterator reverse_it = mstack.rbegin();
		MutantStack<int>::const_iterator const_it = mstack.begin();
		MutantStack<int>::const_reverse_iterator const_reverse_it = mstack.rbegin();
		reverse_it++;
		std::cout << *reverse_it << std::endl;
		*reverse_it = 999;
		std::cout << *reverse_it << std::endl;
		std::cout << *const_it << std::endl;
		// *const_it = 3;	// Can't be chaged because it's const_iterator
		std::cout << *const_reverse_it << std::endl;

		MutantStack<int> ms2;
		ms2 = mstack;
	}
}