/* Program that uses pointers to functions of a certain result type. */
#include <stdio.h>

/* Symbolic work constants. */
#define	V_ZERO	0

//Function prototipes.
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

//Function to perform arithmetic operation using function pointer.
float performArithmetic(float a, float b, float (*operation)(float, float))
	{
		return operation(a, b);
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		float a = V_ZERO, b = V_ZERO;

		//Request for input data.
		printf("Function Pointers in \'C\'.\n");
		printf("Value 'a' : ");
		scanf("%f", &a);
		printf("Value 'b' : ");
		scanf("%f", &b);

		//Call the performArithmetic function using function pointers.
		float sum = performArithmetic(a, b, add);
		float difference = performArithmetic(a, b, subtract);
		float product = performArithmetic(a, b, multiply);
		float quotient = performArithmetic(a, b, divide);

		//Deployment of results.
		printf("\nResults of calls to pointers.\n");
		printf("Perform Arithmetic.\n");
		printf("(%p).\n\n", performArithmetic);

		printf("Add:\t\t(%p).\n", add);
		printf("{(%p) = [%f]} + {(%p) = [%f]} = {(%p) = [%f]}.\n\n", &a, a, &b, b, &sum, sum);

		printf("Subtract:\t(%p).\n", subtract);
		printf("{(%p) = [%f]} - {(%p) = [%f]} = {(%p) = [%f]}.\n\n", &a, a, &b, b, &difference, difference);

		printf("Multiply:\t(%p).\n", multiply);
		printf("{(%p) = [%f]} * {(%p) = [%f]} = {(%p) = [%f]}.\n\n", &a, a, &b, b, &product, product);

		printf("Divide:\t\t(%p).\n", divide);
		printf("{(%p) = [%f]} / {(%p) = [%f]} = {(%p) = [%f]}.\n\n", &a, a, &b, b, &quotient, quotient);

		return V_ZERO;
	}

//Adition.
float add(float a, float b)
	{
		return a + b;
	}

//Subtraction.
float subtract(float a, float b)
	{
		return a - b;
	}

//Multiplication.
float multiply(float a, float b)
	{
		return a * b;
	}

//Division.
float divide(float a, float b)
	{
		return a / b;
	}
