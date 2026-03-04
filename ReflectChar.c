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
 ** Function:		size_t bit_counter_on			**
 **				(const char char_value).	**
 ** Explanation:	Counts the bits that have a given value	**
 **			set to one.				**
 ** Input Parms:	const char char_value.			**
 ** Output Parms:	None.					**
 ** Result:		bitcount: count 1 bits in 'x'.		**
 ****************************************************************/
size_t bit_counter_on(const char char_value)
	{
		/* Preliminary working variables. */
		size_t b = V_ZERO;
		unsigned char x = (unsigned char) char_value;

		/* Bit counting cycle. */
		for (b = V_ZERO; x > V_ZERO; x >>= V_ONE)
			if (x & V_OCTAL_ONE) b++;

		/* Return of key value. */
		return b;
	}

/*****************************************************************
 ** Function:		size_t get_bits(			**
 **				const char char_value,		**
 **				const size_t szt_position,	**
 **				const size_t szt_quantity_bits).**
 ** Explanation:	Returns the value corresponding to the	**
 **			requested 'bits' of the received value.	**
 ** Input Parms:	const char char_value,			**
 **			const char szt_position,		**
 **			const char szt_quantity_bits.		**
 ** Output Parms:	None.					**
 ** Result:		getbits: get 'n' bits from position 'p'.**
 ****************************************************************/
size_t get_bits(const char char_value, const size_t szt_position, const size_t szt_quantity_bits)
	{
		/* Preliminary working variables. */
		size_t mask = V_ZERO;
		size_t shift = V_ZERO;
		size_t x = (size_t) char_value;

		/* Handle error or avoid negative shift. */
		if (szt_quantity_bits)
			if (szt_quantity_bits <= sizeof(char) * V_EIGHT)
				if (szt_position + V_ONE >= szt_quantity_bits)
					{
						shift = szt_position + V_ONE - szt_quantity_bits;
						mask = ((size_t) V_ONE << szt_quantity_bits) - V_ONE;
					}
				else
					fprintf(stderr, "\nError! A change can occur with a negative number.\n");
			else
				fprintf(stderr, "\nThe number of bits manipulated is greater than the total.\n");
		else
			fprintf(stderr, "\nAt least one bit must be reported to be extracted.\n");

		/* Return of key value. */
		return (x >> shift) & mask;
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

		/* Header message. */
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
				fprintf(stderr, "\nThe value entered is not valid.\n");

				scanf("%*[^\n]%*c");
				while ((int_key = getchar()) != CARRIAGE_RETURN && int_key != EOF);
			}

		/* Return of key values. */
		if (p_int_key_pressed) *p_int_key_pressed = int_key;
		return int_key;
	}

/*****************************************************************
 ** Function:		char *to_binary				**
 **				(const char char_value,		**
 **				  char **p_to_binary,		**
 **				  size_t *p_count_to_binary).	**
 ** Explanation:	Reverses bit order of an entered	**
 **			character, such that bit 0 becomes bit 7**
 **			bit 1 becomes bit 6, bit 2 becomes bit 5**
 **			and so on.				**
 ** Input Parms:	const int char_value,			**
 **			char **p_to_binary.			**
 ** Output Parms:	char **p_to_binary,			**
 **			size_t *p_count_to_binary.		**
 **			size_t *p_count_to_binary.		**
 ** Result:		Pointer to character with sequence of	**
 **			binary digits.				**
 ****************************************************************/
char *to_binary(const char char_value, char **p_to_binary, size_t *p_count_to_binary)
	{
		/* Preliminary working variables. */
		char *p_binary = NULL;
		int idx = V_ZERO, ind = V_ZERO;

		/* Initial declaration of work variables. */
		int int_size_type = (int) ((sizeof(char) * V_EIGHT) - V_ONE);
		size_t szt_size_of_type = (sizeof(char) * V_EIGHT) + V_ONE;

		/* Assignment of the memory pointer and filling with the corresponding converted bits. */
		*p_count_to_binary = V_ZERO;

		if ((p_binary = (char *) calloc(szt_size_of_type, sizeof(char))))
			{
				for (idx = int_size_type, ind = V_ZERO; idx >= V_ZERO && ind <= int_size_type; idx--, ind++, (*p_count_to_binary)++)
					*(p_binary + ind) = (char_value & (V_ONE << idx)) ? V_CHAR_ONE : V_CHAR_ZERO;

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
 **				(const char *str_Message,	**
 **				 const char char_value,		**
 **				 const char *p_to_binary,	**
 **				 const size_t count_to_binary,	**
 **				 const size_t bit_counter,	**
 **				 const size_t count_bits).	**
 ** Explanation:	Display on screen the ascii,		**
 **			hexadecimal, octal and binary values	**
 **			of a given character.			**
 ** Input Parms:	const char *str_Message,		**
 **			const char char_value,			**
 **			const char *p_to_binary,		**
 **			const size_t count_to_binary,		**
 **			const size_t bit_counter,		**
 **			const size_t count_bits.		**
 ** Output Parms:	None.					**
 ** Result:		View an informative chain on the screen.**
*****************************************************************/
void view_outcomes(const char *str_Message, const char char_value, const char *p_to_binary, const size_t count_to_binary, const size_t bit_counter, const size_t count_bits)
	{
		printf("\n%s\n", str_Message);
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("+     Information data segments.    +\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("| > Pointer:\t[%p].\n", (void *) (p_to_binary));
		printf("| > Value:\t[%c].\n", *p_to_binary);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| + Char:\t[%c].\n", char_value);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| - Ascii:\t[%u].\n", char_value);
		printf("| - Decimal:\t[%d].\n", char_value);
		printf("| - Hexa:\t[%x].\n", char_value);
		printf("| - Octal:\t[%o].\n", char_value);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| * Binary:\t{%s}.\n", p_to_binary);
		printf("| * Length:\t[%ld].\n", count_to_binary);
		printf("| * Count:\t[%ld].\n", count_bits);
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
		/* Preliminary working variables. */
		char char_value = NULL_CHARACTER;
		char char_value_reflected = NULL_CHARACTER;

		/* Calculation incidence pointers. */
		char *p_to_binary_value = NULL;
		char *p_to_binary_value_reflected = NULL;

		/* Initial declaration of work variables. */
		int int_key = V_ZERO;
		size_t bit_counter_value = V_ZERO;
		size_t bit_counter_value_reflected = V_ZERO;
		size_t count_bits_value = V_ZERO;
		size_t count_bits_value_reflected = V_ZERO;
		size_t count_to_binary_value = V_ZERO;
		size_t count_to_binary_value_reflected = V_ZERO;

		/*------------------------------------------------
		 * Mirror a given character by inverting its	--
		 * extreme half-bits.				--
		 *----------------------------------------------*/
		printf("+===|====+===|====+===|====+===|====+====+\n");
		printf("+ Mirror a given character by inverting. +\n");
		printf("+===|====+===|====+===|====+===|====+====+\n");
		printf("Enter a unique valid character: ");
		scanf("%c%*c", &char_value);

		/* View conversion results. */
		if ((p_to_binary_value = to_binary(char_value, &p_to_binary_value, &count_to_binary_value)))
			{
				/* Obtaining the binary information of a pressed character. */
				bit_counter_value = bit_counter_on(char_value);
				count_bits_value = get_bits(char_value, V_SEVEN, V_EIGHT);
				view_outcomes("Regular Binary Value.", char_value, p_to_binary_value, count_to_binary_value, bit_counter_value, count_bits_value);

				/* View results and free up memory. */
				int_key = get_response("Press ENTER key to continue...", &int_key);
				free(p_to_binary_value);
			}
		else
			fprintf(stderr, "\nInsufficient memory space to hold the binary string of characters.\n");

		/* View conversion results with reversed character. */
		char_value_reflected = (char) THROWBACKCHAR(char_value);
		int_key = V_ZERO;

		if ((p_to_binary_value_reflected = to_binary(char_value_reflected, &p_to_binary_value_reflected, &count_to_binary_value_reflected)))
			{
				/* Obtaining the binary information of a pressed character. */
				bit_counter_value_reflected = bit_counter_on(char_value_reflected);
				count_bits_value_reflected = get_bits(char_value_reflected, V_SEVEN, V_EIGHT);
				view_outcomes("Turned around binary outcome.", char_value_reflected, p_to_binary_value_reflected, count_to_binary_value_reflected, bit_counter_value_reflected, count_bits_value_reflected);

				/* View results and free up memory. */
				int_key = get_response("Press ENTER key to continue...", &int_key);
				free(p_to_binary_value_reflected);
			}
		else
			fprintf(stderr, "\nInsufficient memory space to hold the binary string of characters.\n");

		return V_ZERO;
	}
