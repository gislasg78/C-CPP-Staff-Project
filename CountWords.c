/* This program calculates the number of characters,
   lines, and words in a captured text from an input. */

/* Standard work libraries. */
#include <stdio.h>

/* Symbolic work constants. */
#define	CARRIAGE_RETURN	'\n'
#define	NORMAL_SPACE	'\x20'
#define	TABULATOR	'\t'

#define	V_ONE	1
#define	V_ZERO	0

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int character = V_ZERO;
		int number_characters = V_ZERO, number_lines = V_ZERO, number_words = V_ZERO;
		int inside_word = V_ZERO;

		/* Initial header messages. */
		printf("Character, line, and word counter.\n");
		printf("Enter the desired lines.\n");
		printf("Press Left [CTRL] + [D] to exit.\n");

		/* Main cycle of counting characters, lines, and words. */
		while ((character = getchar()) != EOF)
			{
				++number_characters;

				if (character == CARRIAGE_RETURN) ++number_lines;

				if ((character == CARRIAGE_RETURN) || (character == NORMAL_SPACE) || (character == TABULATOR))
					inside_word = V_ZERO;
				else if (inside_word == V_ZERO)
					{
						inside_word = V_ONE;
						number_words++;
					}
			}

		/* Printout of final results. */
		printf("\nOutcomes.\n");
		printf("+ Characters : [%d].\n", number_characters);
		printf("+ Lines      : [%d].\n", number_lines);
		printf("+ Words      : [%d].\n", number_words);

		return V_ZERO;
	}
