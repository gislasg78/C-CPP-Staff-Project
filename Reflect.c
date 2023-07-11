/************************* Reflect a byte ************************
 ** Source Code:	Reflect.c				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Monday, July 31, 2023.			**
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
 ** Function:		getpause.				**
 ** Explanation:	This function shows a specific message	**
 **			on the screen to indicate a given pause,**
 **			and returns the key that was pressed to	**
 **			continue with the execution of the	**
 **			program as a result.			**
 ** Input Parms:	const char *str_Message,		**
 ** Output Parms:	None.					**
 ** Result:		The function returns the character	**
 **			entered with the Enter key to have	**
 **			paused this program.			**
 ****************************************************************/
char getpause (const char *str_Message)
	{
		static char chr_Car=NULL_CHARACTER;

		printf("%s", str_Message);
		scanf("%*c%c", &chr_Car);

		return (chr_Car);
	}

/*****************************************************************
 ** Function:		binary.					**
 ** Explanation:	Reverses bit order of an entered	**
 **			character, such that bit 0 becomes bit 7**
 **			bit 1 becomes bit 6, bit 2 becomes bit 5**
 **			and so on.				**
 ** Input Parms:	unsigned char c.			**
 ** Output Parms:	None.					**
 ** Result:		Pointer to character with sequence of	**
 **			binary digits.				**
 ****************************************************************/
char *binary (unsigned char chr)
	{
		char *p_bn = NULL;
		int int_idx = V_ZERO;
		int int_ind = V_ZERO;

		if ( (p_bn = (char *) malloc(V_EIGHT * sizeof(char)) ) != NULL)
			for (int_idx = V_SEVEN, int_ind = V_ZERO;
			     int_idx >= V_ZERO && int_ind <= V_SEVEN;
			     int_idx--, int_ind++)
				*(p_bn+int_ind)=(chr & (V_ONE << int_idx))
			 		? V_C_ONE : V_C_ZERO;

		return (p_bn);
	}

/*****************************************************************
 ** Function:		viewbinary.				**
 ** Explanation:	Display on screen the ascii, hexadecimal**
 **			octal and binary values of a given	**
 **			character.				**
 ** Input Parms:	unsigned char c.			**
 ** Output Parms:	None.					**
 ** Result:		View an informative chain on the screen.**
*****************************************************************/
void viewbinary(unsigned char chr)
	{
		printf("| Char   : [%c].\n", chr);
		printf("| Ascii  : [%3.u].\n", chr);
		printf("| Hex    : [%3.x].\n", chr);
		printf("| Octal  : [%3.o].\n", chr);
		printf("| Binary : [%s].\n", binary(chr));
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
		unsigned char ch_c = V_ZERO;

		/*------------------------------------------------
		 * Mirror a given character by inverting its	--
		 * extreme half-bits.				--
		 *----------------------------------------------*/
		printf("\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Mirror a given character by inverting.|\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("Enter a unique valid character: ");
		ch_c = getchar();

		printf("\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|      Regular Binary Value of [%d].    |\n", ch_c);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		viewbinary(ch_c);

		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Turned around binary outcome of [%d]. |\n", ch_c);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		viewbinary(THROWBACKCHAR(ch_c));

		printf("+---|----+---|----+---|----+---|----+---|\n");

		getpause("\nEste programa ha terminado con éxito.\n"
		"Presione la tecla ENTRAR para finalizarlo...");

		return(ch_c);
	}
