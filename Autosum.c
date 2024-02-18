#include <stdio.h>

#define	V_MINUS_ONE	-1
#define	V_ONE		1
#define	V_ZERO		0

int autosum(int x)
	{
		return (x < V_ONE) ? x : x + autosum(x + V_MINUS_ONE);
	}

int main()
	{
		int x = V_ZERO;

		printf("Value [x] : ");
		scanf("%d", &x);

		printf("\n");
		printf("Value [x] : [%d].\n", x);
		printf("Autosum   : [%d].\n", autosum(x));

		return V_ZERO;
	}
