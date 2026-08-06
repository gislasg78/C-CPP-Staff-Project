/* Program that dynamically allocates memory in C++
   to store a series of given matrices, each with a variable number of rows,
   and each of its respective rows with a variable number of columns.*/

/* Standard work libraries. */
#include <iostream>
#include <limits>

/* Symbolic work constants. */
template <typename T>
constexpr T	CARRIAGE_RETURN		{static_cast<T>('\n')};
template <typename T>
constexpr T	V_ONE			{T(1)};
template <typename T>
constexpr T	V_ZERO			{T(0)};

/* This function creates and captures both the three-dimensional dynamic variable array
   and the two arrays storing the row and column limits of that main array. */
template <typename TX, typename TY>
TX create_matrix_3D (const TX& n_matrix, TY*** &matrix, TX* &matrix_r, TX** &matrix_rxc)
	{
		/* Main header messages. */
		std::cout << std::endl << "Memory assigning spaces..." << std::endl;

		/* Preliminary working variables. */
		TX items {V_ZERO<TX>};	//Initializing items number.
		matrix = nullptr;
		matrix_r = nullptr;
		matrix_rxc = nullptr;

		/* Supplementary allowances. */
		matrix = new TY** [n_matrix]();
		matrix_r = new TX [n_matrix]();
		matrix_rxc = new TX* [n_matrix]();

		/* General loading cycles of dynamic pointer pointers. */
		std::cout << std::endl << "Capturing values..." << std::endl;

		/* Dynamic memory is allocated to know the number of matrices to be generated. */
		for (TX m {V_ZERO<TX>}; m < n_matrix; m++)		//Cycle by matrix.
			{
				std::cout << "For the matrix #: [" << m + V_ONE<TX> << "] of [" << n_matrix << "]." << std::endl;
				std::cout << "How many lines will it generate for it? : ";
				std::cin >> matrix_r[m];	//Number of matrices to store.

				/* Dynamic memory is allocated for each matrix to know the number of rows it will have. */
				matrix[m] = new TY* [matrix_r[m]]();	//Number of rows for each matrix.
				matrix_rxc[m] = new TX [matrix_r[m]]();

				for (TX r {V_ZERO<TX>}; r < matrix_r[m]; r++)	//Cycle through each row of each matrix.
					{
						std::cout << "For the matrix #: [" << m + V_ONE<TX> << "] of [" << n_matrix << "], and its row #: [" << r + V_ONE<TX> << "] of [" << matrix_r[m] << "]." << std::endl;
						std::cout << "How many columns will it generate for it and its respective row? : ";
						std::cin >> matrix_rxc[m][r];	//Number of rows for each matrix created.

						/* Dynamic memory is allocated for each row of the matrix in concurrent turn to know the number of columns it will have. */
						matrix[m][r] = new TY [matrix_rxc[m][r]]();	//Number of columns per row of each matrix.

						for (TX c {V_ZERO<TX>}; c < matrix_rxc[m][r]; c++)	//Cycle through each column of each row of each matrix.
							{
								std::cout << "Enter a value #: " << items++ << " for Matrix #: [" << m + V_ONE<TX> << "] of [" << n_matrix << "] -> (Row: [" << r + V_ONE<TX> << "] of [" << matrix_r[m] << "], Column: [" << c + V_ONE<TX> << "] of [" << matrix_rxc[m][r] << "]) : ";
								std::cin >> matrix[m][r][c];	//Value according to number of column per row of each matrix created.

								std::cout << "(Matrix: [" << m + V_ONE<TX> << "] of [" << n_matrix << "], Row: [" << r + V_ONE<TX> << "] of [" << matrix_r[m] << "], Column: [" << c + V_ONE<TX> << "] of [" << matrix_rxc[m][r] << "]) = [" << matrix[m][r][c] << "]." << std::endl;
							}

						std::cout << std::endl;
					}

				std::cout << std::endl;
			}
		std::cout << "[" << items << "] Captured input values." << std::endl;

		/* Return and refund of the calculated amount. */
		return items;
	}

/* Function that pauses execution until a key is pressed to continue. */
void enter_a_pause(const std::string& str_Message)
	{
		std::cout << str_Message;
		std::cin.clear();
		std::cin.get();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);
	}

/* Function that cleans up and frees the three-dimensional dynamic matrix and its auxiliary matrices. */
template <typename TX, typename TY>
TX release_matrix_3D(const TX& n_matrix, TY*** &matrix, TX* &matrix_r, TX** &matrix_rxc)
	{
		/* Preliminary working variables. */
		TX items {V_ZERO<TX>};

		/* The allocated memory is freed from each allocated row of each created array. */
		std::cout << std::endl << "Freeing the memory of all dynamically allocated pointers..." << std::endl;

		/* Freeing each memory space allocated to each array. */
		for (TX m {V_ZERO<TX>}; m < n_matrix; m++)
			{
				std::cout << "Deallocating memory for array #: [" << m + V_ONE<TX> << "] of [" << n_matrix << "]." << std::endl;

				/* Freeing each memory space allocated to each row of each matrix. */
				for (TX r {V_ZERO<TX>}; r < matrix_r[m]; r++, items++)
					{
						std::cout << "\tDeallocating memory for its row #: [" << r + V_ONE<TX> << "] of [" << matrix_r[m] << "]." << std::endl;

						delete [] matrix[m][r];	//Deallocate each row of each matrix.
						matrix[m][r] = nullptr;	//Zero out each row of the three-dimensional matrix.
					}

				delete [] matrix[m];		//Deallocate each array.
				matrix[m] = nullptr;		//Nullify each array.

				delete [] matrix_rxc[m];	//Deallocate each col of row.
				matrix_rxc[m] = nullptr;	//Nullify each col of row.

				std::cout << std::endl;
			}

		/* Higher-order pointers are deallocated. */
		std::cout << "Evicting main memory addresses..." << std::endl;

		delete [] matrix_rxc;	//Deallocate cols by rows.
		matrix_rxc = nullptr;	//Zero out cols by rows.

		delete [] matrix_r;	//Deallocate rows by matrix.
		matrix_r = nullptr;	//Zero out rows by matrix.

		delete [] matrix;	//Deallocate matrix 3D.
		matrix = nullptr;	//Zero out matrix 3D.

		/* Return and refund of the calculated amount. */
		return items;
	}

/* This function displays the values ​​contained in the various dynamically created matrices. */
template <typename TX, typename TY>
TX view_matrix_3D(const TX& n_matrix, const TY *const *const *const &matrix, const TX *const &matrix_r, const TX *const *const &matrix_rxc)
	{
		/* Preliminary working variables. */
		TX items {V_ZERO<TX>};

		/* Process of dumping each column, each row, each matrix. */
		std::cout << std::endl << "Displaying captured values..." << std::endl;

		/* Dump of each matrix. */
		for (TX m {V_ZERO<TX>}; m < n_matrix; m++)
			{
				std::cout << "Matrix: [" << m + V_ONE<TX> <<"] of [" << n_matrix << "]." << std::endl;

				/* Dump of each row of each matrix. */
				for (TX r {V_ZERO<TX>}; r < *(matrix_r + m); r++)
					{
						std::cout << "\tRow: [" << r + V_ONE<TX> << "] of [" << *(matrix_r + m) << "]." << std::endl;

						/* Dump of each column of each row of each matrix. */
						for (TX c {V_ZERO<TX>}; c < *(*(matrix_rxc + m) + r); c++, items++)
							{
								std::cout << "\t\tColumn: [" << c + V_ONE<TX> << "] of [" << *(*(matrix_rxc + m) + r) << "].\t";
								std::cout << "(" << m + V_ONE<TX> << ", " << r + V_ONE<TX> << ", " << c + V_ONE<TX> << ") = [" << matrix[m][r][c] << "]." << std::endl;
							}

						std::cout << std::endl;
					}

				std::cout << std::endl;
			}
		std::cout << "[" << items << "] Generated output results." << std::endl;

		/* Return and refund of the calculated amount. */
		return items;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		size_t items {};
		size_t n_matrix {};	//Number of dynamic matrices to generate.

		/* Three, two and one dimension dynamic pointers. */
		int ***matrix {nullptr};
		size_t *matrix_r {nullptr};
		size_t **matrix_rxc {nullptr};

		/* Header messages. */
		std::cout << "Highly dynamic pointer generator." << std::endl;
		std::cout << "How many rectangular arrangements do you want to create? : ";
		std::cin >> n_matrix;

		/* Function that dynamically creates and captures the three-dimensional matrix. */
		items = create_matrix_3D<std::size_t, int>(n_matrix, matrix, matrix_r, matrix_rxc);
		std::cout << std::endl << "[" << items << "] Items created." << std::endl;
		enter_a_pause("Press the ENTER key to continue...");

		/* Visualize each element of the three-dimensional matrix and its auxiliary matrices. */
		items = view_matrix_3D<std::size_t, int>(n_matrix, matrix, matrix_r, matrix_rxc);
		std::cout << std::endl << "[" << items << "] Items displayed." << std::endl;
		enter_a_pause("Press the ENTER key to continue...");

		/* Deallocation of the memory assigned to each auxiliary matrix and the dynamic three-dimensional matrix. */
		items = release_matrix_3D<std::size_t, int>(n_matrix, matrix, matrix_r, matrix_rxc);
		std::cout << std::endl << "[" << items << "] Items released." << std::endl;
		enter_a_pause("Press the ENTER key to continue...");

		/* Program closure notice. */
		std::cout << std::endl << "[End of the assigment!]." << std::endl;
		std::cout << CARRIAGE_RETURN<char> << "Done!" << CARRIAGE_RETURN<char>;
		std::cout << "This program has ended." << CARRIAGE_RETURN<char>;

		return EXIT_SUCCESS;
	}
