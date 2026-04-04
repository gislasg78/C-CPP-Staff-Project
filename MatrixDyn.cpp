#include <iostream>

#define	V_ZERO	0

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int cols = V_ZERO, rows = V_ZERO;

		std::cout << "Matrix Creation." << std::endl;
		std::cout << "Enter rows: ";
		std::cin >> rows;

		std::cout << "Enter cols: ";
		std::cin >> cols;

		/* Dynamically allocate memory to store the array. */
		int **matrix = new int* [rows]();

		for (int row = V_ZERO; row < rows; row++)
			matrix[row] = new int [cols]();

		/* Fill the dynamically created matrix with values. */
		std::cout << std::endl << "Dump of the dynamically created matrix." << std::endl;

		for (int row = V_ZERO; row < rows; row++)
			{
				for (int col = V_ZERO; col < cols; col++)
					{
						matrix[row][col] = row * col;
						std::cout << "(" << row << ", " << col << ") = [" << matrix[row][col] << "]." << std::endl;
					}

				std::cout << std::endl;
			}

		/* Releasing dynamically allocated memory from the array. */
		for (int row = V_ZERO; row < rows; row++)
			delete [] matrix[row];

		delete[] matrix;

		std::cout << "This program has ended." << std::endl;

		return V_ZERO;
	}
