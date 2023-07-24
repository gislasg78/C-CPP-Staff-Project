/************* Euler exponential natural number 'e'. *************
 ** Source Code:        Expn.c					**
 ** Author:             Gustavo Islas Gálvez.			**
 ** Creation Date:      Thursday, August 31, 2023.		**
 ** Purpose:		This program is in charge of raising	**
 **			Euler's natural number 'e' to a		**
 **			determined power 'x', and it is solved	**
 **			through power series or Taylow series.	**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//Numeric Symbolic Constants.
#define V_NUM_TERMS	20
#define V_ONE		1
#define V_ZERO		0

/*****************************************************************
 ** Function:           absolute.                               **
 ** Explanation:        Returns as a result the positive or     **
 **                     unsigned value of a certain value,      **
 **                     as long as it is subjected to a series  **
 **                     of conditions such as being greater     **
 **                     than zero, to be positive; be zero,     **
 **                     to be zero, and less than zero,         **
 **                     to become positive by sign              **
 **                     neutralization.                         **
 ** Input Parms:        double int_value.                       **
 ** Output Parms:       None.                                   **
 ** Result:             the base value (int_value) is           **
 **                     sign-neutralized.                       **
 ****************************************************************/
double absolute(int int_value)
	{
		return  (int_value==V_ZERO) ? V_ZERO
		: (int_value>V_ZERO) ? int_value : -int_value;
	}

/*****************************************************************
 ** Function:           factorial.                              **
 ** Explanation:        Gets the value of the factorial of any  **
 **                     integer by recursively multiplying it by**
 **                     its descendant surrogate numbers.       **
 ** Input Parms:        integer int_num.                        **
 ** Output Parms:       None.                                   **
 ** Result:             Factorial from 'i' to 'n'.              **
 ****************************************************************/
double factorial(int int_num)
	{
		return (int_num <= V_ZERO) ? V_ONE
			: (double) int_num * factorial(int_num - V_ONE);
	}

/*****************************************************************
 ** Function:           potency.                                **
 ** Explanation:        Returns a base coefficient raised to the**
 **                     specified power recursively by means of **
 **                     successive multiplications or divisions.**
 **                                                             **
 **                     This function can also be programmed    **
 **                     recursively in the form:                **
 **                     (int_exp == V_ZERO) ? V_ONE : dbl_base  **
 **                      * potency(dbl_base, int_exp - V_ONE);  **
 **                                                             **
 ** Input Parms:        double dbl_base,                        **
 **                     integer int_exp.                        **
 ** Output Parms:       None.                                   **
 ** Result:             dbl_base raised to int_exp.             **
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
 ** Function:           expn.					**
 ** Explanation:	Computes Euler's natural number 'e'	**
 **			through power series given a specified	**
 **			number of terms, in such a way that the	**
 **			series is obtained: (x^0 / 0!) +	**
 **			(x^1 / 1!) + (x^2 / 2!) + (x^3 / 3!)...	**
 ** Input Parms:        double dbl_x.				**
 ** Output Parms:       None.					**
 ** Result:             'e' raised to dbl_x.			**
 ****************************************************************/
double expn(double dbl_x)
	{
		double dbl_ret=V_ZERO;

		for (int int_i=V_ZERO; int_i<V_NUM_TERMS; int_i++)
			dbl_ret+=potency(dbl_x, int_i)/factorial(int_i);

		return dbl_ret;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	In the main module of this program,	**
 **			simply request the power 'x' to which	**
 **			the Euler's natural number 'e' is going **
 **			to be calculated raised to said power	**
 **			'x' by means of power series or Taylor	**
 **			series.					**
 ** Input Parms:        None.                                   **
 ** Output Parms:       None.                                   **
 ** Result:		Euler's natural number 'e' raised to	**
 **			the given 'x' power.			**
 ****************************************************************/
int main()
	{
		double dbl_x=V_ZERO;

		printf("+---|----+---|----+---|----+---|--\n");
		printf("| Número neperiano 'e' de Euler. |\n");
		printf("+---|----+---|----+---|----+---|--\n");
		printf("Potencia  'x' : ");
		scanf("%lf", &dbl_x);

		printf("\n");
		printf("+---|----+---|----+---|----+---|--\n");
		printf("| Potencia  'x' : [%lf].\n", dbl_x);
		printf("| Euler 'e'^'x' : [%lf].\n", expn(dbl_x));
		printf("+---|----+---|----+---|----+---|--\n");
		printf("\n");

		return dbl_x;
	}
