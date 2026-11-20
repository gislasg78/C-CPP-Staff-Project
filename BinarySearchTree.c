/* The primary purpose of this program is to demonstrate the maintenance of Binary Search Trees
   by providing various operations for updating them—such as the insertion, deletion, modification,
   querying, and visualization of their nodes—as well as the deletion of the entire tree.
   Test Example: {8, 3, 1, 6, 5, 4, 9, 14, 11, 12, 13, 15}. */

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
		enm_opt_deleteNode,
		enm_opt_deleteTree,
		enm_opt_eliminateNode,
		enm_opt_modifyNode,
		enm_opt_searchNode,
		enm_opt_showGraphic,
		enm_opt_viewAllTree,
		enm_opt_exitMenu
	} enm_opt_global_maintenance;

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

/* Enumeration with type entry variables and its reseting. */
enum enm_type_entry
	{
		enm_type_entry_char,
		enm_type_entry_double,
		enm_type_entry_float,
		enm_type_entry_int,
		enm_type_entry_long,
		enm_type_entry_short,
		enm_type_entry_sizet
	};

/* Enumeration for memory area reset system. */
enum enm_type_reset
	{
		enm_type_reset_NO,
		enm_type_reset_YES
	};

/* Legends for the traversal type of a binary search tree. */
static char *str_Modes[] = {"PreOrder", "InOrder", "PostOrder", "Inverse PreOrder", "Inverse InOrder", "Inverse PostOrder"};

/* Structure of a node in a binary search tree. */
struct Node
	{
		int data;			/* Data value. */
		struct Node *leftNode;  	/* Pointer to the root of the left subtree. */
		struct Node *rightNode;		/* Pointer to the root of the right subtree. */
		struct Node *fatherNode;	/* Parent or head node to which a node belongs.*/
	};

/* Function prototypes. */
struct Node* addNode(const int data, struct Node **rootNode, int *const counter, struct Node *const fatherNode);
int captureNodes(struct Node **rootNode, int *const counter);
struct Node *createNode(const int data, struct Node *const leftNode, struct Node *const rightNode, struct Node *const fatherNode);
void delNode(struct Node* rootNode, const int data, int *const counter);
void deleteNode(struct Node *rootNode, int *const counter);
int deleteTree(struct Node *rootNode, int *const counter);
struct Node* destroyNode(struct Node **rootNode, int *const counter);
struct Node *eliminateNode(struct Node* rootNode, const int data, int *const counter);
void *GetEntry(const char *const str_Message, void *const void_var_address, const enum enm_type_entry enm_type_data, const enum enm_type_reset enm_type_reset_OK);
int MainMenu(enum enm_opt enm_opt_maintenance, struct Node **rootNode, int *const option, int *const counter, int *const opers);
struct Node* minimumNode(struct Node *const rootNode, int *const counter);
struct Node* modifyNode(const int data, const int value, struct Node *const rootNode, int *const counter);
void replaceNode(struct Node *rootNode, struct Node *newNode);
struct Node* searchNode(const int data, struct Node *const rootNode, int *const counter);
int SelectedOptionMainMenu(const enum enm_opt enm_opt_maintenance, struct Node **rootNode, int *const counter, int *const opers);
int showGraphicTree(struct Node *rootNode, const int count, int *const counter);
int viewAllTree(struct Node *rootNode, int *const counter);
int viewTree(struct Node *rootNode, const enum enm_TreeTour enm_TT, int *const counter);

//Main function.
int main()
	{
		/* Preliminary working variables. */
		char chr_pause = NULL_CHARACTER;
		int counter = V_ZERO, opers = V_ZERO, option = V_ZERO;
		struct Node *rootNode = NULL;   /* Point to the root of the binary search tree. */

		/* Call the Main Menu. */
		option = MainMenu(enm_opt_global_maintenance, &rootNode, &option, &counter, &opers);

		/* Final exit messages at the end of the program. */
		printf("\nEnd of the Program.\n");
		printf("* Last requested option : [%d].\n", option);
		printf("* Operations performed  : [%d].\n", opers);
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This program has ended!\n");
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		return EXIT_SUCCESS;
	}

/* Adding a key to the binary search tree. */
struct Node* addNode(const int data, struct Node **rootNode, int *const counter, struct Node *const fatherNode)
	{
		/* This conditional validates that the node to be inserted does not, in fact, already exist in the binary search tree. */
		if (*rootNode)
			{
				if (data < (*rootNode)->data)
					addNode(data, &(*rootNode)->leftNode, counter, *rootNode);

				if (data > (*rootNode)->data)
					addNode(data, &(*rootNode)->rightNode, counter, *rootNode);

				if (data == (*rootNode)->data)
					printf("The value # [%d] : [%d] = [%d] was already inserted previously!\n", *counter + V_ONE, data, (*rootNode)->data);
			}
		else
			{
				*rootNode = createNode(data, NULL, NULL, fatherNode);
				printf("Inserted data: # [%d] = {%d}.\n", ((*counter)++) + V_ONE, data);
			}

		/* Returns the binary search tree with all the nodes added and attached. */
		return *rootNode;
	}

/* Function to capture values ​​and enter them into the binary search tree. */
int captureNodes(struct Node **rootNode, int *const counter)
	{
		/* Preliminary working variables. */
		int data = V_ZERO;

		/* Header messages. */
		printf("\nEntering integer values to build a binary search tree.\n");
		printf("To end the capture, enter the value '0' (zero).\n");

		/* The root tree is passed by value its memory address stored in the pointer variable. */
		do
			{
				if ((data = *((int *) GetEntry("\nEnter a entire data ('0' to exit) : ", &data, enm_type_entry_int, enm_type_reset_YES))))
					*rootNode = addNode(data, rootNode, counter, NULL);
			}
		while (data);

		printf("\n[%d] Generated output results.\n", *counter);

		/* Return the number of nodes successfully captured and created. */
		return *counter;
	}

/* Free the memory allocated to each of the nodes in the binary search tree. */
struct Node *createNode(const int data, struct Node *const leftNode, struct Node *const rightNode, struct Node *const fatherNode)
	{
		/* Preliminary working variables. */
		struct Node *newNode = NULL;

		/* Conditional to verify and validate that a node has been created correctly. */
		if ((newNode = (struct Node *) calloc((size_t) V_ONE, sizeof(struct Node))))
			{
				newNode->data = data;
				newNode->leftNode = leftNode;
				newNode->rightNode = rightNode;
				newNode->fatherNode = fatherNode;
			}
		else
			{
				fputs("\nSerious problem when creating the node.", stderr);
				fprintf(stderr, "\nA serious problem occurred when allocating dynamic memory for a new node.\n");
				perror("Mistake! Insufficient memory space for allocation...");
				exit(EXIT_FAILURE);
			}

		/* Return the newly created node as the result. */
		return newNode;
	}

/* Function to remove the given node. */
void delNode(struct Node* rootNode, const int data, int *const counter)
	{
		/* The node to be deleted must contain valid information. */
		if (rootNode)
			{
				(*counter)++;

				if (data < rootNode->data)
					delNode(rootNode->leftNode, data, counter);
				else if (data > rootNode->data)
					delNode(rootNode->rightNode, data, counter);
				else if (data == rootNode->data)
					deleteNode(rootNode, counter);
			}
	}

/* Function to remove the found node. */
void deleteNode(struct Node *rootNode, int *const counter)
	{
		/* The node to be deleted must contain valid information. */
		if (rootNode)
			{
				/* Delete a node with two dependent child subtrees. */
				if (rootNode->leftNode && rootNode->rightNode)	//Delete a tree with two child subtrees.
					{
						/* For a node with two children, the successor must be obtained in order. */
						struct Node* myMinimumNode = minimumNode(rootNode->rightNode, counter);
						rootNode->data = myMinimumNode->data;
						deleteNode(rootNode->rightNode, counter);
					}
				else if (rootNode->leftNode)			//If it only has one child node on the left.
					{
						/* Only the current node has information in the left node. */
						replaceNode(rootNode, rootNode->leftNode);
						rootNode = destroyNode(&rootNode, counter);
					}
				else if (rootNode->rightNode)			//If it only has one child node on the right.
					{
						/* Only the current node has information in the right node. */
						replaceNode(rootNode, rootNode->rightNode);
						rootNode = destroyNode(&rootNode, counter);
					}
				else						//If it doesn't have any children.
					{
						/* Only if the current node lacks both left and right slopes. */
						replaceNode(rootNode, NULL);
						rootNode = destroyNode(&rootNode, counter);
					}
			}
	}

/* Free the memory allocated to each of the nodes in the binary search tree. */
int deleteTree(struct Node *rootNode, int *const counter)
	{
		/* The tree to be deleted must contain valid information. */
		if (rootNode)
			{
				*counter = deleteTree(rootNode->leftNode, counter);
				*counter = deleteTree(rootNode->rightNode, counter);

				(*counter)++;
				rootNode = destroyNode(&rootNode, counter);
			}

		/* Return the number of nodes in the tree that have been released and initialized. */
		return *counter;
	}

/* Removes the memory occupied by a node from the binary search tree. */
struct Node* destroyNode(struct Node **rootNode, int *const counter)
	{
		/* The node to be deleted must contain valid information. */
		if (*rootNode)
			{
				(*rootNode)->data = V_ZERO;
				(*rootNode)->leftNode = NULL;
				(*rootNode)->rightNode = NULL;
				(*rootNode)->fatherNode = NULL;

				(*counter)++;
				free(*rootNode);
				*rootNode = NULL;
			}

		/* Returns the binary search tree with the node removed. */
		return *rootNode;
	}

/* Function to permanently remove a node from the binary search tree. */
struct Node *eliminateNode(struct Node* rootNode, const int data, int *const counter)
	{
		/* The node to be deleted must contain valid information. */
		if (rootNode)
			{
				(*counter)++;	//Count the nodes that have been effectively removed from the Binary Search Tree.

				/* Depth-first search of the node to be located. */
				if (data < rootNode->data)
					{
						rootNode->leftNode = eliminateNode(rootNode->leftNode, data, counter);
					}
				else if (data > rootNode->data)
					{
						rootNode->rightNode = eliminateNode(rootNode->rightNode, data, counter);
					}
				else
					{
						/* A specific node with either a single child (left or right) or no children. */
						if (rootNode->leftNode && rootNode->rightNode)
							{
								/* For a node with two children, the successor must be obtained in order. */
								struct Node* myMinimumNode = minimumNode(rootNode->rightNode, counter);
								rootNode->data = myMinimumNode->data;
								rootNode->rightNode = eliminateNode(rootNode->rightNode, myMinimumNode->data, counter);
							}
						else if (rootNode->leftNode == NULL)
							{
								/* Only the current node has information in the right node. */
								struct Node* tempNode = rootNode->rightNode;
								rootNode = destroyNode(&rootNode, counter);
								rootNode = tempNode;
							}
						else if (rootNode->rightNode == NULL)
							{
								/* Only the current node has information in the left node. */
								struct Node* tempNode = rootNode->leftNode;
								rootNode = destroyNode(&rootNode, counter);
								rootNode = tempNode;
							}
					}
			}

		/* Return the specified node from the binary search tree. */
		return rootNode;
	}

/* Function that gets a correct type value depending on its option. */
void *GetEntry(const char *const str_Message, void *const void_var_address, const enum enm_type_entry enm_type_data, const enum enm_type_reset enm_type_reset_OK)
	{
		/* Preliminary working variables. */
		static char chr_storage = NULL_CHARACTER;
		int int_chars = V_ZERO;
		int int_fields = V_ZERO;
		int int_key = V_ZERO;

		/* Convert the specified enumerated type to an 'integer'. */
		int option_type_entry = (int) enm_type_data;

		/* Validate if the obtained memory addresses are valid. */
		if (void_var_address)
			{
				/* Initialize the specified memory area. */
				if (enm_type_reset_OK == enm_type_reset_YES)
					{
						switch(enm_type_data)
							{
								case enm_type_entry_char:
									*((char *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_double:
									*((double *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_float:
									*((float *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_int:
									*((int *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_long:
									*((long *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_short:
									*((short *) void_var_address) = V_ZERO;
									break;

								case enm_type_entry_sizet:
									*((size_t *) void_var_address) = V_ZERO;
									break;

								default:
									fputs("\nUnrecognized Option!\n", stderr);
									fprintf(stderr, "The selected option: [%d] is invalid. Please correct it!\n", option_type_entry);
									break;
							}
					}

				/* Incoming message. */
				printf("%s", str_Message);

				/* Selection of validating case of the type of variable to generate. */
				switch(enm_type_data)
					{
						/* Get a correct character value. */
						case enm_type_entry_char:
							if ((int_fields = scanf("%c%*c%n", (char *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%x] : [%d] = [%c]. Characters: [%d]. OK!\n", int_fields, *((char *) void_var_address), *((char *) void_var_address), *((char *) void_var_address), int_chars);
							break;

						/* Get a correct floating-point double precision value. */
						case enm_type_entry_double:
							if ((int_fields = scanf("%lf%*c%n", (double *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%lf]. Characters: [%d]. OK!\n", int_fields, *((double *) void_var_address), int_chars);
							break;

						/* Get a correct floating-point single precision value. */
						case enm_type_entry_float:
							if ((int_fields = scanf("%f%*c%n", (float *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%f]. Characters: [%d]. OK!\n", int_fields, (double) *((float *) void_var_address), int_chars);
							break;

						/* Get a correct integer value. */
						case enm_type_entry_int:
							if ((int_fields = scanf("%d%*c%n", (int *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%d]. Characters: [%d]. OK!\n", int_fields, *((int *) void_var_address), int_chars);
							break;

						/* Get a correct long int value. */
						case enm_type_entry_long:
							if ((int_fields = scanf("%ld%*c%n", (long *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%ld]. Characters: [%d]. OK!\n", int_fields, *((long *) void_var_address), int_chars);
							break;

						/* Get a correct short int value. */
						case enm_type_entry_short:
							if ((int_fields = scanf("%hi%*c%n", (short *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%hi]. Characters: [%d]. OK!\n", int_fields, *((short *) void_var_address), int_chars);
							break;

						/* Get a correct unsigned long int value. */
						case enm_type_entry_sizet:
							if ((int_fields = scanf("%zu%*c%n", (size_t *) void_var_address, &int_chars)))
								printf("\nFields: [%d]. Input value: [%zu]. Characters: [%d]. OK!\n", int_fields, *((size_t *) void_var_address), int_chars);
							break;

						/* It is specified that if the option is incorrect, an error message should be sent. */
						default:
							fputs("\nUnrecognized Option!\n", stderr);
							fprintf(stderr, "The selected option: [%d] is invalid. Please correct it!\n", option_type_entry);
							break;
					}

				/* Verify that exactly one field is captured and saved at the given address. */
				if ((int_fields != V_ONE) || !(int_chars))
					{
						/* Check whether an End-of-File condition occurred during keyboard data input. */
						if (feof(stdin) || ferror(stdin))
							{
								fprintf(stderr, "\nEnd of File (EOF) detected in data stream!\n");
								clearerr(stdin);
								fflush(stdin);
							}

						/* Get an incorrect entried value. */
						fputs("\nThe value entered is not valid!\n", stderr);
						fprintf(stderr, "Press ENTER to continue...");

						/* Proceed to clear all characters present in the buffer. */
						int_chars = V_ZERO;
						int_fields = scanf("%*[^\n]%*c%n", &int_chars);

						/* Check whether an End-of-File condition occurred during keyboard data input. */
						if (feof(stdin) || ferror(stdin))
							{
								fprintf(stderr, "\nEnd of File (EOF) detected in data stream!\n");
								clearerr(stdin);
								fflush(stdin);
							}

						/* We must always clear the input buffer of impurities. */
						fputs("\nPress the ENTER key to clear the input buffer...", stderr);
						while ((int_key = getchar()) != CARRIAGE_RETURN && int_key != EOF);

						/* Check whether an End-of-File condition occurred during keyboard data input. */
						if (feof(stdin) || ferror(stdin))
							{
								fprintf(stderr, "\nEnd of File (EOF) detected in data stream!\n");
								clearerr(stdin);
								fflush(stdin);
							}
					}
			}
		else
			{
				fputs("\nUnrecognized Memory Address!\n", stderr);
				fprintf(stderr, "The memory address: [%p] to hold the variable is not valid!\n", void_var_address);
			}

		/* Return of void pointer key value. */
		return (void_var_address) ? void_var_address : &chr_storage;
	}

/* Main menu for binary search tree maintenance. */
int MainMenu(enum enm_opt enm_opt_maintenance, struct Node **rootNode, int *const option, int *const counter, int *const opers)
	{
		/* Preliminary working variables. */
		char chr_pause = NULL_CHARACTER;
		*counter = *option = V_ZERO;

		/* Binary search tree maintenance options. */
		while (enm_opt_maintenance != enm_opt_exitMenu)
			{
				/* Display of menu options. */
				printf("\n");
				printf("+===+====+===+====+===+====+===+\n");
				printf("| Menu of Binary Search Trees. |\n");
				printf("+---+----+---+----+---+----+---+\n");
				printf("| [1]. Insert nodes.           |\n");
				printf("| [2]. Delete a node. (Risky!).|\n");
				printf("| [3]. Delete the entire tree. |\n");
				printf("| [4]. Eliminate a node.       |\n");
				printf("| [5]. Modify a node.          |\n");
				printf("| [6]. Find a specific node.   |\n");
				printf("| [7]. Display graphically.    |\n");
				printf("| [8]. Display routes.         |\n");
				printf("| [9]. Exit this program.      |\n");
				printf("+===+====+===+====+===+====+===+\n");

				/* Converting an integer to an enumerated type. */
				*counter = V_ZERO;
				enm_opt_maintenance = (enum enm_opt) (*option = *((int *) GetEntry("Option: ", option, enm_type_entry_int, enm_type_reset_YES)));

				/* Execute the requested operation on the binary search tree. */
				*option = SelectedOptionMainMenu(enm_opt_maintenance, rootNode, counter, opers);
			}

		/* Introduce a forced pause after each option is chosen and executed. */
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* The last captured option and the number of operations performed are displayed. */
		printf("\nExit Main Menu.\n");
		printf("+ Last requested option : [%d].\n", *option);
		printf("+ Operations performed  : [%d].\n", *opers);
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* Returns the last option chosen and captured as the final result. */
		return *option;
	}

/* Returns the deepest and smallest left node of the binary search tree. */
struct Node* minimumNode(struct Node *const rootNode, int *const counter)
	{
		/* Preliminary working variables. */
		struct Node *tempNode = NULL;

		/* The tree to be searched must contain valid information. */
		if (rootNode)
			{
				(*counter)++;	//Count each recursive iteration until the minimum or smallest node.

				//If it has a left child node.
				if (rootNode->leftNode)
					//We look for the deepest and most left part possible.
					tempNode = minimumNode(rootNode->leftNode, counter);
				else
					//If it has no left child, we return to the same node.
					tempNode = rootNode;
			}

		/* Return the lowest-level node of the subtree as the result. */
		return tempNode;
	}

/* This function modifies a node by the specified value. */
struct Node* modifyNode(const int data, const int value, struct Node *const rootNode, int *const counter)
	{
		/* Preliminary working variables. */
		struct Node *tempRootNode = NULL;

		tempRootNode = searchNode(data, rootNode, counter);

		/* Validate the existence of the sought value. */
		if (tempRootNode)
			{
				printf("Value located: [%d] with [%d] iterations!\n", tempRootNode->data, *counter);

				struct Node *newTempNode = searchNode(value, rootNode, counter);

				/* Verify the node value change is not a repeated. */
				if (newTempNode)
					{
						printf("The value: [%d] already existed and cannot be changed to: [%d].\n", tempRootNode->data, newTempNode->data);
					}
				else
					{
						printf("The value: [%d] found in [%d] cycles has been changed to the value: [%d].\n", tempRootNode->data, *counter, value);
						tempRootNode->data = value;
					}

				newTempNode = NULL;
			}

		/* Return the requested modified node as the result. */
		return tempRootNode;
	}

/* Parent or head node to which a node belongs. */
void replaceNode(struct Node *rootNode, struct Node *newNode)
	{
		/* A condition that must be checked to determine when a parent node has children within a binary search tree.*/
		if (rootNode)
			{
				/* The parent tree must be assigned to its new dependent child node. */
				if (rootNode->fatherNode)
					{
						/* It is validated if the parent node of the root node on its left node has valid information. */
						if (rootNode->fatherNode->leftNode)
							{
								if (rootNode->data == rootNode->fatherNode->leftNode->data)
									{
										rootNode->fatherNode->leftNode = newNode;
									}
							}

						/* It is validated if the parent node of the root node on its right node has valid information. */
						if (rootNode->fatherNode->rightNode)
							{
								if (rootNode->data == rootNode->fatherNode->rightNode->data)
									{
										rootNode->fatherNode->rightNode = newNode;
									}
							}
					}

				/* The new node is assigned its new parent. */
				if (newNode)
					{
						newNode->fatherNode = rootNode->fatherNode;
					}
			}
	}

/* Function to perform a specific operation on the binary search tree. */
int SelectedOptionMainMenu(const enum enm_opt enm_opt_maintenance, struct Node **rootNode, int *const counter, int *const opers)
	{
		/* Preliminary working variables. */
		char chr_pause = NULL_CHARACTER;
		int count = V_ZERO, data = V_ZERO, value = V_ZERO;
		struct Node *tempRootNode = NULL;

		/* Calibrates whether the tree has valid nodes inserted. */
		if (*rootNode)
			printf("\nThe tree already had values ​​previously entered.\n");
		else
			printf("\nThe binary search tree is completely empty!\n");

		/* Calculate the number of operations carried out. */
		if (enm_opt_maintenance >= enm_opt_addNode && enm_opt_maintenance <= enm_opt_viewAllTree) (*opers)++;

		/* Case selection structure for each chosen option. */
		switch(enm_opt_maintenance)
			{
				/* Loading the binary search tree. */
				case enm_opt_addNode:
					*counter = V_ZERO;
					*counter = captureNodes(rootNode, counter);
					printf("[%d] Nodes captured.\n", *counter);
					break;

				/* Delete a given node. Delete a specific node. */
				case enm_opt_deleteNode:
					printf("\nDelete a specific value in the binary tree.\n");

					*counter = V_ZERO;
					data = *((int *) GetEntry("Enter a value to search for : ", &data, enm_type_entry_int, enm_type_reset_YES));

					/* Validate the existence of the sought value. */
					if ((tempRootNode = searchNode(data, *rootNode, counter)))
						{
							printf("Value located: [%d] with [%d] iterations!\n", tempRootNode->data, *counter);

							*counter = V_ZERO;
							delNode(*rootNode, data, counter);
						}
					else
						printf("The value: [%d] was not located in the tree with [%d] iterations.\n", data, *counter);

					tempRootNode = NULL;
					break;

				/* Remove all nodes from the entire tree. */
				case enm_opt_deleteTree:
					printf("\nDelete the entire binary tree and free its memory...\n");

					*counter = V_ZERO;
					*counter = deleteTree(*rootNode, counter);
					printf("[%d] Nodes deleted.\n", *counter);

					*rootNode = NULL;
					break;

				/* Eliminate a given or user-specified node. */
				case enm_opt_eliminateNode:
					printf("\nEliminate a specific value in the binary tree.\n");

					*counter = V_ZERO;
					data = *((int *) GetEntry("Enter a value to search for : ", &data, enm_type_entry_int, enm_type_reset_YES));

					/* Validate the existence of the sought value. */
					if ((tempRootNode = searchNode(data, *rootNode, counter)))
						{
							printf("Value located: [%d] with [%d] iterations!\n", tempRootNode->data, *counter);

							*counter = V_ZERO;
							*rootNode = eliminateNode(*rootNode, data, counter);
						}
					else
						printf("The value: [%d] was not located in the tree with [%d] iterations.\n", data, *counter);

					tempRootNode = NULL;
					break;

				/* Iteratively searches for a node and modifies it if it finds one. */
				case enm_opt_modifyNode:
					printf("\nModify a specific value in the binary tree.\n");

					*counter = V_ZERO;
					data = *((int *) GetEntry("Enter a value to search for : ", &data, enm_type_entry_int, enm_type_reset_YES));

					printf("\nEnter a unique value to modify the value: [%d] : ", data);
					value = *((int *) GetEntry("", &value, enm_type_entry_int, enm_type_reset_YES));

					if ((tempRootNode = modifyNode(data, value, *rootNode, counter)))
						printf("Value located: [%d] with [%d] iterations!\n", tempRootNode->data, *counter);
					else
						printf("The value: [%d] was not located in the tree with [%d] iterations. *\n", data, *counter);

					tempRootNode = NULL;
					break;

				/* Perform a search test for a given value in the tree. */
				case enm_opt_searchNode:
					printf("\nSearch for a specific value in the binary tree.\n");

					*counter = V_ZERO;
					data = *((int *) GetEntry("Enter a value to search for : ", &data, enm_type_entry_int, enm_type_reset_YES));

					/* Validate the existence of the sought value. */
					if ((tempRootNode = searchNode(data, *rootNode, counter)))
						printf("Value located: [%d] with [%d] iterations!\n", tempRootNode->data, *counter);
					else
						printf("The value: [%d] was not located in the tree with [%d] iterations.\n", data, *counter);

					tempRootNode = NULL;
					break;

				/* Graphical arrangement of binary search tree. */
				case enm_opt_showGraphic:
					printf("\nGraphical arrangement of Binary Search Tree.\n");

					*counter = V_ZERO;
					*counter = showGraphicTree(*rootNode, count, counter);

					printf("\n[%d] Evenly distributed spaces.\n", *counter);
					break;

				/* View the entire tree in all its forms. */
				case enm_opt_viewAllTree:
					*counter = V_ZERO;
					*counter = viewAllTree(*rootNode, counter);

					printf("[%d] Invoked traversal processes.\n", *counter);
					break;

				/* Program exit option. */
				case enm_opt_exitMenu:
					printf("\nLeaving this program...\n");

					*counter = V_ZERO;
					*counter = deleteTree(*rootNode, counter);
					printf("[%d] Nodes deleted.\n", *counter);

					*rootNode = NULL;
					break;

				/* In case of incorrect or invalid option. */
				default:
					fputs("\nUnrecognized Option!", stderr);
					fprintf(stderr, "\nInvalid captured option: [%d]. Please correct it!\n", (int) enm_opt_maintenance);
					break;
			}

		/* Introduce a forced pause after each option is chosen and executed. */
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* The last captured option and the number of operations performed are displayed. */
		printf("\nSelected Option Menu.\n");
		printf("- Last requested option : [%d].\n", (int) enm_opt_maintenance);
		printf("- Operations performed  : [%d].\n", *opers);
		chr_pause = *((char *) GetEntry("Press the ENTER key to continue...", &chr_pause, enm_type_entry_char, enm_type_reset_YES));

		/* Return the executed and selected option as the result. */
		return (int) enm_opt_maintenance;
	}

/* It is responsible for searching for a specific value within the binary search tree. */
struct Node* searchNode(const int data, struct Node *const rootNode, int *const counter)
	{
		/* Preliminary working variables. */
		struct Node* tempNode = NULL;

		/* Recursive cyclic search for a value at a specific node. */
		if (rootNode)
			{
				(*counter)++;	//Count the number of nodes located within the Binary Search Tree.

				if (data < rootNode->data)
					tempNode = searchNode(data, rootNode->leftNode, counter);

				if (data > rootNode->data)
					tempNode = searchNode(data, rootNode->rightNode, counter);

				if (data == rootNode->data)
					{
						printf("\nThe value: [%d] = [%d] was found in [%d] cycles!\n", data, rootNode->data, *counter);
						tempNode = rootNode;
					}
			}
		else
			printf("\nThe value: [%d] was not found despite having traversed [%d] nodes!\n", data, *counter);

		/* Return the located node as the result. */
		return tempNode;
	}

/* Display the binary search tree in a clearer, more distributed format. */
int showGraphicTree(struct Node *rootNode, const int count, int *const counter)
	{
		/* Arrange the tree so that it appears horizontal and neatly distributed. */
		if (rootNode)
			{
				*counter = showGraphicTree(rootNode->rightNode, count + V_ONE, counter);

				for (int idx = V_ZERO; idx < count; idx++, (*counter)++)
					printf("\t");

				printf("[%d].\n", rootNode->data);

				*counter = showGraphicTree(rootNode->leftNode, count + V_ONE, counter);
			}

		/* Return the number of nodes that were displayed on the screen. */
		return *counter;
	}

/* Allows viewing of all types of binary search tree traversals. */
int viewAllTree(struct Node *rootNode, int *const counter)
	{
		/* Preliminary working variables. */
		int counting = V_ZERO;
		printf("\nEntire display of the binary search tree.");

		/* Check if the tree has at least one node in its structure. */
		if (rootNode)
			{
				/* Root node is tracked for each node level and for each node type. */
				for (int int_idx = (int) enm_TT_PreOrder; int_idx <= (int) enm_TT_Inv_PostOrder; int_idx++, counting++)
					{
						printf("\n[%s].\n", str_Modes[int_idx]);
						*counter = viewTree(rootNode, (enum enm_TreeTour) int_idx, counter);
					}
			}

		printf("\n[%d] Generated exit routes.\n", counting);

		/* Return the number of nodes printed on the screen. */
		return *counter;
	}

/* Display the tree directed by the root node. */
int viewTree(struct Node *rootNode, const enum enm_TreeTour enm_TT, int *const counter)
	{
		switch (enm_TT)
			{
				case enm_TT_PreOrder:		//PreOrder.	{data, left, right}.
					if (rootNode)
						{
							(*counter)++;
							printf("%d\t", rootNode->data);
							*counter = viewTree(rootNode->leftNode, enm_TT_PreOrder, counter);
							*counter = viewTree(rootNode->rightNode, enm_TT_PreOrder, counter);
						}
					break;

				case enm_TT_InOrder:		//InOrder.	{left, data, right}.
					if (rootNode)
						{
							(*counter)++;
							*counter = viewTree(rootNode->leftNode, enm_TT_InOrder, counter);
							printf("%d\t", rootNode->data);
							*counter = viewTree(rootNode->rightNode, enm_TT_InOrder, counter);
						}
					break;

				case enm_TT_PostOrder:		//PostOrder.	{left, right, data}.
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
					fputs("\nUnrecognized Option!", stderr);
					fprintf(stderr, "\nInvalid Option! Please correct it!\n");
					break;
			}

		/* Return the number of nodes visited according to the selected traversal model. */
		return *counter;
	}
