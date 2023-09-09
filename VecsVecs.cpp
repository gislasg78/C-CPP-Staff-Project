#include <iostream>
#include <vector>

using namespace std;

#define V_ZERO      0

int main()
	{
		vector<vector<int>> vec_vec_matrix;

		int int_Columns=V_ZERO;
		int int_Rows=V_ZERO;

		cout << "Number of rows: ";
		cin >> int_Rows;
		cout << "Number of columns: ";
		cin >> int_Columns;

		cout << endl;
		cout << "+----------------------+" << endl;
		cout << "|Multiplication tables.|" << endl;
		cout << "+----------------------+" << endl;

		for (int int_y=V_ZERO; int_y<int_Rows; int_y++)
			{
				vector<int> vec_columns;

				for (int int_x=V_ZERO; int_x<int_Columns; int_x++)
					vec_columns.push_back(int_y * int_x);

				vec_vec_matrix.push_back(vec_columns);
			}

		for (int int_row=V_ZERO; int_row<int_Rows; int_row++)
			{
				for (int int_col=V_ZERO; int_col<int_Columns; int_col++)
					cout << "[" << vec_vec_matrix[int_row][int_col] << "]\t";

				cout << endl;
			}

		cout << endl;

		return V_ZERO;
	}
