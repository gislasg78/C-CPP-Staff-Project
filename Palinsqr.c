#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define	V_ONE	1
#define V_TEN   10
#define V_ZERO  0

//Function to check if a number is a palindrome.
bool bln_Is_Palindromic_Square(int int_number)
	{
		//Initial working variables.
		int int_original_number = int_number;
		int int_inverted_number = V_ZERO;
		int int_rest_number = V_ZERO;

		//Invert the number provided.
		while (int_number > V_ZERO)
			{
				int_rest_number = int_number % V_TEN;
				int_inverted_number = int_inverted_number * V_TEN + int_rest_number;
				int_number /= V_TEN;
			}

		//Compare the inverted number with the original number.
		return int_original_number == int_inverted_number;
	}

//Function to create palindromic numbers.
void generate_Palindromic_Squares(int int_number)
	{
		//Initial working variables.
		int int_counter = V_ZERO;
		int int_idx = V_ONE;

		//As long as 'n' number of palindromic squares have not been generated.
		while (int_counter < int_number)
			{
				//Squared number obtained.
				int int_square_number = int_idx * int_idx;

				//Check if the square is palindromic.
				if (bln_Is_Palindromic_Square(int_square_number))
					{
						printf("#%3.d:\t[%10.d].\n", int_counter + V_ONE, int_square_number);
						int_counter++;
					}

				int_idx++;
			}
	}


int main()
	{
		//Initial working variables.
		int int_number = V_ZERO;

		//Requests the number of palindromic squares.
		printf("Program that automatically generates palindromic squares.\n");
		printf("Enter the number of palindromic squares to generate: ");
		scanf("%d", &int_number);

		//Generate palindromic squares.
		printf("\n");
		printf("List of generated palindromic squares.\n");
		generate_Palindromic_Squares(int_number);

		return V_ZERO;
	}
