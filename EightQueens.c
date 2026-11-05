/* This program solves the dilemma of the eight queens on a chessboard
   in which the queens do not attack each other on their respective paths. */

/* Standard Work Libraries. */
#include <stdio.h>

/* Random number generator. */
#define RANDOM_GENERATOR(s)		(((V_MULTIPLIER) * (s) + (V_INCREMENTER)) % (V_MODULUS))
#define	V_INCREMENTER			13849
#define V_MODULUS			65536
#define V_MULTIPLIER			25173
#define V_RESIDUAL_MODULUS		65535

/* Symbolic work constants.*/
#define	ASTERISK			'\x2a'
#define	CARRIAGE_RETURN			'\n'
#define	NULL_CHARACTER			'\0'
#define	QUEEN				'\x51'
#define	SPACE				0x20

/* Expected response. */
#define	V_CHR_LOWER_Y			0x79
#define	V_CHR_UPPER_Y			0x59

/* Limits of the Chess Board. */
#define V_MAXIMUM_COLUMNS		8	//The size of the chessboard is eight columns.
#define V_MAXIMUM_ROWS			8	//The size of the chessboard is eight rows.

/* Symbolic Work Constants. */
#define	V_MINUS_ONE			-1
#define	V_ONE				1
#define	V_ZERO				0

/* An enumeration defining the options for placing the 'queen' piece on the chessboard. */
enum enm_option_place
	{
		enm_option_place_change_random_seed = V_ONE,
		enm_option_place_random_calculation,
		enm_option_place_manual_entry,
		enm_option_place_view_current_board,
		enm_option_place_view_general_info,
		enm_option_place_exit_menu
	};

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

/* Create an empty chessboard (initialized to SPACE 0x20 or '\x20'). */
char chessboard[V_MAXIMUM_ROWS][V_MAXIMUM_COLUMNS] =	{
									{SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
									{SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
									{SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
									{SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
									{SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
									{SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
									{SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
									{SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
							};

/* Essential dimensions of the chessboard. */
const size_t chessboard_rows = sizeof(chessboard) / sizeof(*chessboard);
const size_t chessboard_columns = sizeof(*chessboard) / sizeof(**chessboard);

/* Prototypes of the functions to be used. */
void *GetEntry(const char *const str_Message, void *const void_var_address, const enum enm_type_entry enm_type_data, const enum enm_type_reset enm_type_reset_OK);
int GetRandomInterval(const int start, const int finish, int *const random_seed);
double GetRandomNumber(int *const random_seed);
size_t Menu(const char _chessboard[V_MAXIMUM_ROWS][V_MAXIMUM_COLUMNS], const size_t _chessboard_rows, const size_t _chessboard_columns);
size_t PrintChessboard(const char _chessboard[V_MAXIMUM_ROWS][V_MAXIMUM_COLUMNS], const size_t _chessboard_rows, const size_t _chessboard_columns);
size_t ResolveQueens(char _chessboard[V_MAXIMUM_ROWS][V_MAXIMUM_COLUMNS], const size_t _chessboard_rows, const size_t _chessboard_columns, const size_t rowQ, const size_t columnQ, size_t *const accumulated, size_t *const counter, size_t *const queens, size_t *const spins);

/* Function that gets a correct type value depending on its option. */
void *GetEntry(const char *const str_Message, void *const void_var_address, const enum enm_type_entry enm_type_data, const enum enm_type_reset enm_type_reset_OK)
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

				/* Selection of validating case of the type of variable to generate. */
				switch(enm_type_data)
					{
						/* Get a correct character value. */
						case enm_type_entry_char:
							if ((int_fields = scanf("%c%*c%n", (char *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%x] : [%d] = [%c]. Characters: [%d]. OK!\n", int_fields, *((char *) void_var_address), *((char *) void_var_address), *((char *) void_var_address), int_chars);
							break;

						/* Get a correct floating-point double precision value. */
						case enm_type_entry_double:
							if ((int_fields = scanf("%lf%*c%n", (double *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%lf]. Characters: [%d]. OK!\n", int_fields, *((double *) void_var_address), int_chars);
							break;

						/* Get a correct floating-point single precision value. */
						case enm_type_entry_float:
							if ((int_fields = scanf("%f%*c%n", (float *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%f]. Characters: [%d]. OK!\n", int_fields, (double) *((float *) void_var_address), int_chars);
							break;

						/* Get a correct integer value. */
						case enm_type_entry_int:
							if ((int_fields = scanf("%d%*c%n", (int *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%d]. Characters: [%d]. OK!\n", int_fields, *((int *) void_var_address), int_chars);
							break;

						/* Get a correct long int value. */
						case enm_type_entry_long:
							if ((int_fields = scanf("%ld%*c%n", (long *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%ld]. Characters: [%d]. OK!\n", int_fields, *((long *) void_var_address), int_chars);
							break;

						/* Get a correct short int value. */
						case enm_type_entry_short:
							if ((int_fields = scanf("%hi%*c%n", (short *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%hi]. Characters: [%d]. OK!\n", int_fields, *((short *) void_var_address), int_chars);
							break;

						/* Get a correct unsigned long int value. */
						case enm_type_entry_sizet:
							if ((int_fields = scanf("%lu%*c%n", (size_t *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%lu]. Characters: [%d]. OK!\n", int_fields, *((size_t *) void_var_address), int_chars);
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
						if (feof(stdin) || ferror(stdin))
							{
								fprintf(stderr, "\nEnd of File (EOF) detected in data stream!\n");
								clearerr(stdin);
								fflush(stdin);
							}

						/* Get an incorrect entried value. */
						fputs("\nThe value entered is not valid!\n", stderr);
						fprintf(stderr, "Press ENTER to continue...");

						/* Proceed to clear all characters present in the buffer. */
						int_chars = V_ZERO;
						int_fields = scanf("%*[^\n]%*c%n", &int_chars);

						/* Check whether an End-of-File condition occurred during keyboard data input. */
						if (feof(stdin) || ferror(stdin))
							{
								fprintf(stderr, "\nEnd of File (EOF) detected in data stream!\n");
								clearerr(stdin);
								fflush(stdin);
							}

						/* We must always clear the input buffer of impurities. */
						fputs("\nPress the ENTER key to clear the input buffer...", stderr);
						while ((int_key = getchar()) != CARRIAGE_RETURN && int_key != EOF);

						/* Check whether an End-of-File condition occurred during keyboard data input. */
						if (feof(stdin) || ferror(stdin))
							{
								fprintf(stderr, "\nEnd of File (EOF) detected in data stream!\n");
								clearerr(stdin);
								fflush(stdin);
							}
					}
			}
		else
			fprintf(stderr, "\nThe memory address to hold the variable is not valid!\n");

		/* Return of void pointer key value. */
		return void_var_address;
	}

/* Function that obtains a random number within a range. */
int GetRandomInterval(const int start, const int finish, int *const random_seed)
	{
		return ((int) ((finish - start + V_ONE) * GetRandomNumber(random_seed) + start));
	}

/* Function that generates a single-precision floating-point random number between zero and one. */
double GetRandomNumber(int *const random_seed)
	{
		return ((double) (*random_seed = RANDOM_GENERATOR(*random_seed)) / (double) V_RESIDUAL_MODULUS);
	}

/* Function to set up a temporary menu for performing operations on the chessboard. */
size_t Menu(const char _chessboard[V_MAXIMUM_ROWS][V_MAXIMUM_COLUMNS], const size_t _chessboard_rows, const size_t _chessboard_columns)
	{
		/* Preliminary working variables. */
		char chr_key = NULL_CHARACTER, chr_pause = V_ZERO;
		int random_seed = V_ZERO;

		enum enm_option_place enm_option = V_ZERO;
		size_t accumulated = V_ZERO, count = V_ZERO, counter = V_ZERO;
		size_t queens = V_ZERO, spins = V_ZERO;

		size_t column = V_ZERO, row = V_ZERO;
		size_t option = V_ZERO;
		const size_t total_number_of_cells = _chessboard_rows * _chessboard_columns;

		/* Header messages. */
		printf("Placing until eight 'queen' pieces on a chessboard.\n");
		random_seed = *((int *) GetEntry("Random starting seed: ", &random_seed, enm_type_entry_int, enm_type_reset_YES));

		/* The current state of the board is printed and you are asked if you want to place 'queen' pieces. */
		PrintChessboard(_chessboard, _chessboard_rows, _chessboard_columns);
		chr_key = *((char *) GetEntry("Do you want to continue placing other 'queen' pieces on the board (y/n)? : ", &chr_key, enm_type_entry_char, enm_type_reset_YES));

		/* Seeds tested for eight queens: 600, 2800, 6300, 6800, 10000, 12100, 18500, 20500, 25000, 27500, 38000, 39500, 41500, 46000, 58500, 59000, 67000, 73500, 74000 and 82000. */
		while ((count < total_number_of_cells) && (chr_key == V_CHR_LOWER_Y || chr_key == V_CHR_UPPER_Y) && (enm_option != enm_option_place_exit_menu))
			{
				/* Maneuvering options for the 'queen'. */
				printf("\n");
				printf("+===|====+===|====+===|====+===|====+\n");
				printf("|     Queen Maneuvering options.    |\n");
				printf("+===|====+===|====+===|====+===|====+\n");
				printf("| [1]. Change the random seed.      |\n");
				printf("| [2]. Place the 'queen' at random. |\n");
				printf("| [3]. Provide her row and column.  |\n");
				printf("| [4]. View current board.          |\n");
				printf("| [5]. View general information.    |\n");
				printf("| [6]. Exit from this menu.         |\n");
				printf("+===|====+===|====+===|====+===|====+\n");

				/* Obtain the option and convert it to the given numerator. */
				enm_option = ((enum enm_option_place) (option = *((size_t *) GetEntry("Option: ", &option, enm_type_entry_sizet, enm_type_reset_YES))));

				/* Randomly obtain the row and column, respectively, for the 'queen' piece to be placed on the chessboard. */
				switch(enm_option)
					{
						/* Option to change the initial random seed. */
						case enm_option_place_change_random_seed:
							printf("\nChange the random seed for stochastic calculations.\n");
							random_seed = *((int *) GetEntry("+ Enter a new random seed: ", &random_seed, enm_type_entry_int, enm_type_reset_YES));
							printf("\nRandom seed: [%d].\n", random_seed);
							break;

						/* Option to randomly calculate the row and column for placement. */
						case enm_option_place_random_calculation:
							puts("\nRandom calculation of the positions of the 'queen' piece.");
							row = (size_t ) GetRandomInterval(V_ZERO, (int) (_chessboard_rows - V_ONE), &random_seed);
							column = (size_t) GetRandomInterval(V_ZERO, (int) (_chessboard_columns - V_ONE), &random_seed);
							printf("\n(Row: [%lu], Column: [%lu]).\n", row, column);
							break;

						/* Manually enter the row and column for the 'queen' piece. */
						case enm_option_place_manual_entry:
							puts("\nManual entry of the positions of the 'queen' piece.");
							printf("Valid range for row from: [%d] to: [%lu].\n", V_ZERO, _chessboard_rows - V_ONE);
							row = *((size_t *) GetEntry("+ Enter a row: ", &row, enm_type_entry_sizet, enm_type_reset_YES));

							printf("Valid range for column from: [%d] to: [%lu].\n", V_ZERO, _chessboard_columns - V_ONE);
							column = *((size_t *) GetEntry("+ Enter a column: ", &column, enm_type_entry_sizet, enm_type_reset_YES));

							printf("\nEntry position: (Row: [%lu], Column: [%lu]).\n", row, column);
							break;

						/* View the current board. */
						case enm_option_place_view_current_board:
							puts("\nView the current board.\n");
							PrintChessboard(_chessboard, _chessboard_rows, _chessboard_columns);
							break;

						/* See the general information available so far. */
						case enm_option_place_view_general_info:
							puts("\nView general information.");
							printf("+ Row:\t\t[%lu].\n", row);
							printf("+ Column:\t[%lu].\n", column);

							if (row < _chessboard_rows && column < _chessboard_columns)
								printf("+ Value:\t[%c].\n", (*(_chessboard + row))[column]);

							printf("+ Seed:\t\t[%d].\n", random_seed);
							chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));
							break;

						/* Exit this main menu. */
						case enm_option_place_exit_menu:
							printf("\nQuitting this menu...\n");
							break;

						/* Invalid option. */
						default:
							printf("\nInvalid option: [%lu]. Please correct it!\n", option);
							break;
					}

				/* Ensure that no 'queen' piece attacks another, and print the board for each attempt at their placement. */
				if (enm_option >= enm_option_place_random_calculation && option <= enm_option_place_manual_entry)
					{
						/* Core mechanism for resolving the placement of 'queen' pieces. */
						count += ResolveQueens(chessboard, chessboard_rows, chessboard_columns, row, column, &accumulated, &counter, &queens, &spins);
						PrintChessboard(_chessboard, _chessboard_rows, _chessboard_columns);

						/* A hasty exit, if one wishes to leave. */
						chr_key = *((char *) GetEntry("Do you want to continue placing other 'queen' pieces on the board (y/n)? : ", &chr_key, enm_type_entry_char, enm_type_reset_YES));
					}
			}

		/* Display and show the final board. */
		puts("\nDisplay and show the final board.");
		PrintChessboard(_chessboard, _chessboard_rows, _chessboard_columns);

		/* Display of output messages. */
		printf("\nFinal Results.\n");
		printf("+ Occupied squares: [%lu].\n", count);

		/* Return the selected option. */
		return option;
	}

/* Function to print the chessboard. */
size_t PrintChessboard(const char _chessboard[V_MAXIMUM_ROWS][V_MAXIMUM_COLUMNS], const size_t _chessboard_rows, const size_t _chessboard_columns)
	{
		/* Preliminary working variables. */
		size_t counter = V_ZERO;

		/* Header messages. */
		printf("\nDisplay chessboard.\n");

		/* Cycle that is responsible for displaying the current contents of the chessboard. */
		for (size_t row = V_ZERO; row < _chessboard_rows; row++)
			{
				for (size_t column = V_ZERO; column < _chessboard_columns; column++)
					{
						counter++;
						printf("(%lu, %lu) : [%c].\t", row, column, _chessboard[row][column]);
					}

				printf("\n");
			}

		/* Final output result message. */
		printf("[%lu] Output results obtained.\n", counter);

		/* Return, as a preliminary step, the number of board squares displayed on the screen. */
		return counter;
	}

/* Function that traces the movements of a given queen. */
size_t ResolveQueens(char _chessboard[V_MAXIMUM_ROWS][V_MAXIMUM_COLUMNS], const size_t _chessboard_rows, const size_t _chessboard_columns, const size_t rowQ, const size_t columnQ, size_t *const accumulated, size_t *const counter, size_t *const queens, size_t *const spins)
	{
		/* Preliminary working variables. */
		*counter = V_ZERO;

		/* It is verified that the position sent to place the 'queen' piece is free and within range. */
		if (rowQ < _chessboard_rows)
			{
				if (columnQ < _chessboard_columns)
					{
						/* Process of validating the positioning of a 'queen' piece that is not attacked. */
						if (_chessboard[rowQ][columnQ] == SPACE)
							{
								/* Initialization of default values ​​for placing a 'queen' piece. */
								*counter = V_ONE;
								_chessboard[rowQ][columnQ] = QUEEN;
								(*queens)++;

								/* Row-based pipeline process. */
								for (size_t row = V_ZERO; row < _chessboard_rows; row++)
									{
										/* Filling the rows of a single column. */
										if (_chessboard[row][columnQ] == SPACE)
											{
												(*counter)++;
												_chessboard[row][columnQ] = ASTERISK;
											}

										/* Column-based pipeline process. */
										for (size_t column = V_ZERO; column < _chessboard_columns; column++)
											{
												/* Filling the columns of a single row. */
												if (_chessboard[rowQ][column] == SPACE)
													{
														(*counter)++;
														_chessboard[rowQ][column] = ASTERISK;
													}

												/* Channeling process for diagonals. */
												if (_chessboard[row][column] == SPACE)
													if ((row + column == rowQ + columnQ) || (row - column) == (rowQ - columnQ))
														{
															(*counter)++;
															_chessboard[row][column] = ASTERISK;
														}
											}
									}
							}

						/* The contents of the placed 'queen' piece are displayed. */
						printf("\n[%s]:\t(Row = [%lu], Column = [%lu]) = {%x} : {%d} : {%c}.\n", (_chessboard[rowQ][columnQ] == QUEEN) ? "Queen position" : (_chessboard[rowQ][columnQ] == ASTERISK) ? "Position held" : "Position available", rowQ, columnQ, _chessboard[rowQ][columnQ], *(_chessboard[rowQ] + columnQ), *(*(_chessboard + rowQ) + columnQ));
						printf("\t\t\tAccumulated: [%lu]. Counter: [%lu]. Queens: [%lu]. Turns: [%lu].\n", *accumulated += *counter, *counter, *queens, (*spins)++);
					}
				else
					fprintf(stderr, "\nMistake! The value for column: [%lu] is outside the range between: [%d] and: [%lu].\n", columnQ, V_ZERO, _chessboard_columns - V_ONE);
			}
		else
			fprintf(stderr, "\nMistake! The value for row: [%lu] is outside the range between: [%d] and: [%lu].\n", rowQ, V_ZERO, _chessboard_rows - V_ONE);

		/* Return the number of 'queen' pieces placed on the board. */
		return *counter;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		char chr_key = V_ZERO;

		/* Access the internal menu. */
		size_t option = Menu(chessboard, chessboard_rows, chessboard_columns);
		printf("\nChosen option: [%lu].\n", option);

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");
		chr_key = *((char *) GetEntry("Press the ENTER key to continue...", &chr_key, enm_type_entry_char, enm_type_reset_YES));

		return V_ZERO;
	}
