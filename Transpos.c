/*************** Transposition of a static matrix. ***************
 ** Source Code:        Transpos.c				**
 ** Author:             Gustavo Islas Gálvez.                   **
 ** Creation Date:      Saturday, December 30, 2023.            **
 ** Purpose:		The purpose of this program is to show	**
 **			the implementation of static matrices	**
 **			that are filled according to the number	**
 **			of rows and columns that the user wishes**
 **			to enter, and shows memory dumps,	**
 **			the filled matrix and its transposed	**
 **			matrix in order to exemplify its uses.	**
 ** +---!----+---!----+---!----++---!----+---!----+---!----+---	**
 **			Test Values:				**
 **				Rows: 4.	Columns: 4.	**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//Working limit constants.
#define V_LOWER_LIMIT_COLS	0
#define V_LOWER_LIMIT_ROWS	0
#define V_UPPER_LIMIT_COLS	100
#define V_UPPER_LIMIT_ROWS	100

//Symbolic work constants.
#define	V_ZERO			0

//Enumeration of options to display the original matrix or the transposed matrix.
enum enm_Options_matrix
	{
		enm_opt_matrix_original,
		enm_opt_matrix_transposed
	};

//Global integer static work array.
static int int_matrix[V_UPPER_LIMIT_ROWS][V_UPPER_LIMIT_COLS];

//Label messages from exposed arrays.
static char *str_Tags[] = { "Original matrix", "Transposed matrix" };

/*****************************************************************
 ** Function:		int capture_int_matrix			**
 **				(const int int_Rows,		**
 **				 const int int_Columns,		**
 **				 int int_matrix[][]);		**
 ** Explanation:	The primary purpose of this function is	**
 **			to capture data by data each of the	**
 **			elements that will make up the entire	**
 **			static matrix up to the number of rows	**
 **			and columns that the user has specified	**
 **			without exceeding the maximum limits on	**
 **			rows and columns established in the	**
**			static test matrix.			**
 ** Input Parms:	const int int_Rows,			**
 **			const int int_Columns,			**
 **			int int_matrix[][].			**
 ** Output Parms:	int int_matrix[][].			**
 ** Result:		The result returned by this function is	**
 **			the number of elements actually		**
 **			captured, which should be equal to the	**
 **			product of the number of rows times the	**
 **			number of columns requested by the user	**
 **			to fill the static array of integers.	**
 ****************************************************************/
int capture_int_matrix(const int int_Rows, const int int_Columns, int int_matrix[][V_UPPER_LIMIT_COLS])
	{
		/* Initial declaration of work variables. */
		int int_counting_items = V_ZERO;

		/* Exposed array warning messages. */
		printf("\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("|    Capture of array elements.     +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| (Rows: [%d], Columns: [%d]).\n", int_Rows, int_Columns);
		printf("+--------+--------+--------+--------+\n");
		printf("Capturing matrix...\n");

		/* Capture request according to rows and columns. */
		for (int int_row = V_LOWER_LIMIT_ROWS; int_row < int_Rows; int_row++)
			for (int int_col = V_LOWER_LIMIT_COLS; int_col < int_Columns; int_col++)
				{
					printf("Enter data #[%03d] : (Row: [%03d], Column: [%03d]) : ", int_counting_items++, int_row, int_col);
					scanf("%d", *(int_matrix + int_row) + int_col);
				}

		printf("[%d] Captured input results.\n", int_counting_items);

		return int_counting_items;
	}

/*****************************************************************
 ** Function:		int dump_int_matrix			**
 **				(const int int_Rows,		**
 **				 const int int_Columns,		**
 **				 const int int_matrix[][]);	**
 ** Explanation:	The primary purpose of this function is	**
 **			to show each memory address of each	**
 **			element of the array in C notations for	**
 **			both array and pointer, to exemplify	**
 **			their uses and practice them.		**
 ** Input Parms:	const int int_Rows,			**
 **			const int int_Columns,			**
 **			const int int_matrix[][].		**
 ** Output Parms:	None.					**
 ** Result:		This function returns the number of	**
 **			elements displayed on the screen whose	**
 **			values and their respective memory	**
 **			locations have been displayed.		**
 ****************************************************************/
int dump_int_matrix(const int int_Rows, const int int_Columns, const int int_matrix[][V_UPPER_LIMIT_COLS])
	{
		/* Initial declaration of work variables. */
		int int_counting_items = V_ZERO;

		/* Array dump display messages. */
		printf("\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("|  Matrix memory address breakdown. +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| (Rows: [%d], Columns: [%d]).\n", int_Rows, int_Columns);
		printf("+--------+--------+--------+--------+\n");
		printf("| Address:\t[%p].\n", int_matrix);
		printf("| Size:\t\t[%ld].\n", sizeof(int_matrix[V_LOWER_LIMIT_ROWS][V_LOWER_LIMIT_COLS]));
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Memory address dump...\n");

		/* Display its value and memory address data by data in various notations. */
		for (int int_row = V_LOWER_LIMIT_ROWS; int_row < int_Rows; int_row++)
			for (int int_col = V_LOWER_LIMIT_COLS; int_col < int_Columns; int_col++)
				{
					printf("# [%03d]\t(Row: [%03d], Column: [%03d]).\t[%p] : [%p] : [%p].\t[%d] = [%d].\n",
						int_counting_items++, int_row, int_col,
						*(int_matrix+int_row) + int_col, int_matrix[int_row] + int_col, &int_matrix[int_row][int_col],
						*(*(int_matrix + int_row) + int_col), int_matrix[int_row][int_col]);
				}

		printf("[%d] Obtained output results.\n", int_counting_items);

		return int_counting_items;
	}

/*****************************************************************
 ** Function:		int view_int_matrix			**
 **				(const int int_Rows,		**
 **				 const int int_Columns,		**
 **				 const int int_matrix[][],	**
 **				 enum enm_Options_matrix enmOp);**
 ** Explanation:	This function achieves the objective of	**
 **			displaying the original matrix with its	**
 **			correct alignment in terms of rows and	**
 **			columns, or its transposed matrix by	**
 **			inverting its rows by columns and its	**
 **			columns by rows when displayed on the	**
 **			screen.					**
 ** Input Parms:	const int int_Rows,			**
 **			const int int_Columns,			**
 **			const int int_matrix[][],		**
 **			enum enm_Options_matrix enmOp.		**
 ** Output Parms:	None.					**
 ** Result:		Displays on the screen the contents of	**
 **			a matrix in their original positions or	**
 **			with their positions transposed.	**
 ****************************************************************/
int view_int_matrix(const int int_Rows, const int int_Columns, const int int_matrix[][V_UPPER_LIMIT_COLS], enum enm_Options_matrix enmOp)
	{
		/* Initial declaration of work variables. */
		int int_counting_items = V_ZERO;

		/* Matrix presentation notification messages. */
		printf("\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("|    Display of matrix elements.    +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| (Rows: [%d], Columns: [%d]).\n", int_Rows, int_Columns);
		printf("+--------+--------+--------+--------+\n");
		printf("[%s]...\n", str_Tags[(int) enmOp]);

		/* Dump the matrix on the screen, depending on the option requested, whether the original or the transposed. */
		for (int int_row = V_LOWER_LIMIT_ROWS; int_row < int_Rows; int_row++)
			{
				for (int int_col = V_LOWER_LIMIT_COLS; int_col < int_Columns; int_col++, int_counting_items++)
					switch (enmOp)
						{
							case enm_opt_matrix_original:
								printf("[%3.d]\t", int_matrix[int_row][int_col]);
								break;

							case enm_opt_matrix_transposed:
								printf("[%3.d]\t", *(*(int_matrix + int_col) + int_row));
								break;
						}

				printf("\n");
			}

		printf("[%d] Obtained output results.\n", int_counting_items);

		return int_counting_items;
	}


/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	The purpose of this main program is to	**
 **			capture data by data of the entire	**
 **			static matrix up to a certain number of	**
 **			rows and columns, to later dump the	**
 **			memory addresses and the values of each	**
 **			position of the captured matrix, and	**
 **			finally, display the matrix in its	**
 **			original form and in its transposed	**
 **			form.					**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		Both the original matrices and their	**
 **			respective transposed matrices can be	**
 **			compared to know if there is symmetry	**
 **			between both types of matrices, or to	**
 **			know how many and which elements are	**
 **			those that do not coincide according to	**
 **			their determined row and column		**
 **			positions.				**
 ** +---!----+---!----+---!----++---!----+---!----+---!----+---	**
 **			Test Values:				**
 **				Rows: 4.	Columns: 4.	**
*****************************************************************/
int main()
	{
		/* Initial declaration of work variables. */
		int int_counting_items = V_ZERO;
		int int_Columns = V_ZERO;
		int int_Rows = V_ZERO;

		/* Static integer array processing program messages. */
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+  Dumping fixed dimensions arrays. +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Rows    from [%d] to [%d] : ", V_LOWER_LIMIT_ROWS, V_UPPER_LIMIT_ROWS);
		scanf("%d", &int_Rows);
		printf("Columns from [%d] to [%d] : ", V_LOWER_LIMIT_COLS, V_UPPER_LIMIT_ROWS);
		scanf("%d", &int_Columns);

		/* Review of the limits of the rows and columns of the matrix. */
		if (int_Rows >= V_LOWER_LIMIT_ROWS && int_Rows <= V_UPPER_LIMIT_ROWS)
			if (int_Columns >= V_LOWER_LIMIT_COLS && int_Columns <= V_UPPER_LIMIT_COLS)
				{
					/* Captured and dumped the array. */
					int_counting_items = capture_int_matrix(int_Rows, int_Columns, int_matrix);
					int_counting_items = dump_int_matrix(int_Rows, int_Columns, int_matrix);

					/* Original matrix and transposed matrix. */
					int_counting_items = view_int_matrix(int_Rows, int_Columns, int_matrix, enm_opt_matrix_original);
					int_counting_items = view_int_matrix(int_Rows, int_Columns, int_matrix, enm_opt_matrix_transposed);
				}
			else
				printf("Mistake! The value for column: [%d] is not in the range [%d] to [%d]\n.", int_Columns, V_LOWER_LIMIT_COLS, V_UPPER_LIMIT_COLS);
		else
			printf("Mistake! The value for row: [%d] is not in the range [%d] to [%d]\n.", int_Rows, V_LOWER_LIMIT_ROWS, V_UPPER_LIMIT_ROWS);

		return V_ZERO;
	}
