/**  Program that performs the product of two dynamic matrices. **
 ** Source Code:        Matprod.c				**
 ** Author:             Gustavo Islas Gálvez.                   **
 ** Creation Date:      Saturday, November 30, 2024.            **
 ** Purpose:		The main purpose of this program is to	**
 **			perform the product of two dynamically  **
 **			created rectangular matrices, such that **
 **			each matrix can have a variable number	**
 **			of rows and each of its respective rows **
 **			a variable number of columns, which then**
 **			store a variable number of integer	**
 **			values.					**
 **								**
 **			+---|----+---|----+---|----+---|----+	**
 **			| Definition of the matrix product. |	**
 **			+---|----+---|----+---|----+---|----+	**
 **			Given two matrices 'A' and 'B' of	**
 **			dimensions 'm' by 'n' and 'n' by 'p'	**
 **			respectively, their product 'A' by 'B'	**
 **			is defined as the matrix of dimension	**
 **			'm' by 'p' such that the element at	**
 **			position row 'i' and column 'j' is the	**
 **			result of the product of the vectors	**
 **			row 'i' of 'A' and column 'j' of 'B'.	**
 **								**
 **			Suppose we have the following		**
 **			two-dimensional arrays:			**
 **								**
 **			'A' = {{2, 0, 1}, {3, 0, 0}, {5. 1. 1}}.**
 **			'B' = {{1, 0, 1}. {1. 2. 1}. {1, 1, 0}}.**
 **								**
 **			The multiplication of both		**
 **			two-dimensional matrices would be as	**
 **			follows:				**
 **								**
 **			'A' by 'B' =				**
 **				{				**
 **					[2*1 + 0*1 + 1*1] = 3,	**
 **				 	[2*0 + 0*2 + 1*1] = 1,	**
 **				 	[2*1 + 0*1 + 1*0] = 2;	**
 **								**
 **				 	[3*1 + 0*1 + 0*1] = 3,	**
 **				 	[3*0 + 0*2 + 0*1] = 0,	**
 **				 	[3*1 + 0*1 + 0*0] = 3;	**
 **								**
 **				 	[5*1 + 1*1 + 1*1] = 7,	**
 **				 	[5*0 + 1*2 + 1*1] = 3,	**
 **				 	[5*1 + 1*1 + 1*0] = 6	**
 **				}.				**
 **								**
 **			From the above, the product resulting	**
 **			from 'A' by 'B'.			**
 **								**
 **			'A' * 'B' =				**
 **				{				**
 **					[3. 1. 2];		**
 **					[3, 0, 3];		**
 **					[7, 3, 6]		**
 **				}.				**
 ****************************************************************/
//C Standard Libraries.
#include <stdio.h>
#include <stdlib.h>

//C Standard Constants.
#define	V_ONE	1
#define	V_THREE	3
#define	V_TWO	2
#define	V_ZERO	0

/*****************************************************************
 ** Function:		int int_capture_matrix			**
 **				(int **int_matrix,		**
 **				 const int int_rows,		**
 **				 const int int_cols).		**
 ** Explanation:	This function is responsible for	**
 **			capturing element by element the	**
 **			entries that a two-dimensional matrix	**
 **			has dynamically created according to a	**
 **			variable number of rows and each row	**
 **			with a variable number of columns.	**
 ** Input Parms:	int **int_matrix.			**
 **			const int int_rows.			**
 **			const int int_cols.			**
 ** Output Parms:	int **int_matrix.			**
 ** Result:		This function returns the values	**
 **			captured in the dynamically created	**
 **			array and the number of elements that	**
 **			were stored in it.			**
 ****************************************************************/
int int_capture_matrix(int **int_matrix, const int int_rows, const int int_cols)
	{
		int int_captured_items = V_ZERO;

		if (int_matrix)
			{
				printf("\n");
				printf("+---|----+---|----+---|----+---|----+---|----+\n");
				printf("|Capture a dynamic array element by element. |\n");
				printf("+---|----+---|----+---|----+---|----+---|----+\n");
				printf("| Rows: [%d].\tColumns: [%d].\n", int_rows, int_cols);
				printf("+---|----+---|----+---|----+---|----+---|----+\n");

				for (int int_row = V_ZERO; int_row < int_rows; int_row++)
					{
						if (int_matrix[int_row])
							{
								for (int int_col = V_ZERO; int_col < int_cols; int_col++)
									{
										int_captured_items++;

										printf("Enter a value #[%d].\t(Row: [%d] of [%d],\tColumn: [%d] of [%d]) : ", int_captured_items, int_row + V_ONE, int_rows, int_col + V_ONE, int_cols);
										scanf("%d", &int_matrix[int_row][int_col]);

										printf("Item #[%d]:\t(Row:\t[%d] of [%d],\tColumn:\t[%d] of [%d].\tValue:\t[%d]).\n", int_captured_items, int_row + V_ONE, int_rows, int_col + V_ONE, int_cols, int_matrix[int_row][int_col]);
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

		printf("[%d] Captured input elements...\n", int_captured_items);

		return int_captured_items;
	}

/*****************************************************************
 ** Function:           int **int_create_matrix			**
 **				(const int int_rows,		**
 **				 const int int_cols).		**
 ** Explanation:	The purpose of this function is to	**
 **			create a two-dimensional matrix with a	**
 **			variable number of rows and each row	**
 **			with a variable number of columns and	**
 **			with its proper initialization for each	**
 **			occurrence.				**
 ** Input Parms:	const int int_rows.                     **
 **                     const int int_cols.                     **
 ** Output Parms:	None.					**
 ** Result:		This function returns a pointer of	**
 **			pointers with the space assigned to the **
 **			number of rows and the number of columns**
 **			individualized for each column of a	**
 **			two-dimensional dynamic array.		**
 ****************************************************************/
int **int_create_matrix(const int int_rows, const int int_cols)
	{
		int int_created_items = V_ZERO;
		int **int_matrix = NULL;

		printf("\n");
		printf("+---|----+---|----+---|----+---|----+---|----+\n");
		printf("|  Creation and initialization of an array.  |\n");
		printf("+---|----+---|----+---|----+---|----+---|----+\n");
		printf("| Rows: [%d].\tColumns: [%d].\n", int_rows, int_cols);
		printf("+---|----+---|----+---|----+---|----+---|----+\n");

		if ((int_matrix = (int **) calloc(int_rows, sizeof(int *))))
			{
				for (int int_row = V_ZERO; int_row < int_rows; int_row++)
					{
						if ((int_matrix[int_row] = (int *) calloc(int_cols, sizeof(int))))
							{
								int_created_items++;
							}
						else
							{
								perror("Insufficient memory space to create matrix row...");
								exit(EXIT_FAILURE);
							}
					}
			}
		else
			{
				perror("Insufficient memory space to create array...");
				exit(EXIT_FAILURE);
			}

		printf("[%d] Lines generated for the dynamic matrix...\n", int_created_items);

		return int_matrix;
	}

/*****************************************************************
 ** Function:           int **int_deallocate_matrix		**
 **                             (int **int_matrix,		**
 **                              const int int_rows).           **
 ** Explanation:	This function is used to deallocate the	**
 **			memory in which a dynamic		**
 **			two-dimensional array was stored,	**
 **			first by evicting each row of it and	**
 **			then the main pointer.			**
 ** Input Parms:        const int int_rows.			**
 ** Output Parms:       int **int_matrix.			**
 ** Result:		This function returns the number of	**
 **			rows deallocated from the dynamic array	**
 **			and the eviction of the memory occupied **
 **			by its pointer of pointers from said	**
 **			dynamic array.				**
 ****************************************************************/
int int_deallocate_matrix(int **int_matrix, const int int_rows)
	{
		int int_deallocated_items = V_ZERO;

		if (int_matrix)
			{
				printf("\n");
				printf("+---|----+---|----+---|----+---|----+---|----+\n");
				printf("|  Deallocating a dynamically created array. |\n");
				printf("+---|----+---|----+---|----+---|----+---|----+\n");
				printf("| Rows: [%d].\n", int_rows);
				printf("+---|----+---|----+---|----+---|----+---|----+\n");

				for (int int_row = V_ZERO; int_row < int_rows; int_row++)
					{
						if (int_matrix[int_row])
							{
								int_deallocated_items++;
								printf("Freeing memory in row:\t[%d] of [%d]\tfrom allocated array...\n", int_row + V_ONE, int_rows);
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

		printf("[%d] Lines unallocated for the dynamic array...\n", int_deallocated_items);

		return int_deallocated_items;
	}

/*****************************************************************
 ** Function:           int **int_matrix_product		**
 ** 				(int **int_f_matrix,		**
 ** 				 int **int_s_matrix,		**
 **				 const int int_f_rows,		**
 **				 const int int_f_cols,		**
 ** 				 const int int_s_rows,		**
 ** 				 const int int_s_cols,		**
 ** 				 int *int_max_rows,		**
 ** 				 int *int_max_cols).		**
 ** Explanation:	The product matrix element is obtained	**
 **			by multiplying each element of the	**
 **			matrix row by each element of the	**
 **			matrix column and summing them.		**
 ** Input Parms:	int **int_f_matrix.			**
 ** 			int **int_s_matrix.			**
 ** 			const int int_f_rows.			**
 ** 			const int int_f_cols.			**
 ** 			const int int_s_rows.			**
 ** 			const int int_s_cols.			**
 ** 			int *int_max_rows.			**
 ** 			int *int_max_cols).			**
 ** Output Parms:       int **int_f_matrix.			**
 **			int **int_s_matrix.			**
 **			int *int_max_rows.			**
 **			int *int_max_cols.			**
 ** Result:		Creation and initialization of the	**
 **			matrix that will serve as the product	**
 **			of the two matrices.			**
 **								**
 **			Given two matrices 'A' and 'B' of       **
 **                     dimensions 'm' by 'n' and 'n' by 'p'    **
 **                     respectively, their product 'A' by 'B'  **
 **                     is defined as the matrix of dimension   **
 **                     'm' by 'p' such that the element at     **
 **                     position row 'i' and column 'j' is the  **
 **                     result of the product of the vectors    **
 **                     row 'i' of 'A' and column 'j' of 'B'.	**
 ****************************************************************/
int **int_matrix_product(int **int_f_matrix, int **int_s_matrix, const int int_f_rows, const int int_f_cols, const int int_s_rows, const int int_s_cols, int *int_max_rows, int *int_max_cols)
	{
		int **int_matrix_prod = NULL;

		*int_max_rows = (int_f_rows > int_s_rows) ? int_f_rows : int_s_rows;
		*int_max_cols = (int_f_cols > int_s_cols) ? int_f_cols : int_s_cols;

		if (int_matrix_prod = int_create_matrix(*int_max_rows, *int_max_cols))
			{
				printf("\n");
				printf("+---|----+---|----+---|----+---|----+---|----+\n");
				printf("|    Resulting Rectangular Matrix Product.   |\n");
				printf("+---|----+---|----+---|----+---|----+---|----+\n");
				printf("| Rows: [%d].\tColumns: [%d].\n", int_f_rows, int_f_cols);
				printf("| Rows: [%d].\tColumns: [%d].\n", int_s_rows, int_s_cols);
				printf("+---|----+---|----+---|----+---|----+---|----+\n");

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
			{
				perror("There is not enough space in memory to allocate a matrix product array...");
				exit(EXIT_FAILURE);
			}

		return int_matrix_prod;
	}

/*****************************************************************
 ** Function:           int int_view_matrix			**
 **                             (int **int_matrix,              **
 **                              const int int_rows,		**
 **				 const int int_cols).           **
 ** Explanation:	The purpose of this function is to	**
 **			display element by element the		**
 **			two-dimensional matrix created on the	**
 **			screen, taking into account its number	**
 **			of rows and the number of columns	**
 **			assigned to each row of said matrix.	**
 **								**
 **			Two matrices 'A' and 'B' are said to be	**
 **			multipliable if the number of columns	**
 **			in 'A' exactly matches the number of	**
 **			rows in 'B'.				**
 **								**
 **			The element 'C[i][j]' of the resulting	**
 **			product matrix is ​​obtained by		**
 **			multiplying each of the individual	**
 **			elements of each of the rows of		**
 **			matrix 'A' by each of the elements of	**
 **			each column of matrix 'B' and adding	**
 **			them in the corresponding element	**
 **			'C[i][j]'.				**
 **								**
 ** Input Parms:        const int int_rows.                     **
 **			const int int_cols.			**
 ** Output Parms:       int **int_matrix.                       **
 ** Result:		This function displays element by	**
 **			element the contents of each allocated	**
 **			memory location of the two-dimensional	**
 **			array and the number of elements that	**
 **			were successfully stored in the		**
 **			two-dimensional dynamic array.		**
 ****************************************************************/
int int_view_matrix(int **int_matrix, const int int_rows, const int int_cols)
	{
		int int_captured_items = V_ZERO;

		if (int_matrix)
			{
				printf("\n");
				printf("+---|----+---|----+---|----+---|----+---|----+\n");
				printf("|   Visualization of the allocated matrix.   |\n");
				printf("+---|----+---|----+---|----+---|----+---|----+\n");
				printf("| Rows: [%d].\tColumns: [%d].\n", int_rows, int_cols);
				printf("+---|----+---|----+---|----+---|----+---|----+\n");

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


/*****************************************************************
 ** Function:		int main().				**
 ** Explanation:	To multiply two matrices, the first one	**
 **			must have the same number of columns as **
 **			the second one has rows.		**
 **								**
 **			The resulting matrix will have the same **
 **			number of rows as the first matrix and	**
 **			the same number of columns as the	**
 **			second one.				**
 **								**
 **			Matrix multiplication has some		**
 **			properties, such as:			**
 **								**
 **			Associativity:				**
 **				For any three matrices		**
 **				'A', 'B' and 'C', (AB)C = A(BC).**
 **								**
 **			Distributivity:				**
 **				C(A + B) = C(A) + C(B);		**
 **				(A + B)C = A(C) + B(C).		**
 **								**
 **			Matrix multiplication is not		**
 **			commutative, that is, the order in	**
 **			which the matrices are multiplied can	**
 **			affect the result.			**
 **								**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		In order to multiply two matrices of	**
 **			regular order, the first must have the	**
 **			same number of columns as the second	**
 **			has rows.				**
 **								**
 **			The matrix resulting from the product	**
 **			will have the same number of rows as	**
 **			the first and the same number of	**
 **			columns as the second.			**
 **								**
 **			If we have a 2x3 matrix and we multiply	**
 **			it by another of order 3x5, the		**
 **			resulting matrix will be of order 2x5.	**
 ****************************************************************/
int main()
	{
		int int_counting_items = V_ZERO;
		int int_f_cols = V_ZERO, int_f_rows = V_ZERO;
		int int_s_cols = V_ZERO, int_s_rows = V_ZERO;

		int ***int_matrix_3D = NULL;
		int int_max_cols = V_ZERO;
		int int_max_rows = V_ZERO;

		printf("+---|----+---|----+---|----+---|----+---|----+\n");
		printf("|    Product of two rectangular matrices.    |\n");
		printf("+---|----+---|----+---|----+---|----+---|----+\n");

		if (int_matrix_3D = (int ***) calloc(V_THREE, sizeof(int **)))
			{
				printf("\n");
				printf("+---|----+---|----+---|----+---|----+---|----+\n");
				printf("|  Rows and columns of matrix #[1] of #[2].  |\n");
				printf("+---|----+---|----+---|----+---|----+---|----+\n");
				printf("Number of rows    : ");
				scanf("%d", &int_f_rows);
				printf("Number of columns : ");
				scanf("%d", &int_f_cols);

				int_matrix_3D[V_ZERO] = int_create_matrix(int_f_rows, int_f_cols);
				int_counting_items = int_capture_matrix(int_matrix_3D[V_ZERO], int_f_rows, int_f_cols);
				int_counting_items = int_view_matrix(int_matrix_3D[V_ZERO], int_f_rows, int_f_cols);

				printf("\n");
				printf("+---|----+---|----+---|----+---|----+---|----+\n");
				printf("|  Rows and columns of matrix #[2] of #[2].  |\n");
				printf("+---|----+---|----+---|----+---|----+---|----+\n");
				printf("Number of rows    : ");
				scanf("%d", &int_s_rows);
				printf("Number of columns : ");
				scanf("%d", &int_s_cols);

				int_matrix_3D[V_ONE] = int_create_matrix(int_s_rows, int_s_cols);
				int_counting_items = int_capture_matrix(int_matrix_3D[V_ONE], int_s_rows, int_s_cols);
				int_counting_items = int_view_matrix(int_matrix_3D[V_ONE], int_s_rows, int_s_cols);

				int_matrix_3D[V_TWO] = int_matrix_product(int_matrix_3D[V_ZERO], int_matrix_3D[V_ONE], int_f_rows, int_f_cols, int_s_rows, int_s_cols, &int_max_rows, &int_max_cols);

				printf("\n");
				printf("The complete product matrix is ​​displayed...\n");
				int_counting_items = int_view_matrix(int_matrix_3D[V_TWO], int_max_rows, int_max_cols);

				printf("\n");
				printf("Evicting arrays from allocated memory areas...\n");
				int_deallocate_matrix(int_matrix_3D[V_ZERO], int_f_rows);
				int_deallocate_matrix(int_matrix_3D[V_ONE], int_s_rows);
				int_deallocate_matrix(int_matrix_3D[V_TWO], int_max_rows);

				printf("\n");
				printf("Three-dimensional matrix pointer released...\n");
				free(int_matrix_3D);
			}
		else
			{
				perror("Error allocating memory for a three-dimensional array...");
				exit(EXIT_FAILURE);
			}

		return EXIT_SUCCESS;
	}
