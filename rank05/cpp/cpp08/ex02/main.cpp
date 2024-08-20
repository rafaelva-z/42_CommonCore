#include <list>
#include "MutantStack.hpp"

int main()
{
	{
		std::cout << " --- subject main ---" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "- Added 5 and 17, last value is:" << std::endl;
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "- Removed 17 with pop() now size is 1" << std::endl;
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "- Current values in mstack:" << std::endl;
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
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
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
		MutantStack<int>	mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::reverse_iterator			reverse_it = mstack.rbegin();
		MutantStack<int>::const_iterator			const_it = mstack.begin();
		MutantStack<int>::const_reverse_iterator	const_reverse_it = mstack.rbegin();
		reverse_it++;
		std::cout << "- Should be 737 because reverse iterator incremented:" << std::endl;
		std::cout << *reverse_it << std::endl;
		std::cout << "- Changing the value from 737 to 999:" << std::endl;
		*reverse_it = 999;
		std::cout << *reverse_it << std::endl;
		std::cout << *const_it << std::endl;
		// *const_it = 3;	// Can't be chaged because it's const_iterator
		std::cout << "- const_reverse_it, the value will the 0, the last added value." << std::endl;
		std::cout << *const_reverse_it << std::endl;

		std::cout << "- Assignment operator (ms2 = mstack):" << std::endl;
		MutantStack<int>	ms2;
		ms2 = mstack;

		std::cout << "- Current values in mstack:" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "- Current values in ms2:" << std::endl;
		it = ms2.begin();
		ite = ms2.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << "- Copy constructor (ms3(ms2))" << std::endl;
		MutantStack<int>	ms3(ms2);

		std::cout << "- Current values in ms3:" << std::endl;
		it = ms3.begin();
		ite = ms3.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
}