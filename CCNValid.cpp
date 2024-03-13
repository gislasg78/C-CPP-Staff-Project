/* Luhn Algorithm.
 * 1. Double every second digit from right to left.
 *    If doubled number is two digits, split them.
 * 2. Add all single digits from step one.
 * 3. All all odd numbered digits from right to left.
 * 4. Sum results from steps two & three.
 * 5. If step four is divisible by ten, # is valid.
*/
#include <iostream>

#define	V_CHAR_ZERO	'0'

#define	V_MINUS_ONE	-1
#define	V_MINUS_TWO	-2

#define	V_TEN	10
#define	V_TWO	2
#define	V_ZERO	0


int getDigit(const int number);
int sumOddDigits(const std::string cardNumber);
int sumEvenDigits(const std::string cardNumber);

int main()
	{
		std::string cardNumber;
		int result = V_ZERO;

		std::cout << "Enter a credit card #: ";
		std::cin >> cardNumber;

		result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

		if (result % V_TEN)
			std::cout << "[" << cardNumber << "] is not valid." << std::endl;
		else
			std::cout << "[" << cardNumber << "] is valid." << std::endl;

		return V_ZERO;
	}

int getDigit(const int number)
	{
		return number % V_TEN + (number / V_TEN % V_TEN);
	}

int sumOddDigits(const std::string cardNumber)
	{
		int sum = V_ZERO;

		for (int i = cardNumber.size() + V_MINUS_ONE; i >= V_ZERO; i += V_MINUS_TWO)
			sum += cardNumber[i] - V_CHAR_ZERO;

		return sum;
	}

int sumEvenDigits(const std::string cardNumber)
	{
		int sum = V_ZERO;

		for (int i = cardNumber.size() + V_MINUS_TWO; i >= V_ZERO; i += V_MINUS_TWO)
			sum += getDigit((cardNumber[i] - V_CHAR_ZERO) * V_TWO);

		return sum;
	}
