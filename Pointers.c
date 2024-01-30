/****************** Use of pointers of pointers. *****************
 ** Source Code:	Pointers.c				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturdar, December 30, 2023.          	**
 ** Purpose:		This program makes examples of pointers	**
 **			pointing to other pointers with the	**
 **			address of a static integer variable	**
 **			that is assigned a memory address at	**
 **			compile time.				**
 ** ----------------------------------------------------------- **
 ** A pointer that stores the memory address of a static integer**
 ** variable that was assigned its memory address at compile	**
 ** time.							**
*****************************************************************/
// C Standard Libraries.
#include <stdio.h>

//Numeric Symbolic Constants.
#define V_ZERO	0

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
 ** ----------------------------------------------------------- **
 ** A pointer that holds the memory address of another pointer	**
 ** that holds the memory address of an integer variable that	**
 ** was assigned an address at compile time.			**
 ****************************************************************/
int main()
	{
		//Work variables.
		int int_value = V_ZERO;				//Numeric integer variable 'num'.
		int *ptr_int_value = &int_value;		//Pointer to address of integer.
		int **ptr_ptr_int_value = &ptr_int_value;	//Pointer to another pointer.

		/* ------------------------------------------------------------ **
		** The entry of a value for an integer numeric variable         **
		** is requested and getting its memory address at compile	**
		** time.							**
		** -------------------------------------------------------------*/
		printf("+===|====+===|====+===|====+===|====+===|\n");
		printf("+      Examples of use of pointers.     +\n");
		printf("+===|====+===|====+===|====+===|====+===|\n");
		printf("Enter an integer value:\n");
		printf("Value [x] : ");
		scanf("%d", &int_value);

		/* ------------------------------------------------------------ **
		** An integer numeric variable whose memory address is assigned	**
		** at compile time and which is obtained using the 'address of'	**
		** operator.							**
		** ------------------------------------------------------------ */
		printf("\n");
		printf("+===|====+===|====+===|====+===|====+===|\n");
		printf("|General information about the pointers.|\n");
		printf("+===|====+===|====+===|====+===|====+===|\n");
		printf("|         Source input variable.        |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p] = [%d].\n", &int_value, int_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("|        Source mapping pointer.        |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p].\n", &ptr_int_value);
		printf("| Value [x] : [%p] = [%d].\n", ptr_int_value, *ptr_int_value);
		printf("|---+----+---+----+---+----+---+----+---|\n");
		printf("|    Source mapping double pointer.     |\n");
		printf("+---|----+---|----+---|----+---|----+---|\n");
		printf("| Value [x] : [%p].\n", &ptr_ptr_int_value);
		printf("| Value [x] : [%p].\n", ptr_ptr_int_value);
		printf("| Value [x] : [%p] = [%d].\n", *ptr_ptr_int_value, **ptr_ptr_int_value);
		printf("+---|----+---|----+---|----+---|----+---|\n");

		return V_ZERO;
	}
