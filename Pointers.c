/****************** Use of pointers of pointers. *****************
 ** Source Code:	Pointers.c				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Friday, June 30, 2023.          	**
 ** Purpose:		This program makes examples of pointers	**
 **			pointing to other pointers with the	**
 **			address of a static integer variable	**
 **			that is assigned a memory address at	**
 **			compile time.				**
*****************************************************************/
// C Standard Libraries.
#include <stdio.h>

//Numeric Symbolic Constants.
#define V_ZERO				0

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	Main module in which the objectives of	**
 **			this program are developed.		**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		The main module of this program		**
 ** 			exemplifies how pointers to pointers	**
 **			are referenced, through the 'address of'**
 **			and 'indirection' operators, in order	**
 **			to learn how to properly initialize	**
 **			and reference them without incurring	**
 **			memory segment violations.		**
 ****************************************************************/
int main(int int_argc, char *ch_argv[])
	{
		// Work variables.
		int num = V_ZERO;	// Numeric integer variable 'num'.
		int *ptr = &num;	// Pointer to address of integer.
		int **ptrPtr = &ptr;    // Pointer to another pointer.

		/* ------------------------------------------------------------ **
		** The entry of a value for an integer numeric variable         **
		** is requested and getting its memory address at compile	**
		** time.							**
		** -------------------------------------------------------------*/
		printf("Valor entero: ");
		scanf("%d", &num);

		/* ------------------------------------------------------------ **
		** An integer numeric variable whose memory address is assigned	**
		** at compile time and which is obtained using the 'address of'	**
		** operator.							**
		** ------------------------------------------------------------ */
		printf("\n");
		printf("+---|----+---|----+---|----+---|----+----|---+----|\n");
		printf("Variable  : 'num'.\n");
		printf("+---|----+---|----+---|----+---|----+----|---+----|\n");
		printf("Valor     : [%d].\n", num);
		printf("Dirección : [%p].\n", &num);
		printf("+--------+--------+--------+--------+--------+----|\n");

		/* ------------------------------------------------------------ **
		** A pointer that stores the memory address of a static integer **
		** variable that was assigned its memory address at compile	**
		** time.							**
		** ------------------------------------------------------------ */
		printf("\n");
		printf("+---|----+---|----+---|----+---|----+----|---+----|\n");
		printf("Apuntador a 'num'.\n");
		printf("+---|----+---|----+---|----+---|----+----|---+----|\n");
		printf("Apuntador : 'ptr'.\n");
		printf("Valor     : [%d].\n", *ptr);
		printf("Dirección : [%p].\n", ptr);
		printf("+--------+--------+--------+--------+--------+----|\n");

		/* ------------------------------------------------------------ **
		** A pointer that holds the memory address of another pointer	**
		** that holds the memory address of an integer variable that was**
		** assigned an address at compile time.				**
		** ------------------------------------------------------------ */
		printf("\n");
		printf("+---|----+---|----+---|----+---|----+----|---+----|\n");
		printf("Apuntador de apuntador a 'num'.\n");
		printf("+---|----+---|----+---|----+---|----+----|---+----|\n");
		printf("Apuntador : 'ptrPtr'.\n");
		printf("Valor     : [%d]\n", **ptrPtr);
		printf("Dirección : [%p]\n", *ptrPtr);
		printf("Dirección : [%p]\n", ptrPtr);
		printf("+--------+--------+--------+--------+--------+----|\n");

		return num;
	}
