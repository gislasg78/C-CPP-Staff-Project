/********************* Prime number Generator. *******************
 ** Source Code:	PrimesIO.cpp				**
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
 **			This program also stores and retrieves	**
 **			user-generated prime numbers in a file	**
 **			that is always appended to the end of	**
 **			each run of the program.		**
*****************************************************************/
//C Standard Libraries.
#include <ctime>
#include <iostream>
#include <fstream>

//C Standard Constants.
#define	V_FIVE		5
#define	V_SEVEN		7
#define	V_THREE		3
#define	V_TWO		2
#define V_ZERO  	0

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
		int int_counting_items = V_ZERO;
		int int_number_Rows = V_ZERO;
		std::string str_FileName = "";
		std::string str_readed_line = "";

		/* Data request. */
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "+      Prime Number Generator.      +" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
		std::cout << "Enter a top of primes numbers  : ";
		std::cin >> int_number_Rows;
		std::cout << "Enter a valid output file name : ";
		std::getline(std::cin >> std::ws, str_FileName);

		/* Open a file for reading and writing simultaneously. */
		std::fstream input_output_FileName(str_FileName, std::ios::in | std::ios::out | std::ios::app);

		/* Check if the file was opened successfully. */
		if (input_output_FileName.is_open())
			{
				std::cout << std::endl;
				std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
				std::cout << "+       Prime Number Results.       +" << std::endl;
				std::cout << "+---|----+---|----+---|----+---|----+" << std::endl;
				std::cout << "Program: [" << __FILE__ << "].\tDate: [" << __DATE__ << "].\tTime: [" << __TIME__ << "]." << std::endl;

				/* Get current time and date. */
				time_t t_seconds = V_ZERO;
				time(&t_seconds);
				input_output_FileName << ctime(&t_seconds);

				/* Write a sequential prime number series to the opened file. */
				input_output_FileName << "[Index].\t[Prime]." << std::endl;

				for (int int_idx = V_ZERO; int_idx < int_number_Rows; int_idx++)
					if ((int_idx == V_TWO) || (int_idx == V_THREE) || (int_idx == V_FIVE) || (int_idx == V_SEVEN))
						input_output_FileName << "[" << int_counting_items++ << "]\t:\t[" << int_idx << "]" << std::endl;
					else if ((int_idx % V_TWO) && (int_idx % V_THREE) && (int_idx % V_FIVE) && (int_idx % V_SEVEN))
						input_output_FileName << "[" << int_counting_items++ << "]\t:\t[" << int_idx << "]" << std::endl;

				input_output_FileName << "[" << int_counting_items << "] Generated output results." << std::endl << std::endl;

				/* Move the read and write pointer to the beginning of the file. */
				input_output_FileName.seekg(V_ZERO, std::ios::beg);

				/* Reading line by line from the file until it finds its end. */
				std::cout << "Display of file content: [" << str_FileName << "] line by line." << std::endl << std::endl;

				while (std::getline(input_output_FileName, str_readed_line))
					std::cout << str_readed_line << std::endl;

				/* Close the file when finished. */
				input_output_FileName.close();
			}
		else
			std::cerr << "File: [" << str_FileName << "] could not be opened!" << std::endl;

		return V_ZERO;
	}
