#include <stdio.h>

#define V_ZERO  0

/* Function that obtains the largest of three integers. */
int getMax(int num1, int num2, int num3)
{
	int result = V_ZERO;

	if (num1 >= num2 && num1 >= num3)
		result = num1;
	else if (num2 >= num1 && num2 >= num3)
		result = num2;
	else if (num3 >= num1 && num3 >= num2)
		result = num3;

	return result;
}

//Main function.
int main()
{
	/* Preliminary working variables. */
	int num1 = V_ZERO, num2 = V_ZERO, num3 = V_ZERO;
	int result = V_ZERO;

	printf("Largest of three numbers.\n");
	printf("+ First number: ");
	scanf("%d", &num1);
	printf("+ Second number: ");
	scanf("%d", &num2);
	printf("+ Third number: ");
	scanf("%d", &num3);

	result = getMax(num1, num2, num3);

	printf("\n Values entered.\n");
	printf("- First value:\t\t[%d].\n", num1);
	printf("- Second value:\t\t[%d].\n", num2);
	printf("- Third value:\t\t[%d].\n", num3);
	printf("\n* Greatest of all:\t[%d].\n", result);

	return V_ZERO;
}
