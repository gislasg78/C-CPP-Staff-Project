#include <stdio.h>
#include <stdlib.h>

#define V_ONE	1
#define	V_ZERO	0

int main()
	{
		/* Three, two and one dimension dynamic pointers. */
		int ***matrix = NULL;
		int **matrix_rxc = NULL;
		int *matrix_r = NULL;

		int n_matrix = V_ZERO;	//Number of dynamic matrices to generate.

		printf("Highly dynamic pointer generator.\n");
		printf("How many rectangular arrangements do you want to create? : ");
		scanf("%d", &n_matrix);

		/* The initial space is first allocated for the number of two-dimensional arrays to be stored. */
		matrix = (int ***) malloc (n_matrix * sizeof(int **));
		matrix_rxc = (int **) malloc (n_matrix * sizeof(int *));
		matrix_r = (int *) malloc (n_matrix * sizeof(int));

		/* General loading cycles of dynamic pointer pointers. */
		printf("\n");
		for (int m = V_ZERO; m < n_matrix; m++)
			{
				printf("For the matrix #[%d] of [%d].\n", m + V_ONE, n_matrix);
				printf("How many lines will it generate for it? : ");
				scanf("%d", &matrix_r[m]);

				/* Dynamic memory is allocated for each matrix to know the number of rows it will have. */
				matrix[m] = (int **) malloc (matrix_r[m] * sizeof (int *));
				matrix_rxc[m] = (int *) malloc (matrix_r[m] * sizeof (int));

				for (int r = V_ZERO; r < matrix_r[m]; r++)
					{
						printf("For the matrix #[%d] of [%d], and its row #[%d] of [%d].\n", m + V_ONE, n_matrix, r + V_ONE, matrix_r[m]);
						printf("How many columns will it generate for it and its respective row? : ");
						scanf("%d", &matrix_rxc[m][r]);

						/* Dynamic memory is allocated for each row of the matrix in concurrent turn to know the number of columns it will have. */
						matrix[m][r] = (int *) malloc (matrix_rxc[m][r] * sizeof(int));

						for (int c = V_ZERO; c < matrix_rxc[m][r]; c++)
							{
								printf("Enter a value for Matrix #[%d] of [%d] -> (Row: [%d] of [%d], Column: [%d] of [%d]) : ", m + V_ONE, n_matrix, r + V_ONE, matrix_r[m], c + V_ONE, matrix_rxc[m][r]);
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

				for (int r = V_ZERO; r < matrix_r[m]; r++)
					{
						printf("\tRow: [%d] of [%d].\n", r + V_ONE, matrix_r[m]);

						for (int c = V_ZERO; c < matrix_rxc[m][r]; c++)
							{
								printf("\t\tColumn: [%d] of [%d].\t", c + V_ONE, matrix_rxc[m][r]);
								printf("Value: [%d].\n", matrix[m][r][c]);
							}

						printf("\n");
					}

				printf("\n");
			}


		printf("Freeing the memory of all dynamically allocated pointers...\n");
		for (int m = V_ZERO; m < n_matrix; m++)
			{
				for (int r = V_ZERO; r < matrix_r[m]; r++)
					{
						free(matrix[m][r]);
					}

				free(matrix[m]);
				free(matrix_rxc[m]);
			}
		free(matrix_rxc);
		free(matrix_r);
		free(matrix);

		printf("\n[%s].\n", "End of the assigment!");

		return V_ZERO;
	}
