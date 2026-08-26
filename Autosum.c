#include <stdio.h>\

#define	V_MINUS_ONE	-1
#define	V_ONE		1
#define	V_TWO		2
#define	V_ZERO		0

long sum(long x)
	{
		return (x * (x + V_ONE)) / V_TWO;
	}

long summation(long x)
	{
		return (x < V_ONE) ? x : x + sum(x + V_MINUS_ONE);
	}

long summatory(long m, long n)
	{
		return (m >= n) ? m : m + summatory(m + V_ONE, n);
	}

int main()
	{
		long x = V_ZERO;

		printf("Recursive summations.\n");
		printf("Enter a value [x] : ");
		scanf("%ld", &x);

		printf("\nResults of the summations.\n");
		printf("+ Value [x] : [%ld].\n", x);
		printf("* Sum       : [%ld].\n", sum(x));
		printf("* Summation : [%ld].\n", summation(x));
		printf("* Summatory : [%ld].\n", summatory(V_ZERO, x));

		printf("\nDone!\n");
		printf("This program has ended.\n");

		return V_ZERO;
	}
