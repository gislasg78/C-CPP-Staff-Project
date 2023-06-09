/************************* Reflect a byte ************************
 ** Source Code:	Reflect.c				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Friday, June 09, 2023.			**
 ** Purpose:		Display an entered character and	**
 **			reflects it in such a way that it	**
 **			reverses the order of the bits		**
 **			(bit 0 becomes bit 7, bit 1 becomes	**
 **			bit 6, bit 2 becomes bit 5) and so on,	**
 **			successively.				**
*****************************************************************/
// C Standard Libraries.
#include <stdio.h>
#include <stdlib.h>

// Work Symbolic Constants.
#define v_ZERO		0
#define v_ONE		1
#define v_SEVEN		7
#define v_EIGHT		8
#define v_C_ZERO	48
#define v_C_ONE		49

// Macro ThrowBackChar reverses a character with bit offset.
#define	ThrowBackChar( c ) \
		((((c)&0x01) << 7) | (((c)&0x02) << 5) | \
		 (((c)&0x04) << 3) | (((c)&0x08) << 1) | \
		 (((c)&0x10) >> 1) | (((c)&0x20) >> 3) | \
		 (((c)&0x40) >> 5) | (((c)&0x80) >> 7))

/*****************************************************************
 ** Function:		ToBin.					**
 ** Explanation:	Reverses bit order of an entered	**
 **			character, such that bit 0 becomes bit 7**
 **			bit 1 becomes bit 6, bit 2 becomes bit 5**
 **			and so on.				**
 ** Input Parms:	unsigned char c.			**
 ** Output Parms:	None.					**
 ** Result:		Pointer to character with sequence of	**
 **			binary digits.				**
 ****************************************************************/
char *ToBin (unsigned char chr)
	{
		char *tbn = NULL;
		int	 idx = v_ZERO;
		int  ind = v_ZERO;

		if ( (tbn = (char *) malloc(v_EIGHT * sizeof(char)) ) != NULL)
			for (idx = v_SEVEN, ind = v_ZERO; \
			     idx >= v_ZERO && ind <= v_SEVEN; idx--, ind++)
				*(tbn+ind)=(chr & (v_ONE << idx))
			 		? v_C_ONE : v_C_ZERO;

		return (tbn);
	}

/*****************************************************************
 ** Function:		viewBin.				**
 ** Explanation:	Display on screen the ascii, hexadecimal**
 **			octal and binary values of a given	**
 **			character.				**
 ** Input Parms:	unsigned char c.			**
 ** Output Parms:	None.					**
 ** Result:		View an informative chain on the screen.**
*****************************************************************/
void viewBin(unsigned char chr)
	{
		printf("Char: [%c], Ascii: [%3.u], Hex: [%3.x], " \
			"Oct: [%3.o], Bin: [%s]. \n",
			chr, chr, chr, chr, ToBin(chr));
	}

/*****************************************************************
 ** Function:	main().						**
 ****************************************************************/
int main()
	{
		unsigned char ch_c = v_ZERO;

		printf("Enter a unique valid character: ");
		ch_c = getchar();

		printf("\nRegular Binary Value of [%d].\n", ch_c);
		printf("+-----------------------------------+\n");
		viewBin(ch_c);

		printf("\nTurned around binary outcome of [%d].\n", ch_c);
		printf("+-----------------------------------+\n");
		viewBin(ThrowBackChar(ch_c));

		return(ch_c);
	}
