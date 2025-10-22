/* This program builds a binary search tree and
   provides basic maintenance for the tree. */
/* Standard Work Libraries. */
#include <stdio.h>
#include <stdlib.h>

/* Symbolic character variables. */
#define CARRIAGE_RETURN	'\n'
#define NULL_CHARACTER	'\0'

/* Symbolic work constants. */
#define	V_ONE		1
#define	V_ZERO		0


/* Traversal modes of a binary search tree. */
enum enm_TreeTour
	{
		enm_TT_PreOrder,
		enm_TT_InOrder,
		enm_TT_PostOrder,
		enm_TT_Inv_PreOrder,
		enm_TT_Inv_InOrder,
		enm_TT_Inv_PostOrder
	};

/* Legends for the traversal type of a binary search tree. */
static char *str_Modes[] = {"PreOrder", "InOrder", "PostOrder", "Inverse PreOrder", "Inverse InOrder", "Inverse PostOrder"};

/* Structure of a node in a binary search tree. */
struct Node
	{
		int data;		/* Data value. */
		struct Node *leftNode;  /* Pointer to the root of the left subtree. */
		struct Node *rightNode; /* Pointer to the root of the right subtree. */
	};


/* Function prototypes. */
struct Node* addNode(int data, struct Node **rootNode);
int captureNodes(struct Node **rootNode);
struct Node *createNode(int data, struct Node *leftNode, struct Node *rightNode);
void deleteTree(struct Node *rootNode);
struct Node* searchNode(int data, struct Node *rootNode);
void viewAllTree(struct Node *rootNode);
void viewTree(struct Node *rootNode, enum enm_TreeTour enm_TT);


//Main function.
int main()
	{
		/* Preliminary working variables. */
		int counter = V_ZERO, data = V_ZERO;
		struct Node *rootNode = NULL;   /* Point to the root of the binary search tree. */

		/* Loading the binary search tree. */
		counter = captureNodes(&rootNode);
		printf("[%d] Nodes captured.\n", counter);

		/* View the entire tree in all its forms. */
		viewAllTree(rootNode);

		/* Perform a search test for a given value in the tree. */
		printf("\n\nSearch for a specific value in the tree.\n");
		printf("Enter a value to search for : ");
		scanf("%d", &data);
		searchNode(data, rootNode);

		/* Remove all nodes from the entire tree. */
		printf("\nDelete the entire binary tree and free its memory...\n");
		deleteTree(rootNode);

		return EXIT_SUCCESS;
	}

/* Adding a key to the binary search tree. */
struct Node* addNode(int data, struct Node **rootNode)
	{
		static int counter = V_ZERO;

		if (*rootNode)
			{
				if (data < (*rootNode)->data)
					addNode(data, &(*rootNode)->leftNode);

				if (data > (*rootNode)->data)
					addNode(data, &(*rootNode)->rightNode);

				if (data == (*rootNode)->data)
					printf("The value: [%d] = [%d] was already inserted previously!\n", data, (*rootNode)->data);
			}
		else
			{
				*rootNode = createNode(data, NULL, NULL);
				printf("Inserted data\t# [%d] = [%d].\n", (counter++) + V_ONE, data);
			}

		return *rootNode;
	}

/* Function to capture values ​​and enter them into the binary search tree. */
int captureNodes(struct Node **rootNode)
	{
		/* Preliminary working variables. */
		char chr_Char = NULL_CHARACTER;
		int counter = V_ZERO, data = V_ZERO;

		/* Header messages. */
		printf("Entering integer values to build a binary search tree.\n");
		printf("To end the capture, enter the value zero.\n");

		/* The root tree is passed by value its memory address stored in the pointer variable. */
		do
			{
				printf("\nEnter a entire data (0 to exit) : ");

				/* Validate that only one value is received. */
				if (scanf("%d%*c", &data) == V_ONE)
					{
						if (data)
							{
								printf("Input value\t# [%d] = [%d]. OK!\n", (counter++) + V_ONE, data);
								*rootNode = addNode(data, rootNode);
							}
					}
				else
					{
						scanf("%*[^\n]%*c");
						while ((chr_Char = getchar()) != CARRIAGE_RETURN && chr_Char != EOF);
					}

				clearerr(stdin);
				fflush(stdin);
			}
		while (data);

		printf("\n[%d] Generated output results.\n", counter);

		return counter;
	}

/* Free the memory allocated to each of the nodes in the binary search tree. */
struct Node *createNode(int data, struct Node *leftNode, struct Node *rightNode)
	{
		struct Node *newNode = NULL;

		if ((newNode = (struct Node *) malloc(sizeof(struct Node))))
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

/* Free the memory allocated to each of the nodes in the binary search tree. */
void deleteTree(struct Node *rootNode)
	{
		if (rootNode)
			{
				deleteTree(rootNode->leftNode);
				deleteTree(rootNode->rightNode);
				free(rootNode);
			}
	}

/* It is responsible for searching for a specific value within the binary search tree. */
struct Node* searchNode(int data, struct Node *rootNode)
	{
		struct Node* tempNode = NULL;

		if (rootNode)
			{
				if (data < rootNode->data)
					tempNode = searchNode(data, rootNode->leftNode);

				if (data > rootNode->data)
					tempNode = searchNode(data, rootNode->rightNode);

				if (data == rootNode->data)
					{
						printf("The value: [%d] = [%d] was found!\n", data, rootNode->data);
						tempNode = rootNode;
					}
			}
		else
			printf("The value: [%d] was not found!\n", data);

		return tempNode;
	}

/* Allows viewing of all types of binary search tree traversals. */
void viewAllTree(struct Node *rootNode)
	{
		printf("\nEntire display of the binary search tree.");

		/* Root node is tracked for each node level and for each node type. */
		for (int int_idx = (int) enm_TT_PreOrder; int_idx <= (int) enm_TT_Inv_PostOrder; int_idx++)
			{
				printf("\n[%s].\n", str_Modes[int_idx]);
				viewTree(rootNode, (enum enm_TreeTour) int_idx);
			}
	}

/* Display the tree directed by the root node. */
void viewTree(struct Node *rootNode, enum enm_TreeTour enm_TT)
	{
		switch (enm_TT)
			{
				case enm_TT_PreOrder:    //PreOrder.	{data, left, right}.
					if (rootNode)
						{
							printf("[%d].\t", rootNode->data);
							viewTree(rootNode->leftNode, enm_TT_PreOrder);
							viewTree(rootNode->rightNode, enm_TT_PreOrder);
						}
					break;

				case enm_TT_InOrder:	//InOrder.	{left, data, right}.
					if (rootNode)
						{
							viewTree(rootNode->leftNode, enm_TT_InOrder);
							printf("[%d].\t", rootNode->data);
							viewTree(rootNode->rightNode, enm_TT_InOrder);
						}
					break;

				case enm_TT_PostOrder:	//PostOrder.	{left, right, data}.
					if (rootNode)
						{
							viewTree(rootNode->leftNode, enm_TT_PostOrder);
							viewTree(rootNode->rightNode, enm_TT_PostOrder);
							printf("[%d].\t", rootNode->data);
						}
					break;

				case enm_TT_Inv_PreOrder:	//Inverse PreOrder.
					if (rootNode)
						{
							printf("[%d].\t", rootNode->data);
							viewTree(rootNode->rightNode, enm_TT_Inv_PreOrder);
							viewTree(rootNode->leftNode, enm_TT_Inv_PreOrder);
						}
					break;

				case enm_TT_Inv_InOrder:	//Inverse InOrder.
					if (rootNode)
						{
							viewTree(rootNode->rightNode, enm_TT_Inv_InOrder);
							printf("[%d].\t", rootNode->data);
							viewTree(rootNode->leftNode, enm_TT_Inv_InOrder);
						}
					break;

				case enm_TT_Inv_PostOrder:	//Inverse PostOrder.
					if (rootNode)
						{
							viewTree(rootNode->rightNode, enm_TT_Inv_PostOrder);
							viewTree(rootNode->leftNode, enm_TT_Inv_PostOrder);
							printf("[%d].\t", rootNode->data);
						}
					break;

				default:
					printf("Invalid Option!\n");
					break;
			}
	}
