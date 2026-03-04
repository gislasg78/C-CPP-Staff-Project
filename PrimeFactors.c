/* This program extracts the list of prime factors of a given number. */

/* Standard work libraries. */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* Symbolic work constants. */
#define	CARRIAGE_RETURN	'\n'

#define	V_MINUS_ONE	-1
#define	V_ONE		1
#define	V_TWO		2
#define	V_ZERO		0

/* Validate a correct input from the keyboard. */
size_t GetEntry(const char *str_Message, size_t *data_value)
	{
		/* Preliminary working variables. */
		int counter_chars = V_ZERO, counter_fields = V_ZERO;
		size_t value_data = V_ZERO;

		/* Print the initial message. */
		printf("%s", str_Message);

		/* Validate data entry as correct. */
		if ((counter_fields = scanf("%zu%*c%n", &value_data, &counter_chars)) == V_ONE)
			{
				/* Get a correct int value. */
				printf("\nInput value: [%ld] = [%lu]. OK!\n", value_data, value_data);
				*data_value = value_data;
			}
		else
			{
				/* Get an incorrect int value. */
				fprintf(stderr, "\nThe value entered is not valid.\n");

				scanf("%*[^\n]%*c");
				while (getchar() != CARRIAGE_RETURN && !feof(stdin));
			}

		/* Return the correct value of this function. */
		return value_data;
	}

/* Function that returns a pointer to a list of integers with prime factors. */
size_t *GetPrimeFactors(const size_t number, size_t *quantity, size_t **factors)
	{
		/* Preliminary working variables. */
		size_t counter = V_ZERO;
		size_t divisor = V_TWO;
		size_t numeral = number;
		size_t *list_factors = NULL;

		/* Validate that the number to be entered is greater than absolute zero. */
		if (number > V_ZERO && number <= INT_MAX)
			{
				/* Count how many prime factors a given number has. */
				while (divisor <= numeral)
					if (numeral % divisor) divisor++; else {counter++; numeral /= divisor;}

				/* Create the pointer that will store the array of prime factors of a given number. */
				if ((list_factors = (size_t *) calloc(counter, sizeof(size_t))))
					{
						/* Reset initial values. */
						counter = V_ZERO; divisor = V_TWO; numeral = number;

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
			perror("It is not possible to calculate the prime factors of zero or such a gigantic number.");

		/* Return the results generated in the pointers. */
		*quantity = counter;
		*factors = list_factors;

		return list_factors;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		size_t *list_factors = NULL;
		size_t counter = V_ZERO, number = V_ZERO, quantity = V_ZERO;

		/* Header messages. */
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("|  Decomposition of prime factors.  |\n");
		printf("+===|====+===|====+===|====+===|====+\n");

		/* Request the number to be decomposed into its prime factors. */
		number = GetEntry("Enter an integer value to decompose: ", &number);

		/* Validate that the number to be entered is greater than absolute zero. */
		if (number > V_ZERO && number <= INT_MAX)
			{
				if ((list_factors = GetPrimeFactors(number, &quantity, &list_factors)))
					{
						/* Table of critical results. */
						printf("\n");
						printf("Results.\n");
						printf("+ Number to be decomposed: [%ld].\n", number);
						printf("+ Number of prime factors: [%ld].\n\n", quantity);

						/* List one by one of each calculated prime factor. */
						printf("+===|====+===|====+===|====+\n");
						printf("|  List of prime factors.  |\n");
						printf("+===|====+===|====+===|====+\n");

						for (size_t idx = V_ZERO; idx < quantity; idx++)
							printf("#: [%ld]\t=\t[%ld].\n", counter++, list_factors[idx]);

						printf("+---|----+---|----+---|----+\n");
						printf("[%ld] Output generated results.\n", counter);
						free(list_factors);
					}
				else
					fprintf(stderr, "\nThere is not enough memory space to store the prime factors.\n");
			}
		else
			fprintf(stderr, "\nIt is not possible to calculate the prime factors of zero or such a gigantic number.\n");

		return V_ZERO;
	}
