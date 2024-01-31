#include <stdio.h>
#include <stdlib.h>

#define	V_ONE	1
#define	V_ZERO	0

struct Node
	{
		int data;
		struct Node *nextNode;
	};

struct Queue
	{
		struct Node *front;
		struct Node *final;
	};

struct Node *enqueueNode(int data, struct Queue *queue);
struct Node *dequeueNode(int *data, struct Queue *queue);
struct Queue *initializeQueue(struct Queue **queue);
struct Queue *load(int numNodes, struct Queue **queue);
struct Queue *unload(int *data, struct Queue **queue);
void view(struct Queue *Queue);


int main()
	{
		int data = V_ZERO;
		int numNodes = V_ZERO;
		struct Queue *queue = NULL;

                printf("Data number : ");
                scanf("%i", &numNodes);

		queue = load(numNodes, &queue);
		view(queue);
		queue = unload(&data, &queue);

		free(queue);

		return V_ZERO;
	}

struct Node *dequeueNode(int *data, struct Queue *queue)
	{
		struct Node *oldNode = NULL;

		if (queue->front)
			{
				oldNode = queue->front;
				*data = oldNode->data;

				queue->front = queue->front->nextNode;
				free(oldNode);
			}

		return queue->front;
	}

struct Node *enqueueNode(int data, struct Queue *queue)
	{
		struct Node *newNode = NULL;

		if (newNode = (struct Node *) malloc(sizeof(struct Node)))
			{
				newNode->data = data;
				newNode->nextNode = NULL;

				if (queue->front)
					{
						queue->final->nextNode = newNode;
						queue->final = newNode;
					}
				else
					{
						queue->front = newNode;
						queue->final = newNode;
					}
			}

		return newNode;
	}

struct Queue *initializeQueue(struct Queue **queue)
	{
		struct Queue *newQueue = NULL;

		if (newQueue = (struct Queue *) malloc(sizeof(struct Queue)))
			{
				newQueue->front = NULL;
				newQueue->final = NULL;
			}

		if (queue) *queue = newQueue;
		return newQueue;
	}

struct Queue *load(int numNodes, struct Queue **queue)
	{
		int data = V_ZERO;
		struct Queue *newQueue = initializeQueue(&newQueue);

		for (int i = V_ZERO; i < numNodes; i++)
		{
		        printf("Data # [%d] of [%d] : ", i + V_ONE, numNodes);
		        scanf("%d", &data);

		        enqueueNode(data, newQueue);
		}

		if (queue) *queue = newQueue;
		return newQueue;
	}

struct Queue *unload(int *data, struct Queue **queue)
	{
		while ((*queue)->front)
			{
				dequeueNode(data, *queue);
				view(*queue);
			}

		return *queue;
	}

void view(struct Queue *queue)
	{
		int c = V_ZERO;
		static int k = V_ZERO;
		struct Node *actual = queue->front;

		printf("\nQueue:\t#[%3d].\n", k++);

		while (actual)
			{
				printf("\t#[%3d]\t[%p] : [%p] = [%10.d] -> [%p].\n", c++, &actual, actual, actual->data, actual->nextNode);
				actual = actual->nextNode;
			}

    		printf("\n");
	}
