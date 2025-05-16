#include <stdio.h>

#define	V_FIVE	5
#define	V_TEN	10
#define	V_ZERO	0


//Function prototipes.
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);


//Function to perform arithmetic operation using function pointer.
int performArithmetic(int a, int b, int (*operation)(int, int))
	{
		return operation(a, b);
	}


int main()
	{
		int a = V_TEN, b = V_FIVE;

		//Call the performArithmetic function using function pointers.
		int sum = performArithmetic(a, b, add);
		int difference = performArithmetic(a, b, subtract);
		int product = performArithmetic(a, b, multiply);
		int quotient = performArithmetic(a, b, divide);

		//Deployment of results.
		printf("Sum of [%d] and [%d]:\t\t\t[%d]:\t[%p].\tSum address:\t\t[%p].\n", a, b, sum, &sum, add);
		printf("Difference between [%d] and [%d]:\t[%d]:\t[%p].\tDifference address:\t[%p].\n", a, b, difference, &difference, subtract);
		printf("Product of [%d] and [%d]:\t\t[%d]:\t[%p].\tMultiply address:\t[%p].\n", a, b, product, &product, multiply);
		printf("Quotient of [%d] and [%d]:\t\t[%d]:\t[%p].\tDivide address:\t\t[%p].\n", a, b, quotient, &quotient, divide);

		return V_ZERO;
	}


int add(int a, int b)
	{
		return a + b;
	}

int subtract(int a, int b)
	{
		return a - b;
	}

int multiply(int a, int b)
	{
		return a * b;
	}

int divide(int a, int b)
	{
		return a / b;
	}
