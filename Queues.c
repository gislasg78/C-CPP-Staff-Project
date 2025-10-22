/* Event realization. Application of queues. */
#include "stdio.h"
#include "stdlib.h"

#define	NULL_CHARACTER	'\0'
#define	CARRIAGE_RETURN	'\n'

#define	V_ONE	1
#define	V_ZERO	0

struct Node
	{
		int data;
		struct Node *nextNode;
	} *header = NULL, *tail = NULL;

struct Node *createNode(int data, struct Node *nextNode);
int dequeueNode(int *data, struct Node **front, struct Node **final);
struct Node *enqueueNode(int data, struct Node **front, struct Node **final);
int getInputValue(int *int_data);
void loadQueue(int numNodes, struct Node **front, struct Node **final);
void unloadQueue(struct Node **front, struct Node **final);
void viewQueue(struct Node *front);

int main()
	{
		int numNodes = V_ZERO;

		printf("Dynamic structures: queues.\n");
		printf("Enter nodes's number for the queue: ");

		if (getInputValue(&numNodes))
			{
				loadQueue(numNodes, &header, &tail);
				viewQueue(header);
				unloadQueue(&header, &tail);
			}

		return EXIT_SUCCESS;
	}

struct Node *createNode(int data, struct Node *nextNode)
	{
		struct Node *tempNode = NULL;

		if ((tempNode = (struct Node *) malloc(sizeof(struct Node))))
			{
				tempNode->data = data;
				tempNode->nextNode = nextNode;
			}
		else
			{
				perror("Error allocating memory for a new node.\n");
				exit(EXIT_FAILURE);
			}

		return tempNode;
	}

int dequeueNode(int *data, struct Node **front, struct Node **final)
	{
		struct Node *tempNode = NULL;

		if (*front)
			{
				tempNode = *front;
				*data = tempNode->data;
				*front = (*front)->nextNode;
				free(tempNode);

				if (*front == NULL) *final = NULL;
			}
		else
			printf("\nThe queue is empty.\n");

		return *data;
	}

struct Node *enqueueNode(int data, struct Node **front, struct Node **final)
	{
		struct Node *tempNode = NULL;

		if ((tempNode = createNode(data, NULL)))
			{
				if (*front)
					(*final)->nextNode = tempNode;
				else
					*front = tempNode;

				*final = tempNode;
			}
		else
			printf("\nNo more items can be added to the queue.\n");

		return tempNode;
	}

int getInputValue(int *int_data)
	{
		char c = NULL_CHARACTER;
		int t_data = V_ZERO;

		if ((t_data = scanf("%i", int_data)) == V_ONE)
			printf("Correct entry: [%d] in address: [%p]. OK!\n", *int_data, int_data);
		else
			{
				printf("The entry is not valid.\n");
				scanf("%*[^\n]%*c");
				while ((c = getchar()) != CARRIAGE_RETURN && c != EOF);
			}

		return (t_data == V_ONE);
	}

void loadQueue(int numNodes, struct Node **front, struct Node **final)
	{
		int data = V_ZERO;
		struct Node *tempNode = NULL;

		printf("\nLoading data to the queue...\n");

		for (int idx = V_ZERO; idx < numNodes; idx++)
			{
				printf("\nEntry Data #: [%d] of: [%d] : ", idx + V_ONE, numNodes);

				if (getInputValue(&data))
					{
						printf("Correct entry #: [%d] of: [%d] = [%d]. OK!\n", idx + V_ONE, numNodes, data);
						tempNode = enqueueNode(data, front, final);
						printf("Idx: [%2d]. Address Node: [%p]. Data: [%d]. Next Node: [%p].\n", idx + V_ONE, *final, (*final)->data, (*final)->nextNode);
					}
			}
	}

void unloadQueue(struct Node **front, struct Node **final)
	{
		int idx = V_ZERO, data = V_ZERO;

		printf("\nUnloading data from the queue...\n");

		while (*front)
			{
				printf("Idx: [%2d].\tAddress Node: [%p].\tData: [%d].\tNext Node: [%p].\n", idx++, *front, (*front)->data, (*front)->nextNode);
				data = dequeueNode(&data, front, final);
			}

		printf("[%d] Deleted output results.\n", idx);
	}

void viewQueue(struct Node *front)
	{
		int idx = V_ZERO;

		printf("\nViewing the queue without removing its elements...\n");

		while (front)
			{
				printf("Idx: [%2d].\tAddress Node: [%p].\tData: [%d].\tNext Node: [%p].\n", idx++, front, front->data, front->nextNode);
				front = front->nextNode;
			}

		printf("[%d] Observed output results.\n", idx);
	}
