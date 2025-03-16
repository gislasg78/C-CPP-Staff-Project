/*************** Place a bishop on a chess board. ****************
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
#define	V_ZERO				0

//Work Constants.
#define	SPACE				0x20
#define V_ASTERISK			0x2A
#define V_LETTER_B			'\x42'
#define V_LETTER_W			'\x57'

//Limits of the Chess Board.
#define V_LOWER_LIMIT_COLUMN_CHESSBOARD	0
#define V_LOWER_LIMIT_ROW_CHESSBOARD	0
#define V_UPPER_LIMIT_COLUMN_CHESSBOARD	7
#define V_UPPER_LIMIT_ROW_CHESSBOARD	7

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
		printf("\n");

		for (szt_row_chessboard = V_ZERO; szt_row_chessboard < V_EIGHT; szt_row_chessboard++)
			{
				for (szt_column_chessboard = V_ZERO; szt_column_chessboard < V_EIGHT; szt_column_chessboard++)
					{
						szt_box_counter++; /* Counting cells. */
						printf("[%c]\t", sttc_chr_chessboard[szt_row_chessboard][szt_column_chessboard]);
					}

				printf("\n"); /* Change row. */
			}

		printf("[%ld] Chess Board Squares.\n", szt_box_counter);

		return szt_box_counter;
	}

/*****************************************************************
 ** Function:		size_t szt_load_sttc_chr_chessboard	**
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
size_t szt_load_sttc_chr_chessboard(char sttc_chr_chessboard[][V_EIGHT], const size_t szt_row_bishop, const size_t szt_column_bishop)
	{
		/* Initial declaration of work variables. */
		size_t szt_box_counter = V_ZERO;	/* Board square counter. */
		size_t szt_column_chessboard = V_ZERO; 	/* Current position of the chess board. */
		size_t szt_row_chessboard = V_ZERO;	/* Current line of the chess board. */

		/* Load the chess board. */
		printf("\n"); /* Leave a row blank. */
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+    Chess Board Results Matrix.    +\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("| Bishop position (Row: [%ld], Column: [%ld]).\n", szt_row_bishop, szt_column_bishop);
		printf("+-----------------------------------+\n");

		/* Chessboard calculation. */
		for (szt_row_chessboard = V_ZERO; szt_row_chessboard < V_EIGHT; szt_row_chessboard++)
			{
				for (szt_column_chessboard = V_ZERO; szt_column_chessboard < V_EIGHT; szt_column_chessboard++)
					{
						if ((szt_row_chessboard + szt_column_chessboard == szt_row_bishop + szt_column_bishop) ||
							(szt_row_chessboard - szt_column_chessboard == szt_row_bishop - szt_column_bishop))
								sttc_chr_chessboard[szt_row_chessboard][szt_column_chessboard] = V_ASTERISK;
						else if ((szt_row_chessboard + szt_column_chessboard) % V_TWO == V_ZERO)
								sttc_chr_chessboard[szt_row_chessboard][szt_column_chessboard] = V_LETTER_W;
						else
								sttc_chr_chessboard[szt_row_chessboard][szt_column_chessboard] = V_LETTER_B;

						printf("# [%ld]\t:\t(%ld, %ld)\t=\t[%c].\n", szt_box_counter++, szt_row_chessboard, szt_column_chessboard, sttc_chr_chessboard[szt_row_chessboard][szt_column_chessboard]);
					}

				printf("\n");
			}

		printf("[%ld] Obtained output results.\n", szt_box_counter);

		return szt_box_counter;
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
		/* Initial declaration of work variables. */
		static char sttc_chr_chessboard[V_EIGHT][V_EIGHT] =	{
									SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
									SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
									SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
									SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
									SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
									SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
									SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
									SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE
									};

		size_t szt_box_counter = V_ZERO;	/* Board square counter. */
		size_t szt_column_bishop = V_ZERO;	/* Bishop position. */
		size_t szt_column_chessboard = V_ZERO; 	/* Concurrent board position. */
		size_t szt_row_bishop = V_ZERO;		/* Bishop's Line. */
		size_t szt_row_chessboard = V_ZERO;	/* Concurrent line of the board. */

		/* Request for bishop coordinates. */
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("+ Placing a bishop on a chess board.+\n");
		printf("+---|----+---|----+---|----+---|----+\n");
		printf("Bishop's row    between [%d] & [%d] : ", V_LOWER_LIMIT_ROW_CHESSBOARD, V_UPPER_LIMIT_ROW_CHESSBOARD);
		scanf("%ld", &szt_row_bishop);
		printf("Bishop's column between [%d] & [%d] : ", V_LOWER_LIMIT_COLUMN_CHESSBOARD, V_UPPER_LIMIT_COLUMN_CHESSBOARD);
		scanf("%ld", &szt_column_bishop);

		clearerr(stdin);
		fflush(stdin);

		/* Calculation and visualization of the chess board. */
		if (szt_row_bishop >= V_LOWER_LIMIT_ROW_CHESSBOARD && szt_row_bishop <= V_UPPER_LIMIT_ROW_CHESSBOARD)
			if (szt_column_bishop >= V_LOWER_LIMIT_COLUMN_CHESSBOARD && szt_column_bishop <= V_UPPER_LIMIT_COLUMN_CHESSBOARD)
				{
					szt_box_counter = szt_browse_sttc_chr_chessboard(sttc_chr_chessboard);

					szt_box_counter = szt_load_sttc_chr_chessboard(sttc_chr_chessboard, szt_row_bishop, szt_column_bishop);

					szt_box_counter = szt_browse_sttc_chr_chessboard(sttc_chr_chessboard);
				}
			else
				printf("Mistake! The value for column [%ld] is outside the range between [%d] and [%d].\n", szt_column_bishop, V_LOWER_LIMIT_COLUMN_CHESSBOARD, V_UPPER_LIMIT_COLUMN_CHESSBOARD);
		else
			printf("Mistake! The value for row [%ld] is outside the range between [%d] and [%d].\n", szt_row_bishop, V_LOWER_LIMIT_ROW_CHESSBOARD, V_UPPER_LIMIT_ROW_CHESSBOARD);

		return V_ZERO;
	}
