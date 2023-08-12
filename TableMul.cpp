#include <iostream>
#include <list>
#include <vector>

#define V_ZERO	0

using namespace std;

class MyList
	{
		private:
			static int sttc_int_Counting;
			std::list<int> *ptr_lst_int_data=nullptr;

		public:
			MyList()
				{
					sttc_int_Counting++;
					this->ptr_lst_int_data=new std::list<int>();
				}

			void addItem (const int int_Item)
				{
					this->ptr_lst_int_data->push_back(int_Item);
				}

			void printItems() const
				{
					for (auto it_ptr_lst_int_data=this->ptr_lst_int_data->begin();
						it_ptr_lst_int_data!=this->ptr_lst_int_data->end(); ++it_ptr_lst_int_data)
							std::cout << "[" << *it_ptr_lst_int_data << "]\t";

					std::cout << std::endl;
				}
	};

int MyList::sttc_int_Counting=V_ZERO;


template <typename T>
void view_Collector(const T &t_Collector_MyList)
	{
		std::cout << endl << "Collector size.\tRows:\t[" << t_Collector_MyList.size() << "]." << endl;

		for (auto it_t_Collector_MyList=std::begin(t_Collector_MyList);
			it_t_Collector_MyList!=std::end(t_Collector_MyList); ++it_t_Collector_MyList)
				it_t_Collector_MyList->printItems();
	};

int main()
	{
		MyList *ptr_MyList=NULL;

		std::list<MyList> lst_MyList;
		std::vector<MyList> vec_MyList;

		size_t szt_Rows=V_ZERO;
		size_t szt_Cols=V_ZERO;

		std::cout << endl;
		std::cout << "+---|----+---|----+---|----+---+" << endl;
		std::cout << "|Dynamic multiplication tables.|" << endl;
		std::cout << "+---|----+---|----+---|----+---+" << endl;
		std::cout << "Rows: ";
		std::cin >> szt_Rows;
		std::cout << "Cols: ";
		std::cin >> szt_Cols;

		for (size_t szt_row=V_ZERO; szt_row<szt_Rows; szt_row++)
			{
                        	ptr_MyList=new MyList();

				for (size_t szt_col=V_ZERO; szt_col<szt_Cols; szt_col++)
					ptr_MyList->addItem(szt_row * szt_col);

				lst_MyList.push_back(*ptr_MyList);
				vec_MyList.push_back(*ptr_MyList);

				delete ptr_MyList;
			}

		view_Collector(lst_MyList);
		view_Collector(vec_MyList);

		return V_ZERO;
	}
