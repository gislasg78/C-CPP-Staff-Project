/* Implementation of DFS (Depth-First Search) in a matrix in C. */

/* Standard Work Libraries. */
#include <stdio.h>

/* Symbolic Work Constants. */
#define N		4	/* Matrix size: 'N' x 'N'. */
#define	V_MINUS_ONE	-1
#define	V_ONE		1
#define	V_ZERO		0

/* Definition of movement directions (up, down, left, right). */
int rowNum[] = {V_MINUS_ONE, V_ONE, V_ZERO, V_ZERO};
int colNum[] = {V_ZERO, V_ZERO, V_MINUS_ONE, V_ONE};

/* Function to check whether the cell (x, y) is within the bounds of the matrix. */
int isValid(int matrix[N][N], int visited[N][N], int x, int y)
{
	return (x >= V_ZERO && x < N && y >= V_ZERO && y < N && matrix[x][y] == V_ONE && !visited[x][y]);
}

/* Iterative DFS (Depth-First Search). */
void DFS(int matrix[N][N], int visited[N][N], int x, int y)
{
	/* Mark the current cell as visited. */
	visited[x][y] = V_ONE;
	printf("(%d, %d). -> ", x, y);

	/* Traverse the neighboring and/or adjacent cells. */
	for (int idx = V_ZERO; idx < N; idx++)
	{
		/* Intermediate initializations for the new abscissa 'x' and the new ordinate 'y'. */
		int newX = x + rowNum[idx];
		int newY = y + colNum[idx];

		/* Verify the validity of the site visit. */
		if (isValid(matrix, visited, newX, newY))
		{
			DFS(matrix, visited, newX, newY);
		}
	}
}

//Main function.
int main()
{
	/* Preliminary Working Variables. */
	int matrix[N][N] =
	{
		{V_ONE, V_ZERO, V_ZERO, V_ZERO},
		{V_ONE, V_ONE, V_ZERO, V_ONE},
		{V_ZERO, V_ONE, V_ZERO, V_ZERO},
		{V_ONE, V_ONE, V_ONE, V_ONE}
	};

	/* Matrix for tracking the cells visited. */
	int visited[N][N] = {V_ZERO};

	/* Initialization and Start of the 'A*' (A-star) Search. */
	printf("'DFS' (Depth-First Search) Algorithm Program.\n");
	printf("A path search is performed from: (%d, %d) to (%d, %d)...\n\n", V_ZERO, V_ZERO, N + V_MINUS_ONE, N + V_MINUS_ONE);

	/* Start a DFS (Depth-First Search) from cell (x, y) — typically (0, 0). */
	DFS(matrix, visited, V_ZERO, V_ZERO);

	/* Program termination messages. */
	printf("\n\nDone!\n");
	printf("This program has ended.\n");

	return V_ZERO;
}
