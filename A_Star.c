/* Implementation of A* (A-Star Search) in a matrix in C.  */

/* Standard Work Libraries. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Symbolic Work Constants. */
#define	V_FOUR		4
#define	V_MINUS_ONE	-1
#define	V_ONE		1
#define	V_ZERO		0

/* Search control macros. */
#define SIZE		16
#define INF		9999

/* Defined type of the Node structure. */
typedef struct
	{
		int x, y;
	} Node;

/* Defined type of the cell structure. */
typedef struct
	{
		Node node;
		int g, h, f;

		Node parent;
		int in_open;
		int in_closed;
	} Cell;

/* Function to verify that it is the same node. */
int is_same_node(Node a, Node b)
	{
		return a.x == b.x && a.y == b.y;
	}

/* Heuristic function using the Manhattan distance. */
int heuristic(Node a, Node b)
	{
		return abs(a.x - b.x) + abs(a.y - b.y); //Manhattan distance.
	}

/* Function that checks the validity of the node. */
int is_valid(int x, int y)
	{
		return x >= V_ZERO && x < SIZE && y >= V_ZERO && y < SIZE;
	}

/* Function that prints the path followed during the search. */
void print_path(Cell grid[SIZE][SIZE], Node end)
	{
		/* The end of the abscissa 'x' and the end of the ordinate 'y' must be different from '-1'. */
		if (end.x == V_MINUS_ONE || end.y == V_MINUS_ONE) return;

		/* The current node must be the final one. */
		Node current = end;
		printf("\n");

		/* Visualization of the route. */
		while (!(grid[current.x][current.y].parent.x == V_MINUS_ONE))
			{
				printf("(%d, %d). <- ", current.x, current.y);
				current = grid[current.x][current.y].parent;
			}

		printf("[START].\n");
	}

/* 'A*' primary function for search with controlled backtracking. */
void a_star(Node start, Node goal)
	{
		/* Preliminary Working Variables */
		Cell grid[SIZE][SIZE];

		/* Initialize the grid used for the search. */
		for (int idx = V_ZERO; idx < SIZE; ++idx)
			{
				for (int jdx = V_ZERO; jdx < SIZE; ++jdx)
					{
						grid[idx][jdx].node.x = idx;
						grid[idx][jdx].node.y = jdx;
						grid[idx][jdx].g = INF;
						grid[idx][jdx].h = V_ZERO;
						grid[idx][jdx].f = INF;
						grid[idx][jdx].in_open = V_ZERO;
						grid[idx][jdx].in_closed = V_ZERO;
						grid[idx][jdx].parent.x = V_MINUS_ONE;
						grid[idx][jdx].parent.y = V_MINUS_ONE;
					}
			}

		/* Subsequent assignments of 'A*' search control. */
		grid[start.x][start.y].g = V_ZERO;
		grid[start.x][start.y].h = heuristic(start, goal);
		grid[start.x][start.y].f = grid[start.x][start.y].h;
		grid[start.x][start.y].in_open = V_ONE;

		/* Central control loop for searching within a matrix using the A* (A-star) algorithm. */
		while (V_ONE)
			{
				/* Preliminary Initializations for this Cycle */
				int min_f = INF;
				Node current = {V_MINUS_ONE, V_MINUS_ONE};

				/* Find Node with lowest 'f' value. */
				for (int idx = V_ZERO; idx < SIZE; ++idx)
					{
						for (int jdx = V_ZERO; jdx < SIZE; ++jdx)
							{
								if (grid[idx][jdx].in_open && grid[idx][jdx].f < min_f)
									{
										min_f = grid[idx][jdx].f;
										current.x = idx;
										current.y = jdx;
									}
							}
					}

				/* If the 'x' coordinate position returns -1, there is no possible path. */
				if (current.x == V_MINUS_ONE)
					{
						printf("\nNo path was found!\n");
						return;
					}

				/* If it is the same node, then a search path to the goal has been found. */
				if (is_same_node(current, goal))
					{
						printf("\nA way was found!\n");
						print_path(grid, goal);
						return;
					}

				/* Determine that the target has an x-coordinate of zero and a y-coordinate of one. */
				grid[current.x][current.y].in_open = V_ZERO;
				grid[current.x][current.y].in_closed = V_ONE;

				/* Determine the corresponding deviations of the abscissa 'x' and the ordinate 'y'. */
				int dx[] = {V_ZERO, V_MINUS_ONE, V_ONE, V_ZERO};
				int dy[] = {V_MINUS_ONE, V_ZERO, V_ZERO, V_ONE};

				/* A loop that calculates the new position of the abscissae 'x' and the ordinates 'y'. */
				for (int idx = V_ZERO; idx < V_FOUR; ++idx)
					{
						/* Intermediate Working Variables. */
						int nx = current.x + dx[idx];
						int ny = current.y + dy[idx];

						/* Skipping iterations if the cell is invalid or closed. */
						if (!is_valid(nx, ny)) continue;
						if (grid[nx][ny].in_closed) continue;

						int tentative_g = grid[current.x][current.y].g + V_ONE;

						/* Determine the expansion and termination indicators for the 'A*' search. */
						if (!grid[nx][ny].in_open || tentative_g < grid[nx][ny].g)
							{
								grid[nx][ny].parent = current;
								grid[nx][ny].g = tentative_g;
								grid[nx][ny].h = heuristic(grid[nx][ny].node, goal);
								grid[nx][ny].f = grid[nx][ny].g + grid[nx][ny].h;
								grid[nx][ny].in_open = V_ONE;
							}
					}
			}
	}

//Main function.
int main()
	{
		/* Preliminary Working Variables. */
		Node start = {V_ZERO, V_ZERO};
		Node goal = {SIZE + V_MINUS_ONE, SIZE + V_MINUS_ONE};

		/* Initialization and Start of the 'A*' (A-star) Search. */
		printf("\'A*\' (A-Star Search) Algorithm Program.\n");

		/* Begin A* (A-Star Search) from the specified cell, typically from (0, 0). */
		printf("A path search is performed from: (%d, %d) to (%d, %d)...\n", start.x, start.y, goal.x, goal.y);
		a_star(start, goal);

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended.\n");

		return V_ZERO;
	}
