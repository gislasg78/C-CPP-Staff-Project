/* The primary goal of this program is to generate the greatest possible number
   of palindromic squares by performing iterations that check whether a number,
   when squared, yields a result identical to its own reverse.
*/

/* Standard Work Libraries. */
#include <stdio.h>

/* Symbolic work constants. */
#define	V_LOWER_LIMIT	1
#define	V_UPPER_LIMIT	94

/* Symbolic numerical working constants. */
#define	V_ONE		1
#define	V_TEN		10
#define	V_ZERO		0

/* Function that returns an integer in reversed form. */
long reverse_number(long number)
	{
		/* Preliminary working variables. */
		long reversed_number = V_ZERO;

		/* Invert the number provided. */
		while (number)
			{
				reversed_number = reversed_number * V_TEN + (number % V_TEN);
				number /= V_TEN;
			}

		/* Return of the reversed integer. */
		return reversed_number;
	}

/* Function to create palindromic numbers. */
long generate_palindromic_squares(long number)
	{
		/* Initial working variables. */
		long counter = V_ZERO;

		/* As long as 'n' number of palindromic squares have not been generated. */
		for (long idx = V_ONE; counter < number; idx++)
			{
				/* Squared number obtained. */
				long square_number = idx * idx;

				/* Check if the square is a palindromic number. */
				if (square_number == reverse_number(square_number))
					printf("(%2ld)\t[%10ld]\t{%18ld}.\n", counter++, idx, square_number);
			}

		printf("[%ld] Output generated results.\n", counter);

		/* Return the count of palindromic squares. */
		return counter;
	}

//Main function.
int main()
	{
		/* Initial working variables. */
		long counter = V_ZERO, number = V_ZERO;

		/* Requests the number of palindromic squares. */
		printf("Program that generates palindromic squares.\n");
		printf("Quantity of palindromic squares (%d - %d): ", V_LOWER_LIMIT, V_UPPER_LIMIT);
		scanf("%ld", &number);

		/* Validation of count limits. */
		if (number >= V_LOWER_LIMIT && number <= V_UPPER_LIMIT)
			{
				/* Generate palindromic squares. */
				printf("\nList of palindromic squares.\n");
				counter = generate_palindromic_squares(number);

				printf("\n[%ld] viewed outcomes.\n", counter);
			}
		else
			fprintf(stderr,"\nThe value: [%ld] is outside the range between: [%d] and: [%d].\n", number, V_LOWER_LIMIT, V_UPPER_LIMIT);

		/* Termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");

		return V_ZERO;
	}
