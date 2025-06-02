/* Program that dynamically allocates memory in C
   to store a series of given matrices,
   each with a variable number of rows,
   and each of its respective rows with a variable number of columns.*/

/* Standard work libraries. */
#include <stdio.h>
#include <stdlib.h>

/* Symbolic work constants. */
#define	V_ONE	1
#define	V_ZERO	0

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int items = V_ZERO;

		/* Three, two and one dimension dynamic pointers. */
		int ***matrix = NULL;
		int **matrix_rxc = NULL;
		int *matrix_r = NULL;

		int n_matrix = V_ZERO;	//Number of dynamic matrices to generate.

		/* Header messages. */
		printf("Highly dynamic pointer generator.\n");
		printf("How many rectangular arrangements do you want to create? : ");
		scanf("%d", &n_matrix);

		printf("\nMemory assigning spaces...\n");

		/* The initial space is first allocated for the number of two-dimensional arrays to be stored. */
		matrix = (int ***) malloc (n_matrix * sizeof(int **));		//Space is generated for the first dimension of a three-dimensional array.
		matrix_rxc = (int **) malloc (n_matrix * sizeof(int *));	//Space is generated for the first dimension of a two-dimensional array.
		matrix_r = (int *) malloc (n_matrix * sizeof(int));		//Space is generated for the only dimension of a one-dimensional array.

		/* General loading cycles of dynamic pointer pointers. */
		printf("\nCapturing values...\n");

		/* Dynamic memory is allocated to know the number of matrices to be generated. */
		for (int m = V_ZERO; m < n_matrix; m++)		//Cycle by matrix.
			{
				printf("For the matrix #: [%d] of [%d].\n", m + V_ONE, n_matrix);
				printf("How many lines will it generate for it? : ");
				scanf("%d", &matrix_r[m]);	//Number of matrices to store.

				/* Dynamic memory is allocated for each matrix to know the number of rows it will have. */
				matrix[m] = (int **) malloc (matrix_r[m] * sizeof(int *));	//Number of rows for each matrix.
				matrix_rxc[m] = (int *) malloc (matrix_r[m] * sizeof(int));

				for (int r = V_ZERO; r < matrix_r[m]; r++)	//Cycle through each row of each matrix.
					{
						printf("For the matrix #: [%d] of [%d], and its row #: [%d] of [%d].\n", m + V_ONE, n_matrix, r + V_ONE, matrix_r[m]);
						printf("How many columns will it generate for it and its respective row? : ");
						scanf("%d", &matrix_rxc[m][r]);	//Number of rows for each matrix created.

						/* Dynamic memory is allocated for each row of the matrix in concurrent turn to know the number of columns it will have. */
						matrix[m][r] = (int *) malloc (matrix_rxc[m][r] * sizeof(int));	//Number of columns per row of each matrix.

						for (int c = V_ZERO; c < matrix_rxc[m][r]; c++)	//Cycle through each column of each row of each matrix.
							{
								printf("Enter a value #: %d for Matrix #: [%d] of [%d] -> (Row: [%d] of [%d], Column: [%d] of [%d]) : ", items++, m + V_ONE, n_matrix, r + V_ONE, matrix_r[m], c + V_ONE, matrix_rxc[m][r]);
								scanf("%d", &matrix[m][r][c]);	//Value according to number of column per row of each matrix created.

								printf("(Matrix: [%d] of [%d], Row: [%d] of [%d], Column: [%d] of [%d]) = [%d].\n", m + V_ONE, n_matrix, r + V_ONE, matrix_r[m], c + V_ONE, matrix_rxc[m][r], matrix[m][r][c]);
							}

						printf("\n");
					}

				printf("\n");
			}
		printf("[%d] Captured input values.\n", items);

		/* Process of dumping each column, each row, each matrix. */
		printf("Displaying captured values...\n");

		/* Dump of each matrix. */
		for (int m = V_ZERO; m < n_matrix; m++)
			{
				printf("Matrix: [%d] of [%d].\n", m + V_ONE, n_matrix);

				/* Dump of each row of each matrix. */
				for (int r = V_ZERO; r < *(matrix_r + m); r++)
					{
						printf("\tRow: [%d] of [%d].\n", r + V_ONE, *(matrix_r + m));

						/* Dump of each column of each row of each matrix. */
						for (int c = V_ZERO; c < *(*(matrix_rxc + m) + r); c++)
							{
								printf("\t\tColumn: [%d] of [%d].\t", c + V_ONE, *(*(matrix_rxc + m) + r));
								printf("(%d, %d, %d) = [%d].\n", m + V_ONE, r + V_ONE, c + V_ONE, matrix[m][r][c]);
							}

						printf("\n");
					}

				printf("\n");
			}
		printf("[%d] Generated output results.\n", items);

		/* The allocated memory is freed from each allocated row of each created array. */
		printf("Freeing the memory of all dynamically allocated pointers...\n");

		/* Freeing each memory space allocated to each array. */
		for (int m = V_ZERO; m < n_matrix; m++)
			{
				printf("Deallocating memory for array #: [%d] of [%d].\n", m + V_ONE, n_matrix);

				/* Freeing each memory space allocated to each row of each matrix. */
				for (int r = V_ZERO; r < matrix_r[m]; r++)
					{
						printf("\tDeallocating memory for its row #: [%d] of [%d].\n", r + V_ONE, matrix_r[m]);

						free(matrix[m][r]);	//Deallocate each row of each matrix.
					}

				free(matrix[m]);	//Deallocate each array.
				free(matrix_rxc[m]);

				printf("\n");
			}

		/* Higher-order pointers are deallocated. */
		printf("Evicting main memory addresses...\n");

		free(matrix_rxc);
		free(matrix_r);
		free(matrix);

		/* Program closure notice. */
		printf("[End of the assigment!].\n");

		return V_ZERO;
	}
