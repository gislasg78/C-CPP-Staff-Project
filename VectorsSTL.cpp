#include <algorithm>    //For std::for_each
#include <functional>   //For std::function
#include <iostream>
#include <vector>       //For std::vector

#define V_ZERO  0

template <typename T>
T print_value(T value)
	{
		std::cout << "[" << value << "].\t";

		return value;
	}

int main()
	{
		std::vector<int> vec_numbers = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

		std::cout << "Program that uses some functions of the C++ STL library." << std::endl << std::endl;

		std::cout << "Using a lambda function with 'std::for_each'." << std::endl;
		std::for_each(vec_numbers.begin(), vec_numbers.end(), [](int number) {std::cout << "[" << number << "].\t";});
		std::cout << std::endl << std::endl;

		std::cout << "Using inverted iterators to traverse the vector with 'std::for_each'." << std::endl;
		std::for_each(vec_numbers.rbegin(), vec_numbers.rend(), [](int number) {std::cout << "[" << number << "].\t";});
		std::cout << std::endl << std::endl;

		std::cout << "Using 'std::function' to store and pass a callable to 'std::for_each'." << std::endl;
		std::function<int(int)> func_to_apply = print_value<int>; //Stores a free function.
		std::for_each(std::begin(vec_numbers), std::end(vec_numbers), func_to_apply);
		std::cout << std::endl << std::endl;

		std::cout << "Using inverted iterators to traverse the vector with 'std::for_each'." << std::endl;
		std::for_each(vec_numbers.rbegin(), vec_numbers.rend(), print_value<int>);
		std::cout << std::endl << std::endl;

		return V_ZERO;
	}
