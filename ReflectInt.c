/*********************** Reflect a integer. **********************
 ** Source Code:	ReflectInt.c				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Thursday, December 31, 2026.		**
 ** Purpose:		Display an entered integer and		**
 **			reflects it in such a way that it	**
 **			reverses the order of the bits		**
 **			(bit # 0 becomes bit # 31, bit # 1	**
 **			becomes	bit # 30, bit # 2 becomes	**
 **			bit # 29) and so on, successively.	**
*****************************************************************/
/* C Standard Libraries. */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* Work Symbolic Constants. */
#define V_CHAR_ZERO	'\x30'
#define V_CHAR_ONE	'\x31'
#define	V_OCTAL_ONE	01

/* Work Numeric Symbolic Constants. */
#define V_ONE		1
#define V_SEVEN		7
#define V_ZERO		0

/* Symbolic Character Constants. */
#define	CARRIAGE_RETURN	'\n'
#define NULL_CHARACTER	'\0'

/* Macro 'THROWBACKINT' reverses a 32-bit signed int */
#define THROWBACKINT(i)	( \
	(int)( \
	((((size_t)(i)) & 0x00000001u) << 31) | \
	((((size_t)(i)) & 0x00000002u) << 29) | \
	((((size_t)(i)) & 0x00000004u) << 27) | \
	((((size_t)(i)) & 0x00000008u) << 25) | \
	((((size_t)(i)) & 0x00000010u) << 23) | \
	((((size_t)(i)) & 0x00000020u) << 21) | \
	((((size_t)(i)) & 0x00000040u) << 19) | \
	((((size_t)(i)) & 0x00000080u) << 17) | \
	((((size_t)(i)) & 0x00000100u) << 15) | \
	((((size_t)(i)) & 0x00000200u) << 13) | \
	((((size_t)(i)) & 0x00000400u) << 11) | \
	((((size_t)(i)) & 0x00000800u) << 9)  | \
	((((size_t)(i)) & 0x00001000u) << 7)  | \
	((((size_t)(i)) & 0x00002000u) << 5)  | \
	((((size_t)(i)) & 0x00004000u) << 3)  | \
	((((size_t)(i)) & 0x00008000u) << 1)  | \
	((((size_t)(i)) & 0x00010000u) >> 1)  | \
	((((size_t)(i)) & 0x00020000u) >> 3)  | \
	((((size_t)(i)) & 0x00040000u) >> 5)  | \
	((((size_t)(i)) & 0x00080000u) >> 7)  | \
	((((size_t)(i)) & 0x00100000u) >> 9)  | \
	((((size_t)(i)) & 0x00200000u) >> 11) | \
	((((size_t)(i)) & 0x00400000u) >> 13) | \
	((((size_t)(i)) & 0x00800000u) >> 15) | \
	((((size_t)(i)) & 0x01000000u) >> 17) | \
	((((size_t)(i)) & 0x02000000u) >> 19) | \
	((((size_t)(i)) & 0x04000000u) >> 21) | \
	((((size_t)(i)) & 0x08000000u) >> 23) | \
	((((size_t)(i)) & 0x10000000u) >> 25) | \
	((((size_t)(i)) & 0x20000000u) >> 27) | \
	((((size_t)(i)) & 0x40000000u) >> 29) | \
	((((size_t)(i)) & 0x80000000u) >> 31)   \
	) \
)

/*****************************************************************
 ** Function:		size_t bit_counter_on			**
 **				(const int int_value).		**
 ** Explanation:	Counts the bits that have a given value	**
 **			set to one.				**
 ** Input Parms:	const int int_value.			**
 ** Output Parms:	None.					**
 ** Result:		bitcount: count 1 bits in 'x'.		**
 ****************************************************************/
size_t bit_counter_on(const int int_value)
	{
		/* Preliminary working variables. */
		size_t b = V_ZERO;
		unsigned int x = (unsigned int) int_value;

		/* Bit counting cycle. */
		for (b = V_ZERO; x > V_ZERO; x >>= V_ONE)
			if (x & V_OCTAL_ONE) b++;

		/* Return of key value. */
		return b;
	}

/*****************************************************************
 ** Function:		size_t get_bits(			**
 **				const int int_value,		**
 **				const size_t szt_position,	**
 **				const size_t szt_quantity_bits).**
 ** Explanation:	Returns the value corresponding to the	**
 **			requested 'bits' of the received value.	**
 ** Input Parms:	const int int_value,			**
 **			const char szt_position,		**
 **			const char szt_quantity_bits.		**
 ** Output Parms:	None.					**
 ** Result:		getbits: get 'n' bits from position 'p'.**
 ****************************************************************/
size_t get_bits(const int int_value, const size_t szt_position, const size_t szt_quantity_bits)
	{
		/* Preliminary working variables. */
		size_t mask = V_ZERO;
		size_t shift = V_ZERO;
		size_t x = (size_t) int_value;

		/* Handle error or avoid negative shift. */
		if (szt_quantity_bits)
			if (szt_quantity_bits <= sizeof(int) * CHAR_BIT)
				if ((szt_position + V_ONE) >= szt_quantity_bits)
					{
						shift = szt_position + V_ONE - szt_quantity_bits;
						mask = ((size_t) V_ONE << szt_quantity_bits) - V_ONE;
					}
				else
					fprintf(stderr, "\nError! A change can occur with a negative number.\n");
			else
				fprintf(stderr, "\nMistake! The number of bits manipulated is greater than the total.\n");
		else
			fprintf(stderr, "\nWrong! At least one bit must be reported to be extracted.\n");

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
 **				(const int int_value,		**
 **				  char **p_to_binary,		**
 **				  size_t *p_count_to_p_binary).	**
 ** Explanation:	Reverses bit order of an entered	**
 **			integer, such that bit 0 becomes bit 7	**
 **			bit 1 becomes bit 6, bit 2 becomes bit 5**
 **			and so on.				**
 ** Input Parms:	const int int_value,			**
 **			char **p_to_binary.			**
 ** Output Parms:	char **p_to_binary,			**
 **			size_t *p_count_to_p_binary.		**
 ** Result:		Pointer to character with sequence of	**
 **			binary digits.				**
 ****************************************************************/
char *to_binary(const int int_value, char **p_to_binary, size_t *p_count_to_p_binary)
	{
		/* Preliminary working variables. */
		char *p_binary = NULL;
		int idx = V_ZERO, ind = V_ZERO;

		/* Initial declaration of work variables. */
		int int_size_type = (int) ((sizeof(int) * CHAR_BIT) - V_ONE);
		size_t szt_size_of_type = (sizeof(int) * CHAR_BIT) + V_ONE;

		/* Assignment of the memory pointer and filling with the corresponding converted bits. */
		*p_count_to_p_binary = V_ZERO;

		/* First, verify if the dynamic character pointer can be created with the binary number. */
		if ((p_binary = (char *) calloc(szt_size_of_type, sizeof(char))))
			{
				for (idx = int_size_type, ind = V_ZERO; idx >= V_ZERO && ind <= int_size_type; idx--, ind++, (*p_count_to_p_binary)++)
					*(p_binary + ind) = ((size_t) int_value & ((size_t) V_ONE << idx)) ? V_CHAR_ONE : V_CHAR_ZERO;

				p_binary[ind] = NULL_CHARACTER;
			}
		else
			perror("Insufficient memory space to hold the binary string of characters.");

		/* Return of function values. */
		if (p_to_binary) *p_to_binary = p_binary;
		return p_binary;
	}

/*****************************************************************
 ** Function:		void view_outcomes(			**
 **				const char *str_Message,	**
 **				const int int_value,		**
 **				const char *p_to_binary,	**
 **				const size_t count_to_p_binary,	**
 **				const size_t bit_counter,	**
 **				const size_t count_bits).	**
 ** Explanation:	Display on screen the ascii,		**
 **			hexadecimal, octal and binary values	**
 **			of a given character.			**
 ** Input Parms:	const char *str_Message,		**
 **			const int int_value,			**
 **			const char *p_to_binary,		**
 **			const size_t count_to_p_binary,		**
 **			const size_t bit_counter,		**
 **			const size_t count_bits.		**
 ** Output Parms:	None.					**
 ** Result:		View an informative chain on the screen.**
*****************************************************************/
void view_outcomes(const char *str_Message, const int int_value, const char *p_to_binary, const size_t count_to_p_binary, const size_t bit_counter, const size_t count_bits)
	{
		printf("\n%s\n", str_Message);
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("+     Information data segments.    +\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("| > Pointer:\t[%p].\n", (void *) (p_to_binary));
		printf("| > Value:\t[%c].\n", *p_to_binary);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| + Decimal:\t[%d].\n", int_value);
		printf("| + Hexa:\t[%x].\n", int_value);
		printf("| + Octal:\t[%o].\n", int_value);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| - Inversed:\t[%d].\n", !int_value);
		printf("| - Reversed:\t[%d].\n", ~int_value);
		printf("| - Unsigned:\t[%u].\n", int_value);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| * Binary:\t{%s}.\n", p_to_binary);
		printf("| * Length:\t[%ld].\n", count_to_p_binary);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| < Bits on:\t[%ld].\n", bit_counter);
		printf("| < Bits cnt:\t[%ld].\n", count_bits);
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
		char *p_to_binary_value = NULL;
		char *p_to_binary_value_reflected = NULL;

		/* Calculation incidence pointers. */
		int int_key = V_ZERO;
		int int_value = NULL_CHARACTER;
		int int_value_reflected = NULL_CHARACTER;

		/* Initial declaration of work variables. */
		size_t bit_counter_value = V_ZERO;
		size_t bit_counter_value_reflected = V_ZERO;
		size_t count_bits_value = V_ZERO;
		size_t count_bits_value_reflected = V_ZERO;
		size_t count_to_p_binary_value = V_ZERO;
		size_t count_to_p_binary_value_reflected = V_ZERO;

		/*------------------------------------------------
		 * Mirror a given character by inverting its	--
		 * extreme half-bits.				--
		 *----------------------------------------------*/
		printf("+===|====+===|====+===|====+===|====+====+\n");
		printf("+  Mirror a given integer by inverting.  +\n");
		printf("+===|====+===|====+===|====+===|====+====+\n");
		printf("Enter a unique valid integer: ");
		scanf("%d%*c", &int_value);

		/* View conversion results. */
		if ((p_to_binary_value = to_binary(int_value, &p_to_binary_value, &count_to_p_binary_value)))
			{
				/* Obtaining the binary information of a pressed character. */
				bit_counter_value = bit_counter_on(int_value);
				count_bits_value = get_bits(int_value, (sizeof(int) * CHAR_BIT) - V_ONE, sizeof(int) * CHAR_BIT);
				view_outcomes("Regular Binary Value.", int_value, p_to_binary_value, count_to_p_binary_value, bit_counter_value, count_bits_value);

				/* View results and free up memory. */
				int_key = get_response("Press ENTER key to continue...", &int_key);
				free(p_to_binary_value);
			}
		else
			fprintf(stderr, "\nInsufficient memory space to hold the binary string of characters.\n");

		/* View conversion results with reversed character. */
		int_key = V_ZERO;
		int_value_reflected = THROWBACKINT(int_value);

		if ((p_to_binary_value_reflected = to_binary(int_value_reflected, &p_to_binary_value_reflected, &count_to_p_binary_value_reflected)))
			{
				/* Obtaining the binary information of a pressed character. */
				bit_counter_value_reflected = bit_counter_on(int_value_reflected);
				count_bits_value_reflected = get_bits(int_value_reflected, (sizeof(int) * CHAR_BIT) - V_ONE, sizeof(int) * CHAR_BIT);
				view_outcomes("Turned around binary outcome.", int_value_reflected, p_to_binary_value_reflected, count_to_p_binary_value_reflected, bit_counter_value_reflected, count_bits_value_reflected);

				/* View results and free up memory. */
				int_key = get_response("Press ENTER key to continue...", &int_key);
				free(p_to_binary_value_reflected);
			}
		else
			fprintf(stderr, "\nInsufficient memory space to hold the binary string of characters.\n");

		return V_ZERO;
	}
