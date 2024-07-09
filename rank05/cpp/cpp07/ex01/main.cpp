#include <iter.hpp>
#include <iostream>

void	keepFirstWord(std::string *str)
{
	size_t pos = str->find(' ');

	if (pos != std::string::npos)
		*str = str->substr(0, pos);
}

void	addOne(int *number)
{
	(*number)++;
}

int main()
{
	std::cout << "= Case 1 ============" << std::endl;

	std::string strings[] = {
		std::string("Hello World"),
		std::string("my cat is blue"),
		std::string("name is a word"),
		std::string("is there a snake in my boots?"),
		std::string("Rafa")
	};
	iter(strings, 5, keepFirstWord);
	for (int i = 0; i < 5; i++)
		std::cout << strings[i] << std::endl;


	std::cout << "= Case 2 ============" << std::endl;

	int numbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	iter(numbers, 10, addOne);
	for (int i = 0; i < 9; i++)
		std::cout << numbers[i] << ", ";
	std::cout << numbers[9] << std::endl;

	return 0;
}
