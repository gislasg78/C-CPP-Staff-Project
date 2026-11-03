/* The primary purpose of this program is to demonstrate an algorithm that reverses a given character string,
   returning it either as a static array—persisting within a function—or as a pointer
   to a dynamically allocated memory space for subsequent use. */

/* Standard Work Libraries. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Alphanumeric Symbolic Constants. */
#define	CARRIAGE_RETURN	'\n'
#define	NULL_CHARACTER	'\0'

/* Symbolic Work Constants. */
#define	V_ONE	1
#define	V_ZERO	0

/* Function that performs a specified pause with a warning message. */
char* getString(const char *const str_Message)
	{
		/* Preliminary working variables. */
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;
		int int_key = V_ZERO;

		/* Create a persistent chain. */
		static char string[BUFSIZ];
		memset(string, V_ZERO, sizeof(string));

		/* Header message. */
		printf("%s", str_Message);

		/* Validate data entry as correct. */
		if ((int_fields = scanf("%[^\n]%*c%n", string, &int_chars)))
			{
				/* Get a correct string value. */
				printf("\nCaptured chain information.\n");
				printf("+ Fields: [%d].\n", int_fields);
				printf("+ Value:  [%s].\n", string);
				printf("+ Chars:  [%d].\n", int_chars);
			}
		else
			{
				/* Check whether an End-of-File condition occurred during keyboard data input. */
				if (feof(stdin))
					{
						fprintf(stderr, "\nEnd of File (EOF) detected in data entry!\n");
						clearerr(stdin);
						fflush(stdin);
					}

				/* Get an incorrect entried value. */
				fputs("\nThe value entered is not valid!\n", stderr);
				fprintf(stderr, "Press ENTER to continue...");
				scanf("%*[^\n]%*c");

				/* Clear the input buffer until a carriage return followed by a line feed, or an end-of-file, is encountered. */
				fputs("\nPress the ENTER key to clear the input buffer...", stderr);
				while ((int_key = getchar()) != CARRIAGE_RETURN && int_key != EOF);
			}

		/* Return of a string value. */
		return string;
	}

/* Function to reverse a string. */
char *strReV(const char *const s)
	{
		/* Preliminary Working Variables. */
		size_t idx = V_ZERO, len = V_ZERO;

		/* Creation of a pointer character within this function. */
		static char *reversed = NULL;

		/* Obtain the string length. */
		len = strlen(s);

		/* Allocate storage for the reversed string copy. */
		if ((reversed = calloc(len + V_ONE, sizeof(char))))
			{
				/* Copy characters from the end of 's' to the start of 'reversed'. */
				idx = V_ZERO;	/* Index for the reversed string. */
				while (len)	/* Process the length of the string. */
					{
						/* Subtract 1 from len to account for the string starting at offset '0', not '1'. */
						*(reversed + idx) = *(s + len - V_ONE);	/* copy the character. */
						idx++;	/* Increase the 'reversed' index. */
						len--;	/* Decrease the 's' index. */
					}

				/* Always cap the string! */
				*(reversed + idx) = NULL_CHARACTER;
			}
		else
			fprintf(stderr, "Unable to allocate memory for the string!\n");

		/* Return the reversed and inverted string as a result. */
		return reversed;
	}

/* Function to reverse a string. */
char *strRev(const char *const s)
	{
		/* Preliminary Working Variables. */
		size_t idx = V_ZERO, len = V_ZERO;

		/* Creation of a persistent character array within this function. */
		static char reversed[BUFSIZ];
		const size_t size_of_reversed = sizeof(reversed) / sizeof(*reversed);
		memset(reversed, V_ZERO, size_of_reversed);

		/* Obtain the string length. */
		len = strlen(s);

		/* Copy characters from the end of 's' to the start of 'reversed'. */
		idx = V_ZERO;	/* Index for the reversed string. */
		while (len)	/* Process the length of the string. */
			{
				/* Subtract 1 from len to account for the string starting at offset '0', not '1'. */
				*(reversed + idx) = *(s + len - V_ONE);	/* copy the character. */
				idx++;	/* Increase the 'reversed' index. */
				len--;	/* Decrease the 's' index. */
			}

		/* Always cap the string! */
		*(reversed + idx) = NULL_CHARACTER;

		/* Return the reversed and inverted string as a result. */
		return reversed;
	}

//Main function.
int main()
	{
		/* Preliminary Working Variables. */
		char *ptr_reversed_string = NULL;
		char *ptr_string = NULL;

		/* Initial header messages. */
		printf("A program that reverses a character string.\n");

		/* Validate and verify the input data provided. */
		if ((ptr_string = getString("Type a string of characters: ")))
			{
				/* Result of the entered string. */
				printf("\nResult of the entered string.\n");
				printf("+ String: %s\n", ptr_string);

				/* Verify that a valid pointer to the reversed string has been returned. */
				if ((ptr_reversed_string = strRev(ptr_string)))
					{
						printf("\nOutput result generated.\n");
						printf("+ Inverted chain: %s\n", ptr_reversed_string);
					}
				else
					puts("\nIt was impossible to create the inverted string.");

				/* Verify that a valid pointer to the reversed string has been returned. */
				if ((ptr_reversed_string = strReV(ptr_string)))
					{
						printf("\nOutput result generated.\n");
						printf("+ Inverted chain: %s\n", ptr_reversed_string);
						printf("* Dynamically allocated memory released! *\n");
						free(ptr_reversed_string);
					}
				else
					puts("\nIt was impossible to create the inverted string.");
			}
		else
			fprintf(stderr, "\nFatal error while creating the character string!\n");

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended!\n");

		return V_ZERO;
	}
