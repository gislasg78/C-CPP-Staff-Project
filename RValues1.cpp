#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>

constexpr int V_ONE {1};

int main()
{
	size_t numbers{};

	std::cout << "Dynamic Assignment Memory." << std::endl;
	std::cout << "Write on an positive integer: ";
	std::cin >> numbers;

	int* &&int_array {new int[numbers]()};
	int *const &new_array {int_array};

	std::iota(int_array, int_array + numbers, V_ONE);

	std::ostream_iterator<int> out_it (std::cout, "\t");
	std::copy(new_array, new_array + numbers, out_it);

	std::cout << std::endl << std::endl;
	std::for_each(int_array, int_array + numbers, [](const int& value){std::cout << "[" << value << "].\t";});
	std::cout << std::endl;

	delete [] int_array;
	int_array = nullptr;

	std::cout << std::endl << "[" << new_array << "]." << std::endl;

	return EXIT_SUCCESS;
}
