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
struct Node* addNode(int data, struct Node **rootNode, int *counter);
int captureNodes(struct Node **rootNode, int *counter);
struct Node *createNode(int data, struct Node *leftNode, struct Node *rightNode);
int deleteTree(struct Node *rootNode, int *counter);
struct Node* searchNode(int data, struct Node *rootNode, int *counter);
int viewAllTree(struct Node *rootNode, int *counter);
int viewTree(struct Node *rootNode, enum enm_TreeTour enm_TT, int *counter);


//Main function.
int main()
	{
		/* Preliminary working variables. */
		int counter = V_ZERO, data = V_ZERO;
		struct Node *rootNode = NULL;   /* Point to the root of the binary search tree. */

		/* Loading the binary search tree. */
		counter = captureNodes(&rootNode, &counter);
		printf("[%d] Nodes captured.\n", counter);

		/* View the entire tree in all its forms. */
		counter = V_ZERO;
		counter = viewAllTree(rootNode, &counter);
		printf("[%d] Invoked traversal processes.\n", counter);

		/* Perform a search test for a given value in the tree. */
		printf("\nSearch for a specific value in the binary tree.\n");
		printf("Enter a value to search for : ");
		scanf("%d", &data);

		counter = V_ZERO;
		searchNode(data, rootNode, &counter);

		/* Remove all nodes from the entire tree. */
		printf("\nDelete the entire binary tree and free its memory...\n");
		counter = V_ZERO;
		counter = deleteTree(rootNode, &counter);
		printf("[%d] Nodes deleted.\n", counter);

		return EXIT_SUCCESS;
	}

/* Adding a key to the binary search tree. */
struct Node* addNode(int data, struct Node **rootNode, int *counter)
	{
		if (*rootNode)
			{
				if (data < (*rootNode)->data)
					addNode(data, &(*rootNode)->leftNode, counter);

				if (data > (*rootNode)->data)
					addNode(data, &(*rootNode)->rightNode, counter);

				if (data == (*rootNode)->data)
					printf("* The value # [%d] : [%d] = [%d] was already inserted previously!\n", *counter + V_ONE, data, (*rootNode)->data);
			}
		else
			{
				*rootNode = createNode(data, NULL, NULL);
				printf("+ Inserted data\t# [%d] = [%d].\n", ((*counter)++) + V_ONE, data);
			}

		return *rootNode;
	}

/* Function to capture values ​​and enter them into the binary search tree. */
int captureNodes(struct Node **rootNode, int *counter)
	{
		/* Preliminary working variables. */
		char chr_Char = NULL_CHARACTER;
		int data = V_ZERO;

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
								printf("+ Input value\t# [%d] = [%d]. OK!\n", *counter + V_ONE, data);
								*rootNode = addNode(data, rootNode, counter);
							}
					}
				else
					{
						printf("* The entry is not valid!\n");
						scanf("%*[^\n]%*c");
						while ((chr_Char = getchar()) != CARRIAGE_RETURN && chr_Char != EOF);
					}

				clearerr(stdin);
				fflush(stdin);
			}
		while (data);

		printf("\n[%d] Generated output results.\n", *counter);

		return *counter;
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
int deleteTree(struct Node *rootNode, int *counter)
	{
		if (rootNode)
			{
				*counter = deleteTree(rootNode->leftNode, counter);
				*counter = deleteTree(rootNode->rightNode, counter);

				(*counter)++;
				free(rootNode);
			}

		return *counter;
	}

/* It is responsible for searching for a specific value within the binary search tree. */
struct Node* searchNode(int data, struct Node *rootNode, int *counter)
	{
		struct Node* tempNode = NULL;

		if (rootNode)
			{
				(*counter)++;

				if (data < rootNode->data)
					tempNode = searchNode(data, rootNode->leftNode, counter);

				if (data > rootNode->data)
					tempNode = searchNode(data, rootNode->rightNode, counter);

				if (data == rootNode->data)
					{
						printf("The value: [%d] = [%d] was found in [%d] cycles!\n", data, rootNode->data, *counter);
						tempNode = rootNode;
					}
			}
		else
			printf("The value: [%d] was not found despite having traversed [%d] nodes!\n", data, *counter);

		return tempNode;
	}

/* Allows viewing of all types of binary search tree traversals. */
int viewAllTree(struct Node *rootNode, int *counter)
	{
		int counting = V_ZERO;
		printf("\nEntire display of the binary search tree.");

		/* Root node is tracked for each node level and for each node type. */
		for (int int_idx = (int) enm_TT_PreOrder; int_idx <= (int) enm_TT_Inv_PostOrder; int_idx++, counting++)
			{
				printf("\n[%s]\n", str_Modes[int_idx]);
				*counter = viewTree(rootNode, (enum enm_TreeTour) int_idx, counter);
			}

		printf("\n[%d] Generated exit routes.\n", counting);

		return *counter;
	}

/* Display the tree directed by the root node. */
int viewTree(struct Node *rootNode, enum enm_TreeTour enm_TT, int *counter)
	{
		switch (enm_TT)
			{
				case enm_TT_PreOrder:    //PreOrder.	{data, left, right}.
					if (rootNode)
						{
							(*counter)++;
							printf("%d\t", rootNode->data);
							*counter = viewTree(rootNode->leftNode, enm_TT_PreOrder, counter);
							*counter = viewTree(rootNode->rightNode, enm_TT_PreOrder, counter);
						}
					break;

				case enm_TT_InOrder:	//InOrder.	{left, data, right}.
					if (rootNode)
						{
							(*counter)++;
							*counter = viewTree(rootNode->leftNode, enm_TT_InOrder, counter);
							printf("%d\t", rootNode->data);
							*counter = viewTree(rootNode->rightNode, enm_TT_InOrder, counter);
						}
					break;

				case enm_TT_PostOrder:	//PostOrder.	{left, right, data}.
					if (rootNode)
						{
							(*counter)++;
							*counter = viewTree(rootNode->leftNode, enm_TT_PostOrder, counter);
							*counter = viewTree(rootNode->rightNode, enm_TT_PostOrder, counter);
							printf("%d\t", rootNode->data);
						}
					break;

				case enm_TT_Inv_PreOrder:	//Inverse PreOrder.
					if (rootNode)
						{
							(*counter)++;
							printf("%d\t", rootNode->data);
							*counter = viewTree(rootNode->rightNode, enm_TT_Inv_PreOrder, counter);
							*counter = viewTree(rootNode->leftNode, enm_TT_Inv_PreOrder, counter);
						}
					break;

				case enm_TT_Inv_InOrder:	//Inverse InOrder.
					if (rootNode)
						{
							(*counter)++;
							*counter = viewTree(rootNode->rightNode, enm_TT_Inv_InOrder, counter);
							printf("%d\t", rootNode->data);
							*counter = viewTree(rootNode->leftNode, enm_TT_Inv_InOrder, counter);
						}
					break;

				case enm_TT_Inv_PostOrder:	//Inverse PostOrder.
					if (rootNode)
						{
							(*counter)++;
							*counter = viewTree(rootNode->rightNode, enm_TT_Inv_PostOrder, counter);
							*counter = viewTree(rootNode->leftNode, enm_TT_Inv_PostOrder, counter);
							printf("%d\t", rootNode->data);
						}
					break;

				default:
					printf("Invalid Option!\n");
					break;
			}

		return *counter;
	}
