/* This program calculates and returns an integer as a reversed integer. */

/* Standard Work Libraries. */
#include <stdio.h>

/* Symbolic work constants. */
#define V_TEN   10
#define V_ZERO  0

/* Function that returns an integer in reversed form. */
int reverseNumber(int number)
{
	int revNumber = V_ZERO;

	while (number)
	{
		revNumber *= V_TEN;
		revNumber += number % V_TEN;

		number /= V_TEN;
	}

	return revNumber;
}

//Main function.
int main()
{
	/* Preliminary working variables. */
	int number = V_ZERO;
	int revNumber = V_ZERO;

	/* Initial header messages. */
	printf("Inversion of an integer.\n");
	printf("Enter an integer: ");
	scanf("%d", &number);

	/* Call to the function that reverses the integer. */
	revNumber = reverseNumber(number);

	/* Visualization of results. */
	printf("\nResults.\n");
	printf("+ Number:\t[%d].\n", number);
	printf("+ Reversed:\t[%d].\n", revNumber);

	/* Termination messages. */
	printf("\nDone!\n");
	printf("This program has ended.\n");

	return V_ZERO;
}
