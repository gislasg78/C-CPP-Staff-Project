/******** Luhn algorithm to validate credit card numbers. ********
 ** Source Code:        CCNValid.cpp				**
 ** Author:             Gustavo Islas Gálvez.                   **
 ** Creation Date:      Saturday, December 30, 2023.            **
 ** Purpose:		The Luhn algorithm or Luhn formula,	**
 **			also known as "modulo 10 algorithm",	**
 **			is a checksum formula, used to validate **
 **			a variety of identification numbers;	**
 **			such as credit card numbers,		**
 **			IMEI numbers, etc.			**
 **			His idea became the basis for one of	**
 **			the most important algorithms of our	**
 **			era, the hash/hash function as we know	**
 **			it today.				**
 **			+---|----+---|----+---|----+---|----+	**
 **			Luhn Algorithm.				**
 **				1. Double every second digit	**
 **				   from right to left.		**
 **					If doubled number is	**
 **					two digits, split them.	**
 **				2. Add all single digits	**
 **					from step one.		**
 **				3. All all odd numbered digits	**
 **					from right to left.	**
 **				4. Sum results from steps	**
 **					two & three.		**
 **				5. If step four is divisible	**
 **					by ten, # is valid.	**
*****************************************************************/
//C Standard Libraries.
#include <algorithm>
#include <iostream>

//Work Constants.
#define	V_CHAR_ZERO	'0'

//C Standard Constants.
#define	V_MINUS_ONE	-1
#define	V_TEN		10
#define	V_TWO		2
#define	V_ZERO		0

//Definition of function prototypes.
int int_getADigit(const int int_digit_number);		//Obtain a single digit if the value obtained is greater than 4.
int int_sumOfDigits(const std::string &str_CardNumber);	//Add the digits of even and odd positions on the credit card.

/*****************************************************************
 ** Function:		int main().				**
 ** Explanation:	Luhn's algorithm detects any		**
 **			single-digit error, as well as almost	**
 **			all transpositions of adjacent digits.	**
 **			However, it cannot detect the		**
 **			transposition of the two-digit sequence	**
 **			09 to 90 (or vice versa).		**
 **			In that sense, it will detect seven of	**
 **			the 10 possible individual errors	**
 **			(it will not detect 22 ↔ 55, 33 ↔ 66	**
 **			or 44 ↔ 77).				**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		Because the algorithm operates on	**
 **			digits, from right to left, and zero	**
 **			digits affect the result only if they	**
 **			cause a change in one position, a string**
 **			of numbers padded with zeros at the	**
 **			beginning does not affect the		**
 **			calculation.				**
 **			Therefore, systems that pad a specific	**
 **			number of digits by converting from 1234**
 **			to 0.001.234 (for example), can perform	**
 **			Luhn validation before or after padding	**
 **			and achieve the same result.		**
 ****************************************************************/
int main()
	{
		/* Initial declaration of work variables. */
		int int_result = V_ZERO;
		std::string str_CardNumber;

		/* Welcome messages. */
		std::cout << "+---|----+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+  Luhn algorithm to validate credit cards.  +" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "Enter a valid credit card number  # : ";
		std::cin >> str_CardNumber;

		/* Eliminate any blank spaces in the card number. */
		str_CardNumber.erase(std::remove_if(str_CardNumber.begin(), str_CardNumber.end(), ::isspace), str_CardNumber.end());

		/* Call to function that adds the digits of even and odd positions of the credit card. */
		int_result = int_sumOfDigits(str_CardNumber);

		/* Result of the validation of the entered card number. */
		std::cout << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+ Validation results of the Luhn Algorithm.  +" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "Credit Card Number validated\t # : [" << str_CardNumber << "] ";

		/* If the remainder of dividing by ten the sum of digits of even and odd positions is zero, the card number is valid. */
		if (int_result % V_TEN)
			std::cout << "is not valid." << std::endl;
		else
			std::cout << "is valid." << std::endl;

		return V_ZERO;
	}

/*****************************************************************
 ** Function:		int int_getADigit(const int		**
 **				int_digit_number);		**
 ** Explanation:	Check Digit Calculation.		**
 **								**
 **			The above implementation checked the	**
 **			validity of an entry with a check digit.**
 **			The calculation of said digit requires	**
 **			a small adaptation of the above:	**
 **								**
 **			Change even/odd multiplication.		**
 **			If (sum mod 10) == 0, then the check	**
 **			digit is 0.				**
 **			Otherwise, the check digit is equal to	**
 **			(10 - (sum mod 10)).			**
 **								**
 ** Input Parms:	const int int_digit_number.		**
 ** Output Parms:	None.					**
 ** Result:		If the position is odd or even,		**
 **			respectively, only the digits are added	**
 **			as they are, or they are doubled and a	**
 **			single figure is extracted.		**
 ****************************************************************/
int int_getADigit(const int int_digit_number)
	{
		return int_digit_number % V_TEN + (int_digit_number / V_TEN % V_TEN);
	}

/*****************************************************************
 ** Function:		int int_sumOfDigits(			**
 **				const std::string		**
 **					&str_CardNumber).	**
 ** Explanation:	The formula checks a number against its	**
 **			included check digit, which is usually	**
 **			added to a partial account number to	**
 **			generate the full account number.	**
 **			This account number must pass the	**
 **			following test:				**
 **								**
 **			Starting from the included check digit,	**
 **			which is to the right of the entire	**
 **			number, go from right to left doubling	**
 **			every second digit.			**
 **								**
 **			Add the digits of the result:		**
 **				(example: 10 = 1 + 0 = 1,	**
 **					14 = 1 + 4 = 5)		**
 **			together with the unduplicated digits	**
 **			of the original number.			**
 **								**
 **			If the total modulo 10 is equal to 0	**
 **			(if the total ends in zero), then	**
 **			the number is valid according to the	**
 **			Luhn formula, otherwise it is invalid.	**
 ** Input Parms:	const std::string &str_CardNumber.	**
 ** Output Parms:	None.					**
 ** Result:		The bank card number is the number found**
 **			on payment cards, credit cards, debit	**
 **			cards, prepaid cards, gift cards and	**
 **			other similar cards (stored value cards	**
 **			and other Similar cards Some card	**
 **			issuers refer to the card number with	**
 **			the primary account number or PAN	**
 **			(primary account number).		**
 **								**
 **			They have certain levels of internal	**
 **			structure and share a common numbering	**
 **			scheme.					**
 **			Bank card numbers are assigned		**
 **			accordingly with ISO/IEC 7812 standard.	**
 ****************************************************************/
int int_sumOfDigits(const std::string &str_CardNumber)
	{
		/* Initial declaration of work variables. */
		bool bln_Bend = false;
		int int_Current_Digit = V_ZERO;
		int int_sumEvens = V_ZERO;
		int int_sumOdds = V_ZERO;

		/* Welcome messages. */
		std::cout << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+ Digit-by-digit analysis of the card number.+" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+---|----+" << std::endl;

		/* Cycle to go through each digit of the credit or debit card number from right to left. */
		for (int int_idx = str_CardNumber.size() + V_MINUS_ONE; int_idx >= V_ZERO; int_idx--)
			{
				int_Current_Digit = str_CardNumber[int_idx] - V_CHAR_ZERO;

				if (bln_Bend)
					{
						std::cout << "Pair:\t[" << int_idx << "]\t=\t[" << int_Current_Digit << "]\t:\t[" << int_Current_Digit * V_TWO << "]\t:\t[" << int_getADigit(int_Current_Digit * V_TWO) << "]." << std::endl;
						int_sumEvens += int_getADigit(int_Current_Digit * V_TWO);
					}
				else
					{
						std::cout << "Odd:\t[" << int_idx << "]\t=\t[" << int_Current_Digit << "]." << std::endl;
						int_sumOdds += int_Current_Digit;
					}

				bln_Bend = !bln_Bend;
			}

		/* Result of the validation of the entered card number. */
		std::cout << std::endl;
		std::cout << "Evens:\t[" << int_sumEvens << "]." << std::endl;
		std::cout << "Odds:\t[" << int_sumOdds << "]." << std::endl;

		/* Return the summed number of both odd and even digits. */
		return int_sumEvens + int_sumOdds;
	}
