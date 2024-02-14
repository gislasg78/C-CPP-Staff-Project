#include <stdio.h>

#define	V_ZERO			0

#define V_LOWER_LIMIT_COLS	0
#define V_LOWER_LIMIT_ROWS	0
#define V_UPPER_LIMIT_COLS	10
#define V_UPPER_LIMIT_ROWS	10

static int int_matrix[V_UPPER_LIMIT_ROWS][V_UPPER_LIMIT_COLS];

int main()
	{
		int int_counting_items = V_ZERO;

		int int_Columns = V_ZERO;
		int int_Rows = V_ZERO;

		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+  Dumping fixed dimensions arrays. +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Rows    from [%d] to [%d] : ", V_LOWER_LIMIT_ROWS, V_UPPER_LIMIT_ROWS);
		scanf("%d", &int_Rows);
		printf("Columns from [%d] to [%d] : ", V_LOWER_LIMIT_COLS, V_UPPER_LIMIT_ROWS);
		scanf("%d", &int_Columns);

		if (int_Rows >= V_LOWER_LIMIT_ROWS && int_Rows <= V_UPPER_LIMIT_ROWS)
			if (int_Columns >= V_LOWER_LIMIT_COLS && int_Columns <= V_UPPER_LIMIT_COLS)
				{

					printf("\n");
					printf("+---|----+---|----+---|----+---|----+\n");
					printf("|      Obtained output results.     +\n");
					printf("+---|----+---|----+---|----+---|----+\n");
					printf("Capturing matrix...\n");
					for (int int_row = V_LOWER_LIMIT_ROWS; int_row < int_Rows; int_row++)
						for (int int_col = V_LOWER_LIMIT_COLS; int_col < int_Columns; int_col++)
							{
								printf("Enter data (Row: [%02d], Column: [%02d]) : ", int_row, int_col);
								scanf("%d", *(int_matrix + int_row) + int_col);
							}

					printf("\n");
					printf("Memory address breakdown that starts at [%p] with [%ld] bytes...\n", int_matrix, sizeof(int_matrix));
					for (int int_row = V_LOWER_LIMIT_ROWS; int_row < int_Rows; int_row++)
						for (int int_col = V_LOWER_LIMIT_COLS; int_col < int_Columns; int_col++)
							{
								printf("# [%03d]\t(Row: [%02d], Column: [%02d]).\t[%p] : [%p] : [%p].\t[%d] = [%d].\n",
									int_counting_items++, int_row, int_col,
									*(int_matrix+int_row) + int_col, int_matrix[int_row] + int_col, &int_matrix[int_row][int_col],
									*(*(int_matrix + int_row) + int_col), int_matrix[int_row][int_col]);
							}
					printf("[%d] Generated output results.\n", int_counting_items);

					printf("\n");
					printf("Original matrix...\n");
					for (int int_y = V_LOWER_LIMIT_ROWS; int_y < int_Rows; int_y++)
						{
							for (int int_x = V_LOWER_LIMIT_COLS; int_x < int_Columns; int_x++)
								printf("[%3.d]\t", int_matrix[int_y][int_x]);

							printf("\n");
						}

					printf("\n");
					printf("Transposed matrix...\n");
					for (int int_y = V_LOWER_LIMIT_ROWS; int_y < int_Rows; int_y++)
						{
							for (int int_x = V_LOWER_LIMIT_COLS; int_x < int_Columns; int_x++)
								printf("[%3.d]\t", int_matrix[int_x][int_y]);

							printf("\n");
						}
				}
			else
				printf("Mistake! The value for column: [%d] is not in the range [%d] to [%d]\n.", int_Columns, V_LOWER_LIMIT_COLS, V_UPPER_LIMIT_COLS);
		else
			printf("Mistake! The value for row: [%d] is not in the range [%d] to [%d]\n.", int_Rows, V_LOWER_LIMIT_ROWS, V_UPPER_LIMIT_ROWS);

		return V_ZERO;
	}
