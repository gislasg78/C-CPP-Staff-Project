/*
	Program that draws "I Love You" in text mode.
	Obtained from the URL with personal touches:
	https://www.youtube.com/shorts/jhqZIx71Y7g
*/

/* Standard Work Libraries. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Symbolic Work Constants. */
#define	ASTERISK	'\x2a'
#define	NORMAL_SPACE	'\x20'
#define	V_ZERO		0x00

//Main function.
int main()
	{
		/* Fixed missing semicolons in the for loops. */
		for (int jdx = 39; jdx >= -39; jdx--)
			{
				for (int idx = -35; idx <= 35; idx++)
					{
						/* Combined all separated mathematical conditions using logical OR (||). */
						/* Changed the float subtraction abs() to fabs() to prevent C type-conversion errors. */
						if	(
								((abs(jdx - 25) < 14) && (abs(idx) < 6)) ||
								((abs(jdx - 25) == 13) && (abs(idx) < 10)) ||
								(pow(abs(idx) - 9, 2) + 2 * pow(jdx, 2) <= 100) ||
								((9 * abs(idx) - 14 * jdx - 210 <= 0) && (jdx <= -3)) ||
								((pow(idx, 2) + 2 * pow(jdx + 30, 2) <= 225) && (pow(idx, 2) + 2 * pow(jdx + 30, 2) >= 64) && (jdx < -29)) ||
								((fabs(abs(idx) - 11.5) < 3.5) && (abs(jdx + 23) < 7))
							)
							{
								printf("%c", ASTERISK);
							}
						else
							{
								printf("%c", NORMAL_SPACE);
							}

					}

				/* Newline goes outside the inner loop but inside the outer loop */
				printf("\n");
			}

		return V_ZERO;
	}
