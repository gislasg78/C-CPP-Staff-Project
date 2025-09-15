#include <stdio.h>

#define	V_ZERO	0

/* Greater than 'x', 'y' and 'z' values */
int greater(int x, int y, int z)
	{
		int major = V_ZERO;

		if (x > y)
			if (x > z)
				major = x;
			else
				major = y;
		else
			if (y > z)
				major = y;
			else
				major = z;

		return major;
	}

int main()
	{
		int major = V_ZERO, x = V_ZERO, y = V_ZERO, z = V_ZERO;

		printf("Choosing the largest number from three values.\n");
		printf("\nEnter the first  value of three: ");
		scanf("%d", &x);
		printf("Enter the second value of three: ");
		scanf("%d", &y);
		printf("Enter the third  value of three: ");
		scanf("%d", &z);

		major = greater(x, y, z);
		printf("\nThe largest value of the three entered is: [%d].\n", major);

		return V_ZERO;
	}
