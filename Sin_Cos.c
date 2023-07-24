/********** Trigonometric functions of sine and cosine. **********
 ** Source Code:	Sin_Cos.c	               		**
 ** Author:		Gustavo Islas Gálvez.			**
 ** Creation Date:	Thursday, August 31, 2023.          	**
 ** Purpose:		Calculates through the Taylor series	**
 **			the trigonometric functions of sine and	**
 **			cosine according to a determined value	**
 **			that is expressed in radians.		**
 **			Most of the math functions were		**
 **			implemented.				**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//Working Macros.
#define EVEN_AND_ODD(value, addneutr)	(V_TWO * (value) + (addneutr))
#define RADIANS(angle)			((angle) * V_PI / V_HALF_CIRC)

//Numeric Symbolic Constants.
#define V_HALF_CIRC			180.0
#define V_NUM_TERMS			11
#define V_MINUS_ONE			-1.0
#define V_ONE				1
#define V_PI				3.14159265359
#define	V_TWO				2
#define V_ZERO				0

/*****************************************************************
 ** Function:		absolute.				**
 ** Explanation:	Returns as a result the positive or 	**
 **			unsigned value of a certain value,	**
 **			as long as it is subjected to a series	**
 **			of conditions such as being greater	**
 **			than zero, to be positive; be zero,	**
 **			to be zero, and less than zero,		**
 **			to become positive by sign		**
 **			neutralization.				**
 ** Input Parms:	double int_value.			**
 ** Output Parms:	None.					**
 ** Result:		the base value (int_value) is		**
 **			sign-neutralized.			**
 ****************************************************************/
double absolute(int int_value)
	{
		return	(int_value==V_ZERO) ? V_ZERO
		: (int_value>V_ZERO) ? int_value : -int_value;
	}

/*****************************************************************
 ** Function:		factorial.				**
 ** Explanation:	Gets the value of the factorial of any	**
 **			integer by recursively multiplying it by**
 **			its descendant surrogate numbers.	**
 ** Input Parms:	integer int_num.			**
 ** Output Parms:	None.					**
 ** Result:		Factorial from 'i' to 'n'.		**
 ****************************************************************/
double factorial(int int_num)
    {
        return (int_num <= V_ZERO) ? V_ONE
        	: (double) int_num * factorial(int_num - V_ONE);
    }

/*****************************************************************
 ** Function:		potency.				**
 ** Explanation:	Returns a base coefficient raised to the**
 **			specified power recursively by means of	**
 **			successive multiplications or divisions.**
 **								**
 **			This function can also be programmed	**
 **			recursively in the form:		**
 **			(int_exp == V_ZERO) ? V_ONE : dbl_base	**
 **			 * potency(dbl_base, int_exp - V_ONE);	**
 **								**
 ** Input Parms:	double dbl_base,			**
 **			integer int_exp.			**
 ** Output Parms:	None.					**
 ** Result:		dbl_base raised to int_exp.		**
 ****************************************************************/
double potency(double dbl_base, int int_exp)
	{
		double dbl_ret=V_ONE;
		int int_exp_pow=absolute(int_exp);

		for (int int_i=V_ZERO; int_i<int_exp_pow; int_i++)
			dbl_ret = (int_exp > V_ZERO) ? dbl_ret * dbl_base :
				  (int_exp < V_ZERO) ? dbl_ret / dbl_base : V_ONE;

		return dbl_ret;
	}

/*****************************************************************
 ** Function:		sinus_cosinus.				**
 ** Explanation:	The value of the sine or cosine is	**
 **			obtained as a result, depending on an	**
 **			additive neutral passed as a parameter, **
 **			of a certain value in angles expressed	**
 **			in radians, through the Taylor series.	**
 ** Input Parms:	double dbl_base,			**
 **			integer int_addneutr.			**
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
 ****************************************************************/
double sinus_cosinus(double dbl_angle, int int_addneutr)
    {
        double dbl_outcome=V_ZERO;

        for (int int_i=V_ZERO; int_i<V_NUM_TERMS; int_i++)
                dbl_outcome += potency(V_MINUS_ONE, int_i)
                            *  potency(dbl_angle, EVEN_AND_ODD(int_i, int_addneutr))
                            /  factorial(EVEN_AND_ODD(int_i, int_addneutr));

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
int main()
    {
        double dbl_value=V_ZERO;
        double dbl_radns=V_ZERO;

	printf("+---|----+---|----+---|----+---|----+---|----+---|--\n");
	printf("| Funciones de seno y coseno por series de Taylor. |\n");
	printf("+---|----+---|----+---|----+---|----+---|----+---|--\n");
	printf("Valor en grados: ");
	scanf("%lf", &dbl_value);

        dbl_radns=RADIANS(dbl_value);

        printf("\n");
	printf("+---|----+---|----+---|----+---|----+---|----+---|--\n");
	printf("| Funciones trigonométricas del seno y del coseno. |\n");
	printf("+---|----+---|----+---|----+---|----+---|----+---|--\n");
        printf("| Valor en grados   : [%lf].\n", dbl_value);
	printf("| Valor en radianes : [%lf].\n", dbl_radns);
	printf("+---|----+---|----+---|----+---|----+---|----+---|--\n");
        printf("| Valor del seno    : [%lf].\n", sinus_cosinus(dbl_radns, V_ONE));
        printf("| Valor del coseno  : [%lf].\n", sinus_cosinus(dbl_radns, V_ZERO));
	printf("+---|----+---|----+---|----+---|----+---|----+---|--\n");
	printf("\n");

        return dbl_radns;
    }
