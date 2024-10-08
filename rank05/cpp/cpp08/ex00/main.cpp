#include "easyfind.hpp"
#include <vector>
#include <set>
#include <list>

/*	Note:	Associative containers automatically sort and organize elements as they are inserted
 *			as oposed to sequential containers.
*/

int main() {
	int					int_values[] = {3, 422, 86, 42, 1};
	size_t				values_amt = sizeof(int_values) / sizeof(int_values[0]);

	std::vector<int>	vec(int_values, int_values + values_amt);
	std::list<int>		lst(int_values, int_values + values_amt);
	std::set<int>		set(int_values, int_values + values_amt); // Associative container
	
	std::cout << "--- Testing values that exist in the container ---" << std::endl;
	try {
		std::cout << "vector >> " << easyfind(vec, 3) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "list >> " << easyfind(lst, 422) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "set >> " << easyfind(set, 86) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "--- Testing values that DON'T exist in the container ---" << std::endl;
	try {
		std::cout << "vector >> " << easyfind(vec, 999) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "list >> " << easyfind(lst, 999) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "set >> " << easyfind(set, 999) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
