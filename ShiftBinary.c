/* This program converts a 2-byte (16-bit) short integer into a character string
   representing its binary form, and shifts each bit both to the left
   (equivalent to multiplication by powers of 2)
   and to the right (equivalent to division by powers of 2).
*/

/* Standard Work Libraries. */
#include <limits.h>
#include <stdio.h>

/* Symbolic Character Constants. */
#define	V_CHAR_DIGIT_ZERO	'\x30'
#define	V_CHAR_DIGIT_ONE	'\x31'
#define	NULL_CHARACTER		'\0'

/* Program Startup Values. */
#define	V_INITIAL_VALUE		0x0001
#define	V_8000_HEX		0x8000	//Value: 32768 == 2^15.
#define	V_FFFF_HEXA		0xFFFFu	//Value: 65535 == 2^16.

/* Numeric Symbolic Constants. */
#define V_ONE			1u
#define V_SEVENTEEN		17
#define	V_SIXTEEN		16
#define	V_ZERO			0

/* Ensure that unsigned short has exactly 16 value bits. */
_Static_assert(USHRT_MAX == V_FFFF_HEXA, "This program requires a 16-bit unsigned short int.");

/* A function that converts a 16-bit short integer into a string of zeros and ones. */
char *binString(unsigned short number)
{
	/* Preliminary Working Variables. */
	static char bin[V_SEVENTEEN];

	/* Construction of the binary character string, character by character. */
	for (int x = V_ZERO; x < V_SIXTEEN; x++)
	{
		bin[x] = number & V_8000_HEX ? V_CHAR_DIGIT_ONE : V_CHAR_DIGIT_ZERO;
		number = (unsigned short) (number << V_ONE);
	}

	/* Terminate the string with the end-of-string character (null character). */
	bin[V_SIXTEEN] = NULL_CHARACTER;

	return (bin);
}

//Main function.
int main()
{
	/* Preliminary Working Variables. */
	unsigned short a = V_INITIAL_VALUE;

	/* Initial Header Message. */
	printf("Example Exercise Involving Bit Swaps.\n");

	/* Bit deployment with a leftward shift. */
	printf("\nLeft bit shift.\n");
	for (int x = V_ZERO; x < V_SIXTEEN; x++)
	{
		printf("# (%2d) - [%5u] - {%04x} - <%s>.\n", x, (unsigned int) a, (unsigned int) a, binString(a));
		a = (unsigned short) (a << V_ONE);
	}

	a = V_8000_HEX;	//Value: 32768 == 2^15.

	/* Bit shift to the right. */
	printf("\nRightward bit shift.\n");
	for (int x = V_ZERO; x < V_SIXTEEN; x++)
	{
		printf("# (%2d) - [%5u] - {%04x} - <%s>.\n", x, (unsigned int) a, (unsigned int) a, binString(a));
		a >>= V_ONE;
	}

	/* Program termination messages. */
	printf("\nDone!\n");
	printf("This program has ended.\n");

	return V_ZERO;
}
