#include <stdio.h>
#include <stdlib.h>

#define	V_ONE	1
#define	V_ZERO	0

int int_capture_matrix(int **int_matrix, const int int_rows, const int int_cols)
	{
		int int_captured_items = V_ZERO;

		if (int_matrix)
			{
				printf("Capture of the created and assigned matrix...\n");

				for (int int_row = V_ZERO; int_row < int_rows; int_row++)
					{
						if (int_matrix[int_row])
							{
								for (int int_col = V_ZERO; int_col < int_cols; int_col++)
									{
										int_captured_items++;
										printf("Enter a value #[%d]: (Row: [%d] of [%d], Column: [%d] of [%d]) : ", int_captured_items, int_row + V_ONE, int_rows, int_col + V_ONE, int_cols);
										scanf("%d", &int_matrix[int_row][int_col]);
									}

								printf("\n");
							}
						else
							{
								perror("There is no memory space allocated to hold a row of the matrix...");
								exit(EXIT_FAILURE);
							}
					}
			}
		else
			{
				perror("Empty array or not generated correctly to be captured...");
				exit(EXIT_FAILURE);
			}

		printf("[%d] Captured output elements...\n", int_captured_items);

		return int_captured_items;
	}


int **int_create_matrix(const int int_rows, const int int_cols)
	{
		int int_captured_items = V_ZERO;
		int **int_matrix = NULL;

		printf("Direct creation and initialization of an array...\n");

		if ((int_matrix = (int **) calloc(int_rows, sizeof(int *))))
			{
				for (int int_row = V_ZERO; int_row < int_rows; int_row++)
					{
						if ((int_matrix[int_row] = (int *) calloc(int_cols, sizeof(int))))
							{
								int_captured_items++;
							}
						else
							{
								perror("Insufficient memory space to create matrix column...");
								exit(EXIT_FAILURE);
							}
					}
			}
		else
			{
				perror("Insufficient memory space to create array...");
				exit(EXIT_FAILURE);
			}

		printf("[%d] Output results generated...\n", int_captured_items);

		return int_matrix;
	}

int int_deallocate_matrix(int **int_matrix, const int int_rows)
	{
		int int_deallocated_items = V_ZERO;

		if (int_matrix)
			{
				printf("Deallocating rows from a dynamically created array...\n");

				for (int int_row = V_ZERO; int_row < int_rows; int_row++)
					{
						if (int_matrix[int_row])
							{
								int_deallocated_items++;
								printf("Freeing memory in row [%d] of [%d] from allocated array...\n", int_row + V_ONE, int_rows);
								free(int_matrix[int_row]);
							}
						else
							{
								perror("Cannot deallocate a row from the array...");
								exit(EXIT_FAILURE);
							}
					}

				printf("Memory completely freed from allocated array...\n");
				free(int_matrix);
			}
		else
			{
				perror("Cannot deallocate memory from array...");
				exit(EXIT_FAILURE);
			}

		printf("[%d] Freed rows of memory from the allocated array...\n", int_deallocated_items);

		return int_deallocated_items;
	}

int **int_matrix_product(int **int_f_matrix, int **int_s_matrix, const int int_f_rows, const int int_f_cols, const int int_s_rows, const int int_s_cols, int *int_max_rows, int *int_max_cols)
	{
		int **int_matrix_prod = NULL;

		*int_max_rows = int_f_rows;
		*int_max_cols = int_s_cols;

		printf("Creation and initialization of the matrix that will serve as the product of the two matrices...\n");

		if (int_matrix_prod = int_create_matrix(*int_max_rows, *int_max_cols))
			{
				printf("The product matrix element is obtained by multiplying each element of the matrix row by each element of the matrix column and summing them...\n");

				for (int int_f_row = V_ZERO; int_f_row < int_f_rows; int_f_row++)
					{
						for (int int_s_col = V_ZERO; int_s_col < int_s_cols; int_s_col++)
							{
								for (int int_f_col = V_ZERO; int_f_col < int_f_cols; int_f_col++)
									{
										int_matrix_prod[int_f_row][int_s_col] += int_f_matrix[int_f_row][int_f_col] * int_s_matrix[int_f_col][int_s_col];
										printf("i=[%d],j=[%d],k=[%d]:\t{(i=[%d], k=[%d])=[%d], (k=[%d],j=[%d]) = [%d]} = [%d]:\t[%d].\n", int_f_row, int_s_col, int_f_col, int_f_row, int_f_col, int_f_matrix[int_f_row][int_f_col], int_f_col, int_s_col, int_s_matrix[int_f_col][int_s_col], int_f_matrix[int_f_row][int_f_col] * int_s_matrix[int_f_col][int_s_col], int_matrix_prod[int_f_row][int_s_col]);
									}

								printf("\n");
							}

						printf("\n");
					}
			}
		else
			perror("There is not enough space in memory to allocate a matrix product array...");

		return int_matrix_prod;
	}

int int_view_matrix(int **int_matrix, const int int_rows, const int int_cols)
	{
		int int_captured_items = V_ZERO;

		if (int_matrix)
			{
				printf("Visualization of the captured matrix...\n");

				for (int int_row = V_ZERO; int_row < int_rows; int_row++)
					{
						if (int_matrix[int_row])
							{
								for (int int_col = V_ZERO; int_col < int_cols; int_col++)
									{
										int_captured_items++;
										printf("Item #[%d]:\tRow:\t[%d] of [%d].\tColumn:\t[%d] of [%d].\tValue:\t[%d].\n", int_captured_items, int_row + V_ONE, int_rows, int_col + V_ONE, int_cols, int_matrix[int_row][int_col]);
									}

								printf("\n");
							}
						else
							{
								perror("Array row empty or not generated correctly...");
								exit(EXIT_FAILURE);
							}
					}

				printf("[%d] Output results generated...\n", int_captured_items);
			}
		else
			{
				perror("Empty array or not generated correctly...");
				exit(EXIT_FAILURE);
			}

		return int_captured_items;
	}


int main()
	{
		int int_f_captured_items = V_ZERO, int_s_captured_items = V_ZERO;

		int int_f_cols = V_ZERO, int_f_rows = V_ZERO;
		int int_s_cols = V_ZERO, int_s_rows = V_ZERO;

		int **int_f_matrix = NULL;
		int **int_s_matrix = NULL;

		int **int_matrix_prod = NULL;
		int int_max_cols = V_ZERO;
		int int_max_rows = V_ZERO;


		printf("Program to perform the product of two rectangular matrices.\n");

		printf("\n");
		printf("Number of rows in the first matrix: ");
		scanf("%d", &int_f_rows);
		printf("Number of columns in the first matrix: ");
		scanf("%d", &int_f_cols);

		int_f_matrix = int_create_matrix(int_f_rows, int_f_cols);
		int_f_captured_items = int_capture_matrix(int_f_matrix, int_f_rows, int_f_cols);
		int_f_captured_items = int_view_matrix(int_f_matrix, int_f_rows, int_f_cols);


		printf("\n");
		printf("Number of rows in the second matrix: ");
		scanf("%d", &int_s_rows);
		printf("Number of columns in the second matrix: ");
		scanf("%d", &int_s_cols);

		int_s_matrix = int_create_matrix(int_s_rows, int_s_cols);
		int_s_captured_items = int_capture_matrix(int_s_matrix, int_s_rows, int_s_cols);
		int_s_captured_items = int_view_matrix(int_s_matrix, int_s_rows, int_s_cols);


		int_matrix_prod = int_matrix_product(int_f_matrix, int_s_matrix, int_f_rows, int_f_cols, int_s_rows, int_s_cols, &int_max_rows, &int_max_cols);

		printf("\n");
		printf("The complete product matrix is ​​displayed...\n");
		int_view_matrix(int_matrix_prod, int_max_rows, int_max_cols);


		printf("\n");
		printf("Evicting arrays from allocated memory areas...\n");
		int_deallocate_matrix(int_f_matrix, int_f_rows);
		int_deallocate_matrix(int_s_matrix, int_s_rows);
		int_deallocate_matrix(int_matrix_prod, int_max_rows);

		return EXIT_SUCCESS;
	}
