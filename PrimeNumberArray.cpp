/* Generator and counter of dynamic and
   static arrays of prime numbers. */

/* Standard work libraries. */
#include <iostream>
#include <limits>
#include <sstream>

/* Symbolic work constants. */
#define CARRIAGE_RETURN	'\n'

#define	V_FIVE		5
#define	V_SEVEN		7
#define V_THREE		3
#define V_TWO		2
#define V_ZERO		0


//Determine whether a given number is prime or not.
template <typename T>
bool IsPrime(const T& number)
	{
		return (((number == V_TWO) || (number == V_THREE) || (number == V_FIVE) || (number == V_SEVEN)) ||
			((number % V_TWO) && (number % V_THREE) && (number % V_FIVE) && (number % V_SEVEN)));
	}

//Generates a dynamic array with prime numbers.
template <typename T>
T* create_array(const T& size, const T& last_number, T** array)
	{
		T *dynamic_array = new T[size]();

		if (dynamic_array)
			{
				for (T idx = V_ZERO, number = last_number; idx < size; number++)
					if (IsPrime<T>(number))	*(dynamic_array + idx++) = number;
			}
		else
			std::cerr << std::endl << "The reserved memory area could not be properly allocated." << std::endl;

		*array = dynamic_array;
		return dynamic_array;
	}

//Get a given value from the keyboard.
template <typename T>
auto getData(T* ptr_data_value)
	{
		if (ptr_data_value)
			{
				std::string str_data_value {};

				std::getline(std::cin >> std::ws, str_data_value);
				std::stringstream(str_data_value) >> *ptr_data_value;

				std::cout << "Value entered:\t[" << *ptr_data_value << "]. OK!" << std::endl;
			}
		else
			std::cerr << std::endl << "A valid memory address was not provided." << std::endl;

		return *ptr_data_value;
	}

//Generate a pause to continue later.
void getPause(const std::string& str_Message)
	{
		std::cout << std::endl << str_Message;
		std::cin.get();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);
	}

//Display final statistics messages.
template <typename T>
void statistics(const T& count, const T& sum)
	{
		std::cout << std::endl << "Final Statistics." << std::endl;
		std::cout << "+ Counter:\t[" << count << "]." << std::endl;
		std::cout << "+ Summation:\t[" << sum << "]." << std::endl;

		getPause("Press the ENTER key to continue...");
	}

//Cumulative sum of the increased and shifted value.
template <typename T>
auto sum_array(const T* start, const T* stop)
	{
		T sum = V_ZERO;

		while (start != stop)
			{sum += *start++;}

		return sum;
	}

//Counting of the values.
template <typename T>
T view_array(const T *start, const T *stop)
	{
		T count = V_ZERO;

		std::cout << std::endl << "Dumping the array elements." << std::endl;

		while (start != stop)
			{
				std::cout << "#: [" << count++ << "]\t:\t{" << start << "}\t=\t(" << *start << ")." << std::endl;
				start++;
			}

		std::cout << "[" << count << "] Output results generated." << std::endl;
		getPause("Press the ENTER key to continue...");

		return count;
	}


//Main function.
int main()
	{
		/* Preliminary working variables. */
		int array_numbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
		const int num_elements = sizeof(array_numbers) / sizeof(*array_numbers);

		int count = V_ZERO, size {V_ZERO}, sum = V_ZERO;

		/* Header messages. */
		std::cout << "Generator of an array with prime numbers." << std::endl;
		std::cout << "Enter the number of items: ";
		size = getData<int>(&size);

		/* Code block to create a dynamic array with prime numbers. */
		int *ptr_array_numbers = create_array<int>(size, V_TWO, &ptr_array_numbers);

		if (ptr_array_numbers)
			{
				count = view_array<int>(ptr_array_numbers, ptr_array_numbers + size);
				sum = sum_array<int>(ptr_array_numbers, ptr_array_numbers + size);
				statistics<int>(count, sum);

				delete ptr_array_numbers;
			}
		else
			std::cerr << std::endl << "Error allocating memory for a dynamic array of prime numbers." << std::endl;

		/* Code block to read a static array with predefined prime numbers. */
		count = view_array<int>(array_numbers, array_numbers + num_elements);
		sum = sum_array<int>(array_numbers, array_numbers + num_elements);
		statistics<int>(count, sum);

		return V_ZERO;
	}
