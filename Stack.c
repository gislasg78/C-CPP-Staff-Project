#include <stdio.h>
#include <stdlib.h>

#define	V_ONE	1
#define	V_ZERO	0

struct Node
	{
		int data;
		struct Node *nextNode;
	};

struct Node *load(int numNodes, struct Node **stack);
struct Node *pop(int *data, struct Node *stack);
struct Node *push(int data, struct Node *stack);
struct Node *unload(int *data, struct Node **stack);
void view(struct Node *stack);


int main()
	{
		int data = V_ZERO;
		int numNodes = V_ZERO;
		struct Node *stack = NULL;

		printf("Data number : ");
		scanf("%i", &numNodes);

		stack = load(numNodes, &stack);
		view(stack);
		stack = unload(&data, &stack);

		return V_ZERO;
	}


struct Node *load(int numNodes, struct Node **stack)
	{
		int data = V_ZERO;
		struct Node *newNode = NULL;

		for (int i = V_ZERO; i < numNodes; i++)
			{
				printf("Data # [%d] of [%d] : ", i + V_ONE, numNodes);
				scanf("%d", &data);

				newNode = push(data, newNode);
			}

		if (stack) *stack = newNode;
		return newNode;
	}

struct Node *pop(int *data, struct Node *stack)
	{
		struct Node *oldNode = NULL;

		if (stack)
			{
				oldNode = stack;
				*data = oldNode->data;

				stack = stack->nextNode;
				free(oldNode);
			}

		return stack;
	}

struct Node *push(int data, struct Node *stack)
	{
		struct Node *newNode = NULL;

		if (newNode = (struct Node *) malloc(sizeof(struct Node)))
			{
				newNode->data = data;
				newNode->nextNode = stack;
			}

		return newNode;
	}

struct Node *unload(int *data, struct Node **stack)
	{
		while (*stack)
			{
				*stack = pop(data, *stack);
				view(*stack);
			}

		return *stack;
	}

void view(struct Node *stack)
	{
		int c = V_ZERO;
		static int k = V_ZERO;

		printf("\nStack:\t#[%3d].\n", k++);

		while (stack)
			{
				printf("\t#[%3d]\t[%p] : [%p] = [%10.d] -> [%p].\n", c++, &stack, stack, stack->data, stack->nextNode);
				stack = stack->nextNode;
			}

		printf("\n");
	}
