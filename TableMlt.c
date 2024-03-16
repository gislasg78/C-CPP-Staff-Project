/************** Basic multiplication table generator. ************
 ** Source Code:	TableMlt.c				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, December 30, 2023.		**
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
#define	V_LOWER_LIMIT_COLS	1
#define V_LOWER_LIMIT_ROWS	1
#define V_UPPER_LIMIT_COLS	11
#define V_UPPER_LIMIT_ROWS	11

//Work Symbolic Constants.
#define V_ONE			1
#define V_ZERO			0

/*****************************************************************
 ** Function:		int **ptr_ptr_int_tablemult.		**
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
int **ptr_ptr_int_tablemult(int int_Rows, int int_Cols)
	{
		int int_counting_results = V_ZERO;
		int **ptr_ptr_int_tablemult_aux = NULL;

		/*------------------------------------------------
		 * Creation and dynamic assignment of 		--
		 * multiplication tables, given the number of	--
		 * rows and columns they must contain.		--
		 *----------------------------------------------*/
		if ( ( ptr_ptr_int_tablemult_aux = (int **) malloc( (int_Rows + V_ONE) * sizeof(int *) ) ) != NULL )
			{
				printf("\n");

				for (int int_row = V_ZERO; int_row < int_Rows; int_row++)
					{
						printf("Table # [%2.i] of [%2.i].\n", int_row, int_Rows);

						if ( ( ptr_ptr_int_tablemult_aux[int_row] = (int *) malloc ( (int_Cols + V_ONE) * sizeof(int) ) ) != NULL)
							{
								for (int int_col = V_ZERO; int_col < int_Cols; int_col++)
									{
										ptr_ptr_int_tablemult_aux[int_row][int_col] = int_row * int_col;
										printf("# [%3.d]:\t[%2.d]\tx\t[%2.i]\t=\t[%3.d].\n", int_counting_results++, int_row, int_col, *(*(ptr_ptr_int_tablemult_aux+int_row)+int_col));
									}

								printf("\n");
							}
					}

				printf("[%d] Generated output results.\n", int_counting_results);
			}

		return (ptr_ptr_int_tablemult_aux);
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
		int int_Y = V_ZERO;
		int int_X = V_ZERO;
		int **ptr_ptr_int_tablemult_recovered = NULL;

		printf("+---|----+---|----+---|----+---|---+----|---+\n");
		printf("| Dynamic multiplication tables generator.  |\n");
		printf("+---|----+---|----+---|----+---|---+----|---+\n");
		printf("Rows    from [%d] to [%d]: ", V_LOWER_LIMIT_ROWS, V_UPPER_LIMIT_ROWS);
		scanf("%i", &int_Y);
		printf("Columns from [%d] to [%d]: ", V_LOWER_LIMIT_COLS, V_UPPER_LIMIT_COLS);
		scanf("%d", &int_X);

		/* -------------------------------------------- **
		 * Here it is checked that the values entered	**
		 * for rows and columns of the multiplication	**
		 * tables are within established intervals.	**
		 * -------------------------------------------- */
		if (int_Y >= V_LOWER_LIMIT_ROWS && int_Y <= V_UPPER_LIMIT_ROWS)
			if (int_X >= V_LOWER_LIMIT_COLS && int_X <= V_UPPER_LIMIT_COLS)
				{
					/* Call to the function that returns the pointer of pointer. */
					ptr_ptr_int_tablemult_recovered = ptr_ptr_int_tablemult(int_Y, int_X);

					/* Validate that the pointer of pointers has a valid memory address value */
					if (ptr_ptr_int_tablemult_recovered)
						{
							/* Free the memory allocated to each of the rows. */
							for (int int_n_row = V_ZERO; int_n_row < int_Y; int_n_row++)
								free(*(ptr_ptr_int_tablemult_recovered+int_n_row));

                                			/* Free the memory allocated to the array of pointers. */
                                			free(ptr_ptr_int_tablemult_recovered);
						}
				}
			else
				printf("Error! [%d] Columns are not between [%d] and [%d].\n", int_X, V_LOWER_LIMIT_COLS, V_UPPER_LIMIT_COLS);
		else
				printf("Error! [%d] Rows    are not between [%d] and [%d].\n", int_Y, V_LOWER_LIMIT_ROWS, V_UPPER_LIMIT_ROWS);

		return V_ZERO;
	}
