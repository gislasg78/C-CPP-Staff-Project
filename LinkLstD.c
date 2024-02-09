/***** Lista doblemente enlazada ordenada ascendentemente *****/
/* listadob.c
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

typedef struct Node t_Node;		/* tipo elemento */
typedef t_Node * t_ptr_Node;	/* tipo puntero a un elemento */
struct Node	/* estructura de un elemento de la lista */
	{
		t_ptr_Node previousNode;
		int int_data;
		t_ptr_Node nextNode;
	};

typedef struct listroll DoubleLinkedList;
struct listroll
	{
		t_ptr_Node princ;	/* principio de la lista */
		t_ptr_Node final;	/* final de la lista */
	};

void addNode(int, DoubleLinkedList *);
t_ptr_Node createNode(int, t_ptr_Node, t_ptr_Node);
void clearList(DoubleLinkedList *);
void deleteNode(int, DoubleLinkedList *);
void menu(int *);
void modifyNode(int, int, DoubleLinkedList);
t_ptr_Node searchNode(int, DoubleLinkedList);
void viewList(DoubleLinkedList *);

int main()
	{
		DoubleLinkedList listaD;
		t_ptr_Node q = NULL;

		int int_data = V_ZERO;
		int int_data_mod = V_ZERO;
		int int_option = V_ZERO;

		listaD.princ = listaD.final = NULL;	/* lista vacía */

		while (int_option != V_SEVEN)
			{
				menu(&int_option);

				switch(int_option)
					{
						case V_ONE:
							printf("Add item: ");
							scanf("%d", &int_data);
							addNode(int_data, &listaD);
							break;

						case V_TWO:
							printf("Delete item: ");
							scanf("%d", &int_data);
							deleteNode(int_data, &listaD);
							break;

						case V_THREE:
							printf("Clear list...\n");
							clearList(&listaD);
							break;

						case V_FOUR:
							printf("Change item: ");
							scanf("%d", &int_data);

							q = searchNode(int_data, listaD);

							if (q)
								{
									printf("Change item: [%d] for? : ", q->int_data);
									scanf("%d", &int_data_mod);
									modifyNode(int_data, int_data_mod, listaD);
								}

							break;

						case V_FIVE:
							printf("Consult item: ");
							scanf("%d", &int_data);
							q = searchNode(int_data, listaD);
							break;

						case V_SIX:
							printf("Dump list...\n");
							viewList(&listaD);
							break;

						case V_SEVEN:
							clearList(&listaD);
							break;

						default:
							printf("Invalid option: [%d]...\n", int_option);
							break;

					}
			}

		return V_ZERO;
	}

/* Añadir un dato a la lista */
void addNode(int int_data, DoubleLinkedList *listaD)
	{
		t_ptr_Node currentNode = listaD->princ;
		t_ptr_Node previousNode = listaD->princ;
		t_ptr_Node q = NULL;

		/* Generar un nuevo elemento */
		q = createNode(int_data, NULL, NULL);

		if (listaD->princ)	/* Lista con contenido (no vacía) */
			{
				/* Buscar la posición donde hay que agregar el elemento */
				while (currentNode && currentNode->int_data > int_data)
					{
						previousNode = currentNode;
						currentNode = currentNode->nextNode;
					}

				if (previousNode == currentNode)	/* añadir al principio */
					{
						q->nextNode = listaD->princ;
						listaD->princ = currentNode->previousNode = q;
					}
				else	/* añadir después del 'previousNode' */
					{	/* incluye agregar al final */
						q->previousNode = previousNode;
						q->nextNode = currentNode;
						previousNode->nextNode = q;
						/* 'currentNode' será NULL cuando se inserta al final */
						if (currentNode)
							currentNode->previousNode = q;
						else		/* se añadió al final */
							listaD->final = q;
					}
			}
		else
			listaD->princ = listaD->final = q;
	}

/* Limpiar toda la lista */
void clearList(DoubleLinkedList *listaD)
	{
		/* Liberar la memoria ocupada por la lista */
		t_ptr_Node q = listaD->princ;	/* 'q' apunta al primer elemento de la lista */

		while (q)
			{
				listaD->princ = listaD->princ->nextNode;
				free(q);
				q = listaD->princ;
			}
	}

/* Funciones */
t_ptr_Node createNode(int int_data, t_ptr_Node previousNode, t_ptr_Node nextNode)
	{
		t_ptr_Node q = NULL;

		if (q = (t_ptr_Node) malloc (sizeof(t_ptr_Node)))
			{
				q->int_data = int_data;
				q->previousNode = previousNode;
				q->nextNode = nextNode;
			}
		else
			{
				perror("Error: Insufficient memory space for allocation...");
				exit(EXIT_FAILURE);
			}

		return (q);
	}

/* Encontrar un determinado dato y borrar el elemento */
void deleteNode(int int_data, DoubleLinkedList *listaD)
	{
		t_ptr_Node currentNode = listaD->princ;
		t_ptr_Node previousNode = listaD->princ;

		if (listaD->princ)		/* lista con contenido (no vacía) */
			{
				/* Entrar en la lista y encontrar el elemento a borrar */
				while (currentNode && currentNode->int_data > int_data)
					{
						previousNode = currentNode;
						currentNode = currentNode->nextNode;
					}

				/* Si el dato no se encuentra, entonces retornar */
				if (previousNode)
					if (currentNode)
						{
							/* Si el dato se encuentra, borrar el elemento */
							if (previousNode == currentNode)	/* el elemento está al principio */
								{
									listaD->princ = listaD->princ->nextNode;
									if (listaD->princ) listaD->princ->previousNode = NULL;
									/* Si principio es igual a NULL había un sólo elemento */
								}
							else	/* Borrar un elemento que no está al principio */
								{
									/* Modificar el enlace 'nextNode' */
									previousNode->nextNode = currentNode->nextNode;
									/* Modificar el enlace 'previousNode' excepto para el último */
									previousNode->nextNode->previousNode = currentNode->previousNode;
								}

							free(currentNode);
						}
					else
						printf("Value to delete: [%d] not found!\n", int_data);
				else
					printf("Value to erase: [%d] not found!\n", int_data);
			}

	}

/* Menú de opciones */
void menu(int *ptr_int_option)
	{
		int int_option = V_ZERO;

		do
			{
				printf("\n");
				printf("Circular doubly linked list.\n");
				printf("1. Add a data.\n");
				printf("2. Delete a data.\n");
				printf("3. Delete list.\n");
				printf("4. Modify a data.\n");
				printf("5. Look for a data.\n");
				printf("6. Look for list.\n");
				printf("7. Exit.\n");
				printf("Option: ");
				scanf("%d", &int_option);
			}
		while (int_option < V_ONE || int_option > V_SEVEN);

		*ptr_int_option = int_option;
	}

/* Modificar un elemento determinado en la lista. */
void modifyNode(int int_data, int int_data_mod, DoubleLinkedList listaD)
	{
		t_ptr_Node q = listaD.princ;	/* Se apunta al principio de la lista. */

		q = searchNode(int_data, listaD);

		if (q)
			{
				printf("Value: [%d] has been changed to [%d].\n", q->int_data, int_data_mod);
				q->int_data = int_data_mod;
			}
	}

/* Buscar un elemento determinado en la lista. */
t_ptr_Node searchNode(int int_data, DoubleLinkedList listaD)
	{
		t_ptr_Node q = listaD.princ;	/* Se apunta al principio de la lista. */

		while (q && int_data != q->int_data)
			q = q->nextNode;

		if (q)
			printf("Value: [%d] found!\n", q->int_data);
		else
			printf("Value: [%d] not found!\n", int_data);

		return (q);
	}

/* Visualizar el contenido de la lista */
void viewList(DoubleLinkedList *listaD)
	{
		int int_option = V_ZERO;
		t_ptr_Node q = NULL;

		do
			{
				printf("\n");
				printf("Sort the list display.\n");
				printf("1. Descendingly.\n");
				printf("2. Ascendingly.\n");
				printf("Option: ");
				scanf("%d", &int_option);
			}
		while (int_option < V_ONE || int_option > V_TWO);

		switch (int_option)
			{
				case V_ONE:		/* listado descendente */
					q = listaD->princ;

					while (q)
						{
							printf("[%d].\t", q->int_data);
							q = q->nextNode;
						}

					break;

				case V_TWO:		/* listado ascendente */
					q = listaD->final;

					while (q)
						{
							printf("[%d].\t", q->int_data);
							q = q->previousNode;
						}

					break;

				default:
					printf("Invalid option: [%d]...\n", int_option);
					break;

			}
	}
