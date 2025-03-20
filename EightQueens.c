#include <stdio.h>

#define RANDOM_GENERATOR(s)	(((V_MULTIPLIER) * (s) + (V_INCREMENTER)) % (V_MODULUS))
#define	V_INCREMENTER		13849
#define V_MODULUS		65536
#define V_MULTIPLIER		25173
#define V_RESIDUAL_MODULUS	65535

#define	ASTERISK	'\x2a'
#define	QUEEN		'\x51'
#define	SPACE		0x20

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
double GetRandomNumber(int *random_seed);


//Function that obtains a random number within a range.
int GetRandomInterval(int start, int finish, int *random_seed)
	{
		return ((int) ((finish - start) * GetRandomNumber(random_seed) + start));
	}

//Function that generates a single-precision floating-point random number between zero and one.
double GetRandomNumber(int *random_seed)
	{
		return ((double) (*random_seed = RANDOM_GENERATOR(*random_seed)) / (double) V_RESIDUAL_MODULUS);
	}

//Function to print the chessboard.
void printChessBoard(char chessboard[V_EIGHT][V_EIGHT])
	{
		int count = V_ZERO;

		printf("\nDisplay chessboard.\n");

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
	}

//Function that traces the movements of a given queen.
int resolveQueens(char chessboard[V_EIGHT][V_EIGHT], int rowQ, int colQ)
	{
		int count = V_ZERO;

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

		return count;
	}

//Main function.
int main()
	{
		//Preliminary working variables.
		int count = V_ZERO, row = V_ZERO, col = V_ZERO, random_seed = V_ZERO;

		printf("Placing 'queen' pieces on a chessboard.\n");
		printf("Random starting seed: ");
		scanf("%d", &random_seed);

		//Seeds tested for eight queens: 600, 2800, 6300, 6800, 10000, 12100, 18500, 20500, 25000, 27500, 38000, 39500, 41500, 46000, 58500, 59000, 67000, 73500, 74000 and 82000.
		while (count < V_EIGHT * V_EIGHT)
			{
				row = GetRandomInterval(V_ZERO, V_EIGHT, &random_seed);
				col = GetRandomInterval(V_ZERO, V_EIGHT, &random_seed);

				count += resolveQueens(chessboard, row, col);
			}

		printChessBoard(chessboard);

		return V_ZERO;
	}
