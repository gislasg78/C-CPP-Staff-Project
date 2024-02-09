/************ Operaciones con listas ****************
 * listal.c
 */

#include <stdio.h>
#include <stdlib.h>

#define	V_FIVE	5
#define	V_FOUR	4
#define	V_ONE	1
#define	V_SEVEN	7
#define	V_SIX	6
#define	V_THREE	3
#define	V_TWO	2
#define	V_ZERO	0

/* Lista simplemente enlazada.
 * Cada elemento contiene un número entero. */
typedef struct Node /* elemento de una lista de enteros. */
	{
		int int_data;
		struct Node *nextNode;
	} t_Node;

/* Funciones prototipo. */
void addNode(int, t_Node **);
void clearList(t_Node **);
t_Node *createNode(int, t_Node *);
void deleteNode(int, t_Node **);
void menu(int, t_Node **);
void modifyNode(int, int, t_Node *);
t_Node *searchNode(int, t_Node *);
void viewList(t_Node *);


int main()	/* Función principal. */
	{
		int int_option = V_ZERO;
		t_Node *HeaderList = NULL;   /* Lista vacía. */

		while (int_option != V_SEVEN)
			{
				printf("\n");
				printf("Simply linked list.\n");
				printf("1. Add a data.\n");
				printf("2. Delete a data.\n");
				printf("3. Delete list.\n");
				printf("4. Modify a data.\n");
				printf("5. Look for a data.\n");
				printf("6. Look for list.\n");
				printf("7. Exit.\n");
				printf("Option: ");
				scanf("%d", &int_option);

				fflush(stdin);

				menu(int_option, &HeaderList);
			}

		return V_ZERO;
	}

/* Introducir un elemento ordenadamente en la lista. */
void addNode(int int_data, t_Node **HeaderList)
	{
		t_Node *currentNode = *HeaderList;
		t_Node *previousNode = *HeaderList;

		if (*HeaderList)
			{
				/* Entrar en la lista y encontrar el punto de inserción. */
				while (currentNode && int_data > currentNode->int_data)
					{
						previousNode = currentNode;
						currentNode = currentNode->nextNode;
					}

				/* Dos casos:
				 * 1) Insertar al principio de la lista.
				 * 2) Insertar después del previamente insertado. (incluye insertar al final).
				*/
				if (previousNode == currentNode)
					*HeaderList = createNode(int_data, *HeaderList);
				else    /* Insertar después del previamente insertado. */
					previousNode->nextNode = createNode(int_data, currentNode);
			}
		else
				*HeaderList = createNode(int_data, NULL);
	}

/* Limpiar toda la lista. */
void clearList(t_Node **HeaderList)
	{
		/* Liberar la memoria ocupada por lista. */
		t_Node *tempNode = *HeaderList; /* 'q' apunta al primer elemento de la lista. */

		while (tempNode)
			{
				*HeaderList = (*HeaderList)->nextNode;
				free(tempNode);
				tempNode = *HeaderList;
			}
	}

/* Funciones. Crear un nodo. */
t_Node *createNode(int int_data, t_Node *HeaderList)
	{
		t_Node *newNode = NULL;

		if (newNode = (t_Node *) malloc(sizeof(t_Node)))
			{
				newNode->int_data = int_data;
				newNode->nextNode = HeaderList;
			}
		else
			{
				perror("Mistake! Insufficient memory space for allocation...");
				exit(EXIT_FAILURE);
			}

		return (newNode);
	}

/* Encontrar un dato y posteriormente borrarlo. */
void deleteNode(int int_data, t_Node **HeaderList)
	{
		t_Node *currentNode = *HeaderList;
		t_Node *previousNode = *HeaderList;

		if (*HeaderList)
			{
				/* Entrar en la lista y encontrar el elemento a borrar. */
				while (currentNode && int_data != currentNode->int_data)
					{
						previousNode = currentNode;
						currentNode = currentNode->nextNode;
					}

				/* Si el dato no se encuentra, retornar. */
				if (previousNode)
					if (currentNode)
						{
							/* Si el dato se encuentra, borrar el elemento. */
							if (previousNode == currentNode) /* Borrar el elemento de cabecera. */
								*HeaderList = (*HeaderList)->nextNode;
							else    /* Borrar un elemento que no es cabecera. */
								previousNode->nextNode = currentNode->nextNode;

							free(currentNode);
						}
					else
						printf("Value to delete: [%d] not found!\n", int_data);
				else
					printf("Value to erase: [%d] not found!\n", int_data);
			}
	}

/* Menú de opciones.*/
void menu(int int_option, t_Node **HeaderList)
	{	/* Menú de opciones. */
		t_Node *tempNode = NULL;

		int int_data = V_ZERO;
		int int_data_mod = V_ZERO;

		switch(int_option)
			{
				case V_ONE:
					printf("Add item: ");
					scanf("%d", &int_data);
					addNode(int_data, HeaderList);
					break;

				case V_TWO:
					printf("Delete item: ");
					scanf("%d", &int_data);
					deleteNode(int_data, HeaderList);
					break;

				case V_THREE:
					printf("Clear list...\n");
					clearList(HeaderList);
					break;

				case V_FOUR:
					printf("Change item: ");
					scanf("%d", &int_data);

					tempNode = searchNode(int_data, *HeaderList);

					if (tempNode)
						{
							printf("Change item: [%d] for? : ", tempNode->int_data);
							scanf("%d", &int_data_mod);
							modifyNode(int_data, int_data_mod, *HeaderList);
						}

					break;

				case V_FIVE:
					printf("Consult item: ");
					scanf("%d", &int_data);
					tempNode = searchNode(int_data, *HeaderList);
					break;

				case V_SIX:
					printf("Dump list...\n");
					viewList(*HeaderList);
					break;

				case V_SEVEN:
					clearList(HeaderList);
					break;

				default:
					printf("Invalid option: [%d]...\n", int_option);
					break;

			}
	}

/* Modificar un elemento determinado en la lista. */
void modifyNode(int int_data, int int_data_mod, t_Node *HeaderList)
	{
		t_Node *currentNode = NULL;

		currentNode = searchNode(int_data, HeaderList);

		if (currentNode)
			{
				printf("Value: [%d] has been changed to [%d].\n", currentNode->int_data, int_data_mod);
				currentNode->int_data = int_data_mod;
			}
	}

/* Buscar un elemento determinado en la lista. */
t_Node *searchNode(int int_data, t_Node *HeaderList)
	{
		while (HeaderList && int_data != HeaderList->int_data)
			HeaderList = HeaderList->nextNode;

		if (HeaderList)
			printf("Value: [%d] found!\n", HeaderList->int_data);
		else
			printf("Value: [%d] not found!\n", int_data);

		return (HeaderList);
	}

/* Volcar en pantalla todos los elementos de la lista. */
void viewList(t_Node *HeaderList)
	{
		while (HeaderList)
			{
				printf("[%d].\t", HeaderList->int_data);
				HeaderList = HeaderList->nextNode;
			}
	}
