#include "easyfind.hpp"
#include <vector>
#include <set>
#include <list>


int main() {
    std::vector<int> vec;
    std::list<int> lst;
    std::set<int> st;

    vec.push_back(3);
    vec.push_back(422);
    vec.push_back(86);
    vec.push_back(42);
    vec.push_back(1);

    lst.push_back(3);
    lst.push_back(422);
    lst.push_back(86);
    lst.push_back(42);
    lst.push_back(1);

    st.insert(3);
    st.insert(422);
    st.insert(86);
    st.insert(42);
    st.insert(1);
    
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
        std::cout << "set >> " << easyfind(st, 1) << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

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
        std::cout << "set >> " << easyfind(st, 999) << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
