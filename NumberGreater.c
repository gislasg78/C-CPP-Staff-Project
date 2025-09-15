#include <stdio.h>

#define	V_ZERO	0

/* Greater than 'x', 'y' and 'z' values. */
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

//Main function.
int main()
	{
		int x = V_ZERO, y = V_ZERO, z = V_ZERO;

		printf("Choosing the largest number from three values.\n");
		printf("Enter the value of 'x': ");
		scanf("%d", &x);
		printf("Enter the value of 'y': ");
		scanf("%d", &y);
		printf("Enter the value of 'z': ");
		scanf("%d", &z);

		printf("\nValues ​​entered.\n");
		printf("(x = [%d], y = [%d], z = [%d]).\n", x, y, z);
		printf("The largest value is: [%d].\n", greater(x, y, z));

		return V_ZERO;
	}
