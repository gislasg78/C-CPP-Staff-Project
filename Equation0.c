/* This program calculates the roots of a quadratic equation.
   Example: a = 1, b = -5, c = 6; x1 = 3, x2 = 2. */

/* Standard Work Libraries. */
#include <stdio.h>

/* Macros for intermediate calculations to obtain the roots of the quadratic equation. */
#define	DENOMINATOR(c_a)			((V_TWO) * (a))
#define	DISCRIMINATE(c_a, c_b, c_c)		(((b) * (b)) - ((V_FOUR) * (a) * (c)))
#define	SINGLE_ROOT(c_a, c_b)			((-b) / ((V_TWO) * (a)))
#define	UNIQUE_ROOT(c_b, c_c)			((-c) / (b))

/* Sum of quotients to calculate the square root using Newton's method. */
#define	DIFFERENCE(minuend, subtracting)	((minuend) - (subtracting))
#define SUM_OF_QUOTIENTS(number, a_approach)	((((number)/(a_approach)) + (a_approach)) / (V_TWO))

/* Symbolic work constants. */
#define V_EPSILON				0.00001
#define	V_FOUR					4.0
#define	V_ONE					1.0
#define	V_TWO					2.0
#define	V_ZERO					0

/* Custom function that returns the absolute value of a given number. */
double _abs(const double value)
	{
		return	(value > V_ZERO) ? value :
			(value == V_ZERO) ? V_ZERO :
			(value < V_ZERO) ? -value : V_ZERO;
	}

/* Custom function that calculates the square root of a number 'n' using Newton's method. */
double _sqrt(const double value)
	{
		double prev_approx = V_ZERO;
		double approach = V_ONE;

		do
			{
				prev_approx = approach;
				approach = SUM_OF_QUOTIENTS(value, prev_approx);
			}
		while (_abs(DIFFERENCE(approach, prev_approx)) >= V_EPSILON);

		return approach;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		double a = V_ZERO, b = V_ZERO, c = V_ZERO;	//Coefficients.
		double d = V_ZERO;				//Discriminant or Determinant.
		double re = V_ZERO, im = V_ZERO;		//Real Part, Imaginary Part.

		/* Introductory presentation headers. */
		printf("+---|----+---|----+---|----+---|\n");
		printf("| Quadratic Equation Solution. |\n");
		printf("+---|----+---|----+---|----+---|\n");
		printf("> Coefficient 'a' : ");
		scanf("%lf", &a);
		printf("> Coefficient 'b' : ");
		scanf("%lf", &b);
		printf("> Coefficient 'c' : ");
		scanf("%lf", &c);

		/* Calculation Results for the Quadratic Equation. */
		printf("\n");
		printf("+---|----+---|----+---|----+---|\n");
		printf("|  Quadratic Equation Results. |\n");
		printf("+---|----+---|----+---|----+---|\n");

		/* If the coefficient 'a' is equal to zero, the case is one of degeneracy or a single root. */
		if (a == V_ZERO)
			if (b == V_ZERO)
				printf("The equation is degenerate!\n") ;
			else
				printf("The only possible root is: [%1f].\n", UNIQUE_ROOT(b, c));
		else
			{
				/* Preliminary calculations using macros for the validation of the quadratic equation. */
				re = SINGLE_ROOT(a, b);		/* Real value obtained via a simple root. */
				d = DISCRIMINATE(a, b, c);	/* Discriminant or Determinant. */

				/* Obtaining the imaginary part of a complex number. */
				im = _sqrt(_abs(d)) / DENOMINATOR(a);

				/* Validate the discriminant 'd' if and only if the coefficient 'a' is non-zero. */
				printf("Determinant or Discriminant.\n");
				printf("* 'd':\t[%lf].\n", d);

				/* If the discriminant 'd' is greater than or equal to zero,
				   then the roots lie in the set of real numbers. */
				if (d >= V_ZERO)
					{
						printf("\nRoyal Roots.\n");
						printf("* 'x1':\t[%lf].\n", re + im);
						printf("* 'x2':\t[%lf].\n", re - im);
					}

				/* If the discriminant 'd' is less than zero,
				   then the roots lie in the set of complex or imaginary numbers. */
				if (d < V_ZERO)
					{
						printf("\nComplex Roots.\n");
						printf("* 'x1':\t[%lf] + {%lf}'i'.\n", re, _abs(im));
						printf("* 'x2':\t[%lf] - {%lf}'i'.\n", re, _abs(im));
					}
			}

		/* Program termination messages. */
		printf("\nDone!\n");
		printf("This programa has ended.\n");

		return V_ZERO;
	}
