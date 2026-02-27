/* Standard work libraries. */
#include <stdio.h>
#include <stdlib.h>

/* Symbolic work constants. */
#define	CARRIAGE_RETURN	'\n'

#define	V_MINUS_ONE	-1
#define	V_ONE		1
#define	V_TWO		2
#define	V_ZERO		0

//Validate a correct input from the keyboard.
int GetEntry(int *data_value)
	{
		/* Preliminary working variables. */
		int value_data = V_ZERO;

		/* Validate data entry as correct. */
		if (scanf("%d%*c", &value_data) == V_ONE)
			{
				/* Get a correct int value. */
				printf("Input value: [%d]. OK!\n", value_data);
				*data_value = value_data;
			}
		else
			{
				/* Get an incorrect int value. */
				printf("\nThe value entered is not valid.\n");

				scanf("%*[^\n]%*c");
				while (getchar() != CARRIAGE_RETURN && !feof(stdin));
			}

		return value_data;
	}

//Function that returns a pointer to a list of integers with prime factors.
int *GetPrimeFactors(const int number, int *quantity, int **factors)
	{
		/* Preliminary working variables. */
		size_t counter = V_ZERO;
		int divisor = V_TWO;
		int numeral = number;
		int *list_factors = NULL;

		/* Validate that the number to be entered is greater than absolute zero. */
		if (number > V_ZERO)
			{
				/* Count how many prime factors a given number has. */
				while (divisor <= numeral)
					if (numeral % divisor) divisor++; else {counter++; numeral /= divisor;}

				/* Create the pointer that will store the array of prime factors of a given number. */
				if ((list_factors = (int *) malloc(sizeof(int) * counter)))
					{
						/* Reset initial values. */
						counter = V_ZERO;
						divisor = V_TWO;
						numeral = number;

						/* Save each prime factor in the created pointer. */
						while (divisor <= numeral)
							{
								if (numeral % divisor)
									divisor++;
								else
									{
										*(list_factors + counter++) = divisor;
										numeral /= divisor;
									}
							}
					}
				else
					perror("There is not enough memory space to store the prime factors.");
			}
		else
			perror("It is not possible to calculate the prime factors of negative numbers or absolute zero.");

		/* Return the results generated in the pointers. */
		*quantity = (int) counter;
		*factors = list_factors;

		return list_factors;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int *list_factors = NULL;
		int counter = V_ZERO, number = V_ZERO, quantity = V_ZERO;
		printf("Decomposition of a number into its prime factors.\n");

		/* Request the number to be decomposed into its prime factors. */
		printf("Enter an integer value to decompose: ");
		number = GetEntry(&number);

		/* Validate that the number to be entered is greater than absolute zero. */
		if (number > V_ZERO)
			{
				if ((list_factors = GetPrimeFactors(number, &quantity, &list_factors)))
					{
						printf("\n");
						printf("Results.\n");
						printf("+ Number to be decomposed: [%d].\n", number);
						printf("+ Number of prime factors: [%d].\n\n", quantity);
						printf("+ List of prime factors:\n");

						for (int idx = V_ZERO; idx < quantity; idx++)
							{
								counter++;
								printf("#: [%d]\t=\t[%d].\n", idx, list_factors[idx]);
							}

						printf("[%d] Output generated results.\n", counter);
						free(list_factors);
					}
				else
					fprintf(stderr, "There is not enough memory space to store the prime factors.\n");
			}
		else
			fprintf(stderr, "It is not possible to calculate the prime factors of negative numbers or absolute zero.\n");

		return V_ZERO;
	}
