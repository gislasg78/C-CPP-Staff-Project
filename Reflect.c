/************************* Reflect a byte ************************
 ** Source Code:	Reflect.c				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Wednesday, December 31, 2025.		**
 ** Purpose:		Display an entered character and	**
 **			reflects it in such a way that it	**
 **			reverses the order of the bits		**
 **			(bit #0 becomes bit #7, bit #1 becomes	**
 **			bit #6, bit #2 becomes bit #5) and	**
 **			so on, successively.			**
*****************************************************************/
/* C Standard Libraries. */
#include <stdio.h>
#include <stdlib.h>

/* Work Symbolic Constants. */
#define V_CHAR_ZERO	'\x30'
#define V_CHAR_ONE	'\x31'
#define	V_OCTAL_ONE	01

#define	V_EIGHT		8
#define V_ONE		1
#define V_SEVEN		7
#define V_ZERO		0

/* Symbolic Character Constants. */
#define	CARRIAGE_RETURN	'\n'
#define NULL_CHARACTER	'\0'

/* Macro 'ThrowBackChar' reverses a character with bit offset. */
#define	THROWBACKCHAR(c)	((((c)&0x01) << 7) | (((c)&0x02) << 5)	| \
				(((c)&0x04) << 3)  | (((c)&0x08) << 1)	| \
				(((c)&0x10) >> 1)  | (((c)&0x20) >> 3)	| \
				(((c)&0x40) >> 5)  | (((c)&0x80) >> 7))

/*****************************************************************
 ** Function:		size_t bit_counter_on (char x).		**
 ** Explanation:	Counts the bits that have a given value	**
 **			set to one.				**
 ** Input Parms:	char x.					**
 ** Output Parms:	None.					**
 ** Result:		bitcount: count 1 bits in 'x'.		**
 ****************************************************************/
size_t bit_counter_on(char x)
	{
		/* Preliminary working variables. */
		size_t b = V_ZERO;

		/* Bit counting cycle. */
		for (b = V_ZERO; x > V_ZERO; x >>= V_ONE)
			if (x & V_OCTAL_ONE) b++;

		return b;
	}

/*****************************************************************
 ** Function:		int get_response			**
 **				(const char *str_Message,	**
 **				       int *p_int_key_pressed).	**
 ** Explanation:	To pause with a specific message.	**
 ** Input Parms:	const char *str_Message.		**
 ** Output Parms:	int *p_int_key_pressed.			**
 ** Result:		Returns the successfully pressed key.	**
 ****************************************************************/
int get_response(const char *str_Message, int *p_int_key_pressed)
	{
		/* Preliminary working variables. */
		char chr_key = V_ZERO;
		int int_key = NULL_CHARACTER;

		printf("%s", str_Message);

		/* Validate data entry as correct. */
		if (scanf("%c%*c", &chr_key) == V_ONE)
			{
				/* Get a correct character value. */
				printf("\nInput value: [%x] : [%d] = [%c]. OK!\n", chr_key, chr_key, chr_key);
				int_key = (int) chr_key;
			}
		else
			{
				/* Get an incorrect character value. */
				printf("\nThe value entered is not valid.\n");

				scanf("%*[^\n]%*c");
				while ((int_key = getchar()) != CARRIAGE_RETURN && int_key != EOF);
			}

		if (p_int_key_pressed) *p_int_key_pressed = int_key;
		return int_key;
	}

/*****************************************************************
 ** Function:		char *to_binary				**
 **				(const char char_char,		**
 **				       char **p_to_binary).	**
 ** Explanation:	Reverses bit order of an entered	**
 **			character, such that bit 0 becomes bit 7**
 **			bit 1 becomes bit 6, bit 2 becomes bit 5**
 **			and so on.				**
 ** Input Parms:	const char char_char,			**
 **			char **p_to_binary.			**
 ** Output Parms:	char **p_to_binary.			**
 ** Result:		Pointer to character with sequence of	**
 **			binary digits.				**
 ****************************************************************/
char *to_binary(const char char_char, char **p_to_binary)
	{
		/* Preliminary working variables. */
		char *p_binary = NULL;
		int idx = V_ZERO, ind = V_ZERO;
		size_t size_type = (sizeof(char) * V_EIGHT) + V_ONE;
		int up_size_type = (int) ((sizeof(char) * V_EIGHT) - V_ONE);

		/* Assignment of the memory pointer and filling with the corresponding converted bits. */
		if ((p_binary = (char *) calloc(size_type, sizeof(char))))
			{
				for (idx = up_size_type, ind = V_ZERO; idx >= V_ZERO && ind <= up_size_type; idx--, ind++)
					*(p_binary + ind) = (char_char & (V_ONE << idx)) ? V_CHAR_ONE : V_CHAR_ZERO;

				p_binary[ind] = NULL_CHARACTER;
			}
		else
			perror("Insufficient memory space to hold the binary string of characters.");

		/* Return of function values. */
		if (p_to_binary) *p_to_binary = p_binary;
		return p_binary;
	}

/*****************************************************************
 ** Function:		void view_outcomes			**
 **				(const char char_char,		**
 **				 const char *p_to_binary,	**
 **				 const size_t bit_counter).	**
 ** Explanation:	Display on screen the ascii, hexadecimal**
 **			octal and binary values of a given	**
 **			character.				**
 ** Input Parms:	const char char_char,			**
 **			const char *p_to_binary,		**
 **			const size_t bit_counter.		**
 ** Output Parms:	None.					**
 ** Result:		View an informative chain on the screen.**
*****************************************************************/
void view_outcomes(const char char_char, const char *p_to_binary, const size_t bit_counter)
	{
		printf("\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("+     Information data segments.    +\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("| > Pointer:\t[%p].\n", (void *) (p_to_binary));
		printf("| > Value:\t[%c].\n", *p_to_binary);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| + Char:\t[%c].\n", char_char);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| - Ascii:\t[%u].\n", char_char);
		printf("| - Decimal:\t[%d].\n", char_char);
		printf("| - Hexa:\t[%x].\n", char_char);
		printf("| - Octal:\t[%o].\n", char_char);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| * Binary:\t{%s}.\n", p_to_binary);
		printf("| * Bits on:\t[%ld].\n", bit_counter);
		printf("+===|====+===|====+===|====+===|====+\n");
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	This program obtains a character from	**
 **			the keyboard and converts it to binary	**
 **			digits, with the purpose of inverting	**
 **			its bits, in such a way that the ends of**
 **			the character are interchanged with each**
 **			other.					**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		When obtaining any character entered by	**
 **			the keyboard, what is done is that the	**
 **			extreme bits are exchanged with each	**
 **			other, in such a way that bit #7 goes to**
 **			the place of bit #0, bit #0 goes to the	**
 **			place of bit #7, bit #6 moves to bit #1,**
 **			bit #1 moves to bit #6, and so on until **
 **			the first four bits of the bit are in	**
 **			the remaining four bits of the byte and **
 **			vice versa.				**
*****************************************************************/
int main()
	{
		/* Initial declaration of work variables. */
		char char_char = NULL_CHARACTER;
		char char_reflected = NULL_CHARACTER;

		/* Preliminary working variables. */
		char *p_to_binary_char = NULL;
		char *p_to_binary_char_reflected = NULL;

		/* Calculation incidence pointers. */
		int int_key = V_ZERO;
		size_t bit_counter_char = V_ZERO;
		size_t bit_counter_char_reflected = V_ZERO;

		/*------------------------------------------------
		 * Mirror a given character by inverting its	--
		 * extreme half-bits.				--
		 *----------------------------------------------*/
		printf("+===|====+===|====+===|====+===|====+====+\n");
		printf("+ Mirror a given character by inverting. +\n");
		printf("+===|====+===|====+===|====+===|====+====+\n");
		printf("Enter a unique valid character: ");
		scanf("%c%*c", &char_char);

		/* View conversion results. */
		if ((p_to_binary_char = to_binary(char_char, &p_to_binary_char)))
			{
				/* Obtaining the binary information of a pressed character. */
				printf("\n");
				printf("+---|----+---|----+---|----+---|----+----+\n");
				printf("| Regular Binary Value of [%c] is [%d].\n", char_char, char_char);
				printf("+---|----+---|----+---|----+---|----+----+\n");

				/* View results and free up memory. */
				bit_counter_char = bit_counter_on(char_char);
				view_outcomes(char_char, p_to_binary_char, bit_counter_char);

				int_key = get_response("Press ENTER key to continue...", &int_key);
				free(p_to_binary_char);
			}
		else
			fprintf(stderr, "Insufficient memory space to hold the binary string of characters.");

		/* View conversion results with reversed character. */
		char_reflected = (char) THROWBACKCHAR((int) char_char);
		if ((p_to_binary_char_reflected = to_binary(char_reflected, &p_to_binary_char_reflected)))
			{
				/* Obtaining the binary information of a pressed character. */
				printf("\n");
				printf("+---|----+---|----+---|----+---|----+----+\n");
				printf("| Turned around binary outcome of [%c] is [%d].\n", char_reflected, char_reflected);
				printf("+---|----+---|----+---|----+---|----+----+\n");

				/* View results and free up memory. */
				bit_counter_char_reflected = bit_counter_on(char_reflected);
				view_outcomes(char_reflected, p_to_binary_char_reflected, bit_counter_char_reflected);

				int_key = get_response("Press ENTER key to continue...", &int_key);
				free(p_to_binary_char_reflected);
			}
		else
			fprintf(stderr, "Insufficient memory space to hold the binary string of characters.");

		return V_ZERO;
	}
