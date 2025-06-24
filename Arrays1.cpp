//Pointers as arguments.
#include <iostream>

#define V_ZERO  0

//Cumulative sum of the increased and shifted value.
int summatory(int *start, int *stop)
	{
		int sum = V_ZERO;

		while (start != stop)
			{
				sum += *start;
				start++;
			}

		return sum;
	}

int view_all(const int *start, const int *stop)
	{
		int count = V_ZERO;

		std::cout << "Dumping the array elements." << std::endl;

		while (start != stop)
			{
				std::cout << "#: " << count++ << "\t[" << start << "]\t:\t[" << *start++ << "]." << std::endl;
			}

		std::cout << "[" << count << "] Output results generated." << std::endl;

		return count;
	}


int main()
	{
		int numbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
		const int n_elements = sizeof(numbers) / sizeof(numbers[V_ZERO]);

		view_all(numbers, numbers + n_elements);

		std::cout << std::endl << "Sum: [" << summatory(numbers, numbers + n_elements) << "]." << std::endl;

		return V_ZERO;
	}
