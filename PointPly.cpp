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
		int int_count = V_ZERO;
		int int_dimensions = V_ZERO;
		int int_rings = V_ZERO;
		std::vector<int> vect_int_numbers {};

		//Initial headers.
		std::cout << "Polygonal numbers." << std::endl;
		std::cout << "Dimensions: ";
		std::cin >> int_dimensions;
		std::cout << "Rings: ";
		std::cin >> int_rings;

		//Define a 'lambda' function that calculates each of the polygonal numbers.
		auto fnPoly = [&] (int int_rings, int int_dimensions, std::vector<int>& vect_int_numbers) -> int
			{
				int int_total = V_ONE;
				vect_int_numbers.clear();

				for (int int_idx = int_rings + V_MINUS_ONE; int_idx >= V_ONE; int_idx--)
					{
						int_total += int_idx * int_dimensions;
						vect_int_numbers.push_back(int_total);
					}

				return int_total;
			};

		//Shows the final result of calculating polygonal numbers.
		std::cout << std::endl << "Final value:\t[" << fnPoly(int_rings, int_dimensions, vect_int_numbers) << "]." << std::endl;

		//Displays on the screen each of the values calculated to reach the last polygonal number.
		std::cout << std::endl << "Sequential calculation of polygonal numbers." << std::endl;

		auto printPoly = [&int_count] (const std::vector<int>& vect_int_numbers)
			{
				for (std::vector<int>::const_iterator it_vect_int_numbers = std::cbegin(vect_int_numbers); it_vect_int_numbers != std::cend(vect_int_numbers); it_vect_int_numbers++)
					std::cout << '\x23' << int_count++ << '\x3a' << '\t' <<'\x5b' << *it_vect_int_numbers << '\x5d' << '\x2e' << '\n';

				std::cout << std::endl;
			};

		printPoly(vect_int_numbers);

		//Lambda function to display only one element at a time from polygonal number calculation.
		std::cout << "Generated series of polygonal numbers." << std::endl;
		std::for_each(vect_int_numbers.begin(), vect_int_numbers.end(), [&](const int& int_Item) {std::cout << '\x5b' << int_Item << '\x5d' << '\x2e' << '\t';});
		std::cout << std::endl;

		return V_ZERO;
	}
