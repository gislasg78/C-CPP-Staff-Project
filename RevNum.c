/* This program calculates and returns an integer as a reversed integer. */

/* Standard Work Libraries. */
#include <stdio.h>

/* Symbolic work constants. */
#define V_TEN	10
#define V_ZERO	0

long counter_digits(long number)
	{
		/* Preliminary working variables. */
		long counter = V_ZERO;

		/* Counting the number of digits in the number. */
		for (counter = V_ZERO; number; counter++, number /= V_TEN);

		/* Return of the reversed integer. */
		return counter;
	}

/* Function that returns an integer in reversed form.
   Formula: reversed_number *= V_TEN; reversed_number += number % V_TEN;
*/
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

//Main function.
int main()
	{
		/* Preliminary working variables. */
		long digits_number = V_ZERO;
		long number = V_ZERO;
		long reversed_number = V_ZERO;

		/* Initial header messages. */
		printf("Inversion of an integer.\n");
		printf("Enter an integer number: ");
		scanf("%ld", &number);

		/* Call to count the number of digits in the number. */
		digits_number = counter_digits(number);

		/* Call to the function that reverses the integer. */
		reversed_number = reverse_number(number);

		/* Visualization of results. */
		printf("\nResults.\n");
		printf("+ Number:\t[%ld].\n", number);
		printf("- Digits:\t[%ld].\n", digits_number);
		printf("* Reversed:\t[%ld].\n", reversed_number);

		/* Termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");

		return V_ZERO;
	}
