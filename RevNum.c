/* This program calculates and returns an integer as a reversed integer. */

/* Standard Work Libraries. */
#include <stdio.h>

/* Symbolic work constants. */
#define V_TEN   10
#define V_ZERO  0

/* Function that returns an integer in reversed form. */
long reverse_number(long number)
	{
		/* Preliminary working variables. */
		long reversed_number = V_ZERO;

		/* Invert the number provided. */
		while (number)
			{
				reversed_number *= V_TEN;
				reversed_number += number % V_TEN;

				number /= V_TEN;
			}

		/* Return of the reversed integer. */
		return reversed_number;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		long number = V_ZERO;
		long inversed_number = V_ZERO;

		/* Initial header messages. */
		printf("Inversion of an integer.\n");
		printf("Enter an integer: ");
		scanf("%ld", &number);

		/* Call to the function that reverses the integer. */
		inversed_number = reverse_number(number);

		/* Visualization of results. */
		printf("\nResults.\n");
		printf("+ Number:\t[%ld].\n", number);
		printf("* Reversed:\t[%ld].\n", inversed_number);

		/* Termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");

		return V_ZERO;
	}
