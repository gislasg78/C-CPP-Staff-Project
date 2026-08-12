#include <stdio.h>

#define	CARRIAGE_RETURN	'\n'

#define V_ONE		1
#define V_ZERO		0

int main()
	{
		char symbol = V_ZERO;
		int height = V_ZERO;
		int intchar = V_ZERO;

		printf("Draw Triangles.\n");
		printf("Height: ");
		scanf("%d", &height);

		scanf("%*[^\n]%*c");
		while((intchar = getchar()) != CARRIAGE_RETURN && intchar != EOF);

		printf("Symbol: ");
		scanf("%c", &symbol);

		printf("\n");
		printf("Shape.\n");
		for (int idx = V_ONE; idx <= height; idx++)
			{
				for (int jdx = V_ONE; jdx <= idx; jdx++)
					printf("\x5b%c\x5d", symbol);

				printf("\n");
			}

		printf("\n");
		for(int idx = height; idx >= V_ONE; idx--)
			{
				for (int jdx = idx; jdx >= V_ONE; jdx--)
					printf("\x5b%c\x5d", symbol);

				printf("\n");
			}

		printf("\nDone!\n");
		printf("This program has ended.\n");

		return V_ZERO;
	}
