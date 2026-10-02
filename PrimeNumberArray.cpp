/* Generator and counter of dynamic and
   static arrays of prime numbers. */

/* Standard work libraries. */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>

/* Symbolic work constants. */
template <typename T>
constexpr T CARRIAGE_RETURN	{T('\n')};

/* Numerical symbolic constants. */
template <typename T>
constexpr T V_ONE		{T(1)};
template <typename T>
constexpr T V_TWO		{T(2)};
template <typename T>
constexpr T V_ZERO		{T(0)};

/* Determine whether a given number is prime or not. */
template <typename T>
bool IsPrime(const T& number)
	{
		for (T divisor{V_TWO<T>}; divisor <= (number / divisor); divisor += (!(divisor % V_TWO<T>)) ? V_ONE<T> : V_TWO<T>)
			if (!(number % divisor)) return false;

		return (number > V_ONE<T>);
	}

/* Generates a dynamic array with prime numbers. */
template <typename T>
T* create_array(const T& size, const T& last_number, T** array)
	{
		/* Dynamically create the array of prime numbers based on a requested size. */
		T *dynamic_array = new T[size]();

		/* Verify whether dynamic memory allocation for the given size was successful. */
		if (dynamic_array)
			{
				for (T idx {V_ZERO<T>}, number = last_number; idx < size; (!(number % V_TWO<T>)) ? number++ : number += V_TWO<T>)
					if (IsPrime<T>(number))	*(dynamic_array + idx++) = number;
			}
		else
			std::cerr << std::endl << "The reserved memory area could not be properly allocated." << std::endl;

		/* It returns the required memory address as the function result. */
		return (array) ? *array = dynamic_array : dynamic_array;
	}

/* Get a given value from the keyboard. */
template <typename T>
auto getData(const std::string& str_Message, T *const ptr_data_value)
	{
		if (ptr_data_value)
			{
				std::cout << str_Message;
				std::string str_data_value {};
				std::getline(std::cin >> std::ws, str_data_value);
				str_data_value.erase(std::remove_if(str_data_value.begin(), str_data_value.end(), ::isspace), str_data_value.end());
				std::stringstream(str_data_value) >> *ptr_data_value;

				std::cout << "Value entered:\t[" << *ptr_data_value << "]. OK!" << std::endl;
			}
		else
			std::cerr << std::endl << "A valid memory address was not provided." << std::endl;

		return *ptr_data_value;
	}

/* Generate a pause to continue later. */
void getPause(const std::string& str_Message)
	{
		std::cout << str_Message;
		std::cin.clear();
		std::cin.get();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);
	}

/* Display final statistics messages. */
template <typename T>
void statistics(const T& count, const T& sum)
	{
		std::cout << std::endl << "Final Statistics." << std::endl;
		std::cout << "+ Counter:\t[" << count << "]." << std::endl;
		std::cout << "+ Summation:\t[" << sum << "]." << std::endl << std::endl;

		getPause("Press the ENTER key to continue...");
	}

/* Cumulative sum of the increased and shifted value. */
template <typename T>
auto sum_array(const T* start, const T* stop)
	{
		T sum {V_ZERO<T>};

		while (start != stop)
			sum += *start++;

		return sum;
	}

/* Counting of the values. */
template <typename T>
T view_array(const T *start, const T *stop)
	{
		/* Preliminary working variables. */
		T count {V_ZERO<T>};

		std::cout << std::endl << "Dumping the array elements." << std::endl;

		/* A loop that iterates from a start address to an end address of the array. */
		while (start != stop)
			{
				std::cout << "#: [" << count++ << "]\t:\t{" << start << "}\t=\t(" << *start << ")." << std::endl;
				start++;
			}

		/* Latest output results generated. */
		std::cout << "[" << count << "] Output results generated." << std::endl << std::endl;
		getPause("Press the ENTER key to continue...");

		/* Returns the number of counted elements. */
		return count;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		const int array_numbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
		const int num_elements = sizeof(array_numbers) / sizeof(*array_numbers);

		int count = {V_ZERO<int>}, size {V_ZERO<int>}, sum(V_ZERO<int>);

		/* Header messages. */
		std::cout << "Generator of an array with prime numbers." << std::endl;
		size = getData<int>("Enter the number of items: ", &size);

		/* Code block to create a dynamic array with prime numbers. */
		int *ptr_array_numbers = create_array<int>(size, V_TWO<int>, &ptr_array_numbers);

		/* Verify whether the prime number pointer was successfully created. */
		if (ptr_array_numbers)
			{
				/* View the elements contained in the prime number pointer. */
				count = view_array<int>(ptr_array_numbers, ptr_array_numbers + size);

				/* Dumping the prime number pointer to the output streams. */
				std::cout << std::endl << "Generated prime numbers." << std::endl;
				std::copy(ptr_array_numbers, ptr_array_numbers + size, std::ostream_iterator<int>(std::cout, "\t"));
				std::cout << std::endl << "Results: [" << count << "]." << std::endl;
				getPause("Press the ENTER key to continue...");

				/* Calculate the sum of the prime number elements in the created array. */
				sum = sum_array<int>(ptr_array_numbers, ptr_array_numbers + size);
				statistics<int>(count, sum);

				/* Clear and free the memory at the prime number address. */
				delete [] ptr_array_numbers;
				ptr_array_numbers = nullptr;
			}
		else
			std::cerr << std::endl << "Error allocating memory for a dynamic array of prime numbers." << std::endl;

		/* Code block to read a static array with predefined prime numbers. */
		/* View the elements contained in the prime number static array. */
		count = view_array<int>(array_numbers, array_numbers + num_elements);

		/* Output the prime numbers from the predefined static array. */
		std::cout << std::endl << "Recovered prime numbers." << std::endl;
		std::copy(std::cbegin(array_numbers), std::cend(array_numbers), std::ostream_iterator<int>(std::cout, "\t"));
		std::cout << std::endl << "Outcomes: [" << count << "]." << std::endl;
		getPause("Press the ENTER key to continue...");

		/* Calculate the sum of the prime numbers in the static array. */
		sum = sum_array<int>(array_numbers, array_numbers + num_elements);
		statistics<int>(count, sum);

		/* Program termination messages. */
		std::cout << std::endl << "Done!" << std::endl;
		std::cout << "This program has ended." << std::endl;
		getPause("Press the ENTER key to continue...");

		return EXIT_SUCCESS;
	}
