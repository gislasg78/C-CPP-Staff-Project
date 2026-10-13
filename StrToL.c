/* The primary objective of this simple C program
   is to demonstrate the use of the `strtol` function
   for practice purposes. */

/* Standard Work Libraries. */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/* Symbolic Work Constants. */
#define V_BASE  10
#define	V_ONE	1
#define V_ZERO  0

//Main function.
int main()
	{
		/* Preliminary Working Variables. */
		const char str_input[] = "2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536";
		const size_t size_of_str_input = sizeof(str_input) / sizeof(*str_input);
		char *endptr = NULL;
		long int value = V_ZERO;
		size_t position = V_ZERO;

		/* Initial header messages. */
		printf("Practice with StrToL.\n");
		printf("> %s <.\n\n", str_input);
		printf("Enter a position from: [%d] to: [%ld]: ", V_ZERO, size_of_str_input - V_ONE);
		scanf("%zu", &position);

		/* Validate that the starting position for extracting characters is less than the size of the character array. */
		if (position < size_of_str_input)
			{
				/* Extraction of the long integer value. */
				errno = V_ZERO;
				value = strtol(str_input + position, &endptr, V_BASE);

				printf("\nStrToL Results Obtained.\n");

				/* Verify whether the requested values were extracted. */
				if (endptr == str_input)
					{
						printf("No digit to extract was found!\n");
					}
				else
					{
						printf("+ Size of string:\t(%ld).\n", size_of_str_input);
						printf("+ Converted number:\t[%ld].\n", value);
						printf("+ Remaining characters:\t{%s}.\n", endptr);
					}
			}
		else
			fprintf(stderr, "\nError! The specified position is outside the range between: [%d] and: [%ld].\n", V_ZERO, size_of_str_input - V_ONE);

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");

		return V_ZERO;
	}
