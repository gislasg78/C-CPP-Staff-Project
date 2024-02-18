#include <stdio.h>
#include <stdlib.h>

#define	V_ONE	1
#define	V_ZERO	0

struct Node
	{
		int int_data;
		struct Node *nextNode;
	};

struct Queue
	{
		struct Node *front;
		struct Node *final;
	};

struct Queue *createQueue(struct Queue **queue);
struct Node *createNode(int int_data, struct Node *nextNode);
struct Node *enqueueNode(int int_data, struct Queue *queue);
struct Node *dequeueNode(int *int_data, struct Queue *queue);
struct Queue *load(int numNodes, struct Queue **queue);
struct Queue *unload(int *int_data, struct Queue **queue);
void view(struct Queue *Queue);


int main()
	{
		int int_data = V_ZERO;
		int numNodes = V_ZERO;
		struct Queue *queue = NULL;

                printf("Enter a data number : ");
                scanf("%i", &numNodes);

		queue = load(numNodes, &queue);
		view(queue);
		queue = unload(&int_data, &queue);

		return V_ZERO;
	}

struct Node *createNode(int int_data, struct Node *nextNode)
	{
		struct Node *tempNode = NULL;

		if (tempNode = (struct Node *) malloc(sizeof(struct Node)))
			{
				tempNode->int_data = int_data;
				tempNode->nextNode = nextNode;
			}

		return tempNode;

	}

struct Queue *createQueue(struct Queue **queue)
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

struct Node *dequeueNode(int *int_data, struct Queue *queue)
	{
		struct Node *tempNode = NULL;

		if (queue->front)
			{
				tempNode = queue->front;
				*int_data = tempNode->int_data;

				queue->front = queue->front->nextNode;
				free(tempNode);
			}

		return queue->front;
	}

struct Node *enqueueNode(int int_data, struct Queue *queue)
	{
		struct Node *tempNode = NULL;

		if (tempNode = createNode(int_data, NULL))
			{
				if (queue->front)
					queue->final->nextNode = tempNode;
				else
					queue->front = tempNode;

				queue->final = tempNode;
			}

		return tempNode;
	}

struct Queue *load(int numNodes, struct Queue **queue)
	{
		int int_data = V_ZERO;
		struct Queue *newQueue = createQueue(&newQueue);
		struct Node *tempNode = NULL;

		for (int i = V_ZERO; i < numNodes; i++)
			{
		        	printf("Data # [%d] of [%d] : ", i + V_ONE, numNodes);
		        	scanf("%d", &int_data);

		        	tempNode = enqueueNode(int_data, newQueue);
			}

		if (queue) *queue = newQueue;
		return newQueue;
	}

struct Queue *unload(int *int_data, struct Queue **queue)
	{
		struct Node *tempNode = NULL;

		while ((*queue)->front)
			{
				tempNode = dequeueNode(int_data, *queue);
				view(*queue);
			}

		free(*queue);

		return *queue;
	}

void view(struct Queue *queue)
	{
		int c = V_ZERO;
		static int k = V_ZERO;
		struct Node *tempNode = queue->front;

		printf("\nQueue:\t#[%3d].\n", k++);

		while (tempNode)
			{
				printf("\t#[%3d]\t[%p] : [%p] = [%10.d] -> [%p].\n", c++, &tempNode, tempNode, tempNode->int_data, tempNode->nextNode);
				tempNode = tempNode->nextNode;
			}

    		printf("\n");
	}
