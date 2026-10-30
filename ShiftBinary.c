/* This program converts a 2-byte (16-bit) short integer into a character string
   representing its binary form, and shifts each bit both to the left
   (equivalent to multiplication by powers of 2)
   and to the right (equivalent to division by powers of 2). */

/* Standard Work Libraries. */
#include <limits.h>
#include <stdio.h>

/* Compile-time predefined macros for calculating the size of a given variable. */
#define	SIZE_BINARY(n)		(sizeof(n) * (V_EIGHT))
#define SIZE_BINARY_MAX(n)	((sizeof(n) * (V_EIGHT)) + (V_ONE))

/* Numeric Symbolic Constants. */
#define	CARRIAGE_RETURN		'\n'	//Value: 0xC == 13.
#define	NULL_CHARACTER		'\0'	//Value: 0x00 == 0.
#define	V_CHAR_DIGIT_ZERO	'\x30'	//Value: '0'.
#define	V_CHAR_DIGIT_ONE	'\x31'	//Value: '1'.

/* Program Startup Values. */
#define	V_0X0001		0x0001	//Value: +1.
#define	V_0X00FF		0x00FF	//Value: 255 == 2^8 - 1.
#define	V_0X8000		0x8000	//Value: 32768 == 2^15.
#define V_0XAAAA		0xAAAA	//Value: 43690.
#define	V_0XFFFF		0xFFFF	//Value: 65535 == 2^16 - 1.

/* Numeric Symbolic Constants. */
#define	V_EIGHT			8
#define V_ONE			1
#define	V_ZERO			0

/* Ensure that unsigned short has exactly 16 value bits. */
_Static_assert(USHRT_MAX == V_0XFFFF, "This program requires a 16-bit unsigned short int.");

/* A function that converts a 16-bit short integer into a string of 'zeros' and 'ones'. */
char *binString(unsigned short number)
{
	/* Preliminary Working Variables. */
	const size_t size_bin = SIZE_BINARY(number);	//Size in bits of the study variable.
	static char bin[SIZE_BINARY_MAX(number)];	//Character pointer with the binary number.

	/* Construction of the binary character string, character by character. */
	for (size_t idx = V_ZERO; idx < size_bin; idx++)
	{
		bin[idx] = number & V_0X8000 ? V_CHAR_DIGIT_ONE : V_CHAR_DIGIT_ZERO;
		number = (unsigned short) (number << V_ONE);
	}

	/* Terminate the string with the end-of-string character (null character). */
	bin[size_bin] = NULL_CHARACTER;

	/* Return the value of the string pointer created with binary digits. */
	return (bin);
}

/* Function that performs a specified pause with a warning message. */
char getPause(const char *str_Message)
{
	/* Preliminary working variables. */
	char chr_key = NULL_CHARACTER;
	int int_chars = V_ZERO;
	int int_fields = V_ZERO;
	int int_key = V_ZERO;

	/* Header message. */
	printf("%s", str_Message);

	/* Validate data entry as correct. */
	if ((int_fields = scanf("%c%*c%n", &chr_key, &int_chars)) == V_ONE)
	{
		/* Get a correct character value. */
		printf("\nFields: [%d]. Input value: [%x] : [%d] = [%c]. Characters: [%d]. OK!\n", int_fields, chr_key, chr_key, chr_key, int_chars);
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

		chr_key = (char) int_key;
	}

	/* Return of key value. */
	return chr_key;
}

//Main function.
int main()
{
	/* Preliminary Working Variables. */
	size_t counter = V_ZERO;
	unsigned short a = V_0XAAAA, b = V_0X00FF, c = V_ZERO;

	/* Initial Header Message. */
	printf("Example Exercise Involving Bit Swaps.\n");

	/* Bitwise operation using the 'AND' conjunction. */
	c = a & b;

	printf("\n\'AND\x27 Bitwise operation conjunction.\n");
	printf("+ Start: [%5u] - {%04x} - <%s>.\n", a, a, binString(a));
	printf("+     &: [%5u] - {%04x} - <%s>.\n", b, b, binString(b));
	printf("+   End: [%5u] - {%04x} - <%s>.\n", c, c, binString(c));
	getPause("Press the ENTER key to continue...");

	/* Bitwise operation using the 'OR' disjunction. */
	c = a | b;

	printf("\n\x27OR\x27 Bitwise operation disjunction.\n");
	printf("+ Start: [%5u] - {%04x} - <%s>.\n", a, a, binString(a));
	printf("+     |: [%5u] - {%04x} - <%s>.\n", b, b, binString(b));
	printf("+   End: [%5u] - {%04x} - <%s>.\n", c, c, binString(c));
	getPause("Press the ENTER key to continue...");

	/* Bitwise operation using the 'XOR' exclusive-disjunction. */
	c = a ^ b;

	printf("\n\x27XOR\x27 Bitwise operation exclusive-disjunction.\n");
	printf("+ Start: [%5u] - {%04x} - <%s>.\n", a, a, binString(a));
	printf("+     ^: [%5u] - {%04x} - <%s>.\n", b, b, binString(b));
	printf("+   End: [%5u] - {%04x} - <%s>.\n", c, c, binString(c));
	getPause("Press the ENTER key to continue...");

	/* Bit test with 'one's complement' with 'a' variable. */
	c = ~a;

	printf("\n\x22One\x27s Complement\x22 \'a\' Bitwise operation.\n");
	printf("+ Start: [%5u] - {%04x} - <%s>.\n", a, a, binString(a));
	printf("+   End: [%5u] - {%04x} - <%s>.\n", c, c, binString(c));
	getPause("Press the ENTER key to continue...");

	/* Bit test with 'one's complement' with 'b' variable. */
	c = ~b;

	printf("\n\x22One\x27s Complement\x22 \'b\' Bitwise operation.\n");
	printf("+ Start: [%5u] - {%04x} - <%s>.\n", b, b, binString(a));
	printf("+   End: [%5u] - {%04x} - <%s>.\n", c, c, binString(c));
	getPause("Press the ENTER key to continue...");

	/* Bit deployment with a leftward shift. */
	a = V_0X0001;	//Value: +1.
	counter = V_ZERO;
	printf("\nLeft bit shift.\n");

	for (size_t idx = V_ZERO; idx < SIZE_BINARY(a); idx++)
	{
		printf("# (%2lu) - [%5u] - {%04x} - <%s>.\n", counter++, (unsigned int) a, (unsigned int) a, binString(a));
		a = (unsigned short) (a << V_ONE);
	}
	printf("[%lu] Output results generated.\n", counter);
	getPause("Press the ENTER key to continue...");

	/* Bit shift to the right. */
	a = V_0X8000;	//Value: 32768 == 2¹⁵.
	counter = V_ZERO;
	printf("\nRightward bit shift.\n");

	for (size_t idx = V_ZERO; idx < SIZE_BINARY(a); idx++)
	{
		printf("# (%2lu) - [%5u] - {%04x} - <%s>.\n", counter++, (unsigned int) a, (unsigned int) a, binString(a));
		a >>= V_ONE;
	}
	printf("[%lu] Output results generated.\n", counter);
	getPause("Press the ENTER key to continue...");

	/* Program termination messages. */
	printf("\nDone!\n");
	printf("This program has ended.\n");
	getPause("Press the ENTER key to continue...");

	return V_ZERO;
}
