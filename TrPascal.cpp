/****************** Pascal's Triangle Generator. *****************
 ** Source Code:	TrPascal.cpp				**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Saturday, February 3, 2024.		**
 ** Purpose:		This program generates Pascal's Triangle**
 **			as a result up to a certain number of	**
 **			rows or levels, following as a pattern	**
 **			that the first number of each row is the**
 **			unit (1), and that the other		**
 **			consecutive numbers are obtained by	**
 **			adding the pair of numbers that are	**
 **			immediately right above them.		**
 **								**
 **			Example for a eight-row			**
 **			Pascal's Triangle.	(0..7):		**
 **								**
 **				Row #0: 01			**
 **				Row #1: 01 01			**
 **				Row #2: 01 02 01		**
 **				Row #3: 01 03 03 01		**
 **				Row #4: 01 04 06 04 01		**
 **				Row #5: 01 05 10 10 05 01	**
 **				Row #6: 01 06 15 20 15 06 01	**
 **				Row #7: 01 07 21 35 35 21 07 01	**
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
#include <vector>

//Symbolic constants of minimum and maximum limits.
#define V_LOWER_LIMIT_PST	1	//Lower limit of PST.
#define V_LOWER_LIMIT_ROWS	1	//Lower limit of rows.
#define V_UPPER_LIMIT_PST	3	//Upper limit of PST.
#define V_UPPER_LIMIT_ROWS	19	//Upper limit of rows.

//Symbolic work constants.
#define V_MINUS_ONE		-1	//Constant minus one.
#define V_ONE			1	//Constant unit.
#define V_ZERO			0	//Absolute zero constant.

//Symbolic Character Constants.
#define V_CHAR_Y_LOWER_CASE	'y'	//Lowercase 'Y'.
#define V_CHAR_Y_UPPER_CASE	'Y'	//Capital 'Y'
#define NULL_CHARACTER		'\0'	//Null character.

//Using the namespace 'std'.
using namespace std;

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Explanation:	This class builds Pascal's Triangle by	**
 **			receiving as attributes the number of	**
 **			rows from zero to 'n' that it will have	**
 **			and stores it in a pointer of pointers.	**
 **								**
 ** Attributes:		private:				**
 **			friend int				**
 **			int_unit_Testing_Pascal_s_Triangle	**
 **				(Pascal_s_Triangle &psT);	**
 **			friend std::ostream &operator<<		**
 **				(std::ostream &os,		**
 **				 const Pascal_s_Triangle &psT);	**
 **								**
 **			int int_number_Rows;			**
 **			int **ptr_int_Pascal_s_Triangle;	**
 **			static int				**
 **			sttc_int_Counting_Pascal_s_Triangles;	**
 **								**
 ** Methods:		protected:				**
 **			void generate_new_existing_		**
 **				Pascal_s_Triangle();		**
 **			bool get_bool_Response_Regeneration()	**
 **				const;				**
 **			void set_int_number_Rows		**
 **				(const int int_number_Rows);	**
 **			void view_header_Pascal_s_Triangle	**
 **				(const string			**
 **				str_name_Proc_Oper) const;	**
 **								**
 **			public:					**
 **			Pascal_s_Triangle();			**
 **			Pascal_s_Triangle			**
 **				(const int int_number_Rows);	**
 **			Pascal_s_Triangle			**
 **				(const Pascal_s_Triangle	**
 **				&other_Pascal_s_Triangle);	**
 **			~Pascal_s_Triangle();			**
 **								**
 **			int capture_int_number_Rows();		**
 **			void clear_Pascal_s_Triangle();		**
 **			void create_new_Pascal_s_Triangle	**
 **				(const int int_number_Rows);	**
 **			int get_int_number_Rows() const;	**
 **			vector<vector<int>>			**
 **				get_vec_vec_matrix_		**
 **				Pascal_s_Triangle()		**
 **				const;				**
 **			void view_detail_Pascal_s_Triangle()	**
 **				const;				**
 **			void					**
 **			view_info_class_Pascal_s_Triangle()	**
 **				const;				**
 **								**
 ** Result:		To create the class, it is necessary to	**
 **			provide from the beginning of its	**
 **			creation the number of lines, rows or	**
 **			tuples that the Pascal Triangle		**
 **			must have.				**
 ****************************************************************/
class Pascal_s_Triangle
	{
		//Private methods and attributes. Friendly non-member functions.
		private:
			//Non-member function for unit testing of Pascal's Triangle.
			friend int int_unit_Testing_Pascal_s_Triangle (Pascal_s_Triangle &psT);
			//Non-member function to send content to the output stream 'std::ostream'.
			friend std::ostream &operator<< (std::ostream &os, const Pascal_s_Triangle &psT);

			//Number of lines.
			int int_number_Rows=V_ZERO;
			//Double pointer with the arrangement of Pascal's Triangle.
			int **ptr_int_Pascal_s_Triangle=NULL;
			//Number of instantiated objects of a given class 'Pascal's Triangle'.
			static int sttc_int_Counting_Pascal_s_Triangles;

		//Protected attributes and methods.
		protected:
			//It generates a Pascal's Triangle without releasing it previously.
			void generate_new_existing_Pascal_s_Triangle();
			//Gets a confirmation response to regenerate 'Pascal's Triangle'.
			bool get_bool_Response_Regeneration() const;
			//Set the number of lines that Pascal's Triangle must have.
			void set_int_number_Rows (const int int_number_Rows);
			//Displays the main information attributes of the class 'Pascal's Triangle'
			void view_header_Pascal_s_Triangle (const string str_name_Proc_Oper) const;

		//Public attributes and methods.
		public:
			//Create only the skeleton or shell of 'Pascal's Triangle'.
			Pascal_s_Triangle();
			//Class constructor with the number of rows.
			Pascal_s_Triangle (const int int_number_Rows);
			//Class constructor with another object of the same type.
			Pascal_s_Triangle (const Pascal_s_Triangle &other_Pascal_s_Triangle);
			//Class destroyer.
			~Pascal_s_Triangle();

			//Keyboard capture of the number of rows of Pascal's Triangle.
			int capture_int_number_Rows();
			//Clear the memory pointer that stores Pascal's Triangle.
			void clear_Pascal_s_Triangle();
			//Build Pascal's Triangle from scratch.
			void create_new_Pascal_s_Triangle (const int int_number_Rows);
			//Gets the number of lines or rows contained in the row number attribute.
			int get_int_number_Rows() const;
			//Returns a matrix of Pascal's Triangle in vector form.
			vector<vector<int>> get_vec_vec_matrix_Pascal_s_Triangle() const;
			//Visualize Pascal's Triangle.
			void view_detail_Pascal_s_Triangle() const;
			//Presents general information on the created Pascal's Triangle on the screen.
			void view_info_class_Pascal_s_Triangle() const;
	};

/* ---------------------------------------------------------------
 * int Pascal_s_Triangle::sttc_int_Counting_Pascal_s_Triangles.	--
 * +---|----+---|----+---|----+---|----+---|----+---|----+---|+	--
 * This is a global variable belonging to the			--
 * 'Pascal's Triangle' class that is initialized to zero,	--
 * and later in its respective constructors it is increased by	--
 * one unit for each instance generated.			--
 * -------------------------------------------------------------*/
int Pascal_s_Triangle::sttc_int_Counting_Pascal_s_Triangles=V_ZERO;

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		Pascal_s_Triangle().			**
 ** Explanation:	The purpose of this constructor method	**
 **			is to exclusively generate an instance	**
 **			of the empty 'Pascal's Triangle' class,	**
 **			that is, with parameters with default	**
 **			values.					**
 **			If you want to use the mentioned	**
 **			triangle, it is a fundamental		**
 **			requirement to call the method that	**
 **			builds a new triangle.			**
 ** Arguments:		None.					**
 ** Result:		As a result, it returns an		**
 **			initialization message of the private	**
 **			main attributes of the 'Pascal's	**
 **			Triangle' class and prepares the pointer**
 **			of pointers to store a future triangle	**
 **			when the method that is responsible for	**
 **			creating and generating it is		**
 **			necessarily called.			**
 ****************************************************************/
Pascal_s_Triangle::Pascal_s_Triangle()
	{
		this->sttc_int_Counting_Pascal_s_Triangles++;
		this->int_number_Rows=V_ZERO;
		this->ptr_int_Pascal_s_Triangle=NULL;

		Pascal_s_Triangle::view_header_Pascal_s_Triangle("Constructing an object of class 'Pascal's Triangle' as a skeleton or shell......");
	};

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		Pascal_s_Triangle			**
 **				(const int int_number_Rows).	**
 ** Explanation:	Assigns the number of rows received per	**
 **			current parameter to the number of rows	**
 **			attribute of this class.		**
 ** Arguments:		const int int_number_Rows.		**
 ** Result:		Assign the value received by parameter	**
 **			to the row number attribute of the	**
 **			class.					**
 ****************************************************************/
Pascal_s_Triangle::Pascal_s_Triangle(const int int_number_Rows)
	{
		this->sttc_int_Counting_Pascal_s_Triangles++;
		this->int_number_Rows=int_number_Rows;
		this->ptr_int_Pascal_s_Triangle=NULL;

		Pascal_s_Triangle::view_header_Pascal_s_Triangle("Constructing an object of class 'Pascal's Triangle' from only a given number of rows...");
		Pascal_s_Triangle::create_new_Pascal_s_Triangle(int_number_Rows);
	};

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		Pascal_s_Triangle			**
 **				(const Pascal_s_Triangle	**
 **				&other_Pascal_s_Triangle)	**
 ** Explanation:	Assigns the values of an object of the	**
 **			same type to the new instantiated	**
 **			class.					**
 ** Arguments:		const Pascal_s_Triangle &		**
 **				other_Pascal_s_Triangle.	**
 ** Result:		Assigns the values of the instantiated	**
 **			class passed as a parameter to the	**
 **			created class as if it were a true copy **
 **			of the first.				**
 ****************************************************************/
Pascal_s_Triangle::Pascal_s_Triangle(const Pascal_s_Triangle &other_Pascal_s_Triangle)
	{
		this->sttc_int_Counting_Pascal_s_Triangles++;
		this->int_number_Rows=other_Pascal_s_Triangle.int_number_Rows;
		this->ptr_int_Pascal_s_Triangle=other_Pascal_s_Triangle.ptr_int_Pascal_s_Triangle;

		Pascal_s_Triangle::view_header_Pascal_s_Triangle("Constructing an object 'Pascal's Triangle' class from an existing one...");
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
		Pascal_s_Triangle::view_header_Pascal_s_Triangle("Destroying 'Pascal's Triangle'...");

		this->int_number_Rows=V_ZERO;
		this->sttc_int_Counting_Pascal_s_Triangles--;
	};

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		int capture_int_number_Rows().		**
 ** Explanation:	The purpose of this method is to	**
 **			capture the number of lines that the	**
 **			Pascal's Triangle must have to generate	**
 **			through the pointer of pointers or	**
 **			double pointer, which is part of the	**
 **			attribute of the instantiated class.	**
 ** Arguments:		None.					**
 ** Result:		This routine returns as a result the	**
 **			number of lines that the pointer of	**
 **			pointers will have that contains the	**
 **			Pascal's Triangle to be generated in	**
 **			this class or its instance.		**
 ****************************************************************/
int Pascal_s_Triangle::capture_int_number_Rows()
	{
		int int_number_Rows=V_ZERO;

		Pascal_s_Triangle::view_header_Pascal_s_Triangle("Capturing number of rows of Pascal's Triangle...");

		cout << "Manually enter the number of rows between [" << V_LOWER_LIMIT_ROWS << "] & [" << V_UPPER_LIMIT_ROWS << "] that the Pascal's Triangle will have to generate: ";

		/* Pretreatment to clear the option variable and input buffer. */
		scanf("%*[^\n]%*c"); //Perfectly clear the input buffer.
		cin >> int_number_Rows;

		if (int_number_Rows>=V_LOWER_LIMIT_ROWS && int_number_Rows<=V_UPPER_LIMIT_ROWS)
			{
				Pascal_s_Triangle::clear_Pascal_s_Triangle();
				Pascal_s_Triangle::set_int_number_Rows(int_number_Rows);

				cout << "Warning! The Pascal's Triangle should be generated with the new number of rows: # ["<< int_number_Rows << "] entered." << endl;
			}
		else
			cout << "Careful! An attempt was made to set the number of rows between [" << V_LOWER_LIMIT_ROWS << "] & [" << V_UPPER_LIMIT_ROWS << "] in Pascal's Triangle to an invalid number: [" << int_number_Rows << "]." << endl;

		return int_number_Rows;
	};

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		clear_Pascal_s_Triangle().		**
 ** Explanation:	This method is responsible for		**
 **			initializing the attributes of the	**
 **			number of rows and the pointer of	**
 **			pointers that contains the Pascal's	**
 **			Triangle generated by other calls to	**
 **			the class.				**
 ** Arguments:		None.					**
 ** Result:		Set the number of rows in Pascal's	**
 **			Triangle to zero and initialize the	**
 **			pointer of pointers that holds it.	**
 ****************************************************************/
void Pascal_s_Triangle::clear_Pascal_s_Triangle()
	{
		Pascal_s_Triangle::view_header_Pascal_s_Triangle("Clearing existing Pascal's Triangle...");

		if (this->ptr_int_Pascal_s_Triangle)
			{
				if (this->int_number_Rows>=V_LOWER_LIMIT_ROWS && this->int_number_Rows<=V_UPPER_LIMIT_ROWS)
					{
						cout << "+ Clearing memory regions of 'Pascal's Triangle' object # [" << this->sttc_int_Counting_Pascal_s_Triangles
                                		<< "] with [" << this->int_number_Rows << "] rows at memory address: [" << this->ptr_int_Pascal_s_Triangle << "]..." << endl;

						/* Free the memory allocated to each of the rows. */
						for (int int_n_row=V_ZERO; int_n_row<this->int_number_Rows; int_n_row++)
							{
								cout << "Area # [" << int_n_row << "] of [" << this->int_number_Rows
								<< "].\tMemory Address: [" << this->ptr_int_Pascal_s_Triangle[int_n_row]
								<< "].\tReleased!" << endl;

								free(this->ptr_int_Pascal_s_Triangle[int_n_row]);
							}

						/* Free the memory allocated to the array of pointers. */
						cout << "Final area of memory address [" << this->ptr_int_Pascal_s_Triangle
						<< "] of Pascal's Triangle freed!" << endl;

						free(this->ptr_int_Pascal_s_Triangle);
					}
				else
					cout << "Warning! The Pascal's Triangle to initialize has no a valid number of rows between [" << V_LOWER_LIMIT_ROWS << "] & [" << V_UPPER_LIMIT_ROWS << "] to be generated." << endl;

				this->int_number_Rows=V_ZERO;
				this->ptr_int_Pascal_s_Triangle=NULL;
			}
		else
			cout << "Careful! The Pascal Triangle to be initialized was already prepared with ["<< this->int_number_Rows << "] rows." << endl;
	};

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		void create_new_Pascal_s_Triangle	**
 **				(const int int_number_Rows).	**
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
 ** Arguments:		const int int_number_Rows.		**
 ** Result:		This method generate for each row of	**
 **			the constructed Pascal's Triangle the	**
 **			line number, column number, and 	**
 **			computed value for this pointer of	**
 **			pointers, which is actually a		**
 **			two-dimensional array.			**
 ****************************************************************/
void Pascal_s_Triangle::create_new_Pascal_s_Triangle(const int int_number_Rows)
	{
		Pascal_s_Triangle::view_header_Pascal_s_Triangle("Creating new 'Pascal's Triangle'...");

		if (this->ptr_int_Pascal_s_Triangle)
			if (this->int_number_Rows>=V_LOWER_LIMIT_ROWS && this->int_number_Rows<=V_UPPER_LIMIT_ROWS)
				{
					if (Pascal_s_Triangle::get_bool_Response_Regeneration())
						{
							Pascal_s_Triangle::clear_Pascal_s_Triangle();
							Pascal_s_Triangle::set_int_number_Rows(int_number_Rows);
							Pascal_s_Triangle::generate_new_existing_Pascal_s_Triangle();
						}
				}
			else
				cout << "Warning! An attempt was made to generate an instance of the 'Pascal's Triangle' class without reporting its valid number of rows between [" << V_LOWER_LIMIT_ROWS << "] & [" << V_UPPER_LIMIT_ROWS << "]." << endl;
		else
			if (int_number_Rows>=V_LOWER_LIMIT_ROWS && int_number_Rows<=V_UPPER_LIMIT_ROWS)
				{
					cout << "Regenerating Pascal's Triangle again from the existing rows: # [" << this->int_number_Rows << "] to [" << int_number_Rows << "] new rows..." << endl;

					Pascal_s_Triangle::set_int_number_Rows(int_number_Rows);
					Pascal_s_Triangle::generate_new_existing_Pascal_s_Triangle();
				}
			else
				cout << "Careful! It is not possible to generate a new Pascal's Triangle without having informed its valid number of lines between [" << V_LOWER_LIMIT_ROWS << "] & [" << V_UPPER_LIMIT_ROWS << "]..." << endl;
	};

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		void generate_new_existing_		**
 **				Pascal_s_Triangle().		**
 ** Explanation:	Be very careful with this method,	**
 **			you are protected for a reason.		**
 **			If you already had a Pascal's Triangle	**
 **			housed in a perfectly established	**
 **			pointer, you may inadvertently overwrite**
 **			the variable in question and the old	**
 **			memory contents will be trapped, so it	**
 **			is important to first free the commented**
 **			pointer and then reallocate it to new	**
 **			zones from memory.			**
 ** Arguments:		None.					**
 ** Result:		A new pointer of pointers is generated	**
 **			that will store the new Pascal's	**
 **			Triangle, without previously considering**
 **			whether said pointer was already	**
 **			occupied by another object of the same	**
 **			species.				**
 **			Avoid flooding memory and first make	**
 **			sure that the double pointer is properly**
 **			freed and initialized.			**
 ****************************************************************/
void Pascal_s_Triangle::generate_new_existing_Pascal_s_Triangle()
	{
		int int_coeff_value=V_ZERO;

		if ((this->ptr_int_Pascal_s_Triangle = (int **) malloc(this->int_number_Rows * sizeof(int *))) != NULL)
			{
				cout << "+ Generating on screen a new 'Pascal's Triangle' object # [" << this->sttc_int_Counting_Pascal_s_Triangles
				<< "] with [" << this->int_number_Rows << "] rows at memory address: [" << this->ptr_int_Pascal_s_Triangle << "]..." << endl;

				for (int int_n_row=V_ZERO; int_n_row<this->int_number_Rows; int_n_row++)
					{
						cout << "# " << int_n_row << " of " << this->int_number_Rows << "\t[";

						if ((this->ptr_int_Pascal_s_Triangle[int_n_row] = (int *) malloc((int_n_row+V_ONE) * sizeof(int))) != NULL)
							for (int int_n_col=V_ZERO; int_n_col<=int_n_row; int_n_col++)
								{
									if (int_n_col==V_ZERO || int_n_col==int_n_row)
										int_coeff_value=V_ONE;
									else
										int_coeff_value = this->ptr_int_Pascal_s_Triangle[int_n_row + V_MINUS_ONE][int_n_col + V_MINUS_ONE]
												+ this->ptr_int_Pascal_s_Triangle[int_n_row + V_MINUS_ONE][int_n_col];

									cout << int_coeff_value;

									if (int_n_col<int_n_row) cout << ",\t";

									this->ptr_int_Pascal_s_Triangle[int_n_row][int_n_col] = int_coeff_value;
								}
						else
							cout << "Insufficient memory to create for row: [" << int_n_row << "] of [" << int_number_Rows << "] of Pascal's Triangle." << endl;

						cout << "]." << endl;
					}
			}
		else
			cout << "Insufficient memory to create [" << this->int_number_Rows << "] rows of Pascal's Triangle." << endl;
	};

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		bool get_bool_Response_Regeneration()	**
 **				const.				**
 ** Explanation:	This function returns a boolean true if	**
 **			the existing pointer pointer is required**
 **			to be regenerated and rewritten in the	**
 **			instantiated class that stores the	**
 **			current 'Pascal's Triangle', otherwise	**
 **			another response will prevent the area	**
 **			from being rewritten, regenerated or	**
 **			updated of storage of said triangle.	**
 ** Arguments:		None.					**
 ** Result:		Returns a boolean true if the answer to	**
 **			regenerate 'Pascal's Triangle' is 'Y'	**
 **			or 'y'.					**
 **			Any other character entered as a	**
 **			response will be taken as a boolean	**
 **			false value.				**
 ****************************************************************/
bool Pascal_s_Triangle::get_bool_Response_Regeneration() const
	{
		char chr_response_Yy=NULL_CHARACTER;

		cout << endl;
		cout << "+---|----+---|----+---|----+---|----+---|----+---|----+---|----+---|----+---|----+" << endl;
		cout << "|    Information. There was already a previously generated Pascal's Triangle.    |" << endl;
		cout << "+---|----+---|----+---|----+---|----+---|----+---|----+---|----+---|----+---|----+" << endl;
		cout << "Do you want to redo it and prepare it to create a new one from scratch. (Y/N)? : ";

		/* Pretreatment to clear the option variable and input buffer. */
		scanf("%*[^\n]%*c"); //Perfectly clear the input buffer.
		cin >> chr_response_Yy;

		return (chr_response_Yy == V_CHAR_Y_UPPER_CASE || chr_response_Yy == V_CHAR_Y_LOWER_CASE);
	};

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		int get_int_number_Rows() const.	**
 ** Explanation:	Returns as a result the number of lines	**
 **			or rows for which the generation of a	**
 **			Pascal's Triangle is ready.		**
 ** Arguments:		None.					**
 ** Result:		Returns as result value the number of	**
 **			lines that has the attribute of the	**
 **			number of lines of the			**
 **			'Pascal's Triangle' class.		**
 ****************************************************************/
int Pascal_s_Triangle::get_int_number_Rows() const
	{
		Pascal_s_Triangle::view_header_Pascal_s_Triangle("Getting number of rows to 'Pascal's Triangle'...");

		return this->int_number_Rows;
	};

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		vector<vector<int>>			**
 **				get_vec_vec_matrix		**
 **				Pascal_s_Triangle()		**
 **				const.				**
 ** Explanation:	This routine returns an array in the	**
 **			form of a vector of vectors, with the	**
 **			purpose of making it easier to access	**
 **			the intrinsic elements of the pointer	**
 **			of pointers that contains the Pascal	**
 **			Triangle generated as an attribute of	**
 **			this instantiated class.		**
 ** Arguments:		None.					**
 ** Result:		The routine returns as a value a vector	**
 **			of vectors that dynamically stored the	**
 **			pointer of pointers that contains the	**
 **			Pascal's Triangle generated in the last	**
 **			and most recent instantiated class.	**
 ****************************************************************/
vector<vector<int>> Pascal_s_Triangle::get_vec_vec_matrix_Pascal_s_Triangle() const
	{
		int int_coeff_value=V_ZERO;
		vector<vector<int>> vec_vec_matrix_Pascal_s_Triangle;

		Pascal_s_Triangle::view_header_Pascal_s_Triangle("Generating the vector of vectors from 'Pascal's Triangle' double pointer...");

		if (this->ptr_int_Pascal_s_Triangle)
			if (this->int_number_Rows>=V_LOWER_LIMIT_ROWS && this->int_number_Rows<=V_UPPER_LIMIT_ROWS)
				{
					cout << "Loading vector of 'Pascal's Triangle' vectors. Object # [" << this->sttc_int_Counting_Pascal_s_Triangles
					<< "] with [" << this->int_number_Rows << "] rows from memory address: [" << this->ptr_int_Pascal_s_Triangle << "]..." << endl;

					for (int int_y=V_ZERO; int_y<this->int_number_Rows; int_y++)
						{
							vector<int> vec_columns_Pascal_s_Triangle;

							for (int int_x=V_ZERO; int_x<=int_y; int_x++)
								{
									int_coeff_value=*(*(this->ptr_int_Pascal_s_Triangle+int_y)+int_x);

									cout << "(" << int_y << ", " << int_x << ") :\t<" << &this->ptr_int_Pascal_s_Triangle[int_y][int_x]
									 << "> =\t[" << int_coeff_value << "]." << endl;

									vec_columns_Pascal_s_Triangle.push_back(int_coeff_value);
								}

							cout << endl;

							vec_vec_matrix_Pascal_s_Triangle.push_back(vec_columns_Pascal_s_Triangle);
						}

					cout << "Visualizing vector of 'Pascal's Triangle' vectors. Object # [" << this->sttc_int_Counting_Pascal_s_Triangles
					<< "] with [" << this->int_number_Rows << "] rows from memory address: [" << this->ptr_int_Pascal_s_Triangle << "]..." << endl;

					for (int int_row=V_ZERO; int_row<this->int_number_Rows; int_row++)
						{
							for (int int_col=V_ZERO; int_col<=int_row; int_col++)
								cout << "[" << vec_vec_matrix_Pascal_s_Triangle[int_row][int_col] << "]\t";

							cout << endl;
						}
				}
			else
				cout << "Warning! There is no reported a valid number of rows between [" << V_LOWER_LIMIT_ROWS << "] & [" << V_UPPER_LIMIT_ROWS <<"] to return a vector of vectors from 'Pascal's Triangle'." << endl;
		else
			cout << "Careful! The 'Pascal's Triangle' pointer to pointer is empty or initialized." << endl;

		return vec_vec_matrix_Pascal_s_Triangle;
	};

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		void set_int_number_Rows().		**
 ** Explanation:	Sets the number of rows that Pascal's	**
 **			Triangle should have. This method is	**
 **			ideally called when the current		**
 **			instantiated Triangle is initialized.	**
 ** Arguments:		const int int_number_Rows.		**
 ** Result:		Assigns to the attribute of the class	**
 **			that stores the number of rows of	**
 **			Pascal's Triangle the value passed by	**
 **			current parameter.			**
 **			Protected is recommended fully.		**
 ****************************************************************/
void Pascal_s_Triangle::set_int_number_Rows(const int int_number_Rows)
	{
		this->int_number_Rows=int_number_Rows;

		Pascal_s_Triangle::view_header_Pascal_s_Triangle("Setting number of rows to 'Pascal's Triangle'...");
	};

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		void view_detail_Pascal_s_Triangle()	**
 **				const.				**
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
void Pascal_s_Triangle::view_detail_Pascal_s_Triangle() const
	{
		int int_coeff_value=V_ZERO;

		Pascal_s_Triangle::view_header_Pascal_s_Triangle("Viewing Detail 'Pascal's Triangle'...");

		if (this->ptr_int_Pascal_s_Triangle)
			if (this->int_number_Rows>=V_LOWER_LIMIT_ROWS && this->int_number_Rows<=V_UPPER_LIMIT_ROWS)
				{
					cout << "+ Generating on screen 'Pascal's Triangle' object # [" << this->sttc_int_Counting_Pascal_s_Triangles
					<< "] detail with [" << this->int_number_Rows << "] rows at memory address: [" << this->ptr_int_Pascal_s_Triangle << "]." << endl;

					for (int int_n_row=V_ZERO; int_n_row<this->int_number_Rows; int_n_row++)
						{
							for (int int_n_col=V_ZERO; int_n_col<=int_n_row; int_n_col++)
								cout << "Row: [" << int_n_row << "] of [" << this->int_number_Rows << "].\tCol: ["
								<< int_n_col << "] of [" << int_n_row << "].\tValue = ["
								<< *(*(this->ptr_int_Pascal_s_Triangle+int_n_row)+int_n_col)
								<< "]." << endl;

							cout << endl;
						}
				}
			else
				cout << "Warning! There is no a valid number of lines between [" << V_LOWER_LIMIT_ROWS << "] & [" << V_UPPER_LIMIT_ROWS << "] to display the 'Pascal's Triangle' object report." << endl;
		else
			cout << "Careful! No Pascal's Triangle has been generated. You must generate a new one to view it." << endl;
	};

/*****************************************************************
 ** Class:		Pascal_s_Triangle.			**
 ** Method:		void view_header_Pascal_s_Triangle 	**
 **				(const string			**
 **				 str_name_Proc_Oper) const.	**
 ** Explanation:	This method prints on the screen a	**
 **			header with the main attributes of the	**
 **			instantiated 'Pascal's Triangle' class.	**
 **			This method is recommended protected	**
 **			since it is used as a complement to	**
 **			screen messages with header information	**
 **			for other methods of the same		**
 **			instantiated class.			**
 ** Arguments:		const string str_name_Proc_Oper.	**
 ** Result:		This method returns several screen	**
 **			messages displaying the main attributes	**
 **			of the 'Pascal's Triangle' class and the**
 **			values they hold after each individually**
 **			determined operation.			**
 **			This method is highly recommended	**
 **			protected.				**
 ****************************************************************/
void Pascal_s_Triangle::view_header_Pascal_s_Triangle(const string str_name_Proc_Oper) const
	{
		cout << endl;
		cout << "+---|----+---|----+---|----+---|----+---|----+---|----+---|----+---|----+---|----+" << endl;
		cout << "|                               Pascal's Triangle.                               |" << endl;
		cout << "+---|----+---|----+---|----+---|----+---|----+---|----+---|----+---|----+---|----+" << endl;
		cout << "| Number of instantiated and created object of class 'Pascal's Triangle':\t["
			<< this->sttc_int_Counting_Pascal_s_Triangles << "]" << endl;
		cout << "| Number of rows of the instantiated class 'Pascal's Triangle':\t\t\t["
			<< this->int_number_Rows << "]." << endl;
		cout << "| Memory address of the pointer of pointers to hold the 'Pascal's Triangle':\t["
			<< this->ptr_int_Pascal_s_Triangle << "]." << endl;
		cout << "| Running process of class 'Pascal's Triangle':\t\t\t\t\t[" << str_name_Proc_Oper << "]." << endl;
		cout << "+---|----+---|----+---|----+---|----+---|----+---|----+---|----+---|----+---|----+" << endl;
		cout << endl;
	};

/*****************************************************************
 ** Class:              Pascal_s_Triangle.			**
 ** Method:             void view_info_class_Pascal_s_Triangle()**
 **				const.				**
 ** Explanation:	The purpose of this method is to display**
 **			general information on the value of the	**
 **			attributes of the 'Pascal's Triangle'	**
 **			class on the screen.			**
 ** Arguments:          None.					**
 ** Result:		Returns as a result a series of messages**
 **			on the screen about the general		**
 **			information of the attributes contained	**
 **			in the class 'Pascal's Triangle'.	**
 ****************************************************************/
void Pascal_s_Triangle::view_info_class_Pascal_s_Triangle() const
	{
		Pascal_s_Triangle::view_header_Pascal_s_Triangle("Viewing Info Class 'Pascal's Triangle'...");

		if (this->ptr_int_Pascal_s_Triangle)
			if (this->int_number_Rows>=V_LOWER_LIMIT_ROWS && this->int_number_Rows<=V_UPPER_LIMIT_ROWS)
				{
					cout << "+ Generating on screen 'Pascal's Triangle' object # [" << this->sttc_int_Counting_Pascal_s_Triangles
					<< "] info class with [" << this->int_number_Rows << "] rows at memory address: [" << this->ptr_int_Pascal_s_Triangle << "]." << endl;

					for (int int_n_row=V_ZERO; int_n_row<this->int_number_Rows; int_n_row++)
						{
							cout << "+ Row: [" << int_n_row << "] of [" << this->int_number_Rows << "].\tMemory address: ["
							<< this->ptr_int_Pascal_s_Triangle[int_n_row]
							<< "]." << endl;

							for (int int_n_col=V_ZERO; int_n_col<=int_n_row; int_n_col++)

								cout << "  - Col: [" << int_n_col << "] of [" << int_n_row << "].\tMemory address: ["
								<< &this->ptr_int_Pascal_s_Triangle[int_n_row][int_n_col]
								<< "].\tValue = [" << *(*(this->ptr_int_Pascal_s_Triangle+int_n_row)+int_n_col)
								<< "]." << endl;

							cout << endl;
						}
				}
			else
				cout << "Warning! There is no a valid row number between [" << V_LOWER_LIMIT_ROWS << "] & [" << V_UPPER_LIMIT_ROWS << "] to display the report of the object of the generated class 'Pascal's Triangle'." << endl;
		else
			cout << "Careful! Pascal's Triangle is empty or has not been generated before." << endl;
	};

/*****************************************************************
 ** Class:              inline std::ostream			**
 ** Method:             &operator<<.				**
 **				(std::ostream &os,		**
 **				const Pascal_s_Triangle &psT)	**
 ** Explanation:	Declaration as a friend of the		**
 **			non-member overload.			**
 **			This overloaded friend function takes	**
 **			care of using the << operator when	**
 **			calling the std::cout function to	**
 **			directly send the 'Pascal's Triangle'	**
 **			class to standard output and display	**
 **			basic information on its three main	**
 **			attributes: instantiated object number,	**
 **			number of rows and coefficients of the	**
 **			generated Pascal's triangle.		**
 ** Arguments:          (std::ostream &os,			**
 **				const Pascal_s_Triangle &psT)	**
 ** Result:		This overloaded external function of	**
 **			the Pascal's Triangle friend class uses	**
 **			its own flow and displays the		**
 **			information of the main attributes of	**
 **			the aforementioned instantiated class,	**
 **			briefly, in order to know its content	**
 **			without resorting to so much detailed	**
 **			information.				**
 ****************************************************************/
inline std::ostream &operator<< (std::ostream &os, const Pascal_s_Triangle &psT)
	{
		if (psT.ptr_int_Pascal_s_Triangle)
			if (psT.int_number_Rows>=V_LOWER_LIMIT_ROWS && psT.int_number_Rows<=V_UPPER_LIMIT_ROWS)
				{
					os << endl;

					for (int int_n_row=V_ZERO; int_n_row<psT.int_number_Rows; int_n_row++)
						{
							for (int int_n_col=V_ZERO; int_n_col<=int_n_row; int_n_col++)
								os << psT.ptr_int_Pascal_s_Triangle[int_n_row][int_n_col] << "\t";

							os << endl;
						}
				}
			else
				os << "Warning! There is no reported a valid number of rows between [" << V_LOWER_LIMIT_ROWS << "] & [" << V_UPPER_LIMIT_ROWS << "] to display Pascal's Triangle." << endl;
		else
			os << "Careful! Pascal's Triangle is empty or non-existent. Generate it right now!" << endl;

		return os;
	};


/*----------------------------------------------------------------
 ** enum enm_Action_Options_Pascal_s_Triangle.			--
 * +---|----+---|----+---|----+---|----+---|----+---|----+---|+	--
 ** This enumerated type stores all the options with which the	--
 ** user can manipulate the class he instantiates at the time	--
 ** of Pascal's Triangle.					--
 **-------------------------------------------------------------*/
enum enm_Action_Options_Pascal_s_Triangle
	{
		enm_act_opt_PST_absent_option,
		enm_act_opt_PST_capture_int_number_Rows,
		enm_act_opt_PST_clear_Pascal_s_Triangle,
		enm_act_opt_PST_create_new_Pascal_s_Triangle,
		enm_act_opt_PST_get_int_number_Rows,
		enm_act_opt_PST_get_vec_vec_matrix_Pascal_s_Triangle,
		enm_act_opt_PST_view_detail_Pascal_s_Triangle,
		enm_act_opt_PST_view_info_class_Pascal_s_Triangle,
		enm_act_opt_PST_view_quick_info
	} enm_act_opt_PST;

/*****************************************************************
 ** Function:           void do_unit_Testing_Pascal_s_Triangle	**
 **				(const int int_Quantity);	**
 ** Explanation:	The purpose of this function is to call	**
 **			another function that performs unit	**
 **			tests with each class instance of	**
 **			'Pascal's Triangle', controlling that	**
 **			each instantiated or generated class is	**
 **			saved in a vector of the same class	**
 **			type.					**
 ** Input Parms:	const int int_Quantity.			**
 ** Output Parms:       None.                                   **
 ** Result:		This function carries out a series of	**
 **			iterations to create 'n' number of	**
 **			instances of Pascal's Triangle, then	**
 **			calls a friendly function that gives its**
 **			own treatment to each instance that is	**
 **			called by successive iterations.	**
 ****************************************************************/
void do_principal_unit_Testing_Pascal_s_Triangle(const int int_Quantity)
	{
		int int_number_Operations=V_ZERO;

		Pascal_s_Triangle *ptr_obj_Pascal_s_Triangle=nullptr;
		vector <Pascal_s_Triangle> vec_Pascal_s_Triangle;
		vector <Pascal_s_Triangle>::iterator it_vec_Pascal_s_Triangle;

		/* Each instance of Pascal's Triangle is created dynamically. */
		for (int int_n=V_ZERO; int_n<int_Quantity; int_n++)
			{
				cout << "Creating 'Pascal's Triangle' instance # [" << int_n << "] of [" << int_Quantity << "]..." << endl;

				cout << "Assigning new instance..." << endl;
				ptr_obj_Pascal_s_Triangle=new Pascal_s_Triangle();

				cout << "Storing it in vector..." << endl;
				vec_Pascal_s_Triangle.push_back(*ptr_obj_Pascal_s_Triangle);

				cout << "Destroying created instance..." << endl;
				delete ptr_obj_Pascal_s_Triangle;

				cout << "Instance of Pascal's Triangle # [" << int_n << "] of [" << int_Quantity << "] consolidated..." << endl;
			}

		/* Each created instance of Pascal's Triangle is traversed one by one. */
		for (it_vec_Pascal_s_Triangle=std::begin(vec_Pascal_s_Triangle);
			it_vec_Pascal_s_Triangle!=std::end(vec_Pascal_s_Triangle); it_vec_Pascal_s_Triangle++)
			{
				cout << "Starting main unit tests of Pascal's Triangle..." << endl;
				int_number_Operations=int_unit_Testing_Pascal_s_Triangle(*it_vec_Pascal_s_Triangle);
				cout << "Triangle's Pascal operations number performed: [" << int_number_Operations << "]." << endl;
			}
	};

/*****************************************************************
 ** Function:           int int_unit_Testing_Pascal_s_Triangle	**
 **				(Pascal_s_Triangle &psT).	**
 ** Explanation:	This is a unit testing function that	**
 **			puts a simple menu for the user to make	**
 **			combinations of all the methods used by	**
 **			the Pascal's Triangle instantiated	**
 **			class, and change each such instance	**
 **			according to the user's preferences.	**
 ** Input Parms:	Pascal_s_Triangle &psT.			**
 ** Output Parms:       None.                                   **
 ** Result:		This function that returns the number of**
 **			operations performed on a Pascal's	**
 **			Triangle, and that displays a menu for	**
 **			the user to manipulate at will, entering**
 **			an option from the keyboard, to		**
 **			manipulate the instantiated class	**
 **			received from Pascal's Triangle.	**
 ****************************************************************/
int int_unit_Testing_Pascal_s_Triangle(Pascal_s_Triangle &psT)
	{
		int int_number_Rows=V_ZERO;
		int int_number_Operations=V_ZERO;
		int int_number_Option=V_ZERO;

		vector<vector<int>> vec_vec_matrix_Pascal_s_Triangle;

		do
			{
				cout << endl;
				cout << "*===|====+===|====+===|====+===|====+===*" << endl;
				cout << "| Current Managed Instances: # ["
					<< psT.sttc_int_Counting_Pascal_s_Triangles
					<< "].     |" << endl;
				cout << "+---------------------------------------+" << endl;
				cout << "| Menu to maneuver Pascal's Triangles.  |" << endl;
				cout << "+---|----+---|----+---|----+---|----+---+" << endl;
				cout << "|         Options for updating.         |" << endl;
				cout << "+---|----+---|----+---|----+---|----+---+" << endl;
				cout << "| [1]. Capture its number of rows.      |" << endl;
				cout << "| [2]. Clear the Triangle.              |" << endl;
				cout << "| [3]. Create/generate a new one.       |" << endl;
				cout << "+---|----+---|----+---|----+---|----+---+" << endl;
				cout << "|          Options for display.         |" << endl;
				cout << "+---|----+---|----+---|----+---|----+---+" << endl;
				cout << "| [4]. Get its number of rows.          |" << endl;
				cout << "| [5]. Get Triangle's matrix.           |" << endl;
				cout << "+---------------------------------------+" << endl;
				cout << "| [6]. View details info.               |" << endl;
				cout << "| [7]. View general info.               |" << endl;
				cout << "| [8]. View quick   info.               |" << endl;
				cout << "+---------------------------------------+" << endl;
				cout << "| [Another value]. Exit treatment.      |" << endl;
				cout << "*===|====+===|====+===|====+===|====+===*" << endl;

				/* Pretreatment to clear the option variable and input buffer. */
				scanf("%*[^\n]%*c"); //Perfectly clear the input buffer.
				int_number_Option=V_ZERO; //Reset the option pressed by the user.

				/* Request the action option and convert it to an enumerated type. */
				cout << "Option: ";
				cin >> int_number_Option;
				enm_act_opt_PST = (enum enm_Action_Options_Pascal_s_Triangle) int_number_Option;

				/* Selection of cases according to the given option. */
				switch (enm_act_opt_PST)
					{
						case enm_act_opt_PST_capture_int_number_Rows:
							int_number_Rows = psT.capture_int_number_Rows();
							int_number_Operations++;
							break;

						case enm_act_opt_PST_clear_Pascal_s_Triangle:
							psT.clear_Pascal_s_Triangle();
							int_number_Operations++;
							break;

						case enm_act_opt_PST_create_new_Pascal_s_Triangle:
							psT.create_new_Pascal_s_Triangle(int_number_Rows);
							int_number_Operations++;
							break;

						case enm_act_opt_PST_get_int_number_Rows:
							int_number_Rows = psT.get_int_number_Rows();
							int_number_Operations++;
							break;

						case enm_act_opt_PST_get_vec_vec_matrix_Pascal_s_Triangle:
							vec_vec_matrix_Pascal_s_Triangle=psT.get_vec_vec_matrix_Pascal_s_Triangle();
							int_number_Operations++;
							break;

						case enm_act_opt_PST_view_detail_Pascal_s_Triangle:
							psT.view_detail_Pascal_s_Triangle();
							int_number_Operations++;
							break;

						case enm_act_opt_PST_view_info_class_Pascal_s_Triangle:
							psT.view_info_class_Pascal_s_Triangle();
							int_number_Operations++;
							break;

						case enm_act_opt_PST_view_quick_info:
							cout << psT << endl;
							int_number_Operations++;
							break;

						default:
							cout << "Pascal's Triangle is exiting. Typed Option: [" << int_number_Option << "]." << endl;
							break;
					}

			} while (enm_act_opt_PST >= enm_act_opt_PST_capture_int_number_Rows &&
				 enm_act_opt_PST <= enm_act_opt_PST_view_quick_info);

		return int_number_Operations;
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
		int int_Quantity=V_ZERO;

		cout << endl;
		cout << "+---|----+---|----+---|----+---|----+---|----+---|----+---|----+---|----+---|----+" << endl;
		cout << "|                         Pascal's Triangle Generator.                           |" << endl;
		cout << "+---|----+---|----+---|----+---|----+---|----+---|----+---|----+---|----+---|----+" << endl;
		cout << "Number of Pascal's Triangles to generate between ["<< V_LOWER_LIMIT_PST << "] and [" << V_UPPER_LIMIT_PST << "] : ";
		cin  >> int_Quantity;

		/* -----------------------------------------------------------------------
		 * -- Dynamically create pointers of the Pascal's Triangle class, store	--
		 * -- each one in a vector class, and destroy each class pointer.	--
		 * ---------------------------------------------------------------------*/
		if (int_Quantity>=V_LOWER_LIMIT_PST && int_Quantity<=V_UPPER_LIMIT_PST)
			do_principal_unit_Testing_Pascal_s_Triangle(int_Quantity);
		else
			cout << "Error! The quantity value [" << int_Quantity << "] is not between [" << V_LOWER_LIMIT_PST << "] and [" << V_UPPER_LIMIT_PST << "]." << endl;

		return V_ZERO;
	}
