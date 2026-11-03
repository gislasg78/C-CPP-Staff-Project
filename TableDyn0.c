/* Program that dynamically allocates memory in C to store a series of given matrices,
   each with a variable number of rows, and each of its respective rows
   with a variable number of columns. */

/* Standard Work Libraries. */
#include <stdio.h>
#include <stdlib.h>

/* Alphanumeric Symbolic Constants. */
#define	CARRIAGE_RETURN	'\n'
#define	NULL_CHARACTER	'\0'

/* Symbolic Work Constants. */
#define	V_ONE		1
#define	V_ZERO		0

/* Enumeration with type entry variables and its reseting. */
enum enm_type_entry
	{
		enm_type_entry_char,
		enm_type_entry_double,
		enm_type_entry_float,
		enm_type_entry_int,
		enm_type_entry_long,
		enm_type_entry_short,
		enm_type_entry_sizet
	};

/* Enumeration for memory area reset system. */
enum enm_type_reset
	{
		enm_type_reset_NO,
		enm_type_reset_YES
	};

/* Preliminary function prototypes. */
size_t create_matrix_3D(const size_t n_matrix, int **** matrix, size_t **matrix_r, size_t ***matrix_rxc);
size_t destroy_matrix_3D(const size_t n_matrix, int ****matrix, size_t **matrix_r, size_t ***matrix_rxc);
void *getEntry(const char *const str_Message, void *const void_var_address, const enum enm_type_entry enm_type_data, const enum enm_type_reset enm_type_reset_OK);
size_t view_matrix_3D(const size_t n_matrix, int *** matrix, size_t *matrix_r, size_t **matrix_rxc);

/* This function creates and captures both the three-dimensional dynamic variable array
   and the two arrays storing the row and column limits of that main array. */
size_t create_matrix_3D(const size_t n_matrix, int **** matrix, size_t **matrix_r, size_t ***matrix_rxc)
	{
		/* Preliminary working variables. */
		size_t items = V_ZERO;

		/* Validate that the parameters of this function have valid initial values. */
		if ((n_matrix) && (matrix) && (matrix_r) && (matrix_rxc))
			{
				/* Main header messages. */
				printf("\nInitializing memory spaces...\n");

				/* Preliminary initializers. */
				matrix[V_ZERO] = NULL;
				matrix_r[V_ZERO] = NULL;
				matrix_rxc[V_ZERO] = NULL;

				/* Supplementary allowances. */
				printf("Assigning dynamic memory addresses...\n");

				/* The initial space is first allocated for the number of two-dimensional arrays to be stored. */
				if ((matrix[V_ZERO] = (int ***) calloc (n_matrix, sizeof(int **)))) //Space is generated for the first dimension of a three-dimensional array.
						{
							if ((matrix_rxc[V_ZERO] = (size_t **) calloc (n_matrix, sizeof(size_t *))))	//Space is generated for the first dimension of a two-dimensional array.
								{
									if((matrix_r[V_ZERO] = (size_t *) calloc (n_matrix, sizeof(size_t))))	//Space is generated for the only dimension of a one-dimensional array.
										{
											/* General loading cycles of dynamic pointer pointers. */
											printf("Capturing values...\n");

											/* Dynamic memory is allocated to know the number of matrices to be generated. */
											for (size_t m = V_ZERO; m < n_matrix; m++)		//Cycle by matrix.
												{
													printf("For the matrix #: [%lu] of [%lu].\n", m + V_ONE, n_matrix);
													matrix_r[V_ZERO][m] = *((size_t *) getEntry("How many lines will it generate for it? : ", &matrix_r[V_ZERO][m], enm_type_entry_sizet, enm_type_reset_YES));

													/* Dynamic memory is allocated for each matrix to know the number of rows it will have. */
													if ((matrix[V_ZERO][m] = (int **) calloc (matrix_r[V_ZERO][m], sizeof(size_t *))))	//Number of rows for each matrix.
														{
															if ((matrix_rxc[V_ZERO][m] = (size_t *) calloc (matrix_r[V_ZERO][m], sizeof(size_t))))
																{
																	for (size_t r = V_ZERO; r < matrix_r[V_ZERO][m]; r++)		//Cycle through each row of each matrix.
																		{
																			printf("For the matrix #: [%lu] of [%lu], and its row #: [%lu] of [%lu].\n", m + V_ONE, n_matrix, r + V_ONE, matrix_r[V_ZERO][m]);
																			matrix_rxc[V_ZERO][m][r] = *((size_t *) getEntry("How many columns will it generate for it and its respective row? : ", &matrix_rxc[V_ZERO][m][r], enm_type_entry_sizet, enm_type_reset_YES));

																			/* Dynamic memory is allocated for each row of the matrix in concurrent turn to know the number of columns it will have. */
																			if ((matrix[V_ZERO][m][r] = (int *) calloc (matrix_rxc[V_ZERO][m][r], sizeof(int))))	//Number of columns per row of each matrix.
																				{
																						for (size_t c = V_ZERO; c < matrix_rxc[V_ZERO][m][r]; c++)	//Cycle through each column of each row of each matrix.
																							{
																								printf("Enter a value #: %lu for Matrix #: [%lu] of [%lu] -> (Row: [%lu] of [%lu], Column: [%lu] of [%lu]) : ", items++, m + V_ONE, n_matrix, r + V_ONE, matrix_r[V_ZERO][m], c + V_ONE, matrix_rxc[V_ZERO][m][r]);
																								matrix[V_ZERO][m][r][c] = *((int *) getEntry("", &matrix[V_ZERO][m][r][c], enm_type_entry_int, enm_type_reset_YES));

																								printf("(Matrix: [%lu] of [%lu], Row: [%lu] of [%lu], Column: [%lu] of [%lu]) = [%d].\n", m + V_ONE, n_matrix, r + V_ONE, matrix_r[V_ZERO][m], c + V_ONE, matrix_rxc[V_ZERO][m][r], matrix[V_ZERO][m][r][c]);
																							}

																						printf("\n");
																				}
																			else
																				fprintf(stderr, "\nError! Insufficient memory allocation: Matrix 3D. [%lu] of [%lu]. Rows: [%lu] of [%lu].\n", m + V_ONE, n_matrix, r + V_ONE,  matrix_r[V_ZERO][m]);
																		}

																	printf("\n");
																}
															else
																fprintf(stderr, "\nError! Insufficient memory allocation: Matrix rows by columns. [%lu] of [%lu].\n", m + V_ONE, n_matrix);
														}
													else
														fprintf(stderr, "Error! Insufficient memory allocation: Matrix 3D. [%lu] of [%lu].\n", m + V_ONE, n_matrix);
												}

											printf("[%lu] Captured input values.\n", items);
										}
									else
										fprintf(stderr, "\nError! Insufficient memory allocation. Matrix by rows. [%lu].\n", n_matrix);
								}
							else
								fprintf(stderr, "\nError! Insufficient memory allocation: Matrix rows by columns. [%lu].\n.", n_matrix);
						}
				else
						fprintf(stderr, "Error! Insufficient memory allocation: Matrix 3D. [%lu].\n", n_matrix);
			}
		else
			{
				/* Error messages for critical validation. */
				fputs("\nIncorrect input values ​​for creating the matrix.\n", stderr);
				fprintf(stderr, "+ Matrices:\t\t\t[%lu].\n", n_matrix);
				fprintf(stderr, "+ Matrix 3D:\t\t\t[%p].\n", (void *) matrix);
				fprintf(stderr, "+ Matrix rows:\t\t\t[%p].\n", (void *) matrix_r);
				fprintf(stderr, "+ Matrix rows by columns:\t[%p].\n", (void *) matrix_rxc);
			}

		/* Return and refund of the calculated amount. */
		return items;
	}

/* Function that cleans up and frees the three-dimensional dynamic matrix and its auxiliary matrices. */
size_t destroy_matrix_3D(const size_t n_matrix, int ****matrix, size_t **matrix_r, size_t ***matrix_rxc)
	{
		/* Preliminary working variables. */
		size_t items = V_ZERO;

		/* Validate that the parameters of this function have valid initial values. */
		if ((n_matrix) && (matrix) && (matrix_r) && (matrix_rxc))
			{
				/* The allocated memory is freed from each allocated row of each created array. */
				printf("\nFreeing the memory of all dynamically allocated pointers...\n");

				/* Freeing each memory space allocated to each array. */
				for (size_t m = V_ZERO; m < n_matrix; m++)
					{
						printf("Deallocating memory for array #: [%lu] of [%lu].\n", m + V_ONE, n_matrix);

						/* Freeing each memory space allocated to each row of each matrix. */
						for (size_t r = V_ZERO; r < matrix_r[V_ZERO][m]; r++, items++)
							{
								printf("\tDeallocating memory for its row #: [%lu] of [%lu].\n", r + V_ONE, matrix_r[V_ZERO][m]);

								free(matrix[V_ZERO][m][r]);	//Clear the three-dimensional matrix by rows.
								matrix[V_ZERO][m][r] = NULL;
							}

						free(matrix[V_ZERO][m]);	//Clear the three-dimensional matrix by matrices.
						matrix[V_ZERO][m] = NULL;

						free(matrix_rxc[V_ZERO][m]);	//Clear the matrix, row by row, matrix by matrix.
						matrix_rxc[V_ZERO][m] = NULL;

						printf("\n");
					}
				printf("[%lu] Generated output results.\n", items);

				/* Higher-order pointers are deallocated. */
				printf("\nEvicting main memory addresses...\n");

				free(matrix_rxc[V_ZERO]);			//Clear the matrix, row by row, matrix by matrix.
				matrix_rxc[V_ZERO] = NULL;

				free(matrix_r[V_ZERO]);				//Clear the matrix, row by row.
				matrix_r[V_ZERO] = NULL;

				free(matrix[V_ZERO]);				//Clear the three-dimensional matrix.
				matrix[V_ZERO] = NULL;
			}
		else
			{
				/* Error messages for critical validation. */
				fputs("\nIncorrect input values ​​for destroying the matrix.\n", stderr);
				fprintf(stderr, "+ Matrices:\t\t\t[%lu].\n", n_matrix);
				fprintf(stderr, "+ Matrix 3D:\t\t\t[%p].\n", (void *) matrix);
				fprintf(stderr, "+ Matrix rows:\t\t\t[%p].\n", (void *) matrix_r);
				fprintf(stderr, "+ Matrix rows by columns:\t[%p].\n", (void *) matrix_rxc);
			}

		/* Return and refund of the calculated amount. */
		return items;
	}

/* A function responsible for receiving an argument of type (void *) and the type of conversion—specified via an enumerated set—to be performed. */
void *getEntry(const char *const str_Message, void *const void_var_address, const enum enm_type_entry enm_type_data, const enum enm_type_reset enm_type_reset_OK)
	{
		/* Preliminary working variables. */
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;
		int int_key = V_ZERO;

		/* Convert the specified enumerated type to an 'integer'. */
		int option_type_entry = (int) enm_type_data;

		/* Validate if the obtained memory addresses are valid. */
		if (void_var_address)
			{
				/* Initialize the specified memory area. */
				if (enm_type_reset_OK == enm_type_reset_YES)
					{
						switch(enm_type_data)
							{
								case enm_type_entry_char:
									*((char *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_double:
									*((double *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_float:
									*((float *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_int:
									*((int *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_long:
									*((long *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_short:
									*((short *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_sizet:
									*((size_t *) void_var_address) = V_ZERO;
									break;

								default:
									fprintf(stderr, "\nThe selected option: [%d] is invalid. Please correct it!\n", option_type_entry);
									break;
							}
					}

				/* Incoming message. */
				printf("%s", str_Message);

				/* Validate the data type to be captured. */
				switch (enm_type_data)
					{
						/* Get a correct character value. */
						case enm_type_entry_char:
							if ((int_fields = scanf("%c%*c%n", (char *) void_var_address, &int_chars)))
								{
									printf("\nFields: [%d]. Input value: [%x] : [%d] = [%c]. Characters: [%d]. OK!\n", int_fields, *((char *) void_var_address), *((char *) void_var_address), *((char *) void_var_address), int_chars);
								}
							break;

						/* Get a correct floating-point double precision value. */
						case enm_type_entry_double:
							if ((int_fields = scanf("%lf%*c%n", (double *) void_var_address, &int_chars)))
								{
									printf("\nFields: [%d]. Input value: [%lf]. Characters: [%d]. OK!\n", int_fields, *((double *) void_var_address), int_chars);
								}
							break;

						/* Get a correct floating-point single precision value. */
						case enm_type_entry_float:
							if ((int_fields = scanf("%f%*c%n", (float *) void_var_address, &int_chars)))
								{
									double dbl_value = (double) *((float *) void_var_address);
									printf("\nFields: [%d]. Input value: [%f]. Characters: [%d]. OK!\n", int_fields, dbl_value, int_chars);
								}
							break;

						/* Get a correct integer value. */
						case enm_type_entry_int:
							if ((int_fields = scanf("%d%*c%n", (int *) void_var_address, &int_chars)))
								{
									printf("\nFields: [%d]. Input value: [%d]. Characters: [%d]. OK!\n", int_fields, *((int *) void_var_address), int_chars);
								}
							break;

						/* Get a correct long int value. */
						case enm_type_entry_long:
							if ((int_fields = scanf("%ld%*c%n", (long *) void_var_address, &int_chars)))
								{
									printf("\nFields: [%d]. Input value: [%ld]. Characters: [%d]. OK!\n", int_fields, *((long *) void_var_address), int_chars);
								}
							break;

						/* Get a correct short int value. */
						case enm_type_entry_short:
							if ((int_fields = scanf("%hi%*c%n", (short *) void_var_address, &int_chars)))
								{
									printf("\nFields: [%d]. Input value: [%hi]. Characters: [%d]. OK!\n", int_fields, *((short *) void_var_address), int_chars);
								}
							break;

						/* Get a correct unsigned long int value. */
						case enm_type_entry_sizet:
							if ((int_fields = scanf("%lu%*c%n", (size_t *) void_var_address, &int_chars)))
								{
									printf("\nFields: [%d]. Input value: [%lu]. Characters: [%d]. OK!\n", int_fields, *((size_t *) void_var_address), int_chars);
								}
							break;

						/* It is specified that if the option is incorrect, an error message should be sent. */
						default:
							fprintf(stderr, "\nThe selected option: [%d] is invalid. Please correct it!\n", option_type_entry);
							break;
					}

				/* Verify that exactly one field is captured and saved at the given address. */
				if ((int_fields != V_ONE) || !(int_chars))
					{
						/* Check whether an End-of-File condition occurred during keyboard data input. */
						if (feof(stdin))
							{
								fprintf(stderr, "\nEnd of File (EOF) detected in data entry!\n");
								clearerr(stdin);
								fflush(stdin);
							}

						/* Get an incorrect entried value. */
						fputs("\nThe value entered is not valid!\n", stderr);
						fprintf(stderr, "Press ENTER to continue...");
						scanf("%*[^\n]%*c");

						/* We must always clear the input buffer of impurities. */
						fputs("\nPress the ENTER key to clear the input buffer...", stderr);
						while ((int_key = getchar()) != CARRIAGE_RETURN && int_key != EOF);
					}
			}
		else
			fprintf(stderr, "\nThe memory address to hold the variable is not valid!\n");

		/* Return of void pointer key value. */
		return void_var_address;
	}

/* This function displays the values ​​contained in the various dynamically created matrices. */
size_t view_matrix_3D(const size_t n_matrix, int *** matrix, size_t *matrix_r, size_t **matrix_rxc)
	{
		/* Preliminary working variables. */
		size_t items = V_ZERO;

		/* Validate that the parameters of this function have valid initial values. */
		if ((n_matrix) && (matrix) && (matrix_r) && (matrix_rxc))
			{
				/* Process of dumping each column, each row, each matrix. */
				printf("\nDisplaying captured values...\n");

				/* Dump of each matrix. */
				for (size_t m = V_ZERO; m < n_matrix; m++)
					{
						printf("Matrix: [%lu] of [%lu].\n", m + V_ONE, n_matrix);

						/* Dump of each row of each matrix. */
						for (size_t r = V_ZERO; r < *(matrix_r + m); r++)
							{
								printf("\tRow: [%lu] of [%lu].\n", r + V_ONE, *(matrix_r + m));

								/* Dump of each column of each row of each matrix. */
								for (size_t c = V_ZERO; c < *(*(matrix_rxc + m) + r); c++, items++)
									{
										printf("\t\tColumn: [%lu] of [%lu].\t", c + V_ONE, *(*(matrix_rxc + m) + r));
										printf("(%lu, %lu, %lu) = [%d] : [%d].\n", m + V_ONE, r + V_ONE, c + V_ONE, matrix[m][r][c], *(*(*(matrix + m) + r) + c));
									}

								printf("\n");
							}

						printf("\n");
					}
				printf("[%lu] Generated output results.\n", items);
			}
		else
			{
				/* Error messages for critical validation. */
				fputs("\nIncorrect input values ​​for viewing the matrix.\n", stderr);
				fprintf(stderr, "+ Matrices:\t\t\t[%lu].\n", n_matrix);
				fprintf(stderr, "+ Matrix 3D:\t\t\t[%p].\n", (void *) matrix);
				fprintf(stderr, "+ Matrix rows:\t\t\t[%p].\n", (void *) matrix_r);
				fprintf(stderr, "+ Matrix rows by columns:\t[%p].\n", (void *) matrix_rxc);
			}

		/* Return and refund of the calculated amount. */
		return items;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		char chr_key = NULL_CHARACTER;
		size_t items = V_ZERO;

		/* Three, two and one dimension dynamic pointers. */
		int ***matrix = NULL;		//Three-dimensional matrix.
		size_t **matrix_rxc = NULL;	//Matrix containing the columns from each row of each matrix.
		size_t *matrix_r = NULL;	//Arrangement involving the rows of each matrix.

		size_t n_matrix = V_ZERO;	//Number of dynamic matrices to generate.

		/* Header messages. */
		printf("Highly dynamic pointer generator.\n");
		n_matrix = *((size_t *) getEntry("How many rectangular arrangements do you want to create? : ", &n_matrix, enm_type_entry_sizet, enm_type_reset_YES));

		/* Function that dynamically creates and captures the three-dimensional matrix. */
		if ((items = create_matrix_3D(n_matrix, &matrix, &matrix_r, &matrix_rxc)))
			{
				printf("[%zu] Items created.\n", items);
				chr_key = *((char *) getEntry("Press the ENTER key to continue...", &chr_key, enm_type_entry_char, enm_type_reset_YES));
			}

		/* Visualize each element of the three-dimensional matrix and its auxiliary matrices. */
		if ((items = view_matrix_3D(n_matrix, matrix, matrix_r, matrix_rxc)))
			{
				printf("[%lu] Items displayed.\n", items);
				chr_key = *((char *) getEntry("Press the ENTER key to continue...", &chr_key, enm_type_entry_char, enm_type_reset_YES));
			}

		/* Deallocation of the memory assigned to each auxiliary matrix and the dynamic three-dimensional matrix. */
		if ((items = destroy_matrix_3D(n_matrix, &matrix, &matrix_r, &matrix_rxc)))
			{
				printf("[%lu] Items released.\n", items);
				chr_key = *((char *) getEntry("Press the ENTER key to continue...", &chr_key, enm_type_entry_char, enm_type_reset_YES));
			}

		/* Program closure notice. */
		printf("\nDone!\n");
		printf("This program has ended.\n");
		chr_key = *((char *) getEntry("Press the ENTER key to continue...", &chr_key, enm_type_entry_char, enm_type_reset_YES));

		return V_ZERO;
	}
