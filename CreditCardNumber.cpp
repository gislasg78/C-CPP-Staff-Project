/******** Luhn algorithm to validate credit card numbers. ********
 ** Source Code:        CreditCardNumber.cpp			**
 ** Author:             Gustavo Islas Gálvez.                   **
 ** Creation Date:      Thursday, December 31, 2026.		**
 ** Purpose:		The Luhn algorithm or Luhn formula,	**
 **			also known as "modulo 10 algorithm",	**
 **			is a checksum formula, used to validate **
 **			a variety of identification numbers;	**
 **			such as credit card numbers,		**
 **			IMEI numbers, etc.			**
 **								**
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
 **			+===|====+===|====+===|====+===|====+	**
 **			Valid test values:			**
 **				1234 4321 1234 4321		**
 **				1234 1234 4321 4321		**
 **				4321 1234 4321 1234		**
 **                             1234 4321 4321 1234		**
 **				123  443  212  231  223		**
 **			+---|----+---|----+---|----+---|----+	**
 **			VISA.					**
 **				4507 9900 0000 4905		**
 **			 	123 	12-2026			**
 **			American Express (AMEX).		**
 **				3766 341249 71005		**
 **				1234 	12-2026			**
 **			Mastercard.				**
 **				5323 6222 7777 7785		**
 **				123	12-2026			**
*****************************************************************/
/* C Standard Libraries. */
#include <algorithm>
#include <functional>
#include <iostream>

/* Work Constants. */
template <typename T>
constexpr T CARRIAGE_RETURN	{T('\n')};
template <typename T>
constexpr T V_CHAR_DIG_ZERO	{T('\x30')};

/* C Standard Constants. */
template <typename T>
constexpr T V_MINUS_ONE		{T(-1)};
template <typename T>
constexpr T V_ONE		{T(1)};
template <typename T>
constexpr T V_TEN		{T(10)};
template <typename T>
constexpr T V_TWO		{T(2)};
template <typename T>
constexpr T V_ZERO		{T(0)};

/* Definition of function prototypes. */
template <typename T>
T getADigit(const T& digit_number);			//Obtain a single digit if the value obtained is greater than 4.
template <typename T>
T sumOfDigits(const std::string& str_CardNumber);	//Add the digits of even and odd positions on the credit card.

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
		int int_result {V_ZERO<int>};
		std::string str_CardNumber {};

		/* Function that returns a 'boolean' value to determine if the string of characters is purely numeric. */
		std::function<bool(const std::string&)> IsNumeric = [](const std::string& str_value) -> bool
			{
				return (str_value.empty()) ? false :
					std::all_of(str_value.begin(), str_value.end(), [](const unsigned char& c)
					{return std::isdigit(c);});
			};

		/* Welcome messages. */
		std::cout << "+===|====+====|====+====|====+====|" << std::endl;
		std::cout << "+  Credit Cards Luhn Algorithm.   +" << std::endl;
		std::cout << "+===|====+====|====+====|====+====|" << std::endl;
		std::cout << "Enter a valid credit card number  # : ";

		/* Get the character string with the credit card number. */
		std::getline(std::cin >> std::ws, str_CardNumber);

		/* Validate that it is not an empty string. */
		if (str_CardNumber.empty())
			std::cout << std::endl << "Enter a credit card number that has values. " << std::endl;
		else
			{
				/* Eliminate any blank spaces in the card number. */
				str_CardNumber.erase(std::remove_if(str_CardNumber.begin(), str_CardNumber.end(), ::isspace), str_CardNumber.end());

				/* Validate that the character string is pure numeric. */
				if (IsNumeric(str_CardNumber))
					{
						/* Call to function that adds the digits of even and odd positions of the credit card. */
						int_result = sumOfDigits<int>(str_CardNumber);

						/* Result of the validation of the entered card number. */
						std::cout << std::endl << "Credit Card Number validated      # : [" << str_CardNumber << "] = ";

						/* If the remainder of dividing by ten the sum of digits of even and odd positions is zero, the card number is valid. */
						if (int_result % V_TEN<int>)
							std::cout << "[is not valid]." << std::endl;
						else
							std::cout << "[is valid]." << std::endl;
					}
				else
					std::cout << std::endl << "The credit card number: [" << str_CardNumber << "] must be exclusively numeric." << std::endl;
			}

		/* Program termination messages. */
		std::cout << CARRIAGE_RETURN<char> << "Done!" << CARRIAGE_RETURN<char>;
		std::cout << "This program has ended." << CARRIAGE_RETURN<char>;

		return EXIT_SUCCESS;
	}

/*****************************************************************
 ** Function:		template <typename T>			**
 **				T getADigit			**
 **				(const T& digit_number);	**
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
 ** Input Parms:	const T& digit_number.			**
 ** Output Parms:	None.					**
 **								**
 ** Result:		If the position is odd or even,		**
 **			respectively, only the digits are added	**
 **			as they are, or they are doubled and a	**
 **			single figure is extracted.		**
 ****************************************************************/
template <typename T>
T getADigit(const T& digit_number)
	{
		return (digit_number % V_TEN<T> + (digit_number / V_TEN<T> % V_TEN<T>));
	}

/*****************************************************************
 **			template <typename T>			**
 ** Function:			T sumOfDigits			**
 **				(const std::string		**
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
 **								**
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
 **								**
 **			Bank card numbers are assigned		**
 **			accordingly with ISO/IEC 7812 standard.	**
 ****************************************************************/
template <typename T>
T sumOfDigits(const std::string& str_CardNumber)
	{
		/* Preliminary declarations of variables. */
		T CardNumber_Length = T(str_CardNumber.length());
		T CardNumber_Size = (T) str_CardNumber.size();

		/* Initial declaration of work variables. */
		T counting_items {V_ZERO<T>}, counting_pos_items {V_ZERO<T>};
		T counting_odds {V_ZERO<T>}, counting_pos_odds {V_ZERO<T>};
		T counting_pairs {V_ZERO<T>}, counting_pos_pairs {V_ZERO<T>};

		/* Special work variables. */
		T Current_Digit {V_ZERO<T>};
		T sumOfEvens {V_ZERO<T>};
		T sumOfOdds {V_ZERO<T>};
		T sumTotal {V_ZERO<T>};

		/* Array character string of type number. */
		std::string str_TypeOfNumber[] = {"Pair", "Odd"};

		/* Welcome messages. */
		std::cout << std::endl;
		std::cout << "+===|====+====|====+====|====+====|" << std::endl;
		std::cout << "+  Card Digit-by-digit Analysis.  +" << std::endl;
		std::cout << "+===|====+====|====+====|====+====|" << std::endl;

		/* Cycle to go through each digit of the credit or debit card number from right to left. */
		for (T ind {V_ONE<T>}, idx = CardNumber_Size + V_MINUS_ONE<T>; ind <= CardNumber_Size && idx >= V_ZERO<T>; ind++, idx--)
			{
				/* Digit-by-digit accounting messages. */
				counting_items++; counting_pos_items++;
				Current_Digit = static_cast<T>(str_CardNumber[idx]) - V_CHAR_DIG_ZERO<T>;

				std::cout << "# [" << ind << "]\t{" << str_TypeOfNumber[ind % V_TWO<T>] << "}\t(" << Current_Digit << ")\t{"<< str_TypeOfNumber[Current_Digit % V_TWO<T>] << "}\t[" << idx + V_ONE<T> << "]." << std::endl;

				/* Even and odd validation point. */
				if (ind % V_TWO<T>)
					{
						counting_pos_odds++;
						sumOfOdds += Current_Digit;
					}
				else
					{
						counting_pos_pairs++;
						sumOfEvens += getADigit(Current_Digit * V_TWO<T>);
					}

				/* Count even and odd digits within the credit card number. */
				if (Current_Digit % V_TWO<T>) counting_odds++; else counting_pairs++;
			}

		std::cout << "[" << counting_pos_items << "] Generated output results." << std::endl;

		/* Result of the validation of the entered card number. */
		sumTotal = sumOfOdds + sumOfEvens;

		/* Output messages with detailed results. */
		std::cout << std::endl;
		std::cout << "+===|====+====|====+====|====+====|" << std::endl;
		std::cout << "+ Validation Card Luhn Algorithm. +" << std::endl;
		std::cout << "+===|====+====|====+====|====+====|" << std::endl;
		std::cout << "| > Credit Card Number: [" << str_CardNumber << "]." << std::endl;
		std::cout << "+---|----+----|----+----|----+----|" << std::endl;
		std::cout << "+   Basic Content's Card Number.  +" << std::endl;
		std::cout << "+---|----+----|----+----|----+----|" << std::endl;
		std::cout << "| + Items:\t[" << counting_pos_items << "]\t(" << counting_items << ")." << std::endl;
		std::cout << "| + Odds:\t[" << counting_pos_odds << "]\t(" << counting_odds << ")." << std::endl;
		std::cout << "| + Pairs:\t[" << counting_pos_pairs << "]\t(" << counting_pairs << ")." << std::endl;
		std::cout << "+---|----+----|----+----|----+----|" << std::endl;
		std::cout << "+   Chain's General Information.  |" << std::endl;
		std::cout << "+---|----+----|----+----|----+----|" << std::endl;
		std::cout << "| * Length:\t[" << CardNumber_Length << "]." << std::endl;
		std::cout << "| * Size:\t[" << CardNumber_Size << "]." << std::endl;
		std::cout << "+---|----+----|----+----|----+----|" << std::endl;
		std::cout << "+ Digits sum by relative position.+" << std::endl;
		std::cout << "+---|----+----|----+----|----+----|" << std::endl;
		std::cout << "| - Evens:\t[" << sumOfEvens << "]." << std::endl;
		std::cout << "| - Odds:\t[" << sumOfOdds << "]." << std::endl;
		std::cout << "+---|----+----|----+----|----+----|" << std::endl;
		std::cout << "| > Total:\t[" << sumTotal << "]." << std::endl;
		std::cout << "+===|====+====|====+====|====+====|" << std::endl;

		/* Return the summed number of both odd and even digits. */
		return sumTotal;
	}
