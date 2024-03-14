#include <iostream>

#define	V_ONE	1
#define	V_ZERO	0

int main()
	{
		int items = V_ZERO, rows = V_ZERO;
		int **matrix = NULL, *colsxrow = NULL;;

		std::cout << "Highly dynamic pointer generator." << std::endl;
		std::cout << "How many lines will it generate for it? : ";
		std::cin >> rows;

		std::cout << std::endl << "Memory assigning spaces..." << std::endl;

		matrix = new int* [rows];
		colsxrow = new int [rows];

		std::cout << std::endl << "Capturing values..." << std::endl;
		for (int row = V_ZERO; row < rows; row++)
			{
				std::cout << std::endl << "Row: [" << row + V_ONE << "] of [" << rows << "]." << std::endl;
				std::cout << "How many columns will it generate for it and its respective row? : ";
				std::cin >> colsxrow[row];

				matrix[row] = new int[colsxrow[row]];

				for (int col = V_ZERO; col < colsxrow[row]; col++)
					{
						std::cout << "Enter a value #" << items++ << ": (Row: ["<< row + V_ONE << "] of [" << rows << "], Column: ["<< col + V_ONE << "] of [" << colsxrow[row] << "]) : ";
						std::cin >> matrix[row][col];
					}
			}
		std::cout << "[" << items << "] Captured input values." << std::endl;

		std::cout << std::endl << "Displaying captured values..." << std::endl;
		for (int row = V_ZERO, items = V_ZERO; row < rows; row++)
			{
				std::cout << "Row: [" << row + V_ONE << "] of [" << rows << "]." << std::endl;

				for (int col = V_ZERO; col < colsxrow[row]; col++, items++)
					{
						std::cout << "\tColumn: [" << col + V_ONE << "] of [" << colsxrow[row] << "].\t";
						std::cout << "(" << row + V_ONE << ", " << col + V_ONE << "):\t"<< "[" << *(*(matrix+row)+col) << "]." << std::endl;
					}

				std::cout << std::endl;
			}
		std::cout << "[" << items << "] Generated output results." << std::endl;

		std::cout << std::endl << "Deleting values..." << std::endl;
		for (int row = V_ZERO; row < rows; row++)
			delete matrix[row];

		delete colsxrow;
		delete matrix;

		return V_ZERO;
	}
