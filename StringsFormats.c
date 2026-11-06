/* The primary purpose of this program is to demonstrate the use of functions
   such as 'snprintf', 'sscanf', and 'scanf' with a dynamic input format stored
   in a character array, and to validate the input process for this dynamically
   created character string. */

/* Standard Work Libraries. */
#include <stdio.h>
#include <stdlib.h>

/* Symbolic Work Constants. */
#define	V_ONE	1
#define	V_TWO	2
#define	V_ZERO 	0

//Main function.
int main()
	{
		/* Preliminary working variables. */
		static char buffer[V_TWO][BUFSIZ];
		static char str_format[V_TWO][BUFSIZ];
		static int int_chars[V_TWO] = {V_ZERO, V_ZERO};
		static int int_fields[V_TWO] = {V_ZERO, V_ZERO};

		/* Creation of a dynamic character array containing the type of format to be obtained. */
		if ((*int_chars = snprintf(*str_format, sizeof(*str_format), "%%%zu[^\n]%%*c%%n", sizeof(*str_format) - V_ONE)) >= V_ZERO && (size_t)*int_chars < sizeof(*str_format))
			{
				printf("Dynamically created format.\n");
				printf("+ Characters: [%d].\n", *int_chars);
				printf("+ String Fmt: {%s}.\n", *str_format);

				printf("\nCapture and evaluation of a character string.\n");
				printf("- Entry a string: ");

				/* Using a dynamic format character array to validate and accept data input. */
				#pragma GCC diagnostic push
				#pragma GCC diagnostic ignored "-Wformat-nonliteral"
				if ((*int_fields = scanf(*str_format, *buffer, int_chars)) == V_ONE && *(int_chars + V_ZERO) >= V_ZERO)
				#pragma GCC diagnostic pop
					{
						printf("\nInformation on the captured character string.\n");
						printf("+ Chars:  [%d].\n", int_chars[V_ZERO]);
						printf("+ Fields: [%d].\n", int_fields[V_ZERO]);
						printf("+ String: {%s}.\n", *buffer);

						/* Creation of a new dynamic character array containing the type of format to be obtained. */
						if ((*(int_chars + V_ONE) = snprintf(str_format[V_ONE], sizeof(str_format[V_ONE]), "%%%zu[^\n]%%n", sizeof(*(str_format + V_ONE)) - V_ONE)) >= V_ZERO && (size_t)int_chars[V_ONE] < sizeof(*(str_format + V_ONE)))
							{
								printf("\nDynamically created format.\n");
								printf("+ Characters: [%d].\n", *(int_chars + V_ONE));
								printf("+ String Fmt: {%s}.\n", *(str_format + V_ONE));

								/* Using a new dynamic format character array to validate and accept data input. */
								#pragma GCC diagnostic push
								#pragma GCC diagnostic ignored "-Wformat-nonliteral"
								if ((int_fields[V_ONE] = sscanf(*buffer, str_format[V_ONE], *(buffer + V_ONE), &int_chars[V_ONE])) == V_ONE)
								#pragma GCC diagnostic pop
									{
										printf("\nChain information captured and reassigned.\n");
										printf("+ Chars:  [%d].\n", *(int_chars + V_ONE));
										printf("+ Fields: [%d].\n", *(int_fields + V_ONE));
										printf("+ String: [%s].\n", buffer[V_ZERO]);
										printf("+ Output: {%s}.\n", *(buffer + V_ONE));
									}
								else
									fprintf(stderr, "\nError! Could not reassign new fields from string. Result: [%d].\n", int_fields[V_ONE]);
							}
						else
							fputs("\nThe second format string was not created correctly!\n", stderr);
					}
				else
					fprintf(stderr, "It was not possible to assign the capture string! Result: [%d].\n", int_fields[V_ZERO]);
			}
		else
			fputs("\nThe first format string was not created correctly!\n", stderr);

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended!\n");

		return V_ZERO;
	}
