#include <stdio.h>

#define V_FOUR  4
#define V_ZERO  0

union
{
	int i;
	struct
	{
		short hi;
		short lo;
	};
	char c[V_FOUR];
} union_mix_t;

int main()
	{
		printf("Example in ANSI C with unions.\n");
		printf("Enter a integer value: ");
		scanf("%d", &union_mix_t.i);

		printf("\nShort integer.\n");
		printf("Higher value: [%d].\n", (&union_mix_t)->hi);
		printf("Lower  value: [%d].\n", (&union_mix_t)->lo);

		printf("\nCharacter string information.\n");
		printf("String value: [%s].\n", union_mix_t.c);

		for (int idx = V_ZERO; idx < V_FOUR; idx++)
			printf("[%d].\t", *(union_mix_t.c + idx));

		printf("\n");

		return V_ZERO;
	}
