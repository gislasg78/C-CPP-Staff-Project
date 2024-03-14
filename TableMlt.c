#include <stdio.h>
#include <stdlib.h>

#define V_ONE	1
#define	V_ZERO	0

int main()
	{
		/* Three, two and one dimension dynamic pointers. */
		int ***matrix = NULL;
		int **matrixbyrowsbycols = NULL;
		int *matrixbyrows = NULL;

		int n_matrix = V_ZERO;	//Number of dynamic matrices to generate.
		int n_rows = V_ZERO;
		int n_cols = V_ZERO;

		printf("Highly dynamic pointer generator.\n");
		printf("How many rectangular arrangements do you want to create? : ");
		scanf("%d", &n_matrix);

		/* The initial space is first allocated for the number of two-dimensional arrays to be stored. */
		matrixbyrows = (int *) malloc (n_matrix * sizeof(int));
		matrixbyrowsbycols = (int **) malloc (n_matrix * sizeof(int *));
		matrix = (int ***) malloc (n_matrix * sizeof(int **));

		/* General loading cycles of dynamic pointer pointers. */
		printf("\n");
		for (int m = V_ZERO; m < n_matrix; m++)
			{
				printf("For the matrix #[%d] of [%d].\n", m + V_ONE, n_matrix);
				printf("How many lines will it generate for it? : ");
				scanf("%d", &n_rows);

				/* Dynamic memory is allocated for each matrix to know the number of rows it will have. */
				matrixbyrowsbycols[m] = (int *) malloc (n_rows * sizeof (int));
				matrixbyrows[m] = n_rows;
				matrix[m] = (int **) malloc (n_rows * sizeof (int *));

				for (int r = V_ZERO; r < matrixbyrows[m]; r++)
					{
						printf("For the matrix #[%d] of [%d], and its row #[%d] of [%d].\n", m + V_ONE, n_matrix, r + V_ONE, n_rows);
						printf("How many columns will it generate for it and its respective row? : ");
						scanf("%d", &n_cols);

						/* Dynamic memory is allocated for each row of the matrix in concurrent turn to know the number of columns it will have. */
						matrix[m][r] = (int *) malloc (n_cols * sizeof(int));
						matrixbyrowsbycols[m][r] = n_cols;

						for (int c = V_ZERO; c < matrixbyrowsbycols[m][r]; c++)
							{
								printf("Enter a value for Matrix #[%d] of [%d] -> (Row: [%d] of [%d], Column: [%d] of [%d]) : ", m + V_ONE, n_matrix, r + V_ONE, n_rows, c+1, n_cols);
								scanf("%d", &matrix[m][r][c]);
							}

						printf("\n");
					}

				printf("\n");
			}

		printf("\n");
		printf("Dump values of all dynamic pointers...\n");
		for (int m = V_ZERO; m < n_matrix; m++)
			{
				printf("Matrix: [%d] of [%d].\n", m + V_ONE, n_matrix);

				for (int r = V_ZERO; r < matrixbyrows[m]; r++)
					{
						printf("\tRow: [%d] of [%d].\n", r + V_ONE, matrixbyrows[m]);

						for (int c = V_ZERO; c < matrixbyrowsbycols[m][r]; c++)
							{
								printf("\t\tColumn: [%d] of [%d].\t", c + V_ONE, matrixbyrowsbycols[m][r]);
								printf("Value: [%d].\n", matrix[m][r][c]);
							}

						printf("\n");
					}

				printf("\n");
			}

		printf("Freeing the memory of all dynamically allocated pointers...\n");
		for (int m = V_ZERO; m < n_matrix; m++)
			{
				for (int r = V_ZERO; r < matrixbyrows[m]; r++)
					{
						free(matrix[m][r]);
					}

				free(matrix[m]);
				free(matrixbyrowsbycols[m]);
			}
		free(matrixbyrowsbycols);
		free(matrixbyrows);
		free(matrix);

		printf("\n[%s].\n", "End of the assigment!");

		return V_ZERO;
	}
