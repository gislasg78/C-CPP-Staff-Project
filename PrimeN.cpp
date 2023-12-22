/********************* Prime number Generator. *******************
 ** Source Code:	PrimeN.cpp				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, December 23, 2023.		**
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
 ** Function:           bool blnIsPrimeNumber (int int_number);	**
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
 ** Input Parms:	const int int_number.			**
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
bool blnIsPrimeNumber(const int int_number)
	{
		int int_div_count=V_ZERO;

		for (int int_idx=V_ONE; int_idx <= int_number; int_idx++)
			if (int_number % int_idx == V_ZERO)
				int_div_count++;

		return (int_div_count==V_TWO);
	}

/*****************************************************************
 ** Function:           std::vector<int>			**
 **			getvecPrimeNumbers			**
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
std::vector<int> getvecPrimeNumbers(const int int_quantity)
	{
		std::vector<int> vec_prime_numbers;

		for (int int_idx=V_ZERO; int_idx<int_quantity; int_idx++)
			if (blnIsPrimeNumber(int_idx))
				vec_prime_numbers.push_back(int_idx);

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
		int int_counting=V_ZERO, int_quantity=V_ZERO;

		std::cout << "Enter the number of prime numbers you want to get: ";
		std::cin >> int_quantity;

		std::vector<int> vec_prime_numbers = getvecPrimeNumbers(int_quantity);

		std::cout << std::endl << "[" << int_quantity << "] First Prime Numbers:" << std::endl;

		for (int int_prime_number : vec_prime_numbers)
			std::cout << "# " << int_counting++ << " :\t[" << int_prime_number << "].\n";

		std::cout << std::endl;

		return V_ZERO;
	}
