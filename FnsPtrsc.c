#include <stdio.h>

#define	V_ONE	1
#define V_ZERO  0

int compare(int a, int b, int (*pf)(int, int), int c)
	{
		return ((c) ? (*pf)(a, b) : ((*pf)(a, b)) ? a : b);
	}

int bigger(int a, int b)
	{
		return (a > b);
	}

int smaller(int a, int b)
	{
		return (a < b);
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
		printf("[%d] > [%d] : [%d].\n", a, b, compare(a, b, bigger, V_ZERO));
		printf("[%d] < [%d] : [%d].\n", a, b, compare(a, b, smaller, V_ZERO));
		printf("[%d] > [%d] : [%d].\n", b, a, compare(b, a, bigger, V_ZERO));
		printf("[%d] < [%d] : [%d].\n", b, a, compare(b, a, smaller, V_ZERO));

		printf("\nOutcomes.\n");
		printf("[%d] > [%d] = [%d].\n", a, b, compare(a, b, bigger, V_ONE));
		printf("[%d] < [%d] = [%d].\n", a, b, compare(a, b, smaller, V_ONE));
		printf("[%d] > [%d] = [%d].\n", b, a, compare(b, a, bigger, V_ONE));
		printf("[%d] < [%d] = [%d].\n", b, a, compare(b, a, smaller, V_ONE));

		return V_ZERO;
	}
