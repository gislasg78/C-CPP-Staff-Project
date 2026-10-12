/* Polygonal numbers. */

/* Standard Work Libraries. */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

/* Alphanumeric Work Constant. */
template <typename T>
constexpr T CARRIAGE_RETURN	{static_cast<T>('\n')};

/* Numeric Symbolic Constants. */
template <typename T>
constexpr T V_MINUS_ONE	{static_cast<T>(-1)};
template <typename T>
constexpr T V_ONE	{static_cast<T>(1)};
template <typename T>
constexpr T V_ZERO	{static_cast<T>(0)};

/* Generate a pause to continue later. */
void getPause(const std::string& str_Message)
	{
		std::cout << str_Message;
		std::cin.clear();
		std::cin.get();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);
	}

//Main function.
int main()
	{
		/* Definition of preliminary variables. */
		int int_count {V_ZERO<int>};
		int int_dimensions {V_ZERO<int>};	//Number of sides of the polygon.
		int int_rings {V_ZERO<int>};
		std::vector<int> vect_int_numbers {};

		/* Initial headers. */
		std::cout << "Polygonal numbers." << std::endl;
		std::cout << "+ Rings: ";
		std::cin >> int_rings;
		std::cout << "+ Sides: ";
		std::cin >> int_dimensions;

		/* Define a 'lambda' function that calculates each of the polygonal numbers. */
		auto fnPoly = [&] (int int_circlets, int int_sides, std::vector<int>& vec_int_numbers) -> int
			{
				int int_total {V_ONE<int>};
				vec_int_numbers.clear();

				for (int int_idx {int_circlets + V_MINUS_ONE<int>}; int_idx >= V_ONE<int>; --int_idx)
					{
						int_total += int_idx * int_sides;
						vec_int_numbers.push_back(int_total);
					}

				return int_total;
			};

		/* Shows the final result of calculating polygonal numbers. */
		std::cout << std::endl << "Final value:\t[" << fnPoly(int_rings, int_dimensions, vect_int_numbers) << "]." << std::endl;
		getPause("Press the ENTER key to continue...");

		/* Displays on the screen each of the values calculated to reach the last polygonal number. */
		std::cout << std::endl << "Sequential calculation of polygonal numbers." << std::endl;

		/* Anonymous function to manually traverse and print the created vector using iterators. */
		auto printPoly = [&int_count] (const std::vector<int>& vec_int_numbers)
			{
				for (std::vector<int>::const_iterator itc_vec_int_numbers = std::cbegin(vec_int_numbers); itc_vec_int_numbers != std::cend(vec_int_numbers); itc_vec_int_numbers++)
					std::cout << '\x23' << int_count++ << '\x3a' << '\t' <<'\x5b' << *itc_vec_int_numbers << '\x5d' << '\x2e' << '\n';

				std::cout << std::endl;
			};

		/* Call to the anonymous function that iterates over the vector containing the polygonal numbers. */
		printPoly(vect_int_numbers);
		getPause("Press the ENTER key to continue...");

		/* Display the vector elements using a 'For Each' type algorithm. */
		std::cout << std::endl << "Generated series of polygonal numbers." << std::endl;
		std::for_each(vect_int_numbers.cbegin(), vect_int_numbers.cend(), [&](const int& int_Item) {std::cout << '\x5b' << int_Item << '\x5d' << '\x2e' << '\t';});
		std::cout << std::endl;
		getPause("Press the ENTER key to continue...");

		/* Display the vector elements using a copy algorithm that outputs to a `std::ostream` iterator. */
		std::cout << std::endl << "Dumping of polygonal series." << std::endl;
		std::copy(std::cbegin(vect_int_numbers), std::cend(vect_int_numbers), std::ostream_iterator<int>(std::cout, "\t"));
		std::cout << std::endl;
		getPause("Press the ENTER key to continue...");

		/* Program Termination Messages. */
		std::cout << std::endl << "Done!" << std::endl;
		std::cout << "This program has ended." << std::endl;
		getPause("Press the ENTER key to continue...");

		return EXIT_SUCCESS;
	}
