/********** Trigonometric functions of sine and cosine. **********
 ** Source Code:	Sin_Cos.c	               		**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Friday, June 30, 2023.          	**
 ** Purpose:		Calculates through the Taylor series	**
 **			the trigonometric functions of sine and	**
 **			cosine according to a determined value	**
 **			that is expressed in radians.		**
*****************************************************************/
// C Standard Libraries.
#include <stdio.h>

// Work Symbolic Constants.
#define EVEN_AND_ODD(value, addneu)	(2 * (value) + (addneu))
#define NUM_TERMS			11
#define PI				3.14159265359
#define RADIANS(angle)			((angle) * PI / 180.0)

//Numeric Symbolic Constants.
#define V_MINUS_ONE			-1
#define V_ONE				1
#define V_ZERO				0

/*****************************************************************
 ** Function:		factorial.				**
 ** Explanation:	Gets the value of the factorial of any  **
 **			integer by recursively multiplying it by**
 **			its descendant surrogate numbers.	**
 ** Input Parms:	integer int_n.                          **
 ** Output Parms:	None.					**
 ** Result:		Factorial from 'i' to 'n'.		**
 ****************************************************************/
double factorial(int int_n)
    {
        return (int_n <= V_ONE) ? V_ONE
        		: (double)int_n * factorial(int_n - V_ONE);
    }

/*****************************************************************
 ** Function:		potency.				**
 ** Explanation:	Returns a base coefficient raised to the**
 **			specified power recursively by means of	**
 **			successive multiplications.		**
 ** Input Parms:	double dbl_base,			**
 **			integer int_exp.			**
 ** Output Parms:	None.					**
 ** Result:		dbl_base raised to int_exp.		**
 ****************************************************************/
double potency(double dbl_base, int int_exp)
    {
        return (int_exp == V_ZERO) ? V_ONE
			: dbl_base * potency(dbl_base, int_exp - V_ONE);
    }

/*****************************************************************
 ** Function:		sin_cos.				**
 ** Explanation:	The value of the sine or cosine is	**
 **			obtained as a result, depending on an	**
 **			additive neutral passed as a parameter, **
 **			of a certain value in angles expressed	**
 **			in radians, through the Taylor series.	**
 ** Input Parms:	double dbl_base,			**
 **			integer int_addneut.			**
 ** Output Parms:	None.					**
 ** Result:		To calculate the trigonometric function **
 **			of sine, the Taylor number series	**
 **			applied with 'odd' numbers is:		**
 **			sin(x) = x - (x^3 / 3!) + (x^5 / 5!) -	**
 **			(x^7 / 7!) + ...			**
 **								**
 **			To calculate the trigonometric function **
 **			of cosine, the Taylor number series	**
 **			applied with 'even' numbers is:		**
 **			cos(x) = 1 - (x^2 / 2!) + (x^4 / 4!) -	**
 **			(x^6 / 6!) + ...			**
 **								**
 ****************************************************************/
double sin_cos(double dbl_angle, int int_addneut)
    {
        double dbl_outcome = V_ZERO;

        for (int int_i = V_ZERO; int_i < NUM_TERMS; int_i++)
            {
                dbl_outcome += potency(V_MINUS_ONE, int_i)
                            *  potency(dbl_angle, EVEN_AND_ODD(int_i, int_addneut))
                            /  factorial(EVEN_AND_ODD(int_i, int_addneut));
            }

        return dbl_outcome;
    }

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	Main module in which the objectives of	**
 **			this program are developed.		**
 ** Input Parms:	None.					**
 ** Output Parms:	None.					**
 ** Result:		The resulting values of the		**
 **			trigonometric functions of the sine and	**
 **			cosine of an angle expressed in radians **
 **			are obtained.				**
 ****************************************************************/
int main(int int_argc, char *ch_argv[])
    {
        double dbl_value = V_ZERO;
        double dbl_radns = V_ZERO;

	printf("Valor en grados: ");
	scanf("%lf", &dbl_value);

        dbl_radns=RADIANS(dbl_value);

        printf("\n");
        printf("El valor  de [%g] a radianes aprox es: [%g].\n", dbl_value, dbl_radns);
        printf("El seno   de [%g] aproximadamente  es: [%g].\n", dbl_value, sin_cos(dbl_radns, V_ONE));
        printf("El coseno de [%g] aproximadamente  es: [%g].\n", dbl_value, sin_cos(dbl_radns, V_ZERO));

        return dbl_radns;
    }
