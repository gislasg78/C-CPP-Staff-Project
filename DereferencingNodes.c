#include <stdio.h>

#define V_ONE	1
#define V_ZERO  0

struct Node
	{
		int data;
		struct Node* rightNode;
		struct Node* leftNode;
		struct Node* fatherNode;
	} my_Node, *ptr_my_Node = &my_Node;


void viewNode(struct Node* ptr_my_Node)
	{
		printf("\nPointer dereferencing nomenclature.\n");
		printf("Variable: ptr_my_Node.\n");
		printf("[%p] : [%p] = [%d], [%p], [%p], [%p].\n", &ptr_my_Node, ptr_my_Node, ptr_my_Node->data, ptr_my_Node->leftNode, ptr_my_Node->rightNode, ptr_my_Node->fatherNode);
	}

void viewDoubleNode(struct Node** ptr_ptr_my_Node)
	{
		printf("\nDouble Pointer Node dereferencing nomenclature.\n");
		printf("Variable: ptr_ptr_my_Node.\n");
		printf("[%p] : [%p] : [%p] = [%d], [%p], [%p], [%p].\n", &ptr_ptr_my_Node, ptr_ptr_my_Node, *ptr_ptr_my_Node, (*ptr_ptr_my_Node)->data, (*ptr_ptr_my_Node)->leftNode, (*ptr_ptr_my_Node)->rightNode, (*ptr_ptr_my_Node)->fatherNode);
	}


int main()
	{
		printf("Node dereferencing nomenclature.\n");
		printf("Variable: my_Node.\n");

		my_Node.data = V_ONE;
		my_Node.leftNode = NULL;
		my_Node.rightNode = NULL;
		my_Node.fatherNode = NULL;

		viewNode(&my_Node);

		ptr_my_Node->data = V_ZERO;
		ptr_my_Node->leftNode = NULL;
		ptr_my_Node->rightNode = NULL;
		ptr_my_Node->fatherNode = NULL;

		printf("\nptr_my_Node: [%p] = [%p].\n", &ptr_my_Node, ptr_my_Node);
		viewNode(ptr_my_Node);

		(&my_Node)->data = V_ONE;
		(&my_Node)->leftNode = NULL;
		(&my_Node)->rightNode = NULL;
		(&my_Node)->fatherNode = NULL;

		viewNode(&my_Node);

		(*ptr_my_Node).data = V_ZERO;
		(*ptr_my_Node).leftNode = NULL;
		(*ptr_my_Node).rightNode = NULL;
		(*ptr_my_Node).fatherNode = NULL;

		printf("\nptr_my_Node: [%p] = [%p].\n", &ptr_my_Node, ptr_my_Node);
		viewNode(ptr_my_Node);

		printf("\nptr_my_Node: [%p] = [%p].\n", &ptr_my_Node, ptr_my_Node);
		viewDoubleNode(&ptr_my_Node);

		ptr_my_Node = NULL;
		printf("\nNullifying the pointer of my_Node.\n");
		printf("ptr_my_Node: [%p] = [%p].\n", &ptr_my_Node, ptr_my_Node);

		return V_ZERO;
	}
