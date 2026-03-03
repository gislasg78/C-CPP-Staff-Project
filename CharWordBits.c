/* This program exemplifies the encoding
   of a character value into an integer value. */

/* Standard work libraries. */
#include <stdio.h>
#include <string.h>

/* Symbolic work constants. */
#define	HIGH_VALUE	0xff

#define	V_EIGHT		8
#define	V_ONE		1
#define	V_TWO		2
#define	V_ZERO		0

//Main function.
int main()
	{
		/* Preliminary working variables. */
		char s[] = "Hello world";
		int *si = (int *) &s;
		int mask = V_ZERO, masked = V_ZERO, ch = V_ZERO;

		printf(" l l e H  o W - o 00 d l r\n");
		printf("%08x %08x %08x\n", si[V_ZERO], si[V_ONE], si[V_TWO]);

		/* Unmasking character-to-integer encoding. */
		mask = HIGH_VALUE << V_EIGHT;
		masked = si[V_ZERO] & mask;
		ch = masked >> V_EIGHT;

		printf("%08x\n", mask);
		printf("%08x\n", masked);
		printf("%08x %c\n", ch, ch);

		return V_ZERO;
	}
