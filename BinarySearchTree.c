/******************* Árbol binario de búsqueda *********************
 * BSTree.c
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define	V_ZERO	0

enum enm_TreeTour   /* Modalidades de recorrido de un árbol binario. */
	{
		enm_TT_Normal_PreOrder,
		enm_TT_Normal_InOrder,
		enm_TT_Normal_PostOrder,
		enm_TT_Inverse_PreOrder,
		enm_TT_Inverse_InOrder,
		enm_TT_Inverse_PostOrder
	};

static char *str_Modes[] = {"Normal PreOrder", "Normal InOrder", "Normal PostOrder", "Inverse PreOrder", "Inverse InOrder", "Inverse PostOrder"};

struct Node     /* Estructura de un nodo del árbol. */
	{
		int data;
		struct Node *leftNode;  /* Puntero a la raíz del subárbol izquierdo. */
		struct Node *rightNode; /* Puntero a la raíz del subárbol derecho. */
	};

/* Prototipos de funciones. */
void addNodetoTree(int data, struct Node **rootNode);
int captureNodes(struct Node **rootNode);
struct Node *createNode(int data, struct Node *leftNode, struct Node *rightNode);
void deleteAllTree(struct Node *rootNode);
void searchNode(int data, struct Node *rootNode);
void viewAllTree(struct Node *rootNode);
void viewTree(struct Node *rootNode, enum enm_TreeTour enm_TT);


int main()  /* Función principal. */
	{
		int int_counting_items = V_ZERO;
		int data = V_ZERO;
		struct Node *rootNode = NULL;   /* Apunta a la raíz del árbol. */

		int_counting_items = captureNodes(&rootNode);
		viewAllTree(rootNode);

		printf("\n");
		printf("\nEnter a value to search for : ");
		scanf("%d", &data);
		searchNode(data, rootNode);

		printf("\n");
		printf("Delete the entire binary tree and free its memory...\n");
		deleteAllTree(rootNode);

		return EXIT_SUCCESS;
	}


/* Añadir una clave en el árbol binario de búsqueda.
    Se busca por un determinado nodo y si no se encuentra el valor se inserta.
    El valor para el nodo raíz es pasado por referencia para hacer posibles
    los nuevos enlaces entre nodo y nodo cuando se crea uno nuevo.
*/
void addNodetoTree(int data, struct Node **rootNode)
	{
		static int int_counting_items = V_ZERO;

		if (*rootNode)
			{
				if (data < (*rootNode)->data)
					addNodetoTree(data, &(*rootNode)->leftNode);

				if (data > (*rootNode)->data)
					addNodetoTree(data, &(*rootNode)->rightNode);

				if (data == (*rootNode)->data)
					printf("The value: [%d] : [%d] was already inserted previously!\n", data, (*rootNode)->data);
			}
		else
			{
				*rootNode = createNode(data, NULL, NULL);
				printf("Inserted data # [%d] : [%d].\n", int_counting_items++, data);
			}
	}

/* Función para capturar valores e ingresarlos al árbol binario de búsqueda. */
int captureNodes(struct Node **rootNode)
	{
		int data = V_ZERO, datas = V_ZERO;
		int int_counting_items = V_ZERO;

		printf("Entering integer values to build a binary search tree.\n");
		printf("Finish by pressing [CTRL] + [D].\n");

		printf("Enter a entire data [%d] : ", int_counting_items++);
		while (scanf("%d", &data) != EOF)
			{
				addNodetoTree(data, rootNode);  /* Raíz se pasa por referencia. */
				printf("Enter a entire data [%d] : ", int_counting_items++);
			}

		clearerr(stdin);

		printf("\n");
		printf("[%d] Generated output results...\n", int_counting_items);

		return int_counting_items;
	}

/* Función de creación de un nuevo nodo. */
struct Node *createNode(int data, struct Node *leftNode, struct Node *rightNode)
	{
		struct Node *newNode = NULL;

		if (newNode = (struct Node *) malloc(sizeof(struct Node)))
			{
				newNode->data = data;
				newNode->leftNode = leftNode;
				newNode->rightNode = rightNode;
			}
		else
			{
				perror("Mistake! Insufficient memory space for allocation...");
				exit(EXIT_FAILURE);
			}

		return newNode;
	};


/* Liberar la memoria asignada a cada uno de los nodos del árbol direccionado por
    el nodo raíz. Se recorre el árbol, generalmente en PostOrden.
*/
void deleteAllTree(struct Node *rootNode)
	{
		if (rootNode)
			{
				deleteAllTree(rootNode->leftNode);
				deleteAllTree(rootNode->rightNode);
				free(rootNode);
			}
	}

/* Se encarga de buscar un valor determinado dentro del árbol binario de búsqueda. */
void searchNode(int data, struct Node *rootNode)
	{
		if (rootNode)
			{
				if (data < rootNode->data)
					searchNode(data, rootNode->leftNode);

				if (data > rootNode->data)
					searchNode(data, rootNode->rightNode);

				if (data == rootNode->data)
					printf("The value: [%d] : [%d] was found!\n", data, rootNode->data);
			}
		else
			printf("The value: [%d] was not found!\n", data);
	}

/* Permite la visualización de todos los tipos de recorridos del
 * árbol binario de búsqueda.
 */
void viewAllTree(struct Node *rootNode)
	{
		printf("\n");
		printf("Entire display of the binary search tree.\n");

		/* Nodo raíz y nivel de cada nodo. */
		for (int int_idx = (int) enm_TT_Normal_PreOrder; int_idx <= (int) enm_TT_Inverse_PostOrder; int_idx++)
			{
				printf("\n[%s].\n", str_Modes[int_idx]);
				viewTree(rootNode, (enum enm_TreeTour) int_idx);
			}
	}

/* Visualizar el árbol direccionado por raíz.
 * Cada nivel de nodo se visualiza cuando se recorre el árbol.
 *
 * Esencialmente pueden utilizarse tres formas para recorrer un árbol binario: preorden, inorden y postorden.
 * Cuando se visitan los nodos en preorden, primero se visita la raí2, después el subiírbol izquierdo y por último el subárbol derecho.
 * Cuando se visitan los nodos en inorden, primero se visita el subárbol izquierdo, después la raíz y por último el subárbol derecho.
 * Cuando se visitan los nodos en postorden, primero se visita el subárbol izquierdo, después el subárbol derecho y por último la raí2.
 */
void viewTree(struct Node *rootNode, enum enm_TreeTour enm_TT)
	{
		switch (enm_TT)
			{
				case enm_TT_Normal_PreOrder:    //PreOrder.
					if (rootNode)
						{
							printf("[%d].\t", rootNode->data);
							viewTree(rootNode->leftNode, enm_TT_Normal_PreOrder);
							viewTree(rootNode->rightNode, enm_TT_Normal_PreOrder);
						}

					break;

				case enm_TT_Normal_InOrder:	//InOrder.
					if (rootNode)
						{
							viewTree(rootNode->leftNode, enm_TT_Normal_InOrder);
							printf("[%d].\t", rootNode->data);
							viewTree(rootNode->rightNode, enm_TT_Normal_InOrder);
						}

					break;

				case enm_TT_Normal_PostOrder:	//PostOrder.
					if (rootNode)
						{
							viewTree(rootNode->leftNode, enm_TT_Normal_PostOrder);
							viewTree(rootNode->rightNode, enm_TT_Normal_PostOrder);
							printf("[%d].\t", rootNode->data);
						}

					break;

				case enm_TT_Inverse_PreOrder:	//Inverse PreOrder.
					if (rootNode)
						{
							printf("[%d].\t", rootNode->data);
							viewTree(rootNode->rightNode, enm_TT_Inverse_PreOrder);
							viewTree(rootNode->leftNode, enm_TT_Inverse_PreOrder);
						}

					break;

				case enm_TT_Inverse_InOrder:	//Inverse InOrder.
					if (rootNode)
						{
							viewTree(rootNode->rightNode, enm_TT_Inverse_InOrder);
							printf("[%d].\t", rootNode->data);
							viewTree(rootNode->leftNode, enm_TT_Inverse_InOrder);
						}

					break;

				case enm_TT_Inverse_PostOrder:	//Inverse PostOrder.
					if (rootNode)
						{
							viewTree(rootNode->rightNode, enm_TT_Inverse_PostOrder);
							viewTree(rootNode->leftNode, enm_TT_Inverse_PostOrder);
							printf("[%d].\t", rootNode->data);
						}

					break;

				default:
					printf("Invalid Option!\n");
					break;
			}
	}
