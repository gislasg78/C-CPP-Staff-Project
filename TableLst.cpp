#include <iostream>
#include <list>
#include <vector>

#define V_ZERO  0

using namespace std;

template <typename T>
void view_Collector (const T &t_Collector)
	{
		cout << "Size:\t[" << t_Collector.size() << "]." << endl;
		for (auto it=begin(t_Collector); it!=end(t_Collector); ++it)
			cout << " [" << *it << "] ";
		cout << endl;
	};

int main()
	{
		size_t szt_Rows=V_ZERO;
		size_t szt_Cols=V_ZERO;
		int int_Data=V_ZERO;

		list<size_t> lst_szt_Digits={V_ZERO};
		vector<size_t> vec_szt_Digits={V_ZERO};

		cout << "Collectors's generator..." << endl;
		cout << "Rows: ";
		cin >> szt_Rows;
		cout << "Cols: ";
		cin >> szt_Cols;

		for (size_t szt_row=V_ZERO; szt_row<szt_Rows; szt_row++)
			for (size_t szt_col=V_ZERO; szt_col<szt_Cols; szt_col++)
				{
					int_Data=szt_row*szt_col;

					lst_szt_Digits.push_back(int_Data);
					vec_szt_Digits.push_back(int_Data);
				}

		view_Collector(lst_szt_Digits);
		view_Collector(vec_szt_Digits);

		return V_ZERO;
	}
