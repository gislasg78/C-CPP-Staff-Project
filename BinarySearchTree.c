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


/* Binary search tree maintenance options. */
enum enm_opt
	{
		enm_opt_addNode = V_ONE,
		enm_opt_deleteTree,
		enm_opt_modifyNode,
		enm_opt_searchNode,
		enm_opt_showGraphic,
		enm_opt_viewAllTree,
		enm_opt_exitMenu
	} enm_opt_maintenance;

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
int getData(int *data, int *counter);
int MainMenu(enum enm_opt enm_opt_maintenance, struct Node **rootNode, int *counter);
struct Node* searchNode(int data, struct Node *rootNode, int *counter);
int showGraphicTree(struct Node *rootNode, int count, int *counter);
int viewAllTree(struct Node *rootNode, int *counter);
int viewTree(struct Node *rootNode, enum enm_TreeTour enm_TT, int *counter);


//Main function.
int main()
	{
		/* Preliminary working variables. */
		int counter = V_ZERO, option = V_ZERO;
		struct Node *rootNode = NULL;   /* Point to the root of the binary search tree. */

		/* Call the Main Menu. */
		option = MainMenu(enm_opt_maintenance, &rootNode, &counter);
		printf("\nFinal option chosen: [%d].\n", option);

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
		int data = V_ZERO;

		/* Header messages. */
		printf("\nEntering integer values to build a binary search tree.\n");
		printf("To end the capture, enter the value zero.\n");

		/* The root tree is passed by value its memory address stored in the pointer variable. */
		do
			{
				printf("\nEnter a entire data (0 to exit) : ");

				if ((data = getData(&data, counter)))
					*rootNode = addNode(data, rootNode, counter);
			}
		while (data);

		printf("\n[%d] Generated output results.\n", *counter);

		return *counter;
	}

/* Free the memory allocated to each of the nodes in the binary search tree. */
struct Node *createNode(int data, struct Node *leftNode, struct Node *rightNode)
	{
		/* Preliminary working variables. */
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

/* Control function for capturing a particular data. */
int getData(int *data, int *counter)
	{
		/* Preliminary working variables. */
		char chr_Char = NULL_CHARACTER;

		/* Validate that only one value is received. */
		if (scanf("%d%*c", data) == V_ONE)
			printf("+ Input value\t# [%d] = [%d]. OK!\n", *counter + V_ONE, *data);
		else
			{
				printf("* The entry is not valid!\n");
				scanf("%*[^\n]%*c");
				while ((chr_Char = getchar()) != CARRIAGE_RETURN && chr_Char != EOF);
			}

		/* Reset input stream flags. */
		clearerr(stdin);
		fflush(stdin);

		return *data;
	}

/* Main menu for binary search tree maintenance. */
int MainMenu(enum enm_opt enm_opt_maintenance, struct Node **rootNode, int *counter)
	{
		/* Preliminary working variables. */
		int count = V_ZERO, data = V_ZERO, option = V_ZERO;
		struct Node *tempRootNode = NULL;
		*counter = V_ZERO;

		/* Binary search tree maintenance options. */
		while (enm_opt_maintenance != enm_opt_exitMenu)
			{
				/* Display of menu options. */
				printf("\n");
				printf("+===+====+===+====+===+====+===+\n");
				printf("| Menu of Binary Search Trees. |\n");
				printf("+---+----+---+----+---+----+---+\n");
				printf("| [1]. Insert nodes.           |\n");
				printf("| [2]. Delete the entire tree. |\n");
				printf("| [3]. Modify a node.          |\n");
				printf("| [4]. Find a specific node.   |\n");
				printf("| [5]. Display graphically.    |\n");
				printf("| [6]. Display routes.         |\n");
				printf("| [7]. Exit this program.      |\n");
				printf("+===+====+===+====+===+====+===+\n");
				printf("Option: ");

				/* Converting an integer to an enumerated type. */
				*counter = V_ZERO;
				option = getData(&option, counter);
				enm_opt_maintenance = (enum enm_opt) option;

				/* Case selection structure for each chosen option. */
				switch(enm_opt_maintenance)
					{
						/* Loading the binary search tree. */
						case enm_opt_addNode:
							*counter = captureNodes(rootNode, counter);
							printf("[%d] Nodes captured.\n", *counter);
							break;

						/* Remove all nodes from the entire tree. */
						case enm_opt_deleteTree:
							printf("\nDelete the entire binary tree and free its memory...\n");

							*counter = deleteTree(*rootNode, counter);
							printf("[%d] Nodes deleted.\n", *counter);
							*rootNode = NULL;

							break;

						/* Iteratively searches for a node and modifies it if it finds one. */
						case enm_opt_modifyNode:
							printf("\nModify a specific value in the binary tree.\n");
							printf("Enter a value to search for : ");

							data = getData(&data, counter);
							tempRootNode = searchNode(data, *rootNode, counter);

							/* Validate the existence of the sought value. */
							if (tempRootNode)
								{
									printf("* Value located: [%d] with [%d] iterations! *\n", tempRootNode->data, *counter);
									printf("\nEnter a unique value to modify the value: [%d] : ", tempRootNode->data);

									*counter = V_ZERO;
									data = getData(&data, counter);

									*counter = V_ZERO;
									struct Node *newTempNode = searchNode(data, *rootNode, counter);

									/* Verify the node value change is not a repeated. */
									if (newTempNode)
										{
											printf("The value: [%d] already existed previously and cannot be changed to: [%d].\n", tempRootNode->data, newTempNode->data);
										}
									else
										{
											printf("The value: [%d] found in [%d] iterations has been changed to the value: [%d].\n", tempRootNode->data, *counter, data);
											tempRootNode->data = data;
										}

									newTempNode = tempRootNode = NULL;
								}
							else
								printf("* The value: [%d] was not located in the tree with [%d] iterations. *\n", data, *counter);

							break;

						/* Perform a search test for a given value in the tree. */
						case enm_opt_searchNode:
							printf("\nSearch for a specific value in the binary tree.\n");
							printf("Enter a value to search for : ");

							data = getData(&data, counter);
							tempRootNode = searchNode(data, *rootNode, counter);

							/* Validate the existence of the sought value. */
							if (tempRootNode)
								printf("* Value located: [%d] with [%d] iterations! *\n", tempRootNode->data, *counter);
							else
								printf("* The value: [%d] was not located in the tree with [%d] iterations. *\n", data, *counter);

							break;

						/* Graphical arrangement of binary search tree. */
						case enm_opt_showGraphic:
							printf("\nGraphical arrangement of Binary Search Tree.\n");
							*counter = showGraphicTree(*rootNode, count, counter);
							printf("\n[%d] Evenly distributed spaces.\n", *counter);
							break;

						/* View the entire tree in all its forms. */
						case enm_opt_viewAllTree:
							*counter = viewAllTree(*rootNode, counter);
							printf("[%d] Invoked traversal processes.\n", *counter);
							break;

						/* Program exit option. */
						case enm_opt_exitMenu:
							printf("\nLeaving this program...\n");

							*counter = deleteTree(*rootNode, counter);
							printf("[%d] Nodes deleted.\n", *counter);
							*rootNode = NULL;

							break;

						/* In case of incorrect or invalid option. */
						default:
							printf("\nInvalid captured option: [%d]. Please correct it!\n", option);
							break;
					}
			}

		return option;
	}

/* Display the binary search tree in a clearer, more distributed format. */
int showGraphicTree(struct Node *rootNode, int count, int *counter)
	{
		/* Arrange the tree so that it appears horizontal and neatly distributed. */
		if (rootNode)
			{
				showGraphicTree(rootNode->rightNode, count + V_ONE, counter);

				for (int idx = V_ZERO; idx < count; idx++, (*counter)++)
					printf("\t");

				printf("[%d].\n", rootNode->data);

				showGraphicTree(rootNode->leftNode, count + V_ONE, counter);
			}

		return *counter;
	}

/* It is responsible for searching for a specific value within the binary search tree. */
struct Node* searchNode(int data, struct Node *rootNode, int *counter)
	{
		/* Preliminary working variables. */
		struct Node* tempNode = NULL;

		/* Recursive cyclic search for a value at a specific node. */
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
		/* Preliminary working variables. */
		int counting = V_ZERO;
		printf("\nEntire display of the binary search tree.");

		/* Root node is tracked for each node level and for each node type. */
		for (int int_idx = (int) enm_TT_PreOrder; int_idx <= (int) enm_TT_Inv_PostOrder; int_idx++, counting++)
			{
				printf("\n[%s].\n", str_Modes[int_idx]);
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
