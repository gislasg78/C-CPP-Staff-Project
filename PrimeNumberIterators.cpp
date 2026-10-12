/* This program aims to test different ways of accessing iterators
   for an STL 'vector' container and to perform insertions and deletions
   at a specific key position.
*/

/* Standard Work Libraries. */
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

/* Work String Constants. */
template <typename T>
constexpr T CARRIAGE_RETURN	{T('\n')};

/* Symbolic Work Constants. */
template <typename T>
constexpr T V_ONE		{T(1)};
template <typename T>
constexpr T V_THREE		{T(3)};
template <typename T>
constexpr T V_TWO		{T(2)};
template <typename T>
constexpr T V_ZERO		{T(0)};

/* Early function prototype. */
template <typename T>
bool IsPrime(const T& number);

/* Function to generate and obtain a pause. */
void getPause(const std::string& str_Message)
	{
		std::cout << str_Message;
		std::cin.clear();
		std::cin.get();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);
	}

/* Function to generate a specified number of prime numbers. */
template <typename T>
std::vector<T> getPrimesVector(const T& quantity)
	{
		std::vector<T> vec_prime_numbers {};

		for (T idx{V_TWO<T>}, counter{}; counter < quantity; idx++)
			if (IsPrime(idx))
				{
					counter++;
					vec_prime_numbers.push_back(idx);
				}

		return vec_prime_numbers;
	}

/* Function to determine whether or not a number is prime. */
template <typename T>
bool IsPrime(const T& number)
	{
		for (T divisor {V_TWO<T>}; divisor <= (number / divisor); divisor += (!(divisor % V_TWO<T>)) ? V_ONE<T> : V_TWO<T>)
			if (!(number % divisor)) return false;

		return (number > V_ONE<T>);
	}

//Main function
int main()
	{
		/* Preliminary Working Variables. */
		int counter {V_ZERO<int>}, int_inserted_value{}, quantity{};
		std::size_t szt_inserted_position{};

		/* Program Header Messages. */
		std::cout << "Practice using C++ STL iterators." << std::endl;
		std::cout << "> Number of primes to generate: ";
		std::cin >> quantity;
		std::cout << "> Test value to insert into the 'vector': ";
		std::cin >> int_inserted_value;
		std::cout << "> Test position in which to insert said value: ";
		std::cin >> szt_inserted_position;

		/* Create a 'vector' type container and an associated iterator. */
		std::vector<int>&& vec_prime_numbers {getPrimesVector(quantity)};

		/* Dumping the vector created with a constant iterator. */
		std::cout << std::endl << "Dumping a vector." << std::endl;
		for (std::vector<int>::const_iterator itc_vec_prime_numbers {vec_prime_numbers.cbegin()}; itc_vec_prime_numbers != vec_prime_numbers.cend(); ++itc_vec_prime_numbers)
			std::cout << "#: [" << std::setw(V_TWO<int>) << std::fixed << counter++ << "] = {" << std::setw(V_THREE<int>) << std::fixed << *itc_vec_prime_numbers << "}." << std::endl;
		std::cout << "[" << counter << "] Output generated results." << std::endl;
		getPause("Press the ENTER key to continue...");

		/* Specific validation to verify that the insertion position is within a valid range. */
		if (szt_inserted_position < vec_prime_numbers.size())
			{
				/* Recalculate a 'vector' container iterator by advancing it 'n' elements. */
				auto it = vec_prime_numbers.begin() + szt_inserted_position;

				/* Code section for practicing access to vector iterators. */
				std::cout << std::endl << "Vector practice." << std::endl;
				std::cout << "*it = [" << *it << "]." << std::endl;
				std::cout << "*begin = [" << *vec_prime_numbers.begin() << "]." << std::endl;
				std::cout << "it - begin = [" << it - vec_prime_numbers.begin() << "]." << std::endl;
				std::cout << "Distance = {" << std::distance(vec_prime_numbers.begin(), it) << "}." << std::endl;
				std::cout << "*it - *begin = [" << *it - *vec_prime_numbers.begin() << "]." << std::endl;
				getPause("Press the ENTER key to continue...");

				/* Exercise on inserting elements into a 'vector' container. */
				it = vec_prime_numbers.insert(it, int_inserted_value);
				std::cout << std::endl << "Vector insertion." << std::endl;
				std::cout << "*it = [" << *it << "]." << std::endl;
				std::cout << "*begin = [" << *vec_prime_numbers.begin() << "]." << std::endl;
				std::cout << "it - begin = [" << it - vec_prime_numbers.begin() << "]." << std::endl;
				std::cout << "Distance = {" << std::distance(vec_prime_numbers.begin(), it) << "}." << std::endl;
				std::cout << "*it - *begin = [" << *it - *vec_prime_numbers.begin() << "]." << std::endl << std::endl;
				std::cout << "Value #" << szt_inserted_position << ": [" << vec_prime_numbers[szt_inserted_position] << "]." << std::endl << std::endl;
				getPause("Press the ENTER key to continue...");
			}
		else
			std::cerr << std::endl << "The position: [" << szt_inserted_position << "] is out of range between: [" << V_ZERO<size_t> << "] and: [" << vec_prime_numbers.size() - V_ONE<size_t> << "]." << std::endl;

		/* Dumping the creator vector using a 'For Each' loop. */
		counter = V_ZERO<int>;
		std::cout << std::endl << "Dumping a vector." << std::endl;
		for (int item : vec_prime_numbers)
			std::cout << "#: [" << std::setw(V_TWO<int>) << std::fixed << counter++ << "] = {" << std::setw(V_THREE<int>) << std::fixed << item << "}." << std::endl;
		std::cout << "[" << counter << "] Output generated results." << std::endl;
		getPause("Press the ENTER key to continue...");

		/* Dumping the vector created using a "For Each" algorithm. */
		counter = V_ZERO<int>;
		std::cout << std::endl << "Dumping a vector." << std::endl;
		std::for_each(vec_prime_numbers.cbegin(), vec_prime_numbers.cend(), [&](const int& int_Item) {std::cout << '\x5b' << int_Item << '\x5d' << '\x2e' << '\t'; counter++;});
		std::cout << std::endl << "[" << counter << "] Output generated results." << std::endl;
		getPause("Press the ENTER key to continue...");

		/* Dumping the vector created using std::ostream class iterators. */
		std::cout << std::endl << "Dumping a vector." << std::endl;
		std::copy(std::cbegin(vec_prime_numbers), std::cend(vec_prime_numbers), std::ostream_iterator<int>(std::cout, "\t"));
		std::cout << std::endl;
		getPause("Press the ENTER key to continue...");

		/* Program Termination Messages. */
		std::cout << std::endl << "Done!" << std::endl;
		std::cout << "This program has ended." << std::endl;
		getPause("Press the ENTER key to continue...");

		return EXIT_SUCCESS;
	}
