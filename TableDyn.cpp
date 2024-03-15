#include <iostream>

#define	V_ONE	1
#define	V_ZERO	0

int main()
	{
		int items = V_ZERO;

		/* Three, two and one dimension dynamic pointers. */
		int ***matrix = NULL;
		int **matrix_rxc = NULL;
		int *matrix_r = NULL;

		int n_matrix = V_ZERO;	//Number of dynamic matrices to generate.

		std::cout << "Highly dynamic pointer generator." << std::endl;
		std::cout << "How many rectangular arrangements do you want to create? : ";
		std::cin >> n_matrix;

		std::cout << std::endl << "Memory assigning spaces..." << std::endl;

		/* The initial space is first allocated for the number of two-dimensional arrays to be stored. */
		matrix = new int** [n_matrix];
		matrix_rxc = new int* [n_matrix];
		matrix_r = new int [n_matrix];

		/* General loading cycles of dynamic pointer pointers. */
		std::cout << std::endl << "Capturing values..." << std::endl;

		for (int m = V_ZERO; m < n_matrix; m++)
			{
				std::cout << "For the matrix #[" << m + V_ONE << "] of [" << n_matrix << "]." << std::endl;
				std::cout << "How many lines will it generate for it? : ";
				std::cin >> matrix_r[m];

				/* Dynamic memory is allocated for each matrix to know the number of rows it will have. */
				matrix[m] = new int* [matrix_r[m]];
				matrix_rxc[m] = new int [matrix_r[m]];

				for (int r = V_ZERO; r < matrix_r[m]; r++)
					{
						std::cout << "For the matrix #[" << m + V_ONE << "] of [" << n_matrix << "], and its row #[" << r + V_ONE << "] of [" << matrix_r[m] << "]." << std::endl;
						std::cout << "How many columns will it generate for it and its respective row? : ";
						std::cin >> matrix_rxc[m][r];

						/* Dynamic memory is allocated for each row of the matrix in concurrent turn to know the number of columns it will have. */
						matrix[m][r] = new int [matrix_rxc[m][r]];

						for (int c = V_ZERO; c < matrix_rxc[m][r]; c++)
							{
								std::cout << "Enter a value #" << items++ << " for Matrix #[" << m + V_ONE << "] of [" << n_matrix << "] -> (Row: [" << r + V_ONE << "] of [" << matrix_r[m] << "], Column: [" << c + V_ONE << "] of [" << matrix_rxc[m][r] << "]) : ";
								std::cin >> matrix[m][r][c];
								std::cout << "(Matrix: [" << m + V_ONE << "] of [" << n_matrix << "], Row: [" << r + V_ONE << "] of [" << matrix_r[m] << "], Column: [" << c + V_ONE << "] of [" << matrix_rxc[m][r] << "]) = [" << matrix[m][r][c] << "]." << std::endl;
							}

						std::cout << std::endl;
					}

				std::cout << std::endl;
			}
		std::cout << "[" << items << "] Captured input values." << std::endl;

		std::cout << std::endl << "Displaying captured values..." << std::endl;
		for (int m = V_ZERO; m < n_matrix; m++)
			{
				std::cout << "Matrix: [" << m + V_ONE <<"] of [" << n_matrix << "]." << std::endl;

				for (int r = V_ZERO; r < *(matrix_r + m); r++)
					{
						std::cout << "\tRow: [" << r + V_ONE << "] of [" << *(matrix_r + m) << "]." << std::endl;

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

		std::cout << "Freeing the memory of all dynamically allocated pointers..." << std::endl;
		for (int m = V_ZERO; m < n_matrix; m++)
			{
				for (int r = V_ZERO; r < matrix_r[m]; r++)
					{
						delete matrix[m][r];
					}

				delete matrix[m];
				delete matrix_rxc[m];
			}
		delete matrix_rxc;
		delete matrix_r;
		delete matrix;

		std::cout << std::endl << "[End of the assigment!]." << std::endl;

		return V_ZERO;
	}
