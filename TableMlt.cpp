
/************** Generator for multiple value tables. *************
 ** Source Code:	TableMlt.cpp				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, December 30, 2023.		**
 ** Purpose:		This program's personal purpose is to	**
 **			exemplify the use of the C++ standard	**
 **			library collectors storing		**
 **			multiplication tables in lists and	**
 **			vectors; Different modalities of the	**
 **			pointers of these objects are also used	**
 **			for dynamic memory management, and	**
 **			examples of automatic management of the	**
 **			same memory.				**
 **			A class is even created that stores	**
 **			these collectors and adds them in its	**
 **			methods and displays them on the screen.**
*****************************************************************/
//C Standard Libraries.
#include <iostream>
#include <list>
#include <vector>

//Symbolic constants of minimum and maximum limits.
#define	V_LOWER_LIMIT_COLS	1
#define	V_LOWER_LIMIT_ROWS	1
#define	V_UPPER_LIMIT_COLS	10
#define	V_UPPER_LIMIT_ROWS	10

//Symbolic work constants.
#define	V_ZERO			0

/*****************************************************************
 ** Class:		MyList.					**
 ** Explanation:	The purpose of this class is to store	**
 **			in a list-type collector a series of	**
 **			numerical values such that they can be	**
 **			printed by another method of the same	**
 **			class.					**
 ** Attributes:		private:				**
 **				static size_t sttc_szt_Counting;**
 **				std::list<size_t>		**
 **					*ptr_lst_szt_Item;	**
 **			public:					**
 **				MyList();			**
 **				addItem(const size_t szt_Item);	**
 **				printItems() const;		**
 ****************************************************************/
class MyList
	{
		//Private attributes and methods.
		private:
			//Number of instantiated objects of a given class 'MyList'.
			static size_t sttc_szt_Counting;
			//Pointer to a list that will store unsigned integer numeric values.
			std::list<size_t> *ptr_lst_szt_Item = nullptr;

		//Protected attributes and methods.
		public:
			/* ---------------------------------------------------------------------------- **
			 * Constructor of the 'My List' class that increments the instance counter	**
			 * and initializes the list that will store the numeric values.			**
			 * -----------------------------------------------------------------------------**/
			MyList()
				{
					sttc_szt_Counting++;	//Increase instances.

					/* Create list of unsigned integer numeric type pointers. */
					this->ptr_lst_szt_Item = new std::list<size_t>();
				}

			/* ---------------------------------------------------------------------------- **
			 * Add each unsigned integer numeric element to the element list pointer.	**
			 * -----------------------------------------------------------------------------**/
			void addItem (const size_t szt_Item)
				{
					this->ptr_lst_szt_Item->push_back(szt_Item);	//Enter element.
				}

			/* ---------------------------------------------------------------------------- **
			 * Display the elements contained in the list pointer of unsigned integer	**
			 * numeric values..								**
			 * -----------------------------------------------------------------------------**/
			void printItems() const
				{
					size_t szt_Item_Counting=V_ZERO;

					//Here is the list of the 'MyList' class instance.
					for (auto it_ptr_lst_szt_Item = this->ptr_lst_szt_Item->begin();
						it_ptr_lst_szt_Item != this->ptr_lst_szt_Item->end();
						++it_ptr_lst_szt_Item)
								std::cout << "# " << szt_Item_Counting++ <<":\t[" << *it_ptr_lst_szt_Item << "].\t";

					std::cout << "<" << this->ptr_lst_szt_Item->size() << "> items per row." << std::endl;
				}
	};

/* ---------------------------------------
 * size_t MyList::sttc_szt_Counting.	--
 * +---|----+---|----+---|----+---|----+--
 * It is used to initialize the value	--
 * of the number of instances of the	--
 * 'MyList' class to absolute zero.	--
 * -------------------------------------*/
size_t MyList::sttc_szt_Counting=V_ZERO;


/*****************************************************************
 ** Function:		template <typename T>			**
 **				viewCollector			**
 **					(const T &t_Collector); **
 ** Explanation:	This function displays each value 	**
 **			contained in a list or vector in which	**
 **			unsigned integer numeric values were	**
 **			stored.					**
 ** Arguments:		const T &t_Collector.			**
 ** Result:		This function displays the values	**
 **			stored in list and vector types on the	**
 **			screen.					**
 ****************************************************************/
template <typename T>
void view_Collector (const T &t_Collector)
	{
		size_t szt_Item_Counting=V_ZERO;

		std::cout << std::endl << "<" << t_Collector.size() << "> successive elements." << std::endl;

		for (auto it=std::begin(t_Collector); it!=std::end(t_Collector); ++it)
			std::cout << "# " << szt_Item_Counting++ << ":\t[" << *it << "].\t";

		std::cout << std::endl;
	};


/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	The main function has the purpose of	**
 **			asking the user for the number of rows	**
 **			and columns that will contain the	**
 **			different objects to be created in this	**
 **			program, such as a class with a list as	**
 **			its attribute, lists and vectors as	**
 **			collectors that will store a series of	**
 **			unsigned integer numerics values.	**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		Show each value of each generated	**
 **			collector object one by one on the	**
 **			screen.					**
*****************************************************************/
int main()
	{
		size_t szt_Rows = V_ZERO;
		size_t szt_Cols = V_ZERO;
		size_t szt_Item = V_ZERO;

		MyList *ptr_MyList=nullptr;
		std::list<MyList> *ptr_lst_MyList = {nullptr};
		std::list<MyList>::iterator it_ptr_lst_MyList;

		std::list<size_t> lst_szt_Items = {V_ZERO};
		std::vector<size_t> vec_szt_Items = {V_ZERO};

		std::cout << "Dynamic multiple collectors..." << std::endl;
		std::cout << "Enter the number of rows between [" << V_LOWER_LIMIT_ROWS << "] and [" << V_UPPER_LIMIT_ROWS << "]: ";
		std::cin >> szt_Rows;
		std::cout << "Enter the number of cols between [" << V_LOWER_LIMIT_COLS << "] and [" << V_UPPER_LIMIT_COLS<< "]: ";
		std::cin >> szt_Cols;

		/* -------------------------------------------- **
		 * Here it is checked that the values entered	**
		 * for rows and columns of the value tables	**
		 * are within established intervals.		**
		 * -------------------------------------------- */
		if (szt_Rows >= V_LOWER_LIMIT_ROWS && szt_Rows <= V_UPPER_LIMIT_ROWS)
			if (szt_Cols >= V_LOWER_LIMIT_COLS && szt_Cols <= V_UPPER_LIMIT_COLS)
				{
					/* -------------------------------------------------------------------- --
					 * A pointer to a list of object type 'My List' is first generated	--
					 * so that it in turn stores pointers to independent objects of the	--
					 * same type 'My List'.							--
					 * --------------------------------------------------------------------	*/
					ptr_lst_MyList = new std::list<MyList>();

					for (size_t szt_row = V_ZERO; szt_row <= szt_Rows; szt_row++)
						{
							// Each object pointer of type 'My List' is created.
							ptr_MyList = new MyList();

							//Process of saving values in each collection.
							for (size_t szt_col = V_ZERO; szt_col <= szt_Cols; szt_col++)
								{
									szt_Item=szt_row*szt_col;
									ptr_MyList->addItem(szt_Item);

									lst_szt_Items.push_back(szt_Item);
									vec_szt_Items.push_back(szt_Item);
								}

							//Each created object pointer of type 'My List' is stored.
							ptr_lst_MyList->push_back(*ptr_MyList);

							//The pointer to an object of type 'My List' is destroyed every time.
							delete ptr_MyList;
						}

					//Visualization of the contents stored in the different objects.
					for (it_ptr_lst_MyList = std::begin(*ptr_lst_MyList);
						it_ptr_lst_MyList != std::end(*ptr_lst_MyList);
						it_ptr_lst_MyList++)
							it_ptr_lst_MyList->printItems();

					//Sequentially view numerical values stored in lists and vectors.
					view_Collector(lst_szt_Items);
					view_Collector(vec_szt_Items);

					//The pointer to an object of type list 'My List' is destroyed every time.
					delete ptr_lst_MyList;
				}
			else
				std::cout << "Mistake! The [" << szt_Cols << "] value for the columns is outside the range of [" << V_LOWER_LIMIT_COLS << "] and [" << V_UPPER_LIMIT_COLS << "]." << std::endl;
		else
			std::cout << "Mistake! The [" << szt_Rows << "] value for the rows is outside the range of [" << V_LOWER_LIMIT_ROWS << "] and [" << V_UPPER_LIMIT_ROWS << "]." << std::endl;

		return V_ZERO;
	}
