/********************* Prime Number Generator. *******************
 ** Source Code:	PrimeNumberGenerator.cpp		**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Wednesday, December 31, 2025.		**
 ** Purpose:		This program aims to determine the	**
 **			number of prime numbers found in a	**
 **			number determined by the user.		**
 **			It is understood that a prime number is **
 **			one that does not admit more divisors	**
 **			than unity and itself, therefore,	**
 **			if a prime number is divisible by other	**
 **			coefficients, it will then be		**
 **			considered a composite number.		**
*****************************************************************/
/* Standard Work Libraries. */
#include <iostream>
#include <vector>

/* Symbolic Work Constants. */
template <typename T>
constexpr T V_ONE	{static_cast<T>(1)};
template <typename T>
constexpr T V_TWO	{static_cast<T>(2)};
template <typename T>
constexpr T V_ZERO	{static_cast<T>(0)};

/*****************************************************************
 ** Function:		bool IsPrimeNumber			**
 **				(const size_t& number);		**
 ** Explanation:	The purpose of this function is that a	**
 **			number from 'n' to 'm' is subjected to	**
 **			multiple successive divisions and its	**
 **			remainder is obtained in each of them.	**
 **			If the number of successive divisions	**
 **			is precisely the value of two, it is	**
 **			considered prime, otherwise the number	**
 **			is composite.				**
 **			In the first example, true is returned,	**
 **			in the second, false.			**
 ** Input Parms:	const size_t& number.			**
 ** Output Parms:       None.                                   **
 ** Result:		Returns true if there are only two	**
 **			divisors, the unit and the number	**
 **			itself; returns false if there are more	**
 **			than two divisors.			**
 **								**
 **			Note: You can also determine that a	**
 **			number is prime if it is not divisible	**
 **			by two, three, five, or seven.		**
 ****************************************************************/
bool IsPrimeNumber(const size_t& number)
	{
		std::size_t div_count {};

		for (size_t idx {V_ONE<size_t>}; idx <= number; idx++)
			if (!(number % idx)) div_count++;

		return (div_count == V_TWO<size_t>);
	}

/*****************************************************************
 ** Function:           std::vector<size_t>			**
 **				getVectorPrimeNumbers		**
 **				(const size_t& quantity);	**
 ** Explanation:	The purpose of this function is to loop	**
 **			back and forth from unity to 'n'	**
 **			to find each prime number divided by	**
 **			all the lower values, so that it loops	**
 **			through each previous value of 1...n	**
 **			to divide it by the values preceding,	**
 **			and thus verify that the number		**
 **			to be shown can only be divided between	**
 **			itself and the unit.			**
 ** Input Parms:	const size_t& quantity.			**
 ** Output Parms:       None.                                   **
 ** Result:		As a result, this function returns an	**
 **			object of type 'vector' that		**
 **			sequentially stores each of the prime	**
 **			numbers obtained for later review and	**
 **			visualization.				**
 ****************************************************************/
std::vector<size_t> getVectorPrimeNumbers(const size_t& quantity)
	{
		size_t counter {};
		std::vector<std::size_t> vec_prime_numbers {};

		for (size_t idx {}; counter < quantity; idx++)
			if (IsPrimeNumber(idx))
				{
					counter++;
					vec_prime_numbers.push_back(idx);
				}

		return vec_prime_numbers;
	}

/*****************************************************************
 ** Function:           int main()				**
 ** Explanation:	The purpose of this main function is	**
 **			to ask the user through the keyboard	**
 **			the number of prime numbers they wish	**
 **			to obtain from 1...n.			**
 **			Subsequently, the function is called	**
 **			to generate the vector that will contain**
 **			each prime number with its corresponding**
 **			index, and finally, each element of the **
 **			calculated vector will be displayed	**
 **			on the screen.				**
 ** Input Parms:	None.					**
 ** Output Parms:       None.                                   **
 ** Result:		Display on the screen a vector with all	**
 **			the prime numbers calculated from 1...n.**
 ****************************************************************/
int main()
	{
		/* Preliminary working variables. */
		size_t counting {V_ZERO<size_t>};
		size_t quantity {V_ZERO<size_t>};

		/* Initial header messages. */
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "+      Prime Number Generator.      +" << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "Number of prime numbers you want to get: ";
		std::cin >> quantity;

		/* Obtain a vector containing the prime numbers found. */
		std::cout << std::endl << "Generating list of prime numbers..." << std::endl;
		std::vector<std::size_t> vec_prime_numbers = getVectorPrimeNumbers(quantity);

		/* Outbound header messages. */
		std::cout << std::endl << "Visualizing list of prime numbers..." << std::endl << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "+       Prime Number Results.       +" << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "| [" << quantity << "] First Prime Numbers." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;

		/* Dumping of the contents of the obtained vector. */
		for (const size_t& prime_number : vec_prime_numbers)
			std::cout << "| (" << counting++ << ")\t:\t[" << prime_number << "]." << std::endl;

		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "[" << counting << "] Obtained output results." << std::endl;

		/* Termination messages program. */
		std::cout << std::endl << "Done!" << std::endl;
		std::cout << "This program has ended." << std::endl;

		return EXIT_SUCCESS;
	}
