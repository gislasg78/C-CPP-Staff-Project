/* Program that dynamically allocates memory in C++  to store a series of given matrices,
   each with a variable number of rows, and each of its respective rows
   with a variable number of columns. */

/* Standard work libraries. */
#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>

/* Symbolic work constants. */
template <typename T>
constexpr T	CARRIAGE_RETURN		{static_cast<T>('\n')};
template <typename T>
constexpr T	V_ONE			{T(1)};
template <typename T>
constexpr T	V_ZERO			{T(0)};

/* Preliminary function prototypes. */
template <typename TX, typename TY>
TX create_matrix_3D (const TX& n_matrix, TY*** &matrix, TX* &matrix_r, TX** &matrix_rxc);
template <typename TX, typename TY>
TX destroy_matrix_3D(const TX& n_matrix, TY*** &matrix, TX* &matrix_r, TX** &matrix_rxc);
template <typename T>
const T& getEntry(T *const &ptr_value);
/* Function that pauses execution until a key is pressed to continue. */
void getPause(const std::string& str_Message);
template <typename TX, typename TY>
TX view_matrix_3D(const TX& n_matrix, const TY *const *const *const &matrix, const TX *const &matrix_r, const TX *const *const &matrix_rxc);

/* This function creates and captures both the three-dimensional dynamic variable array
   and the two arrays storing the row and column limits of that main array. */
template <typename TX, typename TY>
TX create_matrix_3D (const TX& n_matrix, TY*** &matrix, TX* &matrix_r, TX** &matrix_rxc)
	{
		/* Preliminary working variables. */
		TX items {V_ZERO<TX>};	//Initializing items number.

		/* Validate that the parameters of this function have valid initial values. */
		if ((n_matrix))
			{
				/* Main header messages. */
				std::cout << std::endl << "Initializing memory spaces..." << std::endl;

				/* Preliminary initializers. */
				matrix = nullptr;
				matrix_r = nullptr;
				matrix_rxc = nullptr;

				/* Supplementary allowances. */
				std::cout << "Assigning dynamic memory addresses..." << std::endl;

				/* The initial space is first allocated for the number of two-dimensional arrays to be stored. */
				if ((matrix = new TY** [n_matrix]()))	//Space is generated for the first dimension of a three-dimensional array.
					{
						if ((matrix_r = new TX [n_matrix]()))	//Space is generated for the first dimension of a two-dimensional array.
							{
								if ((matrix_rxc = new TX* [n_matrix]()))	//Space is generated for the only dimension of a one-dimensional array.
									{
										/* General loading cycles of dynamic pointer pointers. */
										std::cout << "Capturing values..." << std::endl;

										/* Dynamic memory is allocated to know the number of matrices to be generated. */
										for (TX m {V_ZERO<TX>}; m < n_matrix; m++)		//Cycle by matrix.
											{
												std::cout << "For the matrix #: [" << m + V_ONE<TX> << "] of [" << n_matrix << "]." << std::endl;
												std::cout << "How many lines will it generate for it? : ";
												matrix_r[m] = getEntry<TX>(&matrix_r[m]);	//Number of matrices to store.

												/* Dynamic memory is allocated for each matrix to know the number of rows it will have. */
												if ((matrix[m] = new TY* [matrix_r[m]]()))	//Number of rows for each matrix.
													{
														if ((matrix_rxc[m] = new TX [matrix_r[m]]()))
															{
																for (TX r {V_ZERO<TX>}; r < matrix_r[m]; r++)	//Cycle through each row of each matrix.
																	{
																		std::cout << "For the matrix #: [" << m + V_ONE<TX> << "] of [" << n_matrix << "], and its row #: [" << r + V_ONE<TX> << "] of [" << matrix_r[m] << "]." << std::endl;
																		std::cout << "How many columns will it generate for it and its respective row? : ";
																		matrix_rxc[m][r] = getEntry<TX>(&matrix_rxc[m][r]);	//Number of rows for each matrix created.

																		/* Dynamic memory is allocated for each row of the matrix in concurrent turn to know the number of columns it will have. */
																		if ((matrix[m][r] = new TY [matrix_rxc[m][r]]()))	//Number of columns per row of each matrix.
																			{
																				for (TX c {V_ZERO<TX>}; c < matrix_rxc[m][r]; c++)	//Cycle through each column of each row of each matrix.
																					{
																						std::cout << "Enter a value #: " << items++ << " for Matrix #: [" << m + V_ONE<TX> << "] of [" << n_matrix << "] -> (Row: [" << r + V_ONE<TX> << "] of [" << matrix_r[m] << "], Column: [" << c + V_ONE<TX> << "] of [" << matrix_rxc[m][r] << "]) : ";
																						matrix[m][r][c] = getEntry<TY>(&matrix[m][r][c]);	//Value according to number of column per row of each matrix created.

																						std::cout << "(Matrix: [" << m + V_ONE<TX> << "] of [" << n_matrix << "], Row: [" << r + V_ONE<TX> << "] of [" << matrix_r[m] << "], Column: [" << c + V_ONE<TX> << "] of [" << matrix_rxc[m][r] << "]) = [" << matrix[m][r][c] << "]." << std::endl;
																					}

																				std::cout << std::endl;
																			}
																		else
																			std::cerr << std::endl << "Error! Insufficient memory allocation: Matrix 3D. [" << m + V_ONE<TX> << "] of [" << n_matrix << "]. Rows: [" << r + V_ONE<TX> << "] of [" << matrix_r[m] << "]." << std::endl;

																		std::cout << std::endl;
																	}
															}
														else
															std::cerr << std::endl << "Error! Insufficient memory allocation: Matrix rows by columns. [" << m + V_ONE<TX> << "] of [" << n_matrix << "]." << std::endl;
													}
												else
													std::cerr << std::endl << "Error! Insufficient memory allocation: Matrix 3D. [" << m + V_ONE<TX> << "] of [" << n_matrix << "]." << std::endl;
											}

										std::cout << "[" << items << "] Captured input values." << std::endl;
									}
								else
									std::cerr << std::endl << "Error! Insufficient memory allocation. Matrix rows by columns. [" << n_matrix << "]." << std::endl;
							}
						else
							std::cerr << std::endl << "Error! Insufficient memory allocation. Matrix by rows. [" << n_matrix << "]." << std::endl;
					}
				else
					std::cerr << std::endl << "Error! Insufficient memory allocation. Matrix 3D. [" << n_matrix << "]." << std::endl;
			}
		else
			{
				/* Error messages for critical validation. */
				std::cerr << std::endl << "Incorrect input values ​​for creating the matrix." << std::endl;
				std::cerr << "+ Matrices:\t\t\t[" << n_matrix << "]." << std::endl;
				std::cerr << "+ Matrix 3D:\t\t\t[" << matrix << "]." << std::endl;
				std::cerr << "+ Matrix rows:\t\t\t[" << matrix_r << "]." << std::endl;
				std::cerr << "+ Matrix rows by columns:\t[" << matrix_rxc << "]." << std::endl;
			}

		/* Return and refund of the calculated amount. */
		return items;
	}

/* Function that cleans up and frees the three-dimensional dynamic matrix and its auxiliary matrices. */
template <typename TX, typename TY>
TX destroy_matrix_3D(const TX& n_matrix, TY*** &matrix, TX* &matrix_r, TX** &matrix_rxc)
	{
		/* Preliminary working variables. */
		TX items {V_ZERO<TX>};

		/* Validate that the parameters of this function have valid initial values. */
		if ((n_matrix) && (matrix) && (matrix_r) && (matrix_rxc))
			{
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

								delete [] matrix[m][r];	//Clear the three-dimensional matrix by rows.
								matrix[m][r] = nullptr;	//Zero out each row of the three-dimensional matrix.
							}

						delete [] matrix[m];		//Clear the three-dimensional matrix by matrices.
						matrix[m] = nullptr;		//Nullify each array.

						delete [] matrix_rxc[m];	//Clear the matrix, row by row, matrix by matrix.
						matrix_rxc[m] = nullptr;	//Nullify each col of row.

						std::cout << std::endl;
					}

				/* Higher-order pointers are deallocated. */
				std::cout << "Evicting main memory addresses..." << std::endl;

				delete [] matrix_rxc;	//Clear the matrix, row by row, matrix by matrix.
				matrix_rxc = nullptr;	//Zero out cols by rows.

				delete [] matrix_r;	//Clear the matrix, row by row.
				matrix_r = nullptr;	//Zero out rows by matrix.

				delete [] matrix;	//Clear the three-dimensional matrix.
				matrix = nullptr;	//Zero out matrix 3D.
			}
		else
			{
				/* Error messages for critical validation. */
				std::cerr << std::endl << "Incorrect input values ​​for creating the matrix." << std::endl;
				std::cerr << "+ Matrices:\t\t\t[" << n_matrix << "]." << std::endl;
				std::cerr << "+ Matrix 3D:\t\t\t[" << matrix << "]." << std::endl;
				std::cerr << "+ Matrix rows:\t\t\t[" << matrix_r << "]." << std::endl;
				std::cerr << "+ Matrix rows by columns:\t[" << matrix_rxc << "]." << std::endl;
			}

		/* Return and refund of the calculated amount. */
		return items;
	}

/* A function responsible for receiving an argument of type (void *) and the type of conversion—specified via an enumerated set—to be performed. */
template <typename T>
const T& getEntry(T *const &ptr_value)
	{
		/* Verify that a valid and correct memory address is sent. */
		if (ptr_value)
			{
				std::string str_value {std::string()};

				/* Verify that the input received is correct and valid. */
				if (std::getline(std::cin >> std::ws, str_value))
					{
						str_value.erase(std::remove_if(str_value.begin(), str_value.end(), ::isspace), str_value.end());
						std::stringstream(str_value) >> *ptr_value;

						std::cout << "+ Characters:\t\t[" << std::cin.gcount() << "]." << std::endl;
						std::cout << "+ Value entered:\t[" << *ptr_value << "]. OK!" << std::endl << std::endl;
					}
				else
					{
						std::cerr << std::endl << std::endl << "Incorrect input information." << std::endl;

						if (std::cin.eof())
							std::cerr << "* EOF detected! *" << std::endl;

						if (std::cin.fail())
							std::cerr << "* Keyboard error detected! *" << std::endl;

						char c{};
						while (std::cin.get(c));

						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);

						std::cerr << "> Throwing overflow exception..." << std::endl << std::endl;
						throw std::overflow_error("The information coming from the keyboard input is overloaded!");
					}
			}
		else
			{
				std::cerr << std::endl << "A valid memory address was not provided." << std::endl << std::endl;
				throw std::runtime_error("The memory location must be valid and not a null pointer!");
			}

		return (ptr_value) ? *ptr_value : V_ZERO<T>;
	}

/* Function that pauses execution until a key is pressed to continue. */
void getPause(const std::string& str_Message)
	{
		std::cout << str_Message;
		std::cin.clear();
		std::cin.get();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN<char>);
	}

/* This function displays the values ​​contained in the various dynamically created matrices. */
template <typename TX, typename TY>
TX view_matrix_3D(const TX& n_matrix, const TY *const *const *const &matrix, const TX *const &matrix_r, const TX *const *const &matrix_rxc)
	{
		/* Preliminary working variables. */
		TX items {V_ZERO<TX>};

		/* Validate that the parameters of this function have valid initial values. */
		if ((n_matrix) && (matrix) && (matrix_r) && (matrix_rxc))
			{
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
										std::cout << "(" << m + V_ONE<TX> << ", " << r + V_ONE<TX> << ", " << c + V_ONE<TX> << ") = [" << matrix[m][r][c] << "] : [" << *(*(*(matrix + m) + r) + c) << "]." << std::endl;
									}

								std::cout << std::endl;
							}

						std::cout << std::endl;
					}

				std::cout << "[" << items << "] Generated output results." << std::endl;
			}
		else
			{
				/* Error messages for critical validation. */
				std::cerr << std::endl << "Incorrect input values ​​for creating the matrix." << std::endl;
				std::cerr << "+ Matrices:\t\t\t[" << n_matrix << "]." << std::endl;
				std::cerr << "+ Matrix 3D:\t\t\t[" << matrix << "]." << std::endl;
				std::cerr << "+ Matrix rows:\t\t\t[" << matrix_r << "]." << std::endl;
				std::cerr << "+ Matrix rows by columns:\t[" << matrix_rxc << "]." << std::endl;
			}

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
		n_matrix = getEntry<size_t>(&n_matrix);

		/* Function that dynamically creates and captures the three-dimensional matrix. */
		try
			{
				if ((items = create_matrix_3D<std::size_t, int>(n_matrix, matrix, matrix_r, matrix_rxc)))
					{
						std::cout << std::endl << "[" << items << "] Items created." << std::endl;
						getPause("Press the ENTER key to continue...");
					}
			}
		catch (const std::exception& e)
			{std::cerr << std::endl << "Exception occurred: [" << e.what() << "]." << std::endl;}

		/* Visualize each element of the three-dimensional matrix and its auxiliary matrices. */
		try
			{
				if ((items = view_matrix_3D<std::size_t, int>(n_matrix, matrix, matrix_r, matrix_rxc)))
					{
						std::cout << std::endl << "[" << items << "] Items displayed." << std::endl;
						getPause("Press the ENTER key to continue...");
					}
			}
		catch (const std::exception& e)
			{std::cerr << std::endl << "Exception occurred: [" << e.what() << "]." << std::endl;}

		/* Deallocation of the memory assigned to each auxiliary matrix and the dynamic three-dimensional matrix. */
		try
			{
				if ((items = destroy_matrix_3D<std::size_t, int>(n_matrix, matrix, matrix_r, matrix_rxc)))
					{
						std::cout << std::endl << "[" << items << "] Items released." << std::endl;
						getPause("Press the ENTER key to continue...");
					}
			}
		catch (const std::exception& e)
			{std::cerr << std::endl << "Exception occurred: [" << e.what() << "]." << std::endl;}

		/* Program closure notice. */
		std::cout << std::endl << "Done!" << std::endl;
		std::cout << "This program has ended." << std::endl;
		getPause("Press the ENTER key to continue...");

		return EXIT_SUCCESS;
	}
