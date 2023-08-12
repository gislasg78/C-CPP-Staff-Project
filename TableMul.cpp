#include <iostream>
#include <list>

#define V_ZERO	0

using namespace std;

class MyList
	{
		private:
			static int int_Counting;
			std::list<int> *ptr_data=NULL;;

		public:
			MyList()
				{
					int_Counting++;
					this->ptr_data=new std::list<int>();
				}

			void addItem (int int_Item)
				{
					this->ptr_data->push_back(int_Item);
				}

			void printItems()
				{
					for (auto it_ptr_data=this->ptr_data->begin(); it_ptr_data!=this->ptr_data->end(); ++it_ptr_data)
						std::cout << "[" << *it_ptr_data << "]\t";

					std::cout << std::endl;
				}
	};

int MyList::int_Counting=V_ZERO;


int main()
	{
		std::list<MyList> lst_MyList;
		MyList *ptr_MyList=NULL;

		int int_Rows=V_ZERO;
		int int_Cols=V_ZERO;

		std::cout << endl;
		std::cout << "+---|----+---|----+---|----+---+" << endl;
		std::cout << "|Dynamic multiplication tables.|" << endl;
		std::cout << "+---|----+---|----+---|----+---+" << endl;
		std::cout << "Rows: ";
		std::cin >> int_Rows;
		std::cout << "Cols: ";
		std::cin >> int_Cols;

		for (int int_row=V_ZERO; int_row<int_Rows; int_row++)
			{
                        	ptr_MyList=new MyList();

				for (int int_col=V_ZERO; int_col<int_Cols; int_col++)
					ptr_MyList->addItem(int_row * int_col);

				lst_MyList.push_back(*ptr_MyList);

				delete ptr_MyList;
			}

		std::cout << "Size:\t[" << lst_MyList.size() << "]." << endl;
		for (auto it=std::begin(lst_MyList); it!=std::end(lst_MyList); ++it)
			it->printItems();

		return V_ZERO;
	}
