/* Generator and counter of dynamic and
   static arrays of prime numbers. */

/* Standard work libraries. */
#include <algorithm>
#include <iostream>
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
		if (number < V_TWO<T>)
			return false;

		for (T divisor{V_TWO<T>}; divisor <= (number / divisor); divisor += (divisor == V_TWO<T>) ? V_ONE<T> : V_TWO<T>)
			{
				if (!(number % divisor))
					return false;
			}

		return true;
	}

/* Generates a dynamic array with prime numbers. */
template <typename T>
T* create_array(const T& size, const T& last_number, T** array)
	{
		T *dynamic_array = new T[size]();

		if (dynamic_array)
			{
				for (T idx {V_ZERO<T>}, number = last_number; idx < size; number++)
					if (IsPrime<T>(number))	*(dynamic_array + idx++) = number;
			}
		else
			std::cerr << std::endl << "The reserved memory area could not be properly allocated." << std::endl;

		*array = dynamic_array;
		return dynamic_array;
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
		T count {V_ZERO<T>};

		std::cout << std::endl << "Dumping the array elements." << std::endl;

		while (start != stop)
			{
				std::cout << "#: [" << count++ << "]\t:\t{" << start << "}\t=\t(" << *start << ")." << std::endl;
				start++;
			}

		std::cout << "[" << count << "] Output results generated." << std::endl << std::endl;
		getPause("Press the ENTER key to continue...");

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
				count = view_array<int>(ptr_array_numbers, ptr_array_numbers + size);
				sum = sum_array<int>(ptr_array_numbers, ptr_array_numbers + size);
				statistics<int>(count, sum);

				delete [] ptr_array_numbers;
				ptr_array_numbers = nullptr;
			}
		else
			std::cerr << std::endl << "Error allocating memory for a dynamic array of prime numbers." << std::endl;

		/* Code block to read a static array with predefined prime numbers. */
		count = view_array<int>(array_numbers, array_numbers + num_elements);
		sum = sum_array<int>(array_numbers, array_numbers + num_elements);
		statistics<int>(count, sum);

		/* Program termination messages. */
		std::cout << std::endl << "Done!" << std::endl;
		std::cout << "This program has ended." << std::endl;
		getPause("Press the ENTER key to continue...");

		return EXIT_SUCCESS;
	}
