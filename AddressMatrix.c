/* This program dumps the values ​​and accesses
   the memory addresses of a simple two-dimensional array. */

/* Standard Work Libraries. */
#include <stdio.h>

/* Symbolic numerical constants. */
#define V_THREE 3
#define V_ZERO  0

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int counter = V_ZERO;
		int matrix[V_THREE][V_THREE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		const int num_rows = sizeof(matrix) / sizeof(*matrix);
		const int num_cols = sizeof(*matrix) / sizeof(**matrix);

		/* Visualization of the fixed num_rows x num_cols matrix. */
		printf("Dump of matrix.\n");
		printf("Rows: [%d]. Columns: [%d].\n", num_rows, num_cols);
		printf("<%p>.\n\n", (void *) matrix);

		/* Travel cycle. */
		for (int r = V_ZERO; r < num_rows; r++)
			{
				printf("<%p>.\n", (void *) *(matrix + r));

				for (int c = V_ZERO; c < num_cols; c++)
					{
						printf("# [%d]. <%p> : (%d, %d) = {%d}.\n", counter++, (void *) &matrix[r][c], r, c, *(*(matrix + r) + c));
					}

				printf("\n");
			}
		printf("[%d] Output generated results.\n", counter);

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");

		return V_ZERO;
	}
