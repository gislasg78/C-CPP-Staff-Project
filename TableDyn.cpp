/* Program that dynamically allocates memory in C++
   to store a series of given matrices,
   each with a variable number of rows,
   and each of its respective rows with a variable number of columns.*/

/* Standard work libraries. */
#include <iostream>

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
		std::cout << "Highly dynamic pointer generator." << std::endl;
		std::cout << "How many rectangular arrangements do you want to create? : ";
		std::cin >> n_matrix;

		std::cout << std::endl << "Memory assigning spaces..." << std::endl;

		/* The initial space is first allocated for the number of two-dimensional arrays to be stored. */
		matrix = new int** [n_matrix];		//Space is generated for the first dimension of a three-dimensional array.
		matrix_rxc = new int* [n_matrix];	//Space is generated for the first dimension of a two-dimensional array.
		matrix_r = new int [n_matrix];		//Space is generated for the only dimension of a one-dimensional array.

		/* General loading cycles of dynamic pointer pointers. */
		std::cout << std::endl << "Capturing values..." << std::endl;

		/* Dynamic memory is allocated to know the number of matrices to be generated. */
		for (int m = V_ZERO; m < n_matrix; m++)		//Cycle by matrix.
			{
				std::cout << "For the matrix #: [" << m + V_ONE << "] of [" << n_matrix << "]." << std::endl;
				std::cout << "How many lines will it generate for it? : ";
				std::cin >> matrix_r[m];	//Number of matrices to store.

				/* Dynamic memory is allocated for each matrix to know the number of rows it will have. */
				matrix[m] = new int* [matrix_r[m]];	//Number of rows for each matrix.
				matrix_rxc[m] = new int [matrix_r[m]];

				for (int r = V_ZERO; r < matrix_r[m]; r++)	//Cycle through each row of each matrix.
					{
						std::cout << "For the matrix #: [" << m + V_ONE << "] of [" << n_matrix << "], and its row #: [" << r + V_ONE << "] of [" << matrix_r[m] << "]." << std::endl;
						std::cout << "How many columns will it generate for it and its respective row? : ";
						std::cin >> matrix_rxc[m][r];	//Number of rows for each matrix created.

						/* Dynamic memory is allocated for each row of the matrix in concurrent turn to know the number of columns it will have. */
						matrix[m][r] = new int [matrix_rxc[m][r]];	//Number of columns per row of each matrix.

						for (int c = V_ZERO; c < matrix_rxc[m][r]; c++)	//Cycle through each column of each row of each matrix.
							{
								std::cout << "Enter a value #: " << items++ << " for Matrix #: [" << m + V_ONE << "] of [" << n_matrix << "] -> (Row: [" << r + V_ONE << "] of [" << matrix_r[m] << "], Column: [" << c + V_ONE << "] of [" << matrix_rxc[m][r] << "]) : ";
								std::cin >> matrix[m][r][c];	//Value according to number of column per row of each matrix created.

								std::cout << "(Matrix: [" << m + V_ONE << "] of [" << n_matrix << "], Row: [" << r + V_ONE << "] of [" << matrix_r[m] << "], Column: [" << c + V_ONE << "] of [" << matrix_rxc[m][r] << "]) = [" << matrix[m][r][c] << "]." << std::endl;
							}

						std::cout << std::endl;
					}

				std::cout << std::endl;
			}
		std::cout << "[" << items << "] Captured input values." << std::endl;

		/* Process of dumping each column, each row, each matrix. */
		std::cout << "Displaying captured values..." << std::endl;

		/* Dump of each matrix. */
		for (int m = V_ZERO; m < n_matrix; m++)
			{
				std::cout << "Matrix: [" << m + V_ONE <<"] of [" << n_matrix << "]." << std::endl;

				/* Dump of each row of each matrix. */
				for (int r = V_ZERO; r < *(matrix_r + m); r++)
					{
						std::cout << "\tRow: [" << r + V_ONE << "] of [" << *(matrix_r + m) << "]." << std::endl;

						/* Dump of each column of each row of each matrix. */
						for (int c = V_ZERO; c < *(*(matrix_rxc + m) + r); c++)
							{
								std::cout << "\t\tColumn: [" << c + V_ONE << "] of [" << *(*(matrix_rxc + m) + r) << "].\t";
								std::cout << "(" << m + V_ONE << ", " << r + V_ONE << ", " << c + V_ONE << ") = [" << matrix[m][r][c] << "]." << std::endl;
							}

						std::cout << std::endl;
					}

				std::cout << std::endl;
			}
		std::cout << "[" << items << "] Generated output results." << std::endl;

		/* The allocated memory is freed from each allocated row of each created array. */
		std::cout << "Freeing the memory of all dynamically allocated pointers..." << std::endl;

		/* Freeing each memory space allocated to each array. */
		for (int m = V_ZERO; m < n_matrix; m++)
			{
				std::cout << "Deallocating memory for array #: [" << m + V_ONE << "] of [" << n_matrix << "]." << std::endl;

				/* Freeing each memory space allocated to each row of each matrix. */
				for (int r = V_ZERO; r < matrix_r[m]; r++)
					{
						std::cout << "\tDeallocating memory for its row #: [" << r + V_ONE << "] of [" << matrix_r[m] << "]." << std::endl;

						delete matrix[m][r];	//Deallocate each row of each matrix.
					}

				delete matrix[m];	//Deallocate each array.
				delete matrix_rxc[m];

				std::cout << std::endl;
			}

		/* Higher-order pointers are deallocated. */
		std::cout << "Evicting main memory addresses..." << std::endl;

		delete [] matrix_rxc;
		delete [] matrix_r;
		delete [] matrix;

		/* Program closure notice. */
		std::cout << "[End of the assigment!]." << std::endl;

		return V_ZERO;
	}
