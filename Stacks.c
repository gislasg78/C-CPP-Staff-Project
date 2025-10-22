#include <stdio.h>
#include <stdlib.h>

#define	NULL_CHARACTER	'\0'
#define	CARRIAGE_RETURN	'\n'

#define	V_ONE		1
#define	V_ZERO		0

struct Node
	{
		int data;
		struct Node *nextNode;
	};

int get(int *int_data);
struct Node *load(int numNodes, struct Node **stack);
struct Node *pop(int *data, struct Node *stack);
struct Node *push(int data, struct Node *stack);
struct Node *unload(int *int_data, struct Node **stack);
void view(struct Node *stack);


int main()
	{
		int int_data = V_ZERO;
		int numNodes = V_ZERO;
		struct Node *stack = NULL;

		printf("Dynamic structures: stacks.\n");
		printf("Enter nodes's number for the stack: ");

		if (get(&numNodes))
			{
				stack = load(numNodes, &stack);
				view(stack);
				stack = unload(&int_data, &stack);
			}

		return EXIT_SUCCESS;
	}

int get(int *int_data)
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

struct Node *load(int numNodes, struct Node **stack)
	{
		int data = V_ZERO;
		struct Node *tempNode = NULL;

		printf("\nLoading data to the stack...\n");

		for (int idx = V_ZERO; idx < numNodes; idx++)
			{
				printf("\nEntry Data #: [%d] of: [%d] : ", idx + V_ONE, numNodes);

				if (get(&data))
					{
						printf("Correct entry #: [%d] of: [%d] = [%d]. OK!\n", idx + V_ONE, numNodes, data);
						tempNode = push(data, tempNode);
						printf("Idx: [%2d]. Address Node: [%p]. Data: [%d]. Next Node: [%p].\n", idx + V_ONE, tempNode, tempNode->data, tempNode->nextNode);
					}
			}

		if (stack) *stack = tempNode;

		return tempNode;
	}

struct Node *pop(int *data, struct Node *stack)
	{
		struct Node *tempNode = NULL;

		if (stack)
			{
				tempNode = stack;
				*data = tempNode->data;

				stack = stack->nextNode;
				free(tempNode);
			}

		return stack;
	}

struct Node *push(int data, struct Node *stack)
	{
		struct Node *tempNode = NULL;

		if ((tempNode = (struct Node *) malloc(sizeof(struct Node))))
			{
				tempNode->data = data;
				tempNode->nextNode = stack;
			}
		else
			{
				perror("Error allocating memory for a new node.\n");
				exit(EXIT_FAILURE);
			}

		return tempNode;
	}

struct Node *unload(int *int_data, struct Node **stack)
	{
		int idx = V_ZERO;

		printf("\nUnloading data from the stack...\n");

		while (*stack)
			{
				printf("Idx: [%2d].\tAddress Node: [%p].\tData: [%d].\tNext Node: [%p].\n", idx++, *stack, (*stack)->data, (*stack)->nextNode);
				*stack = pop(int_data, *stack);
			}

		printf("[%d] Deleted output results.\n", idx);

		return *stack;
	}

void view(struct Node *stack)
	{
		int idx = V_ZERO;

		printf("\nViewing the stack without removing its elements...\n");

		while (stack)
			{
				printf("Idx: [%2d].\tAddress Node: [%p].\tData: [%d].\tNext Node: [%p].\n", idx++, stack, stack->data, stack->nextNode);
				stack = stack->nextNode;
			}

		printf("[%d] Observed output results.\n", idx);
	}
