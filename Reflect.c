/************************* Reflect a byte ************************
 ** Source Code:	Reflect.c				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, December 30, 2023.		**
 ** Purpose:		Display an entered character and	**
 **			reflects it in such a way that it	**
 **			reverses the order of the bits		**
 **			(bit #0 becomes bit #7, bit #1 becomes	**
 **			bit #6, bit #2 becomes bit #5) and	**
 **			so on, successively.			**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>
#include <stdlib.h>

//Work Symbolic Constants.
#define V_ZERO		0
#define V_ONE		1
#define V_SEVEN		7
#define V_EIGHT		8
#define V_C_ZERO	'0'
#define V_C_ONE		'1'

//Symbolic Character Constants.
#define NULL_CHARACTER	'\0'

//Macro 'ThrowBackChar' reverses a character with bit offset.
#define	THROWBACKCHAR( c ) \
		((((c)&0x01) << 7) | (((c)&0x02) << 5) | \
		 (((c)&0x04) << 3) | (((c)&0x08) << 1) | \
		 (((c)&0x10) >> 1) | (((c)&0x20) >> 3) | \
		 (((c)&0x40) >> 5) | (((c)&0x80) >> 7))

/*****************************************************************
 ** Function:		static char *ptr_chr_strbinary		**
 **				(const unsigned char chr_chr).	**
 ** Explanation:	Reverses bit order of an entered	**
 **			character, such that bit 0 becomes bit 7**
 **			bit 1 becomes bit 6, bit 2 becomes bit 5**
 **			and so on.				**
 ** Input Parms:	const unsigned char chr_chr.		**
 ** Output Parms:	None.					**
 ** Result:		Pointer to character with sequence of	**
 **			binary digits.				**
 ****************************************************************/
static char *ptr_chr_strbinary (const unsigned char chr_chr)
	{
		char *ptr_chr_str_binary = NULL;

		if ( (ptr_chr_str_binary = (char *) malloc(V_EIGHT * sizeof(char))) != NULL)
			for (size_t szt_idx = V_SEVEN, szt_ind = V_ZERO;
				szt_idx >= V_ZERO && szt_ind <= V_SEVEN;
				szt_idx--, szt_ind++)
					*(ptr_chr_str_binary + szt_ind) = (chr_chr & (V_ONE << szt_idx))
					? V_C_ONE : V_C_ZERO;

		return (ptr_chr_str_binary);
	}

/*****************************************************************
 ** Function:		void viewbinary				**
 **				(const unsigned char chr_chr).	**
 ** Explanation:	Display on screen the ascii, hexadecimal**
 **			octal and binary values of a given	**
 **			character.				**
 ** Input Parms:	const unsigned char chr_chr.		**
 ** Output Parms:	None.					**
 ** Result:		View an informative chain on the screen.**
*****************************************************************/
void viewbinary(const unsigned char chr_chr)
	{
		printf("| Char   : [%c].\n", chr_chr);
		printf("| Ascii  : [%3.u].\n", chr_chr);
		printf("| Hex    : [%3.x].\n", chr_chr);
		printf("| Octal  : [%3.o].\n", chr_chr);
		printf("| Binary : [%s].\n", ptr_chr_strbinary(chr_chr));
		printf("+---|----+---|----+---|----+---|----+\n");
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
		unsigned char chr_chr = NULL_CHARACTER;

		/*------------------------------------------------
		 * Mirror a given character by inverting its	--
		 * extreme half-bits.				--
		 *----------------------------------------------*/
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+     Mirror a given character.     +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Enter a unique valid character: ");
		chr_chr = getchar();

		printf("\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+    Regular Binary Value of [%d].  +\n", chr_chr);
		printf("+---|----+---|----+---|----+---|----+\n");
		viewbinary(chr_chr);

		printf("\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+Turned around binary outcome: [%d].+\n", chr_chr);
		printf("+---|----+---|----+---|----+---|----+\n");
		viewbinary(THROWBACKCHAR(chr_chr));

		return V_ZERO;
	}
