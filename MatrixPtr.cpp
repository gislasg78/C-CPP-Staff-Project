#include <iostream>

#define V_ELEVEN	11
#define V_ZERO		0

template <typename T, int Rows, int Cols>
T **build_matrix(T ***my_matrix, T *my_items)
	{
		T items = V_ZERO;
		T **matrix = nullptr;

		if ((matrix = new T*[Rows]()))
			{
				std::cout << "Generation of an integer product matrix." << std::endl;

				for (int row = V_ZERO; row < Rows; row++)
					{
						if ((matrix[row] = new T[Cols]()))
							{
								for (int col = V_ZERO; col < Cols; col++)
									{
										items++;
										matrix[row][col] = row * col;
									}
							}
					}

				std::cout << "[" << items << "] Output results generated." << std::endl;
			}

		if (my_matrix) *my_matrix = matrix;
		if (my_items) *my_items = items;
		return matrix;
}

template <typename T, int Rows, int Cols>
void unload_matrix(T ***matrix)
	{
		std::cout << std::endl << "Releasing dynamic matrix..." << std::endl;

		for (int row = V_ZERO; row < Rows; row++)
			{
				std::cout << "Clearing row #: [" << row << "] of: [" << Rows << "]." << std::endl;

				delete [] *(matrix[V_ZERO] + row);
				*(*(matrix + V_ZERO) + row) = nullptr;
			}

		std::cout << "Clearing the main pointer of the array..." << std::endl;
		delete [] matrix[V_ZERO];
		*(matrix + V_ZERO) = nullptr;
	}

template <typename T, int Rows, int Cols>
T view_matrix(T **matrix)
	{
		T items = V_ZERO;

		std::cout << std::endl << "Visualization of the matrix content." << std::endl;

		for (int row = V_ZERO; row < Rows; row++)
			{
				for (int col = V_ZERO; col < Cols; col++, items++)
					std::cout << "(" << row << ", " << col << ") = [" << *(*(matrix + row) + col) << "]." << '\n';

				std::cout << std::endl;
			}

		std::cout << "[" << items << "] Output results generated." << std::endl;

		return items;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int items = V_ZERO;
		int **matrix = build_matrix<int, V_ELEVEN, V_ELEVEN>(&matrix, &items);

		/* Display and release the dynamic matrix created. */
		view_matrix<int, V_ELEVEN, V_ELEVEN>(matrix);
		unload_matrix<int, V_ELEVEN, V_ELEVEN>(&matrix);

		/* Program completion. */
		std::cout << std::endl << "This program has been terminated." << std::endl;

		return V_ZERO;
	}
