#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define	V_FOUR		4
#define	V_MINUS_ONE	-1
#define	V_ONE		1
#define	V_ZERO		0

#define SIZE		16
#define INF		9999

typedef struct
	{
		int x, y;
	} Node;

typedef struct
	{
		Node node;
		int g, h, f;
		Node parent;
		int in_open;
		int in_closed;
	} Cell;


int is_same_node(Node a, Node b)
	{
		return a.x == b.x && a.y == b.y;
	}

int heuristic(Node a, Node b)
	{
		return abs(a.x - b.x) + abs(a.y - b.y); //Manhattan distance.
	}

int is_valid(int x, int y)
	{
		return x >= V_ZERO && x < SIZE && y >= V_ZERO && y < SIZE;
	}

void print_path(Cell grid[SIZE][SIZE], Node end)
	{
		if (end.x == V_MINUS_ONE || end.y == V_MINUS_ONE) return;

		Node current = end;

		while (!(grid[current.x][current.y].parent.x == V_MINUS_ONE))
			{
				printf("(%d, %d) <- ", current.x, current.y);
				current = grid[current.x][current.y].parent;
			}

		printf("START\n");
	}

void a_star(Node start, Node goal)
	{
		Cell grid[SIZE][SIZE];

		/* Initialize the grid used for the search. */
		for (int i = V_ZERO; i < SIZE; ++i)
			{
				for (int j = V_ZERO; j < SIZE; ++j)
					{
						grid[i][j].node.x = i;
						grid[i][j].node.y = j;
						grid[i][j].g = INF;
						grid[i][j].h = V_ZERO;
						grid[i][j].f = INF;
						grid[i][j].in_open = V_ZERO;
						grid[i][j].in_closed = V_ZERO;
						grid[i][j].parent.x = V_MINUS_ONE;
						grid[i][j].parent.y = V_MINUS_ONE;
					}
			}

		grid[start.x][start.y].g = V_ZERO;
		grid[start.x][start.y].h = heuristic(start, goal);
		grid[start.x][start.y].f = grid[start.x][start.y].h;
		grid[start.x][start.y].in_open = V_ONE;

		while (V_ONE)
			{
				int min_f = INF;
				Node current = {V_MINUS_ONE, V_MINUS_ONE};

				//Find Node with lowest 'f' value.
				for (int i = V_ZERO; i < SIZE; ++i)
					{
						for (int j = V_ZERO; j < SIZE; ++j)
							{
								if (grid[i][j].in_open && grid[i][j].f < min_f)
									{
										min_f = grid[i][j].f;
										current.x = i;
										current.y = j;
									}
							}
					}

				if (current.x == V_MINUS_ONE)
					{
						printf("No path was found!\n");
						return;
					}

				if (is_same_node(current, goal))
					{
						printf("A way was found!\n");
						print_path(grid, goal);
						return;
					}

				grid[current.x][current.y].in_open = V_ZERO;
				grid[current.x][current.y].in_closed = V_ONE;

				int dx[] = {V_ZERO, V_MINUS_ONE, V_ONE, V_ZERO};
				int dy[] = {V_MINUS_ONE, V_ZERO, V_ZERO, V_ONE};

				for (int d = V_ZERO; d < V_FOUR; ++d)
					{
						int nx = current.x + dx[d];
						int ny = current.y + dy[d];

						if (!is_valid(nx, ny)) continue;
						if (grid[nx][ny].in_closed) continue;

						int tentative_g = grid[current.x][current.y].g + V_ONE;

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


int main()
	{
		Node start = {V_ZERO, V_ZERO};
		Node goal = {SIZE + V_MINUS_ONE, SIZE + V_MINUS_ONE};

		printf("A path search is performed from: (%d, %d) to (%d, %d)...\n", start.x, start.y, goal.x, goal.y);
		a_star(start, goal);

		return V_ZERO;
	}
