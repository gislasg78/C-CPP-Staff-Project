/********************* Prime number Generator. *******************
 ** Source Code:	PrimeN.cpp				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, December 30, 2023.		**
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
//C Standard Libraries.
#include <iostream>
#include <vector>

//C Standard Constants.
#define V_ONE	1
#define V_TWO	2
#define V_ZERO	0

/*****************************************************************
 ** Function:		static bool blnIsPrimeNumber		**
 **				(size_t szt_number);		**
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
 ** Input Parms:	const size_t szt_number.		**
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
static bool blnIsPrimeNumber(const size_t szt_number)
	{
		size_t szt_div_count = V_ZERO;

		for (size_t szt_idx = V_ONE; szt_idx <= szt_number; szt_idx++)
			if (szt_number % szt_idx == V_ZERO)
				szt_div_count++;

		return (szt_div_count == V_TWO);
	}

/*****************************************************************
 ** Function:           std::vector<size_t>			**
 **				getvecsztPrimeNumbers		**
 **					(const size_t		**
 **						szt_quantity);	**
 **			(const int int_quantity);		**
 ** Explanation:	The purpose of this function is to loop	**
 **			back and forth from unity to 'n'	**
 **			to find each prime number divided by	**
 **			all the lower values, so that it loops	**
 **			through each previous value of 1...n	**
 **			to divide it by the values preceding,	**
 **			and thus verify that the number		**
 **			to be shown can only be divided between	**
 **			itself and the unit.			**
 ** Input Parms:	const int int_quantity.			**
 ** Output Parms:       None.                                   **
 ** Result:		As a result, this function returns an	**
 **			object of type 'vector' that		**
 **			sequentially stores each of the prime	**
 **			numbers obtained for later review and	**
 **			visualization.				**
 ****************************************************************/
std::vector<size_t> getvecsztPrimeNumbers(const size_t szt_quantity)
	{
		std::vector<size_t> vec_szt_prime_numbers = {V_ZERO};

		for (size_t szt_idx = V_ZERO; szt_idx < szt_quantity; szt_idx++)
			if (blnIsPrimeNumber(szt_idx))
				vec_szt_prime_numbers.push_back(szt_idx);

		return vec_szt_prime_numbers;
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
		size_t szt_counting = V_ZERO;
		size_t szt_quantity = V_ZERO;

		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+      Prime Number Generator.      +" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "Number of prime numbers you want to get: ";
		std::cin >> szt_quantity;

		std::vector<size_t> vec_szt_prime_numbers = getvecsztPrimeNumbers(szt_quantity);

		std::cout << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+       Prime Number Results.       +" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "| [" << szt_quantity << "] First Prime Numbers:" << std::endl;

		for (size_t szt_prime_number : vec_szt_prime_numbers)
			std::cout << "| # " << szt_counting++ << "\t:\t[" << szt_prime_number << "]." << std::endl;

		std::cout << "[" << szt_counting << "] Obtained output results." << std::endl;

		return V_ZERO;
	}
