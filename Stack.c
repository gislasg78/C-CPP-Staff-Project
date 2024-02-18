#include <stdio.h>
#include <stdlib.h>

#define	V_ONE	1
#define	V_ZERO	0

struct Node
	{
		int int_data;
		struct Node *nextNode;
	};

struct Node *load(int numNodes, struct Node **stack);
struct Node *pop(int *int_data, struct Node *stack);
struct Node *push(int int_data, struct Node *stack);
struct Node *unload(int *int_data, struct Node **stack);
void view(struct Node *stack);


int main()
	{
		int int_data = V_ZERO;
		int numNodes = V_ZERO;
		struct Node *stack = NULL;

		printf("Enter a data number : ");
		scanf("%i", &numNodes);

		stack = load(numNodes, &stack);
		view(stack);
		stack = unload(&int_data, &stack);

		return V_ZERO;
	}


struct Node *load(int numNodes, struct Node **stack)
	{
		int int_data = V_ZERO;
		struct Node *tempNode = NULL;

		for (int i = V_ZERO; i < numNodes; i++)
			{
				printf("Data # [%d] of [%d] : ", i + V_ONE, numNodes);
				scanf("%d", &int_data);

				tempNode = push(int_data, tempNode);
			}

		if (stack) *stack = tempNode;
		return tempNode;
	}

struct Node *pop(int *int_data, struct Node *stack)
	{
		struct Node *tempNode = NULL;

		if (stack)
			{
				tempNode = stack;
				*int_data = tempNode->int_data;

				stack = stack->nextNode;
				free(tempNode);
			}

		return stack;
	}

struct Node *push(int int_data, struct Node *stack)
	{
		struct Node *tempNode = NULL;

		if (tempNode = (struct Node *) malloc(sizeof(struct Node)))
			{
				tempNode->int_data = int_data;
				tempNode->nextNode = stack;
			}

		return tempNode;
	}

struct Node *unload(int *int_data, struct Node **stack)
	{
		while (*stack)
			{
				*stack = pop(int_data, *stack);
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
				printf("\t#[%3d]\t[%p] : [%p] = [%10.d] -> [%p].\n", c++, &stack, stack, stack->int_data, stack->nextNode);
				stack = stack->nextNode;
			}

		printf("\n");
	}
