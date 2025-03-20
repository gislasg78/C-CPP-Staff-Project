/************ Place several bishops on a chess board. ************
 ** Source Code:        Bishop.c				**
 ** Author:             Gustavo Islas Gálvez.                   **
 ** Creation Date:      Tuesday, December 31, 2024.		**
 ** Purpose:		The purpose of this program is to place	**
 **			a bishop in a given position on a chess	**
 **			board and fill in with asterisks those	**
 **			boxes by which its trajectory would be	**
 **			determined, understanding that the left	**
 **			and right diagonals, ascending and	**
 **			descending, are part of its field of	**
 **			action.					**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//C Standard Constants.
#define	V_EIGHT				8
#define	V_TWO				2
#define	V_ONE				1
#define	V_ZERO				0

//Work Constants.
#define ASTERISK			0x2A
#define	AMPERSAND			0x26
#define CARRIAGE_RETURN			'\n'
#define	NULL_CHARACTER			'\0'
#define	SPACE				0x20
#define	Y_LOWERCASE			0x79
#define	Y_UPPERCASE			0x59

//Limits of the Chess Board.
#define V_LOWER_LIMIT_COLUMN_CHESSBOARD	0
#define V_LOWER_LIMIT_ROW_CHESSBOARD	0
#define V_UPPER_LIMIT_COLUMN_CHESSBOARD	7
#define V_UPPER_LIMIT_ROW_CHESSBOARD	7

/* Initial declaration of work variables. */
static char sttc_chr_chessboard[V_EIGHT][V_EIGHT] =	{
								{SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
								{SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
								{SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
								{SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
								{SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
								{SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
								{SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
								{SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE}
							};

//Preliminary functional prototypes.
size_t szt_get_entry(size_t *szt_data_value);

/*****************************************************************
 ** Function:           char chr_get_response			**
 **				(const char *str_Message)	**
 ** Explanation:	The purpose of this function is to	**
 **			obtain a single character response	**
 **			value 'S' or 's', so that said input is	**
 **			returned perfectly free of any preceding**
 **			or succeeding blank spaces.		**
 ** Input Parms:	const char *str_Message.		**
 ** Output Parms:       None.					**
 ** Result:		Returns only a single character entered,**
 **			removing any whitespace characters that	**
 **			precede or follow it.			**
 ****************************************************************/
char chr_get_response(const char *str_Message)
	{
		//Preliminary working variables.
		char c = V_ZERO, chr_key = NULL_CHARACTER;

		printf("%s", str_Message);	/* Print warning message. */

		//Validate data entry as correct.
		if (scanf("%*c%c", &chr_key))
			{
				printf("\nInput value: [%c]. OK!\n", chr_key);

				scanf("%*[^\n]%*c");
				while ((c = getchar()) != CARRIAGE_RETURN && c != EOF);
			}

		return chr_key;
	}

/*****************************************************************
 ** Function:		size_t szt_browse_sttc_chr_chessboard	**
 **				(char sttc_chr_chessboard[][]);	**
 ** Explanation:	The purpose of this function is to	**
 **			display the content of the static matrix**
 **			on the screen, both before and after the**
 **			calculations to be carried out in each	**
 **			of its cells or squares of the		**
 **			trajectory of a bishop within a chess	**
 **			board.					**
 ** Input Parms:	char sttc_chr_chessboard[][].		**
 ** Output Parms:	char sttc_chr_chessboard[][].		**
 ** Result:		As a result, this function shows the	**
 **			content of each cell of the fixed	**
 **			two-dimensional array that simulates a	**
 **			chessboard, both before and after the	**
 **			calculations that are made to their	**
 **			respective cells.			**
 ****************************************************************/
size_t szt_browse_sttc_chr_chessboard(char sttc_chr_chessboard[][V_EIGHT])
	{
		/* Initial declaration of work variables. */
		size_t szt_box_counter = V_ZERO;	/* Board square counter. */
		size_t szt_column_chessboard = V_ZERO; 	/* Current position of the chess board. */
		size_t szt_row_chessboard = V_ZERO;	/* Current line of the chess board. */

		/* Paint the chess board. */
		printf("\nChessboard display.\n");

		for (szt_row_chessboard = V_ZERO; szt_row_chessboard < V_EIGHT; szt_row_chessboard++)
			{
				for (szt_column_chessboard = V_ZERO; szt_column_chessboard < V_EIGHT; szt_column_chessboard++)
					{
						szt_box_counter++; /* Counting cells. */
						printf("[%c].\t", sttc_chr_chessboard[szt_row_chessboard][szt_column_chessboard]);
					}

				printf("\n"); /* Change row. */
			}

		printf("[%ld] Chess Board Squares.\n", szt_box_counter);

		return szt_box_counter;
	}

/*****************************************************************
 ** Function:           size_t szt_get_coords			**
 **				(size_t *ptr_szt_row_bishop,	**
 **				 size_t *ptr_szt_column_bishop)	**
 ** Explanation:	The primary purpose of this function is	**
 **			to obtain the coordinates of the bishop	**
 **			piece to be placed on the board, and it	**
 **			verifies that the value obtained for	**
 **			its respective row and column is within	**
 **			its specific range. Otherwise, the	**
 **			values ​​are incorrect and should not be	**
 **			used to place an element in the		**
 **			chessboard layout.			**
 ** Input Parms:        size_t *ptr_szt_row_bishop.		**
 **			size_t *ptr_szt_column_bishop.		**
 ** Output Parms:       size_t *ptr_szt_row_bishop.		**
 **			size_t *ptr_szt_colum_bishop.		**
 ** Result:		This function returns a Boolean value	**
 **			that determines that the row and column	**
 **			are in the appropriate range of values	**
 **			in the array.				**
 ****************************************************************/
size_t szt_get_coords(size_t *ptr_szt_row_bishop, size_t *ptr_szt_column_bishop)
	{
		/* Get the value for the positioning row. */
		printf("Bishop's row    between [%d] & [%d] : ", V_LOWER_LIMIT_ROW_CHESSBOARD, V_UPPER_LIMIT_ROW_CHESSBOARD);
		*ptr_szt_row_bishop = szt_get_entry(ptr_szt_row_bishop);

		/* Get the value for the positioning column. */
		printf("Bishop's column between [%d] & [%d] : ", V_LOWER_LIMIT_COLUMN_CHESSBOARD, V_UPPER_LIMIT_COLUMN_CHESSBOARD);
		*ptr_szt_column_bishop = szt_get_entry(ptr_szt_column_bishop);

		/* Verify that the captured row and column values ​​are within the correct ranges. */
		if (*ptr_szt_row_bishop >= V_LOWER_LIMIT_ROW_CHESSBOARD && *ptr_szt_row_bishop <= V_UPPER_LIMIT_ROW_CHESSBOARD)
			if (*ptr_szt_column_bishop >= V_LOWER_LIMIT_COLUMN_CHESSBOARD && *ptr_szt_column_bishop <= V_UPPER_LIMIT_COLUMN_CHESSBOARD)
				printf("\nValid coordinates. Row: [%ld]. Column: [%ld]. OK!\n", *ptr_szt_row_bishop, *ptr_szt_column_bishop);
			else
				printf("Mistake! The value for column [%ld] is outside the range between [%d] and [%d].\n", *ptr_szt_column_bishop, V_LOWER_LIMIT_COLUMN_CHESSBOARD, V_UPPER_LIMIT_COLUMN_CHESSBOARD);
		else
			printf("Mistake! The value for row [%ld] is outside the range between [%d] and [%d].\n", *ptr_szt_row_bishop, V_LOWER_LIMIT_ROW_CHESSBOARD, V_UPPER_LIMIT_ROW_CHESSBOARD);

		/* Return true or false if the values ​​are in correct ranges. */
		return ((*ptr_szt_row_bishop >= V_LOWER_LIMIT_ROW_CHESSBOARD && *ptr_szt_row_bishop <= V_UPPER_LIMIT_ROW_CHESSBOARD) && (*ptr_szt_column_bishop >= V_LOWER_LIMIT_COLUMN_CHESSBOARD && *ptr_szt_column_bishop <= V_UPPER_LIMIT_COLUMN_CHESSBOARD));
	}

/*****************************************************************
 ** Function:           size_t szt_get_entry			**
 **				(size_t *szt_data_value)	**
 ** Explanation:	The purpose of this function is to	**
 **			capture a valid unsigned long integer	**
 **			value of type 'size_t', which can be	**
 **			used to operate on it, and thus be used	**
 **			in certain functions of this program.	**
 ** Input Parms:        size_t *szt_data_value.			**
 ** Output Parms:       size_t *szt_data_value.			**
 ** Result:		Returns the validly captured value in	**
 **			both the function name and the formal	**
 **			parameter, and otherwise returns zero	**
 **			with an error message.			**
 ****************************************************************/
size_t szt_get_entry(size_t *szt_data_value)
	{
		//Preliminary working variables.
		char char_key = NULL_CHARACTER;
		size_t szt_value_data = V_ZERO;

		//Validate data entry as correct.
		if (scanf("%ld", &szt_value_data) == V_ONE)
			{
				//Get a correct unsigned integer value.
				printf("\nInput value: [%ld]. OK!\n", szt_value_data);
				*szt_data_value = szt_value_data;
			}
		else
			{
				//Get a incorrect unsigned integer value.
				printf("\nThe value entered is not valid.\n");

				scanf("%*[^\n]%*c");
				while ((char_key = getchar()) != CARRIAGE_RETURN && char_key != EOF);
			}

		return szt_value_data;
	}

/*****************************************************************
 ** Function:		size_t szt_put_bishop_			**
 **				sttc_chr_chessboard		**
 **				(char sttc_chr_chessboard[][],	**
 **				const size_t szt_row_bishop,	**
 **				const size_t szt_column_bishop)	**
 ** Explanation:	The primary purpose of this function is	**
 **			to load the chess board with the squares**
 **			corresponding to white and black, as	**
 **			well as to place a bishop in a certain	**
 **			position, so that the latter's		**
 **			trajectory is drawn with asterisks	**
 **			within the board to know its movements.	**
 ** Input Parms:	char sttc_chr_chessboard[][],		**
 **			const size_t szt_row_bishop,		**
 **			const size_t szt_column_bishop.		**
 ** Output Parms:	char sttc_chr_chessboard[][].		**
 ** Result:		As a result, this function returns both	**
 **			the board filled with the bishop	**
 **			located, and the number of squares	**
 **			filled with the bishop's displacement	**
 **			information.				**
 ****************************************************************/
size_t szt_put_bishop_sttc_chr_chessboard(char sttc_chr_chessboard[][V_EIGHT], const size_t szt_row_bishop, const size_t szt_column_bishop)
	{
		/* Initial declaration of work variables. */
		size_t szt_box_count = V_ZERO, szt_box_counter = V_ZERO;	/* Board square counter. */

		/* Load the chess board. */
		printf("\n");	/* Leave a row blank. */
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+    Chess Board Results Matrix.    +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| Bishop position (Row: [%ld], Column: [%ld]).\n", szt_row_bishop, szt_column_bishop);
		printf("+-----------------------------------+\n");

		/* Calculation and visualization of the chess board. */
		if (szt_row_bishop >= V_LOWER_LIMIT_ROW_CHESSBOARD && szt_row_bishop <= V_UPPER_LIMIT_ROW_CHESSBOARD)
			{
				if (szt_column_bishop >= V_LOWER_LIMIT_COLUMN_CHESSBOARD && szt_column_bishop <= V_UPPER_LIMIT_COLUMN_CHESSBOARD)
					{
						/* Chessboard calculation. */
						if (sttc_chr_chessboard[szt_row_bishop][szt_column_bishop] == SPACE)
							{
								//Initial placement of the 'bishop' piece.
								sttc_chr_chessboard[szt_row_bishop][szt_column_bishop] = AMPERSAND;
								szt_box_count = V_ONE;

								/* Current line of the chess board. */
								printf("\n[%p]\t:\t[%p].\n", &sttc_chr_chessboard, sttc_chr_chessboard);

								for (size_t szt_row_chessboard = V_LOWER_LIMIT_ROW_CHESSBOARD; szt_row_chessboard <= V_UPPER_LIMIT_ROW_CHESSBOARD; szt_row_chessboard++)
									{
										/* Current position of the chess board. */
										printf("[%p]\t:\t[%p].\n", sttc_chr_chessboard[szt_row_chessboard], *(sttc_chr_chessboard + szt_row_chessboard));

										for (size_t szt_column_chessboard = V_LOWER_LIMIT_COLUMN_CHESSBOARD; szt_column_chessboard <= V_UPPER_LIMIT_ROW_CHESSBOARD; szt_column_chessboard++)
											{
												if (sttc_chr_chessboard[szt_row_chessboard][szt_column_chessboard] == SPACE)
													if ((szt_row_chessboard + szt_column_chessboard == szt_row_bishop + szt_column_bishop) ||
													    (szt_row_chessboard - szt_column_chessboard == szt_row_bishop - szt_column_bishop))
														{
															szt_box_count++;
															sttc_chr_chessboard[szt_row_chessboard][szt_column_chessboard] = ASTERISK;
														}

												printf("# [%ld]\t:\t(%ld, %ld)\t=\t[%p] : [%p] : [%p].\t[%d]\t=\t[%c].\n", szt_box_counter++, szt_row_chessboard, szt_column_chessboard, *(sttc_chr_chessboard + szt_row_chessboard) + szt_column_chessboard, sttc_chr_chessboard[szt_row_chessboard] + szt_column_chessboard, &sttc_chr_chessboard[szt_row_chessboard][szt_column_chessboard], sttc_chr_chessboard[szt_row_chessboard][szt_column_chessboard], *(*(sttc_chr_chessboard + szt_row_chessboard) + szt_column_chessboard));
											}

										printf("\n");
									}
							}
					}
				else
					printf("Mistake! The value for column [%ld] is outside the range between [%d] and [%d].\n", szt_column_bishop, V_LOWER_LIMIT_COLUMN_CHESSBOARD, V_UPPER_LIMIT_COLUMN_CHESSBOARD);
			}
		else
			printf("Mistake! The value for row [%ld] is outside the range between [%d] and [%d].\n", szt_row_bishop, V_LOWER_LIMIT_ROW_CHESSBOARD, V_UPPER_LIMIT_ROW_CHESSBOARD);

		printf("[%ld] Squares filled by a \'bishop\' piece.\n", szt_box_count);
		printf("[%ld] Obtained output results.\n", szt_box_counter);

		return szt_box_count;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	In this main function, the function	**
 **			that is responsible for calculating all	**
 **			the squares of the chess board, the	**
 **			location of the bishop in a certain	**
 **			position (row, column) and the tracing	**
 **			of its trajectory on its ascending and	**
 **			descending diagonals is called,		**
 **			left and right.				**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		Take into consideration that to know if	**
 **			a series of squares on the chess board	**
 **			is in the path of a bishop, it must be	**
 **			determined that the sum of the row and	**
 **			column at board reading time is equal	**
 **			to the sum of the row and the bishop's	**
 **			column, and in this way, the subtraction**
 **			of the row and column at board reading	**
 **			time is equal to the subtraction of the	**
 **			bishop's row and column.		**
*****************************************************************/
int main()
	{
		/* Preliminary working variables. */
		char chr_response = NULL_CHARACTER;	/* Get a follow-up response. */
		size_t szt_box_counter = V_ZERO;	/* Board square counter. */
		size_t szt_column_bishop = V_ZERO;	/* Bishop position. */
		size_t szt_row_bishop = V_ZERO;		/* Bishop's Line. */

		do
			{
				/* Request for bishop coordinates. */
				printf("+---|----+---|----+---|----+---|----+\n");
				printf("+ Placing a bishop on a chess board.+\n");
				printf("+---|----+---|----+---|----+---|----+\n");

				//Capture and validate coordinates simultaneously.
				if (szt_get_coords(&szt_row_bishop, &szt_column_bishop))
					{
						szt_box_counter += szt_put_bishop_sttc_chr_chessboard(sttc_chr_chessboard, szt_row_bishop, szt_column_bishop);
						szt_browse_sttc_chr_chessboard(sttc_chr_chessboard);

						printf("\n[%ld] Full squares.\n", szt_box_counter);
						chr_response = chr_get_response("\nDo you wish to relocate another bishop on the board (y/n)? : ");
					}

				/* Clear input buffer. */
				clearerr(stdin);
				fflush(stdin);
			}
		while (szt_box_counter < (V_EIGHT * V_EIGHT) && (chr_response == Y_UPPERCASE || chr_response == Y_LOWERCASE));

		return V_ZERO;
	}
