/****************** Pascal's Triangle Generator. *****************
 ** Source Code:	TrPascal.cpp				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Thursday, August 31, 2023.		**
 ** Purpose:		This program generates Pascal's Triangle**
 **			as a result up to a certain number of	**
 **			rows or levels, following as a pattern	**
 **			that the first number of each row is the**
 **			 unit (1), and that the other		**
 **			consecutive numbers are obtained by	**
 **			adding the pair of numbers that are	**
 **			immediately right above them.		**
 **								**
 **			Example for a six-row Pascal's Triangle	**
 **			(0..5):					**
 **				Row #0: 01			**
 **				Row #1: 01 01			**
 **				Row #2: 01 02 01		**
 **				Row #3: 01 03 03 01		**
 **				Row #4: 01 04 06 04 01		**
 **				Row #5: 01 05 10 10 05 01	**
 **								**
 **			To calculate each generated row of	**
 **			Pascal's Triangle, the value of the	**
 **			previous row and its previous column	**
 **			are added, plus the value of the	**
 **			previous row and its current column.	**
 **			So, we have:				**
 **								**
 **			Value of the each coefficient obtained.	**
 **				int_coeff_value =		**
 **					 array[r-1][c-1]	**
 **					+array[r-1][c].		**
*****************************************************************/
//C Standard Libraries.
#include <cstdlib>
#include <iostream>

//Symbolic constants of minimum and maximum limits.
#define LIM_MIN		0
#define LIM_MAX		11

//C Standard Libraries.
#define V_MINUS_ONE	-1
#define V_ONE		1
#define V_ZERO		0

//Using the namespace 'std'.
using namespace std;

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Explanation:	This class builds Pascal's Triangle by	**
 **			receiving as attributes the number of	**
 **			rows from zero to 'n' that it will have	**
 **			and stores it in a pointer of pointers.	**
 **								**
 ** Attributes:		int int_number_Rows.			**
 **			int **ptr_int_Pascal_s_Triangle.	**
 **								**
 ** Methods:		Pascal_s_Triangle (int int_number_Rows)	**
 **			Pascal_s_Triangle			**
 **				(const Pascal_s_Triangle	**
 **				 &other_Pascal_s_Triangle)	**
 **								**
 ** Result:		To create the class, it is necessary to	**
 **			provide from the beginning of its	**
 **			creation the number of lines, rows or	**
 **			tuples that the Pascal Triangle		**
 **			must have.				**
 ****************************************************************/
class Pascal_s_Triangle
	{
		//Private attributes and methods.
		private:
			//Number of instantiated objects of a given class 'Pascal's Triangle'.
			static int sttc_int_Counting_Pascal_s_Triangles;
			//Number of lines.
			int int_number_Rows=V_ZERO;
			//Double pointer with the arrangement of Pascal's Triangle.
			int **ptr_int_Pascal_s_Triangle=NULL;


		//Public attributes and methods.
		public:
			//Class constructor with the number of rows.
			Pascal_s_Triangle(int int_number_Rows);
			//Class constructor with another object of the same type.
			Pascal_s_Triangle(const Pascal_s_Triangle &other_Pascal_s_Triangle);
			//Class destroyer.
			~Pascal_s_Triangle();

			//Build Pascal's Triangle from scratch.
			void create_new_Pascal_s_Triangle();
			//Visualize Pascal's Triangle.
			void view_Pascal_s_Triangle();
	};

/* ---------------------------------------------------------------
 * This is a global variable belonging to the			--
 * 'Pascal's Triangle' class that is initialized to zero,	--
 * and later in its respective constructors it is increased by	--
 * one unit for each instance generated.			--
 * -------------------------------------------------------------*/
int Pascal_s_Triangle::sttc_int_Counting_Pascal_s_Triangles=V_ZERO;

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		Pascal_s_Triangle().			**
 ** Explanation:	Assigns the number of rows received per	**
 **			current parameter to the number of rows	**
 **			attribute of this class.		**
 ** Arguments:		int int_number_Rows.			**
 ** Result:		Assign the value received by parameter	**
 **			to the row number attribute of the	**
 **			class.					**
 ****************************************************************/
Pascal_s_Triangle::Pascal_s_Triangle(int int_number_Rows)
	{
		this->sttc_int_Counting_Pascal_s_Triangles++;

		cout << "Pascal's Triangle. Object created # [" << this->sttc_int_Counting_Pascal_s_Triangles << "]." << endl;
		cout << "Generation of a new 'Pascal's Triangle' object with [" << int_number_Rows << "] rows." << endl;

		this->int_number_Rows=int_number_Rows;
	};

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		Pascal_s_Triangle().			**
 ** Explanation:	Assigns the values of an object of the	**
 **			same type to the new instantiated	**
 **			class.					**
 ** Arguments:		int int_number_Rows.			**
 **			int **ptr_int_Pascal_s_Triangle.	**
 ** Result:		Assigns the values of the instantiated	**
 **			class passed as a parameter to the	**
 **			created class as if it were a true copy **
 **			of the first.				**
 ****************************************************************/
Pascal_s_Triangle::Pascal_s_Triangle(const Pascal_s_Triangle &other_Pascal_s_Triangle)
	{
		this->sttc_int_Counting_Pascal_s_Triangles++;

		cout << "Pascal's Triangle. Object created # [" << this->sttc_int_Counting_Pascal_s_Triangles << "]." << endl;
		cout << "Generation of a new 'Pascal's Triangle' object from another of the same species." << endl;

		this->int_number_Rows=other_Pascal_s_Triangle.int_number_Rows;
		this->ptr_int_Pascal_s_Triangle=other_Pascal_s_Triangle.ptr_int_Pascal_s_Triangle;
	};

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		create_new_Pascal_s_Triangle().		**
 ** Explanation:	Calculates and bilds the requested	**
 **			Pascal's Triangle on the pointer from	**
 **			the sum of the values of the preceding	**
 **			lines, in such a way that the first	**
 **			value and the last value of each line,	**
 **			respectively, will always be the	**
 **			unit (1).				**
 **								**
 **			To calculate each generated row of	**
 **			Pascal's Triangle, the value of the	**
 **			previous row and its previous column	**
 **			are added, plus the value of the	**
 **			previous row and its current column.	**
 **			So, we have:				**
 **								**
 **			Value of the each coefficient obtained.	**
 **				int_coeff_value =		**
 **					 array[r - 1][c - 1]	**
 **					+array[r - 1][c].	**
 **								**
 ** Arguments:		None.					**
 ** Result:		This method generate for each row of	**
 **			the constructed Pascal's Triangle the	**
 **			line number, column number, and 	**
 **			computed value for this pointer of	**
 **			pointers, which is actually a		**
 **			two-dimensional array.			**
 ****************************************************************/
void Pascal_s_Triangle::create_new_Pascal_s_Triangle()
	{
		int int_coeff_value=V_ZERO;

		cout << "Creation of a Pascal's Triangle of [" << int_number_Rows << "] rows." << endl;

		if ((this->ptr_int_Pascal_s_Triangle = (int **) malloc(int_number_Rows * sizeof(int *))) != NULL)
			for (int int_n_row=V_ZERO; int_n_row<int_number_Rows; int_n_row++)
				if ((this->ptr_int_Pascal_s_Triangle[int_n_row] = (int *) malloc ((int_n_row+V_ONE) * sizeof(int))) != NULL)
					{
						for (int int_n_col=V_ZERO; int_n_col<=int_n_row; int_n_col++)
							if (int_n_col==V_ZERO || int_n_col==int_n_row)
								this->ptr_int_Pascal_s_Triangle[int_n_row][int_n_col]=V_ONE;
							else
								{
									int_coeff_value = this->ptr_int_Pascal_s_Triangle[int_n_row + V_MINUS_ONE][int_n_col + V_MINUS_ONE]
											+ this->ptr_int_Pascal_s_Triangle[int_n_row + V_MINUS_ONE][int_n_col];

									this->ptr_int_Pascal_s_Triangle[int_n_row][int_n_col] = int_coeff_value;
								}
					}
				else
					cout << "Insufficient memory to create for row [" << int_n_row << "] of Pascal's Triangle." << endl;
		else
			cout << "Insufficient memory to create [" << int_number_Rows << "] rows of Pascal's Triangle." << endl;
	};

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		view_Pascal_s_Triangle().		**
 ** Explanation:	This method displays each column of	**
 **			each row of the Pascal's Triangle stored**
 **			in the pointer pointer that is an	**
 **			attribute of this same class, and if no	**
 **			triangle has been created, it sends an	**
 **			error message.				**
 ** Arguments:		None.					**
 ** Result:		Display the pointer of pointers,	**
 **			attribute of this class, if and only if	**
 **			it has some previously computed and	**
 **			created content.			**
 ****************************************************************/
void Pascal_s_Triangle::view_Pascal_s_Triangle()
	{
		int int_coeff_value=V_ZERO;

		cout << "Visualization of a Pascal's Triangle of [" << int_number_Rows << "] rows." << endl;

		if (this->ptr_int_Pascal_s_Triangle != NULL)
			for (int int_n_row=V_ZERO; int_n_row<int_number_Rows; int_n_row++)
				{
					for (int int_n_col=V_ZERO; int_n_col<=int_n_row; int_n_col++)
						cout << "Row: [" << int_n_row << "]. Col: [" << int_n_col << "]. Value = [" <<
								*(*(this->ptr_int_Pascal_s_Triangle+int_n_row)+int_n_col) << "]." << endl;

					cout << endl;
				}
		else
			cout << "Warning! No Pascal's Triangle has been generated. You must generate a new one to view it." << endl;
	};

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		~Pascal_s_Triangle().			**
 ** Explanation:	Destroys the created instance of the	**
 **			'Pascal's Triangle' object.		**
 ** Arguments:		None.					**
 ** Result:		Disintegrates from memory the instance	**
 **			of the created object			**
 **			'Pascal's Triangle'.			**
 ****************************************************************/
Pascal_s_Triangle::~Pascal_s_Triangle()
	{
		cout << "Pascal's Triangle. Object destroyed # [" << this->sttc_int_Counting_Pascal_s_Triangles << "]." << endl;

		/* Free the memory allocated to each of the rows. */
		//for (int int_n_row=V_ZERO; int_n_row<int_number_Rows; int_n_row++)
		//	free(this->ptr_int_Pascal_s_Triangle[int_n_row]);

		/* Free the memory allocated to the array of pointers. */
		//free(this->ptr_int_Pascal_s_Triangle);

		this->int_number_Rows=V_ZERO;
		this->sttc_int_Counting_Pascal_s_Triangles--;
	};


/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	The main function of this program	**
 **			creates a class for Pascal's Triangle	**
 **			from only the number of rows that you	**
 **			want to be calculated and displayed,	**
 **			and then a new instantiated object is	**
 **			created from the first mentioned to	**
 **			demonstrate its operation and handling.	**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		For didactic purposes, only a maximum	**
 **			number of rows is allowed to generate	**
 **			Pascal's Triangle and appreciate that	**
 **			the calculation performed by the class	**
 **			methods is performed correctly.		**
 ****************************************************************/
int main()
	{
		int int_n_Levels=V_ZERO;

		cout << "+---|----+---|----+---|----+---|----+---|----+---|----+" << endl;
		cout << "|            Pascal's Triangle Generator.             |" << endl;
		cout << "+---|----+---|----+---|----+---|----+---|----+---|----+" << endl;
		cout << "Levels of Pascal's Triangle between ["<< LIM_MIN << "] and [" << LIM_MAX << "] : ";
		cin  >> int_n_Levels;

		if (int_n_Levels >= LIM_MIN && int_n_Levels <= LIM_MAX)
			{
				/* First instance. It is called with number of rows. The Triangle is created and then displayed. */
				Pascal_s_Triangle psTOld(int_n_Levels);
				psTOld.create_new_Pascal_s_Triangle();
				psTOld.view_Pascal_s_Triangle();

				/* Second instance. It is called with a previously created Triangle and then displayed. */
				Pascal_s_Triangle psTNew(psTOld);
				psTNew.view_Pascal_s_Triangle();

				/* Third instance. It is called with a given number of rows but without being created and its display is requested. */
				Pascal_s_Triangle psTOther(int_n_Levels);
				psTOther.view_Pascal_s_Triangle();
				psTOther.create_new_Pascal_s_Triangle();
				psTOther.view_Pascal_s_Triangle();
			}
		else
			cout << "Error! The value [" << int_n_Levels << "] is not between [" << LIM_MIN << "] and [" << LIM_MAX << "]." << endl;

		return V_ZERO;
	}
