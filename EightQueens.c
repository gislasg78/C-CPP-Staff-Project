/* This program solves the dilemma of the eight queens on a chessboard
   in which the queens do not attack each other on their respective paths.*/
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

#define	V_CHR_LOWER_Y	0x79
#define	V_CHR_UPPER_Y	0x59

//Limits of the Chess Board.
#define V_LOWER_LIMIT_COLUMN_CHESSBOARD	0
#define V_LOWER_LIMIT_ROW_CHESSBOARD	0
#define V_UPPER_LIMIT_COLUMN_CHESSBOARD	7
#define V_UPPER_LIMIT_ROW_CHESSBOARD	7

#define V_EIGHT		8	//The size of the chessboard is eight by eight squares.
#define	V_MINUS_ONE	-1
#define	V_ONE		1
#define	V_ZERO		0

//Create an empty chessboard (initialized to SPACE 0x20 or '\x20').
static char chessboard[V_EIGHT][V_EIGHT] =	{
						SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
						SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
						SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
						SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
						SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
						SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
						SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
						SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
						};

//Prototypes of the functions to be used.
int GetRandomInterval(int start, int finish, int *random_seed);
double GetRandomNumber(int *random_seed);
int PrintChessboard(char chessboard[V_EIGHT][V_EIGHT]);
int ResolveQueens(char chessboard[V_EIGHT][V_EIGHT], int rowQ, int colQ);


//Function to receive a specific character from the keyboard.
char GetResponse(const char *str_Message)
	{
		/* Preliminary working variables. */
		char chr_Char = NULL_CHARACTER;

		/* Header messages. */
		printf("%s", str_Message);

		/* Validate that only one key is received. */
		if (scanf("\n%c", &chr_Char))
			printf("\nInput value: [%d] = [%c]. OK!\n", chr_Char, chr_Char);
		else
			{
				scanf("%*[^\n]%*c");
				while ((chr_Char = getchar()) != CARRIAGE_RETURN && chr_Char != EOF);
			}

		return chr_Char;
	}

//Function that obtains a random number within a range.
int GetRandomInterval(int start, int finish, int *random_seed)
	{
		return ((int) ((finish - start + V_ONE) * GetRandomNumber(random_seed) + start));
	}

//Function that generates a single-precision floating-point random number between zero and one.
double GetRandomNumber(int *random_seed)
	{
		return ((double) (*random_seed = RANDOM_GENERATOR(*random_seed)) / (double) V_RESIDUAL_MODULUS);
	}

//Function to print the chessboard.
int PrintChessboard(char chessboard[V_EIGHT][V_EIGHT])
	{
		/* Preliminary working variables. */
		int count = V_ZERO;

		/* Header messages. */
		printf("\nDisplay chessboard.\n");

		/* Cycle that is responsible for displaying the current contents of the chessboard. */
		for (int row = V_ZERO; row < V_EIGHT; row++)
			{
				for (int col = V_ZERO; col < V_EIGHT; col++)
					{
						count++;
						printf("[%c].\t", chessboard[row][col]);
					}

				printf("\n");
			}

		printf("[%d] Output results obtained.\n", count);

		return count;
	}

//Function that traces the movements of a given queen.
int ResolveQueens(char chessboard[V_EIGHT][V_EIGHT], int rowQ, int colQ)
	{
		//Preliminary working variables.
		int count = V_ZERO;

		if (rowQ >= V_LOWER_LIMIT_ROW_CHESSBOARD && rowQ <= V_UPPER_LIMIT_ROW_CHESSBOARD)
			{
				if (colQ >= V_LOWER_LIMIT_COLUMN_CHESSBOARD && colQ <= V_UPPER_LIMIT_COLUMN_CHESSBOARD)
					{
						if (chessboard[rowQ][colQ] == SPACE)
							{
								count = V_ONE;
								chessboard[rowQ][colQ] = QUEEN;

								for (int row = V_ZERO; row < V_EIGHT; row++)
									{
										if (chessboard[row][colQ] == SPACE)
											{
												count++;
												chessboard[row][colQ] = ASTERISK;
											}

										for (int col = V_ZERO; col < V_EIGHT; col++)
											{
												if (chessboard[rowQ][col] == SPACE)
													{
														count++;
														chessboard[rowQ][col] = ASTERISK;
													}

												if (chessboard[row][col] == SPACE)
													if ((row + col == rowQ + colQ) || (row - col) == (rowQ - colQ))
														{
															count++;
															chessboard[row][col] = ASTERISK;
														}
											}
									}
							}
					}
				else
					printf("Mistake! The value for column [%d] is outside the range between [%d] and [%d].\n", colQ, V_LOWER_LIMIT_COLUMN_CHESSBOARD, V_UPPER_LIMIT_COLUMN_CHESSBOARD);
			}
		else
			printf("Mistake! The value for row [%d] is outside the range between [%d] and [%d].\n", rowQ, V_LOWER_LIMIT_ROW_CHESSBOARD, V_UPPER_LIMIT_ROW_CHESSBOARD);

		return count;
	}

//Main function.
int main()
	{
		//Preliminary working variables.
		char char_key = V_ZERO;
		int col = V_ZERO, row = V_ZERO;
		int count = V_ZERO, spins = V_ZERO, random_seed = V_ZERO;

		/* Header messages. */
		printf("Placing until eight 'queen' pieces on a chessboard.\n");
		printf("Random starting seed: ");
		scanf("%d", &random_seed);

		/* The current state of the board is printed and you are asked if you want to place 'queen' pieces. */
		PrintChessboard(chessboard);
		char_key = GetResponse("Do you want to continue placing other 'queen' pieces on the board (y/n)? : ");

		//Seeds tested for eight queens: 600, 2800, 6300, 6800, 10000, 12100, 18500, 20500, 25000, 27500, 38000, 39500, 41500, 46000, 58500, 59000, 67000, 73500, 74000 and 82000.
		while ((count < (V_EIGHT * V_EIGHT)) && (char_key == V_CHR_LOWER_Y || char_key == V_CHR_UPPER_Y))
			{
				row = GetRandomInterval(V_LOWER_LIMIT_ROW_CHESSBOARD, V_UPPER_LIMIT_ROW_CHESSBOARD, &random_seed);
				col = GetRandomInterval(V_LOWER_LIMIT_COLUMN_CHESSBOARD, V_UPPER_LIMIT_COLUMN_CHESSBOARD, &random_seed);

				count += ResolveQueens(chessboard, row, col);
				printf("\nQ : (x = [%d], y = [%d]) = {%d} : {%d}.\n", col, row, count, spins++);
				PrintChessboard(chessboard);

				char_key = GetResponse("Do you want to continue placing other 'queen' pieces on the board (y/n)? : ");
			}

		return V_ZERO;
	}
