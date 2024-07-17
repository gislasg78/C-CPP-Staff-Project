/* Polygonal numbers. */
#include <algorithm>
#include <iostream>
#include <vector>

#define V_MINUS_ONE	-1
#define V_ONE   	1
#define V_ZERO  	0

int main()
	{
		//Definition of preliminary variables.
		int int_dimensions = V_ZERO;
		int int_rings = V_ZERO;
		std::vector<int> vec_int_numbers;

		std::cout << "Polygonal numbers." << std::endl;
		std::cout << "Dimensions: ";
		std::cin >> int_dimensions;
		std::cout << "Rings: ";
		std::cin >> int_rings;

		//Define a 'lambda' function that calculates each of the polygonal numbers.
		auto fnPoly = [] (int int_rings, int int_dimensions, std::vector<int> &vec_int_numbers) -> int
			{
				int int_total = V_ONE;
				vec_int_numbers.clear();

				for (int int_idx = int_rings + V_MINUS_ONE; int_idx >= V_ONE; int_idx-- )
					{
						int_total += int_idx * int_dimensions;
						vec_int_numbers.push_back(int_total);
					}

				return int_total;
			};

		//Shows the final result of calculating polygonal numbers.
		std::cout << std::endl << "Final value: [" << fnPoly(int_rings, int_dimensions, vec_int_numbers) << "]." << std::endl;


		//Displays on the screen each of the values calculated to reach the last polygonal number.
		auto printPoly = [] (std::vector<int> &vec_int_numbers)
			{
				int int_count = V_ZERO;

				for (std::vector<int>::iterator it_vec_int_numbers = std::begin(vec_int_numbers); it_vec_int_numbers != std::end(vec_int_numbers); it_vec_int_numbers++)
					std::cout << '\x23' << int_count++ << '\x3a' << '\t' <<'\x5b' << *it_vec_int_numbers << '\x5d' << '\x2e' << '\n';

				std::cout << std::endl;
			};

		printPoly(vec_int_numbers);


		//Lambda function to display only one element at a time from polygonal number calculation.
		std::for_each(vec_int_numbers.begin(), vec_int_numbers.end(), [&](int int_Item) { std::cout << '\x5b' << int_Item << '\x5d' << '\x2e' << '\t';});
		std::cout << std::endl;

		return V_ZERO;
	}
