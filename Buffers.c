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
#define V_32768				32768
#define	V_ONE				1
#define	V_TWENTY			20
#define V_ZERO				0

//Main function.
int main()
	{
		/* Preliminary Working Variables. */
		int bc = V_ZERO, x = V_ZERO;
		char buffer[BUFSIZ];
		memset(buffer, V_ZERO, BUFSIZ);

		/* Seed the randomizer. */
		srand((unsigned int) time(NULL));

		/* Configure the buffer for unbuffered output. */
		setvbuf(stdout, buffer, _IONBF, BUFSIZ);

		/* Cycle to demonstrate the delay in writing to the output buffer. */
		printf("Output Buffer Write Test.\n");

		for (x = V_ZERO; x < V_TWENTY; x++)
			{
				printf("Writing: [%d] bytes...\r", bc);
				bc += GENERATE_RANDOM(rand(), V_ONE, V_32768);
				sleep(V_ONE);
			}

		putchar(CARRIAGE_RETURN);

		/* Program termination messages. */
		puts("\nDone!");
		puts("This program has ended.");

		return V_ZERO;
	}
