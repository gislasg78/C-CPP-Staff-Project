/************** Basic multiplication table generator *************
 ** Source Code:	TableMul.c				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Thursday, August 31, 2023.		**
 ** Purpose:		This program generates a set of		**
 **			multiplication tables from zero to ten	**
 **			using the creation of a pointer to a	**
 **			pointer of type integer in a given	**
 **			function that is called with a pointer	**
 **			to a function.				**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>
#include <stdlib.h>

//Symbolic constants of minimum and maximum limits.
#define LIM_MIN	0
#define LIM_MAX	10

//Work Symbolic Constants.
#define V_ONE	1
#define V_ZERO	0

/*****************************************************************
 ** Function:		tablemult.				**
 ** Explanation:	This function returns a pointer pointer	**
 **			to an integer type containing the array	**
 **			of times tables requested by the user,	**
 **			the user providing the number of rows	**
 **			and columns that the user wants those	**
 **			multiplication tables to have.		**
 ** Input Parms:	int int_Rows,				**
 **			int int_Cols.				**
 ** Output Parms:	None.					**
 ** Result:		This function returns as a result a	**
 **			pointer pointer to an integer type that	**
 **			contains the multiplication tables with	**
 **			as many rows and columns as they are	**
 **			passed by formal and current parameters.**
 ****************************************************************/
int **tablemult(int int_Rows, int int_Cols)
	{
		int **ppa = NULL;

		/*------------------------------------------------
		 * Creation and dynamic assignment of 		--
		 * multiplication tables, given the number of	--
		 * rows and columns they must contain.		--
		 *----------------------------------------------*/
		if ( ( ppa = (int **) malloc( (int_Rows+V_ONE) * sizeof(int *) ) ) != NULL )
			for (int int_row=V_ZERO; int_row<=int_Rows; int_row++)
				if ( ( ppa[int_row] = (int *) malloc ( (int_Cols+V_ONE) * sizeof(int) ) ) != NULL)
					{
						for (int int_col=V_ZERO; int_col<=int_Cols; int_col++)
							{
								ppa[int_row][int_col] = int_row * int_col;
								printf("[%2.d]x[%2.i]=[%3.d].\n", int_row, int_col, *(*(ppa+int_row)+int_col));
							}

						printf("\n");
					}

		return (ppa);
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	In this main function, the user is	**
 **			prompted to enter a specified number of	*+
 **			rows and columns to generate a series	**
 **			of times tables using pointers of	**
 **			pointers to an integer type.		**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		This procedure calls the function in	**
 **			charge of creating a set of		**
 **			multiplication tables through pointers	**
 **			of pointers to an integer type.		**
*****************************************************************/
int main()
	{
		int **ppRec=NULL;
		int int_Y=V_ZERO;
		int int_X=V_ZERO;

		printf("+---|----+---|----+---|----+---|----+\n");
		printf("|       Tablas de multiplicar.      |\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Renglones desde [%d] hasta [%d]: ", LIM_MIN, LIM_MAX);
		scanf("%i", &int_Y);
		printf("Columnas  desde [%d] hasta [%d]: ", LIM_MIN, LIM_MAX);
		scanf("%d", &int_X);

		printf("\n");

		/* -------------------------------------------- **
		 * Here it is checked that the values entered	**
		 * for rows and columns of the multiplication	**
		 * tables are within established intervals.	**
		 * -------------------------------------------- */
		if (int_Y >= LIM_MIN && int_Y <= LIM_MAX)
			if (int_X >= LIM_MIN && int_X <= LIM_MAX)
				{
					/* Call to the function that returns the pointer of pointer. */
					ppRec=tablemult(int_Y, int_X);

					/* Validate that the pointer of pointers has a valid memory address value */
					if (ppRec!=NULL)
						{
							/* Free the memory allocated to each of the rows. */
							for (int int_n_row=V_ZERO; int_n_row<int_Y; int_n_row++)
								free(ppRec[int_n_row]);

                                			/* Free the memory allocated to the array of pointers. */
                                			free(ppRec);
						}
				}
			else
				printf("¡Error! [%d] columnas  no están entre [%d] y [%d].\n", int_X, LIM_MIN, LIM_MAX);
		else
				printf("¡Error! [%d] renglones no están entre [%d] y [%d].\n", int_Y, LIM_MIN, LIM_MAX);

		return V_ZERO;
	}
