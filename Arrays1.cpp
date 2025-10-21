//Pointers as arguments.
#include <iostream>

#define V_ZERO  0

//Cumulative sum of the increased and shifted value.
template <typename T>
auto sum_all(const T *start, const T *stop)
	{
		T sum = V_ZERO;

		while (start != stop)
			{sum += *start++;}

		return sum;
	}

//Counting of the values.
template <typename T>
T view_all(const T *start, const T *stop)
	{
		T count = V_ZERO;

		std::cout << "Dumping the array elements." << std::endl;

		while (start != stop)
			{
				std::cout << "#: [" << count++ << "]\t:\t{" << start << "}\t=\t(" << *start << ")." << std::endl;
				start++;
			}

		std::cout << "[" << count << "] Output results generated." << std::endl;

		return count;
	}


//Main function.
int main()
	{
		int count = V_ZERO, sum = V_ZERO;
		int array_numbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
		const int num_elements = sizeof(array_numbers) / sizeof(*array_numbers);

		count = view_all<int>(array_numbers, array_numbers + num_elements);
		sum = sum_all<int>(array_numbers, array_numbers + num_elements);

		std::cout << std::endl << "Final Statistics." << std::endl;
		std::cout << "+ Counter:\t[" << count << "]." << std::endl;
		std::cout << "+ Summation:\t[" << sum << "]." << std::endl;

		return V_ZERO;
	}
