/* The purpose of this program is to set the output buffer
   where emitted data is written and to hold it until
   it is subsequently released. */

/* Standard Work Libraries. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* Alphanumeric Symbolic Constants. */
#define	CARRIAGE_RETURN			'\n'

/* User-defined macros. */
#define GENERATE_RANDOM(v, minV, maxV)	(((v) % ((maxV) - (minV) + (V_ONE))) + (minV))

/* Symbolic Work Constants. */
#define	V_ONE				1
#define V_ZERO				0

//Main function.
int main()
	{
		/* Preliminary Working Variables. */
		char buffer[BUFSIZ];
		memset(buffer, V_ZERO, BUFSIZ);

		/* Intermediate and auxiliary working variables. */
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;

		/* Diversified accumulators and counters. */
		size_t bc = V_ZERO;					//‘size_t’ {aka ‘long unsigned int’}.
		size_t lower_limit = V_ZERO, upper_limit = V_ZERO;
		size_t quantity = V_ZERO;

		/* Seed the randomizer. */
		time_t t_elapsed_seconds = time(&t_elapsed_seconds);	//‘time_t’ {aka ‘long int’} to ‘unsigned int’
		srand((unsigned int) t_elapsed_seconds);

		/* Configure the buffer for unbuffered output. */
		setvbuf(stdout, buffer, _IONBF, BUFSIZ);

		/* Cycle to demonstrate the delay in writing to the output buffer. */
		printf("Output Buffer Write Test.\n");
		printf("+ Number of values ​​to generate: ");

		/* Enter the number of values ​​to generate. */
		int_chars = V_ZERO;
		if ((int_fields = scanf("%zu%*c%n", &quantity, &int_chars)) == V_ONE)
			{
				printf("+ Lower limit of the generator: ");

				/* Enter the 'lower limit' for the set of random values ​​to be generated. */
				int_chars = V_ZERO;
				if ((int_fields = scanf("%zu%*c%n", &lower_limit, &int_chars)) == V_ONE)
					{
						printf("+ Upper limit of the generator: ");

						/* Enter the 'upper limit' for the set of random values ​​to be generated. */
						int_chars = V_ZERO;
						if ((int_fields = scanf("%zu%*c%n", &upper_limit, &int_chars)) == V_ONE)
							{
								puts("");

								/* Generation of random numbers and accumulation in the output buffer stream. */
								for (size_t idx = V_ZERO; idx < quantity; idx++)
									{
										/* Obtaining a random value according to a predefined macro. */
										size_t random_value = GENERATE_RANDOM((size_t) rand(), lower_limit, upper_limit);
										bc += random_value;

										/* Sending an outgoing message. */
										printf("Accumulating in the turn: [%zu] of: [%zu] the sum: [%zu] with current value: [%zu]...\t\r", idx + V_ONE, quantity, bc, random_value);
										sleep(V_ONE);
									}

								putchar(CARRIAGE_RETURN);
							}
						else
							fprintf(stderr, "\nInvalid and incorrect 'upper limit' entry!\n");
					}
				else
					fprintf(stderr, "\nInvalid and incorrect 'lower limit' entry!\n");
			}
		else
			fprintf(stderr, "\nInvalid and incorrect 'number of values' entry!\n");

		/* Program termination messages. */
		puts("\nDone!");
		puts("This program has ended.");

		return V_ZERO;
	}
