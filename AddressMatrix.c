/* This program dumps the values ​​and accesses
   the memory addresses of a simple two-dimensional array. */

/* Standard Work Libraries. */
#include <stdio.h>

/* Symbolic numerical constants. */
#define	CARRIAGE_RETURN	'\n'
#define V_THREE		3
#define V_ZERO		0

/* Function that performs a specified pause with a warning message. */
char getPause(const char *str_Message)
	{
		/* Preliminary working variables. */
		char chr_key = V_ZERO;
		int int_chars = V_ZERO;

		/* Header message. */
		printf("%s", str_Message);

		/* Validate data entry as correct. */
		if (scanf("%c%*c%n", &chr_key, &int_chars))
			{
				/* Get a correct character value. */
				printf("\nInput value: [%x] : [%d] = [%c] : [%d]. OK!\n", chr_key, chr_key, chr_key, int_chars);
			}
		else
			{
				/* Get an incorrect character value. */
				fprintf(stderr, "\nThe value entered is not valid.\n");

				scanf("%*[^\n]%*c");
				while ((chr_key = (char) getchar()) != CARRIAGE_RETURN && chr_key != EOF);
			}

		/* Return of key value. */
		return chr_key;
}


/* Function responsible for adding two two-dimensional matrices and storing the result in a third one. */
int sumOfMatrices(const int matrix_a[][V_THREE], const int matrix_a_rows, const int matrix_a_columns, const int matrix_b[][V_THREE], const int matrix_b_rows, const int matrix_b_columns, int matrix_result[][V_THREE], const int matrix_result_rows, const int matrix_result_columns)
	{
		/* Preliminary working variables. */
		int counter = V_ZERO;

		/* Verify that all rows and columns of the matrices to be added are of the same size. */
		if ((matrix_a_rows == matrix_b_rows) && (matrix_a_rows == matrix_result_rows) && (matrix_b_rows == matrix_result_rows))
			{
				if ((matrix_a_columns == matrix_b_columns) && (matrix_a_columns == matrix_result_columns) && (matrix_b_columns == matrix_result_columns))
					{
						/* Loop to add the two matrices and store the result in a single matrix. */
						for (int current_row = V_ZERO; current_row < matrix_result_rows; ++current_row)
							{
								for (int current_column = V_ZERO; current_column < matrix_result_columns; ++current_column)
									{
										counter++;
										matrix_result[current_row][current_column] = matrix_a[current_row][current_column] + matrix_b[current_row][current_column];
									}
							}
					}
				else
					{
						fprintf(stderr, "\nThe columns of the origin and destination matrices must be identical!\n");
						fprintf(stderr, "Matrix 'a'.\n");
						fprintf(stderr, "+ Columns: [%d].\n", matrix_a_columns);

						fprintf(stderr, "Matrix 'b'.\n");
						fprintf(stderr, "+ Columns: [%d].\n", matrix_b_columns);

						fprintf(stderr, "Matrix 'result'.\n");
						fprintf(stderr, "+ Columns: [%d].\n", matrix_result_columns);
					}
			}
		else
			{
				fprintf(stderr, "\nThe rows of the origin and destination matrices must be identical!\n");
				fprintf(stderr, "Matrix 'a'.\n");
				fprintf(stderr, "+ Rows: [%d].\n", matrix_a_rows);

				fprintf(stderr, "Matrix 'b'.\n");
				fprintf(stderr, "+ Rows: [%d].\n", matrix_b_rows);

				fprintf(stderr, "Matrix 'result'.\n");
				fprintf(stderr, "+ Rows: [%d].\n", matrix_result_rows);
			}

		/* Returns the number of processed elements. */
		return counter;
	}

/* Function responsible for printing the contents of an 'm' x 'n' matrix. */
int viewMatrix(const int matrix[][V_THREE], const int matrix_rows, const int matrix_columns)
	{
		/* Preliminary working variables. */
		int counter = V_ZERO;

		/* Visualization of the fixed num_rows x num_cols matrix. */
		printf("\nDump of matrix.\n");
		printf("+ Rows:\t\t[%d].\n", matrix_rows);
		printf("+ Columns:\t[%d].\n", matrix_columns);
		printf("+ Address:\t<%p : %p>.\n\n", (void *) &matrix, (void *) matrix);

		/* Travel cycle for rows. */
		for (int current_row = V_ZERO; current_row < matrix_rows; current_row++)
			{
				printf("* Row #: [%d].\n", current_row);
				printf("<%p : %p : %p : %p>.\n", (void *) (matrix + current_row), (void *) matrix[current_row], (void *) &matrix[current_row], (void *) *(matrix + current_row));

				/* Travel cycle for columns. */
				for (int current_column = V_ZERO; current_column < matrix_columns; current_column++)
					{
						printf("# [%d]. <%p : %p : %p>. (%d, %d) = {%d} : {%d} : {%d} : {%d}.\n",
							counter++,
							(void *) (matrix[current_row] + current_column),
							(void *) &matrix[current_row][current_column],
							(void *) (*(matrix + current_row) + current_column),
							current_row,
							current_column,
							*(matrix[current_row] + current_column),
							matrix[current_row][current_column],
							(*(matrix + current_row))[current_column],
							*(*(matrix + current_row) + current_column));
					}

				printf("\n");
			}
		printf("[%d] Output generated results.\n", counter);

		/* Returns the number of processed elements. */
		return counter;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int counter = V_ZERO;

		/* Fixed two-dimensional primary matrix. */
		int matrix_a[V_THREE][V_THREE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		const int matrix_a_rows = sizeof(matrix_a) / sizeof(*matrix_a);
		const int matrix_a_columns = sizeof(*matrix_a) / sizeof(**matrix_a);

		/* Fixed two-dimensional second matrix. */
		int matrix_b[V_THREE][V_THREE] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
		const int matrix_b_rows = sizeof(matrix_b) / sizeof(*matrix_b);
		const int matrix_b_columns = sizeof(*matrix_b) / sizeof(**matrix_b);

		/* Fixed two-dimensional outcome matrix. */
		int matrix_result[V_THREE][V_THREE] = {{V_ZERO, V_ZERO, V_ZERO}, {V_ZERO, V_ZERO, V_ZERO}, {V_ZERO, V_ZERO, V_ZERO}};
		const int matrix_result_rows = sizeof(matrix_result) / sizeof(*matrix_result);
		const int matrix_result_columns = sizeof(*matrix_result) / sizeof(**matrix_result);

		/* Initial header message. */
		printf("Addition of fixed two-dimensional matrices.\n");

		/* Visualize the first two-dimensional array with its memory addresses. */
		counter = viewMatrix(matrix_a, matrix_a_rows, matrix_a_columns);
		printf("[%d] Records retrieved.\n", counter);
		getPause("Press the ENTER key to continue...");

		/* Visualize the second two-dimensional array with its memory addresses. */
		counter = viewMatrix(matrix_b, matrix_b_rows, matrix_b_columns);
		printf("[%d] Records retrieved.\n", counter);
		getPause("Press the ENTER key to continue...");

		/* Call to the function that adds two fixed two-dimensional matrices. */
		counter = sumOfMatrices(matrix_a, matrix_a_rows, matrix_a_columns, matrix_b, matrix_b_rows, matrix_b_columns, matrix_result, matrix_result_rows, matrix_result_columns);
		printf("\n[%d] Records processed.\n", counter);
		getPause("Press the ENTER key to continue...");

		/* Visualize the summed result matrix. */
		counter = viewMatrix(matrix_result, matrix_result_rows, matrix_result_columns);
		printf("[%d] Records retrieved.\n", counter);
		getPause("Press the ENTER key to continue...");

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");
		getPause("Press the ENTER key to continue...");

		return V_ZERO;
	}
