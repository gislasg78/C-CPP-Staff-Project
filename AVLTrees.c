/* Main work libraries. */
#include <stdio.h>
#include <stdlib.h>

/* Symbolic work constants. */
#define	V_MINUS_ONE	-1
#define	V_ONE		1
#define	V_ZERO		0

/* Structure for an AVL tree node. */
typedef struct Node
	{
		int value;

		struct Node *leftNode;
		struct Node *rightNode;

		int height;
	} Node;

/* Function to obtain the height of a node. */
int height(Node *Node)
	{
		return (Node) ? Node->height : V_ZERO;
	}

/* Function to obtain the balance factor of a node. */
int balance(Node *Node)
	{
		return (Node) ? height(Node->leftNode) - height(Node->rightNode) : V_ZERO;
	}

/* Function to rotate nodes to the right of the tree. */
Node *rotationRight(Node *y)
	{
		/* Preliminary assignments. */
		Node *x = y->leftNode;
		Node *T2 = x->rightNode;

		/* We carry out the rotation. */
		x->rightNode = y;
		y->leftNode = T2;

		/* We update the heights of the branches of the binary search tree. */
		y->height = (height(y->leftNode) > height(y->rightNode)) ? height(y->leftNode) + V_ONE : height(y->rightNode) + V_ONE;
		x->height = (height(x->leftNode) > height(x->rightNode)) ? height(x->leftNode) + V_ONE : height(x->rightNode) + V_ONE;

		return x;	/* New root node. */
	}

/* Function to rotate nodes to the left of the tree. */
Node *rotationLeft(Node *x)
	{
		/* Preliminary assignments. */
		Node *y = x->rightNode;
		Node *T2 = y->leftNode;

		/* We carry out the rotation. */
		y->leftNode = x;
		x->rightNode = T2;

		/* We update the heights of the branches of the binary search tree. */
		x->height = (height(x->leftNode) > height(x->rightNode)) ? height(x->leftNode) + V_ONE : height(x->rightNode) + V_ONE;
		y->height = (height(y->leftNode) > height(y->rightNode)) ? height(y->leftNode) + V_ONE : height(y->rightNode) + V_ONE;

		return y;	/* New root node. */
	}

/* Function to perform right to left rotation of the branches of the binary search tree. */
Node *rotationRightLeft(Node *z)
	{
		z->leftNode = rotationLeft(z->leftNode);

		return rotationRight(z);	/* The rotated to the right is returned. */
	}

/* Function to perform left to right rotation of the branches of the binary search tree. */
Node *rotationLeftRight(Node *z)
	{
		z->rightNode = rotationRight(z->rightNode);

		return rotationLeft(z);		/* The rotated to the left is returned. */
	}

Node *createNode(const int value, Node *leftNode, Node *rightNode)
	{
		/* Generates a new node to be inserted. */
		Node *newNode = NULL;

		/* Memory allocation and validation. */
		if (newNode = (Node *) malloc(sizeof(Node)))
			{
				newNode->value = value;
				newNode->leftNode = leftNode;
				newNode->rightNode = rightNode;
				newNode->height = V_ONE;	/* A new node is always a leaf. */
			}
		else
			{
				perror("Error allocating memory for generating a new node.");
				exit(EXIT_FAILURE);
			}

		return newNode;
	}

/* Function to insert a new node into the binary search tree. */
Node *insertNode(Node *Node, int value)
	{
		/* If the binary search tree has at least one node, its branches are rotated. */
		if (Node)
			{
				/* We perform the insertion into the binary search tree. */
				if (value > Node->value)
					{
						Node->rightNode = insertNode(Node->rightNode, value);
					}
				else if (value < Node->value)
					{
						Node->leftNode = insertNode(Node->leftNode, value);
					}
				else if (value == Node->value)
					{
						/* Duplicate values ​​are not allowed. */
						printf("Duplicate value already exists: [%d].\n", value);
					}

				/* We update the height of this node. */
				Node->height = V_ONE + ((height(Node->leftNode) > height(Node->rightNode)) ? height(Node->leftNode) : height(Node->rightNode));

				/* We check the balance and perform rotations if necessary. */
				int balanceFactor = balance(Node);

				/* Simple left rotation case. */
				if (balanceFactor > V_ONE && value < Node->leftNode->value)
					{
						Node = rotationRight(Node);
					}

				/* Simple right rotation case. */
				if (balanceFactor < V_MINUS_ONE && value > Node->rightNode->value)
					{
						Node = rotationLeft(Node);
					}

				/* Double rotation case: from left to right. */
				if (balanceFactor > V_ONE && value > Node->leftNode->value)
					{
						Node = rotationRightLeft(Node);
					}

				/* Double rotation case: from right to left. */
				if (balanceFactor < V_MINUS_ONE && value < Node->rightNode->value)
					{
						Node = rotationLeftRight(Node);
					}
			}
		else
			{
				if (Node = createNode(value, NULL, NULL))
					{
						printf("[%d]. OK!\n", value);
					}
			}

		return Node;  /* We return the node unchanged if no balancing is necessary. */
	}

/* Function to find the node with the minimum value. */
Node *MinimumNode(Node *Node)
	{
		while (Node->leftNode)
			{
				Node = Node->leftNode;
			}

		return Node;
	}

/* Function to remove a given node from the binary search tree. */
Node *deleteNode(Node *root, int value)
	{
		/* Check that the binary search tree has at least one valid node. */
		if (root)
			{
				/* We delete the node recursively. */
				if (value > root->value)
					{
						root->rightNode = deleteNode(root->rightNode, value);
					}
				else if (value < root->value)
					{
						root->leftNode = deleteNode(root->leftNode, value);
					}
				else if (value == root->value)
					{
						/* Node found. */
						if (root->leftNode == NULL || root->rightNode == NULL)
							{
								Node *tempNode = root->leftNode ? root->leftNode : root->rightNode;

								if (tempNode)
									{
										*root = *tempNode;
									}
								else
									{
										tempNode = root;
										root = NULL;
									}

								free(tempNode);
							}
						else
							{
								Node *tempNode = MinimumNode(root->rightNode);

								root->value = tempNode->value;
								root->rightNode = deleteNode(root->rightNode, tempNode->value);
							}
					}
			}

		/* It is verified whether there are valid values ​​left in the tree after the rotation. */
		if (root)
			{
				/* We update the height of the binary search tree. */
				root->height = V_ONE + ((height(root->leftNode) > height(root->rightNode)) ? height(root->leftNode) : height(root->rightNode));

				/* We check the balance of the binary search tree. */
				int balanceFactor = balance(root);

				/* We perform the rotations of the binary search tree. */
				if (balanceFactor > V_ONE && balance(root->leftNode) >= V_ZERO)
					{
						root = rotationRight(root);
					}

				if (balanceFactor > V_ONE && balance(root->leftNode) < V_ZERO)
					{
						root = rotationRightLeft(root);
					}

				if (balanceFactor < V_MINUS_ONE && balance(root->rightNode) <= V_ZERO)
					{
						root = rotationLeft(root);
					}

				if (balanceFactor < V_MINUS_ONE && balance(root->rightNode) > V_ZERO)
					{
						root = rotationLeftRight(root);
					}
			}

		return root;
	}

/* In-order traversal processing function. */
void inorder(Node *Node)
	{
		if (Node)
			{
				inorder(Node->leftNode);
				printf("[%d].\t", Node->value);
				inorder(Node->rightNode);
			}
	}

/* Pre-order traversal processing function. */
void preorder(Node *Node)
	{
		if (Node)
			{
				printf("[%d].\t", Node->value);
				preorder(Node->leftNode);
				preorder(Node->rightNode);
			}
	}

/* Pos-order traversal processing function. */
void posorder(Node *Node)
	{
		if (Node)
			{
				posorder(Node->leftNode);
				posorder(Node->rightNode);
				printf("[%d].\t", Node->value);
			}
	}

/* Main function. */
int main()
	{
		/* Preliminary working variables. */
		Node* root = NULL;

		/* Beginning of operations on the binary search tree. */
		printf("Program that generates perfectly balanced binary search trees.\n");

		/* We insert several nodes into the binary search tree. */
		printf("\nNode insertion process.\n");
		root = insertNode(root, 5);
		root = insertNode(root, 10);
		root = insertNode(root, 15);
		root = insertNode(root, 20);
		root = insertNode(root, 25);
		root = insertNode(root, 30);
		root = insertNode(root, 35);
		root = insertNode(root, 40);
		root = insertNode(root, 45);
		root = insertNode(root, 50);
		root = insertNode(root, 55);
		root = insertNode(root, 60);
		root = insertNode(root, 65);
		root = insertNode(root, 70);
		root = insertNode(root, 75);

		/* We show each of the types of traversals in the binary tree. */
		printf("\nNode traversal process.\n");
		printf("Tour in 'in-order'.\n");
		inorder(root);
		printf("\n");

		printf("Tour in 'pre-order'.\n");
		preorder(root);
		printf("\n");

		printf("Tour in 'pos-order'.\n");
		posorder(root);
		printf("\n");

		/* We remove a specific node from the binary search tree. */
		printf("\nNode removal process.\n");

		root = deleteNode(root, 5);
		printf("After deleting node: '5'. Traversal in 'in-order'.\n");
		inorder(root);
		printf("\n");

		root = deleteNode(root, 15);
		printf("After deleting node: '15'. Traversal in 'in-order'.\n");
		inorder(root);
		printf("\n");

		root = deleteNode(root, 25);
		printf("After deleting node: '25'. Traversal in 'in-order'.\n");
		inorder(root);
		printf("\n");

		root = deleteNode(root, 35);
		printf("After deleting node: '35'. Traversal in 'in-order'.\n");
		inorder(root);
		printf("\n");

		root = deleteNode(root, 45);
		printf("After deleting node: '45'. Traversal in 'in-order'.\n");
		inorder(root);
		printf("\n");

		root = deleteNode(root, 55);
		printf("After deleting node: '55'. Traversal in 'in-order'.\n");
		inorder(root);
		printf("\n");

		root = deleteNode(root, 65);
		printf("After deleting node: '65'. Traversal in 'in-order'.\n");
		inorder(root);
		printf("\n");

		root = deleteNode(root, 75);
		printf("After deleting node: '75'. Traversal in 'in-order'.\n");
		inorder(root);
		printf("\n");

		return V_ZERO;
	}
