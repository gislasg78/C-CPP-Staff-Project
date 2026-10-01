/********************* Prime Number Generator. *******************
 ** Source Code:	PrimeNumberGenerator.cpp		**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Thursday, December 31, 2026.		**
 ** Purpose:		This program aims to determine the	**
 **			number of prime numbers found in a	**
 **			number determined by the user.		**
 **			It is understood that a prime number is **
 **			one that does not admit more divisors	**
 **			than unity and itself, therefore,	**
 **			if a prime number is divisible by other	**
 **			coefficients, it will then be		**
 **			considered a composite number.		**
 **			+---|----+---|----+---|----+---|----+	**
 **			Note: This program uniquely compares	**
 **			different algorithms for generating	**
 **			prime numbers.				**
*****************************************************************/
/* Standard Work Libraries. */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

/* Symbolic Work Constants. */
template <typename T>
constexpr T CARRIAGE_RETURN	{static_cast<T>('\n')};

/* Template symbolic numeric bound constants. */
template <typename T>
constexpr T V_LOWER_LIMIT_PRIME	{static_cast<T>(1)};
template <typename T>
constexpr T V_UPPER_LIMIT_PRIME	{static_cast<T>(10000)};

/* Template symbolic numeric constants. */
template <typename T>
constexpr T V_FIVE		{static_cast<T>(5)};
template <typename T>
constexpr T V_ONE		{static_cast<T>(1)};
template <typename T>
constexpr T V_SEVEN		{static_cast<T>(7)};
template <typename T>
constexpr T V_THREE		{static_cast<T>(3)};
template <typename T>
constexpr T V_TWO		{static_cast<T>(2)};
template <typename T>
constexpr T V_ZERO		{static_cast<T>(0)};

/* This function pauses until the ENTER key is pressed. */
void enter_a_pause(const std::string& str_Message)
	{
		std::cout << str_Message;
		std::cin.clear();
		std::cin.get();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);
	}

/*****************************************************************
 ** Function:		bool IsPrime				**
 **				(const std::size_t& number);	**
 ** Explanation:	The fundamental purpose of this function**
 **			is to determine whether a number is	**
 **			prime based on a divisibility		**
 **			test—specifically, by verifying that it	**
 **			is not a multiple of 2, 3, 5, or	**
 **			7—thereby ruling out those numbers to	**
 **			establish whether the number is truly	**
 **			prime or definitely not prime.		**
 **								**
 **			This function is only useful for	**
 **			prime numbers less than one hundred	**
 **			(100).					**
 **								**
 ** Input Parms:	const std::size_t& number.		**
 ** Output Parms:       None.                                   **
 ** Result:		This function returns true if the	**
 **			number is prime				**
 **			(not divisible by 2, 3, 5, or 7),	**
 **			with these numbers excluded because	**
 **			they are the initial primes.		**
 **								**
 **			The function correctly identifies	**
 **			numbers that are not divisible by	**
 **			2, 3, 5, or 7,				**
 **			but this is not sufficient to determine	**
 **			general primality.			**
 ****************************************************************/
bool IsPrime(const std::size_t& number)
	{
		return	(number < V_TWO<size_t>) ? false :
			(((number == V_TWO<size_t>) || (number == V_THREE<size_t>) || (number == V_FIVE<size_t>) || (number == V_SEVEN<size_t>)) ||
			((number % V_TWO<size_t>) && (number % V_THREE<size_t>) && (number % V_FIVE<size_t>) && (number % V_SEVEN<size_t>)));
	}

/*****************************************************************
 ** Function:		bool IsPrimeNum				**
 **				(const size_t &number);		**
 ** Explanation:	The primary purpose of this function is	**
 **			to determine whether a given		**
 **			number—passed as a parameter—is prime	**
 **			by checking that it is not a multiple	**
 **			of any of the numbers sequentially	**
 **			preceding it (from 1 to *n*);		**
 **			if it is a multiple of any such		**
 **			preceding number, it is ruled out as	**
 **			a prime, since a prime number must be	**
 **			divisible only by 1 and itself.		**
 ** Input Parms:	const size_t &number.			**
 ** Output Parms:       None.                                   **
 ** Result:		This function returns 'true' or 'false'	**
 **			based on whether the number provided as	**
 **			a parameter is divisible—progressively	**
 **			and sequentially, without leaving any	**
 **			remainder—by its predecessors.		**
 ****************************************************************/
bool IsPrimeNum(const size_t &number)
	{
		for (std::size_t idx {V_TWO<std::size_t>}; idx <= (number / idx); idx += (idx == V_TWO<std::size_t>) ? V_ONE<std::size_t> : V_TWO<std::size_t>)
			if ((number % idx) == V_ZERO<std::size_t>) return false;

		return (number < V_TWO<std::size_t>) ? false : true;
	}

/*****************************************************************
 ** Function:		bool IsPrimeNum				**
 **			(const std::size_t& number,		**
 **			 const std::vector<std::size_t>&	**
 **					vec_primes);		**
 ** Explanation:	The purpose of this function is to	**
 **			verify that a number is prime—meaning	**
 **			it is divisible only by 1 and itself—and**
 **			to check a 'vector' container for	**
 **			previously stored prime numbers to	**
 **			ensure the number under analysis is not	**
 **			divisible by any of them.		**
 ** Input Parms:	const std::size_t& number.		**
 **			const std::vector<std::size_t>&		**
 **				vec_primes.			**
 ** Output Parms:       None.                                   **
 ** Result:		This function returns a result		**
 **			indicating whether the number is	**
 **			prime—specifically,			**
 **			if it is not found to be divisible by	**
 **			previously identified prime numbers	**
 **			(which are themselves divisible only by	**
 **			themselves and one).			**
 **								**
 **			Clarification Note:			**
 **				The prime number checking cycle	**
 **				can also use this stopping	**
 **				condition:			**
 **								**
 **				if ((prime * prime) > number)	**
 **					break;			**
 ****************************************************************/
bool IsPrimeNum(const std::size_t& number, const std::vector<std::size_t>& vec_primes_numbers)
	{
		if (number < V_TWO<std::size_t>)
			return false;

		for (const std::size_t& prime : vec_primes_numbers)
			{
				if (prime > (number / prime))
					break;

				if (!(number % prime))
					return false;
			}

		return true;
	}

/*****************************************************************
 ** Function:		bool IsPrimeNumber			**
 **				(const std::size_t& number);	**
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
 ** Input Parms:	const std::size_t& number.		**
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
bool IsPrimeNumber(const std::size_t& number)
	{
		std::size_t div_count {};

		for (std::size_t idx {V_ONE<std::size_t>}; idx <= number; idx++)
			if (!(number % idx)) div_count++;

		return (div_count == V_TWO<std::size_t>);
	}

/*****************************************************************
 ** Function:           std::vector<std::size_t>		**
 **				getVectorPrimeNumbers		**
 **				(const std::size_t& quantity);	**
 ** Explanation:	The purpose of this function is to loop	**
 **			back and forth from unity to 'n'	**
 **			to find each prime number divided by	**
 **			all the lower values, so that it loops	**
 **			through each previous value of 1...n	**
 **			to divide it by the values preceding,	**
 **			and thus verify that the number		**
 **			to be shown can only be divided between	**
 **			itself and the unit.			**
 ** Input Parms:	const std::size_t& quantity.		**
 ** Output Parms:       None.                                   **
 ** Result:		As a result, this function returns an	**
 **			object of type 'vector' that		**
 **			sequentially stores each of the prime	**
 **			numbers obtained for later review and	**
 **			visualization.				**
 ****************************************************************/
std::vector<std::size_t> getVectorPrimeNumbers(const std::size_t& quantity)
	{
		std::size_t counter {};
		std::vector<std::size_t> vec_primes_numbers {};

		for (std::size_t idx {}; counter < quantity; idx++)
			if (IsPrimeNum(idx))
				{
					counter++;
					vec_primes_numbers.push_back(idx);
				}

		return vec_primes_numbers;
	}

/*****************************************************************
 ** Function:           std::vector<std::size_t>		**
 **				getVectorPrimesNumbers		**
 **				(const std::size_t& quantity);	**
 ** Explanation:	This function returns a 'vector'	**
 **			container holding all the requested	**
 **			prime numbers up to a quantity 'n';	**
 **			it checks each candidate by comparing	**
 **			it against previously stored primes	**
 **			to ensure it is not divisible by them,	**
 **			thereby guaranteeing that the generated	**
 **			prime is divisible only by itself and	**
 **			one.					**
 ** Input Parms:	const std::size_t& quantity.		**
 ** Output Parms:       None.                                   **
 ** Result:		This function returns a 'vector'	**
 **			container holding all the generated	**
 **			prime numbers, verifying that they are	**
 **			not divisible by the primes already	**
 **			obtained—since, by definition,		**
 **			a prime number must be divisible	**
 **			strictly only by one and itself.	**
 ****************************************************************/
std::vector<std::size_t> getVectorPrimesNumbers(const std::size_t& quantity)
	{
		std::size_t counter {};
		std::vector<std::size_t> vec_primes_numbers {};

		for (std::size_t idx {V_TWO<std::size_t>}; counter < quantity; idx += (idx == V_TWO<std::size_t>) ? V_ONE<std::size_t> : V_TWO<std::size_t>)
			if (IsPrimeNum(idx, vec_primes_numbers))
				{
					counter++;
					vec_primes_numbers.push_back(idx);
				}

		return vec_primes_numbers;
	}

/*****************************************************************
 ** Function:		std::size_t viewVectorPrimeNumber	**
 **			(const std::vector<std::size_t>&	**
 **				vec_primes_numbers);		**
 ** Explanation:	The purpose of this function is		**
 **			to display every single element of the	**
 **			'vector' container holding prime	**
 **			numbers—a vector generated using one of	**
 **			the functions implemented in this	**
 **			program to produce prime numbers via	**
 **			various algorithms.			**
 ** Input Parms:	const std::vector<std::size_t>&		**
 **				vec_primes_numbers).		**
 ** Output Parms:       None.                                   **
 ** Result:		This function returns the number of	**
 **			elements displayed on the screen after	**
 **			outputting, element by element, the	**
 **			contents of the vector passed to it as	**
 **			an argument.				**
 ****************************************************************/
std::size_t viewVectorPrimeNumber(const std::vector<std::size_t>& vec_primes_numbers)
	{
		/* Preliminary internal working variables. */
		std::size_t counter {};

		/* Outbound header messages. */
		std::cout << std::endl << "Visualizing list of prime numbers..." << std::endl << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "+       Prime Number Results.       +" << std::endl;
		std::cout << "+===|====+===|====+===|====+===|====+" << std::endl;
		std::cout << "| [" << vec_primes_numbers.size() << "] First Prime Numbers." << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;

		/* Dumping of the contents of the first obtained vector. */
		for (std::vector<std::size_t>::const_iterator itc_vec_primes_numbers = vec_primes_numbers.cbegin(); itc_vec_primes_numbers != vec_primes_numbers.cend(); itc_vec_primes_numbers++)
			{
				std::cout << "| (" << counter++ << ")\t:\t[" << *itc_vec_primes_numbers << "]." << std::endl;
			}

		/* Final result messages. */
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "[" << counter << "] Obtained output results." << std::endl;
		enter_a_pause("Press the ENTER key to continue...");

		/* Returns the count of elements printed on the screen. */
		return counter;
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
		std::cout << "Quantity prime numbers between: [" << V_LOWER_LIMIT_PRIME<size_t> << "] and: [" << V_UPPER_LIMIT_PRIME<size_t> << "] you want to get: ";

		/* Input validation. */
		if (std::cin >> quantity)
			{
				/* Validate that the maximum number of prime numbers is within the range of 1 to 10,000. */
				if (quantity >= V_LOWER_LIMIT_PRIME<std::size_t> && quantity <= V_UPPER_LIMIT_PRIME<std::size_t>)
					{
						/* Obtain a vector containing the first prime numbers found. */
						std::cout << std::endl << "Generating first list of prime numbers..." << std::endl;
						std::vector<std::size_t> vec_primes_numbers_1 = getVectorPrimeNumbers(quantity);
						enter_a_pause("Press the ENTER key to continue...");

						counting = viewVectorPrimeNumber(vec_primes_numbers_1);
						std::cout << std::endl << "Displaying the prime number array." << std::endl;
						std::copy(vec_primes_numbers_1.cbegin(), vec_primes_numbers_1.cend(), std::ostream_iterator<std::size_t>(std::cout, "\t"));
						std::cout << std::endl << "Outcomes: [" << counting << "]." << std::endl;
						enter_a_pause("Press the ENTER key to continue...");

						/* Obtain a vector containing the second prime numbers found. */
						std::cout << std::endl << "Generating second list of primes numbers..." << std::endl;
						std::vector<std::size_t> vec_primes_numbers_2 = getVectorPrimesNumbers(quantity);
						enter_a_pause("Press the ENTER key to continue...");

						counting = viewVectorPrimeNumber(vec_primes_numbers_2);
						std::cout << std::endl << "Displaying the prime number array." << std::endl;
						std::copy(std::cbegin(vec_primes_numbers_2), std::cend(vec_primes_numbers_2), std::ostream_iterator<std::size_t>(std::cout, "\t"));
						std::cout << std::endl << "Results: [" << counting << "]." << std::endl;
						enter_a_pause("Press the ENTER key to continue...");
					}
				else
					std::cerr << "The entered value: [" << quantity << "] is outside the range between: [" << V_LOWER_LIMIT_PRIME<std::size_t> << "] and: [" << V_UPPER_LIMIT_PRIME<std::size_t> << "]." << std::endl;
			}
		else
			std::cerr << std::endl << "The input is incorrect or invalid!" << std::endl;

		/* Termination messages program. */
		std::cout << std::endl << "Done!" << std::endl;
		std::cout << "This program has ended." << std::endl;
		enter_a_pause("Press the ENTER key to continue...");

		return EXIT_SUCCESS;
	}
