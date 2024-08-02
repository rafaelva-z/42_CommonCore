#pragma once

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack() : std::stack<T>() {}

		MutantStack(const MutantStack &other) : std::stack<T>(other)
		{
			if (this == &other)
				return ;
			*this = other;
		}
		MutantStack &operator=(const MutantStack &other)
		{
			if (this == &other)
				return (*this);
			std::stack<T>::operator=(other);
			return (*this);
		}

		iterator begin(){
			return (this->c.begin());
		}
		iterator end(){
			return (this->c.end());
		}

		reverse_iterator rbegin(){
			return (this->c.rbegin());
		}
		reverse_iterator rend(){
			return (this->c.rend());
		}

		const_iterator begin() const {
			return (this->c.begin());
		}
		const_iterator end() const {
			return (this->c.end());
		}

		const_reverse_iterator rbegin() const {
			return (this->c.rbegin());
		}
		const_reverse_iterator rend() const {
			return (this->c.rend());
		}
};
