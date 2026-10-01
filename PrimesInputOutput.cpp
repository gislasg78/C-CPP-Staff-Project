/********************* Prime Number Generator. *******************
 ** Source Code:	PrimesInputOutput.cpp			**
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
 **			This program also stores and retrieves	**
 **			user-generated prime numbers in a file	**
 **			that is always appended to the end of	**
 **			each run of the program.		**
*****************************************************************/
/* C++ Standard Libraries. */
#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>

/* C++ Standard Constants. */
template <typename T>
constexpr T CARRIAGE_RETURN	{T('\n')};

/* Standard Numerical Constants. */
template <typename T>
constexpr T V_ONE		{T(1)};
template <typename T>
constexpr T V_TWO		{T(2)};
template <typename T>
constexpr T V_ZERO		{T(0)};

/* Generate a pause to continue later. */
void enter_a_pause(const std::string& str_Message)
	{
		std::cout << str_Message;
		std::cin.clear();
		std::cin.get();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);
	}

/*****************************************************************
 ** Function:           template <typename T>			**
 **				bool IsPrime(const T& number);	**
 ** Explanation:	This function is designed to check	**
 ** 			whether a number is prime, albeit in	**
 **			a very limited way:			**
 **								**
 **			it verifies that the number is not a	**
 **			multiple of any of the previous numbers	**
 **			in that prime number set.		**
 **								**
 **			It is used to obtain the first 'm'	**
 **			prime numbers between 1 and 'n'.	**
 ** Input Parms:	const T& number.			**
 ** Output Parms:       None.                                   **
 ** Result:		This function returns 'true' if the	**
 **			number analyzed in its parameter is	**
 **			prime, based on its divisibility only	**
 **			by one and itself.			**
 ****************************************************************/
template <typename T>
bool IsPrime(const T& number)
	{
		for (T divisor{V_TWO<T>}; divisor <= (number / divisor); divisor += (divisor == V_TWO<T>) ? V_ONE<T> : V_TWO<T>)
			if ((number % divisor) == V_ZERO<T>) return false;

		return (number < V_TWO<T>) ? false : true;
	}

/*****************************************************************
 ** Function:		template <typename T>			**
 **				T loadFile			**
 **					(const std::string&	**
 **						str_FileName);	**
 ** Explanation:	This function reads a file containing	**
 **			formatted prime numbers line by line	**
 **			and returns the number of lines		**
 **			successfully read.			**
 ** Input Parms:	const std::string& str_FileName.	**
 ** Output Parms:       None.                                   **
 ** Result:		This function returns the number of	**
 **			lines in the file that stores the prime	**
 **			numbers from previous program runs.	**
 ****************************************************************/
template <typename T>
T loadFile(const std::string& str_FileName)
	{
		/* Preliminary working variables. */
		T counter {V_ZERO<T>};
		std::string str_read_line {std::string()};

		/* Open a file for reading and writing simultaneously. */
		std::fstream iof_File(str_FileName, std::ios::in | std::ios::out | std::ios::app);

		/* Check if the file was opened successfully. */
		if (iof_File.is_open())
			{
				/* Move the read and write pointer to the beginning of the file. */
				iof_File.seekg(V_ZERO<T>, std::ios::beg);

				/* Reading line by line from the file until it finds its end. */
				std::cout << std::endl << "Display of file content: [" << str_FileName << "] line by line." << std::endl << std::endl;

				/* Sequential reading of the file line by line until the end is reached. */
				while (std::getline(iof_File, str_read_line))
					{
						counter++;
						std::cout << str_read_line << std::endl;
					}

				/* Close the file when finished. */
				iof_File.close();
			}
		else
			std::cerr << std::endl << "File: [" << str_FileName << "] could not be opened!" << std::endl;

		return counter;
	}

/*****************************************************************
 ** Function:		template <typename T>			**
 **				T saveFile			**
 **					(const std::string&	**
 **						str_FileName,	**
 **					 const T& quantity);	**
 ** Explanation:	The purpose of this function is		**
 **			to create a text-format file containing	**
 **			every prime number successfully found	**
 **			and generated, along with their		**
 **			respective headers and footers.		**
 ** Input Parms:	const std::string& str_FileName.	**
 **			const T& quantity.			**
 ** Output Parms:       None.                                   **
 ** Result:		This function returns the number of	**
 **			prime numbers 'm' between 1 and 'n'	**
 **			requested by the user.			**
 ****************************************************************/
template <typename T>
T saveFile(const std::string& str_FileName, const T& quantity)
	{
		/* Preliminary working variables. */
		T counter {V_ZERO<T>};
		time_t t_elapsed_seconds {time(&t_elapsed_seconds)};

		/* Open a file for reading and writing simultaneously. */
		std::fstream iof_File(str_FileName, std::ios::in | std::ios::out | std::ios::app);

		/* Check if the file was opened successfully. */
		if (iof_File.is_open())
			{
				/* Get current time and date. */
				iof_File << ctime(&t_elapsed_seconds);

				/* Write a sequential prime number series to the opened file. */
				iof_File << "[Index].\t[Prime]." << std::endl;

				/* Main loop that records each successfully found prime number. */
				for (T idx {V_ZERO<T>}; counter < quantity; idx++)
					if (IsPrime<T>(idx))
						iof_File << "(" << counter++ << ")\t:\t[" << idx << "]" << std::endl;

				iof_File << "[" << counter << "] Generated output results." << std::endl << std::endl;

				/* Close the file when finished. */
				iof_File.close();
			}
		else
			std::cerr << std::endl << "File: [" << str_FileName << "] could not be opened!" << std::endl;

		return counter;
	}

/*****************************************************************
 ** Function:           int main()				**
 ** Explanation:	The purpose of this main function is	**
 **			to ask the user through the keyboard	**
 **			the number of prime numbers they wish	**
 **			to obtain from 1...n.			**
 **			Subsequently, each prime number is	**
 **			created, evaluating that it is not a	**
 **			multiple of 2, 3, 5 and 7, with the	**
 **			exception of said numbers, and a list	**
 **			is saved with each series generated with**
 **			its respective date and time of		**
 **			generation.				**
 **			If the file does not exist, it is	**
 **			created, and if it already existed, each**
 **			generation of prime number lists is	**
 **			added to the end.			**
 ** Input Parms:	None.					**
 ** Output Parms:       None.                                   **
 ** Result:		The result consists of displaying on the**
 **			screen the content of the file saved	**
 **			with each series of prime numbers	**
 **			requested.				**
 **			Note: It has been purposely that the	**
 **			first index of generation of prime	**
 **			numbers, that is, the zero index number,**
 **			contains the value one, so that from	**
 **			index one onwards, the exact prime	**
 **			numbers are obtained.			**
 ****************************************************************/
int main()
	{
		/* Initial declaration of elementary work variables. */
		int counter {V_ZERO<int>};
		int quantity = {V_ZERO<int>};
		std::string str_FileName {};

		/* Data request. */
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+      Prime Number Generator.      +" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "Enter a top of primes numbers  : ";
		std::cin >> quantity;
		std::cout << "Enter a valid output file name : ";
		std::getline(std::cin >> std::ws, str_FileName);

		/* Introductory presentation headers. */
		std::cout << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+       Prime Number Results.       +" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "| + Program:\t[" << __FILE__ << "]." << std::endl;
		std::cout << "| + Date:\t[" << __DATE__ << "]." << std::endl;
		std::cout << "| + Time:\t[" << __TIME__ << "]." << std::endl;
		std::cout << "| + Line:\t[" << __LINE__ << "]." << std::endl;
		std::cout << "+---+----+---+----+---+----+---+----+" << std::endl;
		enter_a_pause("Press the ENTER key to continue...");

		/* Save the generated prime numbers to a file. */
		counter = saveFile<int>(str_FileName, quantity);
		std::cout << "[" << counter << "] Records processed." << std::endl;
		enter_a_pause("Press the ENTER key to continue...");

		/* Load the generated prime numbers from a file. */
		counter = loadFile<int>(str_FileName);
		std::cout << "[" << counter << "] Records recovered." << std::endl;
		enter_a_pause("Press the ENTER key to continue...");

		/* Program termination messages. */
		std::cout << std::endl << "Done!" << std::endl;
		std::cout << "This program has ended." << std::endl;
		enter_a_pause("Press the ENTER key to continue...");

		return EXIT_SUCCESS;
	}
