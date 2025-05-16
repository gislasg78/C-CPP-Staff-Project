/* Program that makes comparisons and returns a boolean value
   if the comparison is successful or the value that exceeds the comparison.*/

#include <stdio.h>

#define	V_MINUS_ONE	-1
#define V_ZERO  	0

int compare(int a, int b, int (*pf)(int, int, int), int cmp, int opt)
	{
		return ((cmp) ? (*pf)(a, b, opt) : ((*pf)(a, b, opt)) ? a : b);
	}

int equate(int a, int b, int opt)
	{
		return ((opt) ? (a > b) : (a < b));
	}

int main()
	{
		int a = V_ZERO, b = V_ZERO;

		printf("Function Pointers in C.\n");
		printf("Value 'a': ");
		scanf("%d", &a);

		printf("Value 'b': ");
		scanf("%d", &b);

		printf("\nResults.\n");
		printf("[%d] > [%d] : [%d].\n", a, b, compare(a, b, equate, V_ZERO, V_MINUS_ONE));
		printf("[%d] < [%d] : [%d].\n", a, b, compare(a, b, equate, V_ZERO, V_ZERO));
		printf("[%d] > [%d] : [%d].\n", b, a, compare(b, a, equate, V_ZERO, V_MINUS_ONE));
		printf("[%d] < [%d] : [%d].\n", b, a, compare(b, a, equate, V_ZERO, V_ZERO));

		printf("\nOutcomes.\n");
		printf("[%d] > [%d] = [%d].\n", a, b, compare(a, b, equate, V_MINUS_ONE, V_MINUS_ONE));
		printf("[%d] < [%d] = [%d].\n", a, b, compare(a, b, equate, V_MINUS_ONE, V_ZERO));
		printf("[%d] > [%d] = [%d].\n", b, a, compare(b, a, equate, V_MINUS_ONE, V_MINUS_ONE));
		printf("[%d] < [%d] = [%d].\n", b, a, compare(b, a, equate, V_MINUS_ONE, V_ZERO));

		return V_ZERO;
	}
