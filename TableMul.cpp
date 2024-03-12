#include <iostream>

#define	V_ONE	1
#define	V_ZERO	0

int main()
	{
		int items = V_ZERO, rows = V_ZERO;
		int **matrix = NULL, *colsxrow = NULL;;

		std::cout << "Creating a dynamic rectangular array." << std::endl;
		std::cout << "Rows: ";
		std::cin >> rows;

		std::cout << std::endl << "Memory assigning spaces..." << std::endl;

		matrix = new int* [rows];
		colsxrow = new int [rows];

		for (int row = V_ZERO; row < rows; row++)
			{
				std::cout << "Row # " << row + 1 << " of " << rows << "." << std::endl;
				std::cout << "Columns for this row: ";

				std::cin >> colsxrow[row];

				matrix[row] = new int[colsxrow[row]];
			}

		std::cout << std::endl << "Capturing values..." << std::endl;
		for (int row = V_ZERO; row < rows; row++)
			for (int col = V_ZERO; col < colsxrow[row]; col++)
				{
					std::cout << "Enter value #" << items++ << ": ("<< row+1 << ", "<< col+1 << "): ";
					std::cin >> matrix[row][col];
				}
		std::cout << "[" << items << "] Captured input values." << std::endl;

		std::cout << std::endl << "Displaying values..." << std::endl;
		for (int row = V_ZERO, items = V_ZERO; row < rows; row++)
			{
				for (int col = V_ZERO; col < colsxrow[row]; col++, items++)
					std::cout << "(" << row + V_ONE << ", " << col + V_ONE << "):\t"<< "[" << *(*(matrix+row)+col) << "].\t";

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
