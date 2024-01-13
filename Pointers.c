/****************** Use of pointers of pointers. *****************
 ** Source Code:	Pointers.c				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturdar, December 30, 2023.          	**
 ** Purpose:		This program makes examples of pointers	**
 **			pointing to other pointers with the	**
 **			address of a static integer variable	**
 **			that is assigned a memory address at	**
 **			compile time.				**
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
 ****************************************************************/
int main()
	{
		//Work variables.
		int int_num = V_ZERO;			//Numeric integer variable 'num'.
		int *ptr_int_num = &int_num;		//Pointer to address of integer.
		int **ptr_ptr_int_num = &ptr_int_num;	//Pointer to another pointer.

		/* ------------------------------------------------------------ **
		** The entry of a value for an integer numeric variable         **
		** is requested and getting its memory address at compile	**
		** time.							**
		** -------------------------------------------------------------*/
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+    Examples of use of pointers.   +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Integer value: ");
		scanf("%d", &int_num);

		/* ------------------------------------------------------------ **
		** An integer numeric variable whose memory address is assigned	**
		** at compile time and which is obtained using the 'address of'	**
		** operator.							**
		** ------------------------------------------------------------ */
		/* ------------------------------------------------------------ **
		** A pointer that stores the memory address of a static integer **
		** variable that was assigned its memory address at compile	**
		** time.							**
		** ------------------------------------------------------------ */
		/* ------------------------------------------------------------ **
		** A pointer that holds the memory address of another pointer	**
		** that holds the memory address of an integer variable that was**
		** assigned an address at compile time.				**
		** ------------------------------------------------------------ */
		printf("\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("+ Pointers of pointers Information. +\n");
		printf("+===|====+===|====+===|====+===|====+\n");
		printf("+        Variable: 'int_num'.       +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| Value int\t: [%d].\n", int_num);
		printf("| Own Address\t: [%p].\n", &int_num);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+      Variable: 'ptr_int_num'.     +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| Value int\t: [%d].\n", *ptr_int_num);
		printf("| Stored Address: [%p].\n", ptr_int_num);
		printf("|-----------------------------------|\n");
		printf("| Self Address\t: [%p].\n", &ptr_int_num);
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+   Variable: 'ptr_ptr_int_num'.    +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| Value int\t: [%d].\n", **ptr_ptr_int_num);
		printf("| First Address\t: [%p].\n", *ptr_ptr_int_num);
		printf("| Second Address: [%p].\n", ptr_ptr_int_num);
		printf("|-----------------------------------|\n");
		printf("| Self Address\t: [%p].\n", &ptr_ptr_int_num);
		printf("+===|====+===|====+===|====+===|====+\n");

		return V_ZERO;
	}
