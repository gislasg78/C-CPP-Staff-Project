/* Implementation of BFS (Breadth-First Search) in a matrix in C. */

/* Standard Work Libraries. */
#include <stdio.h>
#include <stdlib.h>

/* Symbolic Work Constants. */
#define N		4	/* Matrix size: 'N' x 'N'. */
#define	V_MINUS_ONE	-1
#define	V_ONE		1
#define	V_ZERO		0


/* Definition of movement directions (up, down, left, right). */
int rowNum[] = {V_MINUS_ONE, V_ONE, V_ZERO, V_ZERO};
int colNum[] = {V_ZERO, V_ZERO, V_MINUS_ONE, V_ONE};

/* Structure of a cell for storing the (x, y) position, */
typedef struct
{
	int x, y;
} Cell;

/* Queue for BFS (Breadth-First Search). */
typedef struct
{
	int front, rear;
	Cell cells[N * N];
} Queue;

/* Function that removes the next element from the queue. */
Cell dequeue(Queue* q)
{
	return q->cells[q->front++];
}

/* Function that appends the next element to the queue. */
void enqueue(Queue* q, int x, int y)
{
	q->cells[q->rear].x = x;
	q->cells[q->rear].y = y;
	q->rear++;
}

/* Function that initializes the queue to 'zero'. */
void initQueue(Queue* q)
{
	q->front = q->rear = V_ZERO;
}

/* Function that determines whether the queue is empty. */
int isEmpty(Queue* q)
{
    return q->front == q->rear;
}

/* Function to check whether the cell (x, y) is within the bounds of the matrix. */
int isValid(int matrix[N][N], int visited[N][N], int x, int y)
{
	return (x >= V_ZERO && x < N && y >= V_ZERO && y < N && matrix[x][y] == V_ONE && !visited[x][y]);
}

/* Iterative BFS (Breadth-First Search) in a loop. */
void BFS(int matrix[N][N], int visited[N][N], int x, int y)
{
	/* Preliminary Working Variables. */
	Queue q;
	initQueue(&q);

	/* Mark the initially indicated cell as visited and enqueue it. */
	visited[x][y] = V_ONE;
	enqueue(&q, x, y);

	/* An iterative-recursive loop responsible for visiting each cell in the matrix. */
	while (!isEmpty(&q))
	{
		Cell cell = dequeue(&q);
		x = cell.x;
		y = cell.y;

		printf("(%d, %d).\n", x, y);

		/* Traverse each and every neighboring and/or adjacent cell. */
		for (int i = V_ZERO; i < N; i++)
		{
			int newX = x + rowNum[i];
			int newY = y + colNum[i];

			if (isValid(matrix, visited, newX, newY))
			{
				visited[newX][newY] = V_ONE;
				enqueue(&q, newX, newY);
			}
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

	/* Matrix for tracking the cells visited within it. */
	int visited[N][N] = {V_ZERO};

	/* Begin BFS (Breadth-First Search) from the specified cell, typically from (0, 0). */
	BFS(matrix, visited, V_ZERO, V_ZERO);

	return V_ZERO;
}
