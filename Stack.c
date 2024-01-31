#include <stdio.h>
#include <stdlib.h>

#define	V_ONE	1
#define	V_ZERO	0

// Estructura para un nodo de la pila.
struct Node
	{
		int data;
		struct Node *nextNode;
	};

// Función para eliminar un elemento de la pila.
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

// Función para insertar un elemento en la stack
struct Node *push(int data, struct Node *stack)
	{
		struct Node *newNode = NULL;

		if (newNode = malloc(sizeof(struct Node)))
			{
				newNode->data = data;
				newNode->nextNode = stack;
			}

		return newNode;
	}

// Función para cargar elementos a la stack.
struct Node *load(int num, struct Node **stack)
	{
		int data = V_ZERO;
		struct Node *newNode = NULL;

		for (int i = V_ZERO; i < num; i++)
			{
				printf("Dato # [%d] de [%d] : ", i + V_ONE, num);
				scanf("%d", &data);

				newNode = push(data, newNode);
			}

		if (stack) *stack = newNode;
		return newNode;
	}

// Función para visualizar los elementos de la stack
void view(struct Node *stack)
	{
		int c = V_ZERO;
		static int k = V_ZERO;

		printf("\nStack:\t#[%3d].\n", k++);

		while (stack)
			{
				printf("\t#[%3d]\t[%p] : [%p] = [%5.d] -> [%p].\n", c++, &stack, stack, stack->data, stack->nextNode);
				stack = stack->nextNode;
			}

		printf("\n");
	}

//Función para descargar elementos de la stack.
struct Node *unload(int *data, struct Node **stack)
	{
		while (*stack)
			{
				*stack = pop(data, *stack);
				view(*stack);
			}

		return *stack;
	}


//Función principal.
int main()
	{
		int data = V_ZERO;
		int num = V_ZERO;
		struct Node *stack = NULL;

		printf("Número de datos : ");
		scanf("%i", &num);

		// Operaciones de prueba.
		stack = load(num, &stack);

		// Ver el contenido actual de la pila.
		view(stack);

		// Liberar memoria al finalizar el programa.
		stack = unload(&data, &stack);

		return V_ZERO;
	}
