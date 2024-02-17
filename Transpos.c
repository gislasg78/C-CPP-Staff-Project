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
 **				Rows: 3.	Columns: 3.	**
 **				--------	-----------	**
 **			[	-8	1	3	].	**
 **			[	1	7	4	].	**
 **			[	3	4	9	].	**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//Working limit constants.
#define V_LOWER_LIMIT_COLS	0
#define V_LOWER_LIMIT_ROWS	0
#define V_UPPER_LIMIT_COLS	100
#define V_UPPER_LIMIT_ROWS	100

//Symbolic work constants.
#define	V_ONE			1
#define	V_ZERO			0

//Alphanumeric symbolic constants.
#define CARRIAGE_RETURN		'\n'
#define NULL_CHARACTER		'\0'


/* ------------------------------------------------------------	--
 * Data types that contain informative alphanumeric literals,	--
 * options for displaying arrays, and the global integer static --
 * array.							--
 * ------------------------------------------------------------	*/
//Enumeration of options to display the original matrix or the transposed matrix.
enum enm_Options_matrix
	{
		enm_opt_matrix_equivalents,
		enm_opt_matrix_original,
		enm_opt_matrix_symmetrical,
		enm_opt_matrix_transposed
	};

//Global integer static work array.
static int int_matrix[V_UPPER_LIMIT_ROWS][V_UPPER_LIMIT_COLS];

//Label messages from exposed arrays.
static char *str_Tags[] = { "Matrix Equivalent Positions", "Original matrix", "Symmetrical matrix", "Transposed matrix" };


//Prototype of the function to receive and validate integer data.
int enter_a_data(int *const);

/*****************************************************************
 ** Function:		int capture_int_matrix			**
 **				(const int int_Rows,		**
 **				 const int int_Columns,		**
 **				 int int_matrix[][],		**
 **				 const enum enm_Options_matrix	**
 **					enmOp);			**
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
 **			int int_matrix[][],			**
 **			const enum enm_Options_matrix enmOp.	**
 ** Output Parms:	int int_matrix[][].			**
 ** Result:		The result returned by this function is	**
 **			the number of elements actually		**
 **			captured, which should be equal to the	**
 **			product of the number of rows times the	**
 **			number of columns requested by the user	**
 **			to fill the static array of integers.	**
 ****************************************************************/
int capture_int_matrix(const int int_Rows, const int int_Columns, int int_matrix[][V_UPPER_LIMIT_COLS], const enum enm_Options_matrix enmOp)
	{
		/* Initial declaration of work variables. */
		int int_counting_items = V_ZERO;

		/* Exposed array warning messages. */
		printf("\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("|    Capture of array elements.     +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| (Rows: [%d],\tColumns: [%d]).\n", int_Rows, int_Columns);
		printf("+--------+--------+--------+--------+\n");
		printf("Capturing matrix...\n");

		switch (enmOp)
			{
				/* Capture request according to rows and columns. */
				case enm_opt_matrix_original:
					for (int int_row = V_LOWER_LIMIT_ROWS; int_row < int_Rows; int_row++)
						for (int int_col = V_LOWER_LIMIT_COLS; int_col < int_Columns; int_col++)
							{
								printf("Enter data #[%03d] : (Row: [%03d], Column: [%03d]) : ", int_counting_items++, int_row, int_col);
								int_matrix[int_row][int_col] = enter_a_data(*(int_matrix + int_row) + int_col);
							}

					break;

				/* Capture a matrix to be created in a mirrored symmetric manner. */
				case enm_opt_matrix_symmetrical:
					for (int int_row = V_ZERO; int_row < int_Rows; int_row++)
						for (int int_col = V_ZERO; int_col < int_Columns; int_col++)
							if (int_matrix[int_row][int_col] == V_ZERO)
								{
									printf("Enter data #[%03d] : (Row: [%d], Column: [%d]; Row: [%d], Column: [%d]) : ", int_counting_items++, int_row, int_col, int_col, int_row);
									int_matrix[int_row][int_col] = enter_a_data(&int_matrix[int_row][int_col]);

									int_matrix[int_col][int_row] = int_matrix[int_row][int_col];
								}

					break;

				/* In case of invalid option parameter. */
				default:
					printf("Invalid option typed: [%d].\n", enmOp);
					break;

			}

		/* Informative message of output results. */
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
		printf("| (Rows: [%d],\tColumns: [%d]).\n", int_Rows, int_Columns);
		printf("+--------+--------+--------+--------+\n");
		printf("| Matrix Address:\t[%p].\n", int_matrix);
		printf("| Size by Item  :\t[%ld].\n", sizeof(int_matrix[V_LOWER_LIMIT_ROWS][V_LOWER_LIMIT_COLS]));
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

		/* Informative message of output results. */
		printf("[%d] Obtained output results.\n", int_counting_items);

		return int_counting_items;
	}

/*****************************************************************
 ** Function:		int enter_a_data			**
 **				(int *const ptr_int_data);	**
 ** Explanation:	This function primarily covers the	**
 **			purpose of validating that a data	**
 **			entered by keyboard is an integer	**
 **			numeric and does not contain invalid	**
 **			characters, otherwise, said characters	**
 **			will be eliminated from the input buffer**
 **			until it is freed and can be requested	**
 **			again without problems, the same	**
 **			numerical entry.			**
 ** Input Parms:	int *const ptr_int_data.		**
 ** Output Parms:	int *const ptr_int_data.		**
 ** Result:		The result returned by this function is	**
 **			the perfectly validated numeric integer	**
 **			value without special characters and	**
 **			without overflowing the input buffer.	**
 ****************************************************************/
int enter_a_data(int *const ptr_int_data)
	{
		/* Initial declaration of work variables. */
		char chr_chr = NULL_CHARACTER;
		*ptr_int_data = V_ZERO;

		/* Error handling can be done in data entry if necessary. */
		if (scanf("%d", ptr_int_data) != V_ONE)	//Entry was successful with one only data.
			{
				/* The value returned by the 'scanf' function is initialized. */
				*ptr_int_data = V_ZERO;

				/* The input was not a valid integer. */
				fprintf(stderr, "Mistake! The input is not a valid integer at address: [%p].\n", ptr_int_data);

				/* Clear the input buffer of invalid characters. */
				while ((chr_chr = getchar()) != CARRIAGE_RETURN && chr_chr != EOF);
			}

		return *ptr_int_data;
	}

/*****************************************************************
 ** Function:		int initialize_int_matrix		**
 **				(int int_matrix[][]);		**
 ** Explanation:	The primary purpose of this function is	**
 **			to initialize with zero values each of	**
 **			the row and column positions indicated	**
 **			in the entire global static matrix of	**
 **			this program to be certain that said	**
 **			two-dimensional array has initially	**
 **			correct values.				**
 ** Input Parms:	int int_matrix[][].			**
 ** Output Parms:	None.					**
 ** Result:		The result returned by this function is	**
 **			the effective number of elements that	**
 **			were initialized to zeros in their	**
 **			entirety, in accordance with the number	**
 **			of actual rows and columns that the	**
 **			entire global static matrix of this	**
 **			program has.				**
 ****************************************************************/
int initialize_int_matrix(int int_matrix[][V_UPPER_LIMIT_COLS])
	{
		/* Initial declaration of work variables. */
		int int_counting_items = V_ZERO;

		/* Assigning initial values to the working integer global static array. */
		for (int int_row = V_LOWER_LIMIT_ROWS; int_row < V_UPPER_LIMIT_ROWS; int_row++)
			for (int int_col = V_LOWER_LIMIT_COLS; int_col < V_UPPER_LIMIT_COLS; int_col++)
				{
					int_counting_items++;
					*(*(int_matrix + int_row) + int_col) = V_ZERO;
				}

		/* Informative message of output results. */
		printf("[%d] Initialized array positions.\n", int_counting_items);

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
		int int_counting_equivalences = V_ZERO;
		int int_counting_items = V_ZERO;
		int int_Limit_Columns = int_Columns;
		int int_Limit_Rows = int_Rows;

		/* The values of rows and columns are inverted in the case of a transposed matrix. */
		if (enmOp == enm_opt_matrix_transposed)
			{
				int_Limit_Rows = int_Columns;
				int_Limit_Columns = int_Rows;
			}

		/* Matrix presentation notification messages. */
		printf("\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("|    Display of matrix elements.    +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| (Rows: [%d],\tColumns: [%d]).\n", int_Limit_Rows, int_Limit_Columns);
		printf("+--------+--------+--------+--------+\n");
		printf("[%s]...\n", str_Tags[(int) enmOp]);

		/* Dump the matrix on the screen, depending on the option requested, whether the original or the transposed. */
		switch (enmOp)
			{
				/* Equivalent positions of the original matrix and the transposed matrix. */
				case enm_opt_matrix_equivalents:
					for (int int_row = V_LOWER_LIMIT_ROWS; int_row < int_Limit_Rows; int_row++)
						{
							for (int int_col = V_LOWER_LIMIT_COLS; int_col < int_Limit_Columns; int_col++)
								{
									printf("#[%d].\t(%d, %d) = [%d].\t(%d, %d) = [%d].\n",
										int_counting_items++, int_row, int_col,
										*(*(int_matrix + int_row) + int_col),
										int_col, int_row,
										int_matrix[int_col][int_row]);

									if (int_matrix[int_row][int_col] == *(*(int_matrix + int_col) + int_row))
										int_counting_equivalences++;
								}

							printf("\n");
						}

					/* Informational messages about the symmetry of a matrix. */
					printf("+---|----+---|----+---|----+---|----+\n");
					printf("+    Matrix symmetry information.   +\n");
					printf("+---|----+---|----+---|----+---|----+\n");
					printf("| Rows\t\t:\t[%d].\n", int_Limit_Rows);
					printf("| Columns\t:\t[%d].\n", int_Limit_Columns);
					printf("| Items\t\t:\t[%d].\n", int_counting_items);
					printf("+--------+--------+--------+--------+\n");
					printf("| Equivalences\t:\t[%d].\n", int_counting_equivalences);
					printf("+---|----+---|----+---|----+---|----+\n");

					break;

				/* Show the positions of the original array. */
				case enm_opt_matrix_original:
					for (int int_row = V_LOWER_LIMIT_ROWS; int_row < int_Limit_Rows; int_row++)
						{
							for (int int_col = V_LOWER_LIMIT_COLS; int_col < int_Limit_Columns; int_col++, int_counting_items++)
								printf("[%3.d]\t", int_matrix[int_row][int_col]);

							printf("\n");
						}

					break;

				/* Determination of whether an original matrix is symmetric relative to its transpose. */
				case enm_opt_matrix_symmetrical:
					for (int int_row = V_LOWER_LIMIT_ROWS; int_row < int_Limit_Rows; int_row++)
						for (int int_col = V_LOWER_LIMIT_COLS; int_col < int_Limit_Columns; int_col++)
							{
								int_counting_items++;

								if (int_matrix[int_row][int_col] == *(*(int_matrix + int_col) + int_row))
									int_counting_equivalences++;
							}

					/* Detection if the matrix in the normal state is symmetric to its transpose. */
					if (int_counting_equivalences == int_counting_items)
						printf("Perfectly symmetrical array...\n");
					else
						printf("Asymmetrical unbalanced arrangement...\n");

					break;

				/* Show the positions of the transposed matrix. */
				case enm_opt_matrix_transposed:
					for (int int_row = V_LOWER_LIMIT_ROWS; int_row < int_Limit_Rows; int_row++)
						{
							for (int int_col = V_LOWER_LIMIT_COLS; int_col < int_Limit_Columns; int_col++, int_counting_items++)
								printf("[%3.d]\t", *(*(int_matrix + int_col) + int_row));

							printf("\n");
						}

					break;

				/* In case of invalid option parameter. */
				default:
					printf("Invalid option typed: [%d].\n", enmOp);
					break;

			}

		/* Informative message of output results. */
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
 **				Rows: 3.	Columns: 3.	**
 **				--------	-----------	**
 **			[	-8	1	3	].	**
 **			[	1	7	4	].	**
 **			[	3	4	9	].	**
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
		int_Rows = enter_a_data(&int_Rows);
		printf("Columns from [%d] to [%d] : ", V_LOWER_LIMIT_COLS, V_UPPER_LIMIT_ROWS);
		int_Columns = enter_a_data(&int_Columns);

		/* Review of the limits of the rows and columns of the matrix. */
		if (int_Rows >= V_LOWER_LIMIT_ROWS && int_Rows <= V_UPPER_LIMIT_ROWS)
			if (int_Columns >= V_LOWER_LIMIT_COLS && int_Columns <= V_UPPER_LIMIT_COLS)
				{
					/* Initialized, captured and dumped the bidimensional array. */
					int_counting_items = initialize_int_matrix(int_matrix);
					int_counting_items = capture_int_matrix(int_Rows, int_Columns, int_matrix, enm_opt_matrix_original);
					int_counting_items = dump_int_matrix(int_Rows, int_Columns, int_matrix);

					/* Original matrix and transposed matrix. */
					int_counting_items = view_int_matrix(int_Rows, int_Columns, int_matrix, enm_opt_matrix_original);
					int_counting_items = view_int_matrix(int_Rows, int_Columns, int_matrix, enm_opt_matrix_transposed);
					int_counting_items = view_int_matrix(int_Rows, int_Columns, int_matrix, enm_opt_matrix_equivalents);
					int_counting_items = view_int_matrix(int_Rows, int_Columns, int_matrix, enm_opt_matrix_symmetrical);

					/* Initialized, captured and dumped the array as symmetric. */
					int_counting_items = initialize_int_matrix(int_matrix);
					int_counting_items = capture_int_matrix(int_Rows, int_Columns, int_matrix, enm_opt_matrix_symmetrical);
					int_counting_items = dump_int_matrix(int_Rows, int_Columns, int_matrix);

					/* Original matrix (symmetric) and transposed matrix. */
					int_counting_items = view_int_matrix(int_Rows, int_Columns, int_matrix, enm_opt_matrix_original);
					int_counting_items = view_int_matrix(int_Rows, int_Columns, int_matrix, enm_opt_matrix_transposed);
					int_counting_items = view_int_matrix(int_Rows, int_Columns, int_matrix, enm_opt_matrix_equivalents);
					int_counting_items = view_int_matrix(int_Rows, int_Columns, int_matrix, enm_opt_matrix_symmetrical);
				}
			else
				printf("Mistake! The value for column: [%d] is not in the range [%d] to [%d]\n.", int_Columns, V_LOWER_LIMIT_COLS, V_UPPER_LIMIT_COLS);
		else
			printf("Mistake! The value for row: [%d] is not in the range [%d] to [%d]\n.", int_Rows, V_LOWER_LIMIT_ROWS, V_UPPER_LIMIT_ROWS);

		return V_ZERO;
	}
