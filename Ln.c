/****************** Natural logarithm base 'e'. ******************
 ** Source Code:        Ln.c					**
 ** Author:             Gustavo Islas Gálvez.			**
 ** Creation Date:      Thursday, August 31, 2023.		**
 ** Purpose:		This program calculates through the	**
 **			Taylor series the natural logarithm	**
 **			with a base 'x' determined at a certain	**
 **			number of calculation cycles, taking	**
 **			into consideration the development of	**
 **			the following power series:		**
 **								**
 **			ln(x) = 2 * { [(1/1) * ((x-1)/(x+1))^1]	**
 **			+ [(1/3) * ((x-1)/(x+1))^3]		**
 **			+ [(1/5) * ((x-1)/(x+1))^5]		**
 **			+ [(1/7) * ((x-1)/(x+1))^7] + [...] }	**
 **			For all 'x' -> (x>0).			**
 **								**
*****************************************************************/
//C Standard Libraries.
#include <stdio.h>

//Numeric Symbolic Constants.
#define V_MINUS_ONE	-1.0
#define V_NUM_TERMS	20
#define V_TWO		2.0
#define V_ONE		1.0
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
 ** Function:           ln.					**
 ** Explanation:	Calculates the natural logarithm of a	**
 **			defined number of base 'x' through the	**
 **			Taylor power series, based on which as	**
 **			many calculations are developed as	**
 **			there are number of terms to obtain a	**
 **			good approximation.			**
 **			This calculation is subjected to the	**
 **			following series:			**
 **								**
 **			ln(x) = 2 * { [(1/1) * ((x-1)/(x+1))^1]	**
 **			+ [(1/3) * ((x-1)/(x+1))^3]		**
 **			+ [(1/5) * ((x-1)/(x+1))^5]		**
 **			+ [(1/7) * ((x-1)/(x+1))^7] + [...] }	**
 **			For all 'x' -> (x>0).			**
 **								**
 ** Input Parms:        double dbl_x.				**
 ** Output Parms:       None.					**
 ** Result:		Returns the natural logarithm based on	**
 **			the exponential natural number 'e',	**
 **			that is, it is its inverse.		**
 ****************************************************************/
double ln(double dbl_x)
	{
		double dbl_ret=V_ZERO;

		for (int int_i=V_ZERO; int_i<V_NUM_TERMS; int_i++)
			dbl_ret += (V_ONE / (V_TWO * int_i + V_ONE)) *
				    potency(((dbl_x + V_MINUS_ONE) / (dbl_x + V_ONE)), (V_TWO * int_i + V_ONE));

		return V_TWO * dbl_ret;
	}

/*****************************************************************
 ** Function:		main.					**
 ** Explanation:	In this main module the user is asked	**
 **			for the base 'x' to calculate his	**
 **			natural logarithm based on the		**
 **			exponential natural number 'e', and	**
 **			calls a function that performs a series	**
 **			of cyclical calculations to get a good	**
 **			approximation.				**
 **								**
 **			ln(x) = 2*{ [ (1/(2*i+1)) *		**
 **				((x-1)/(x+1)) ^ (2*i+1) ] +	**
 **				[...] }	-> (x>0).		**
 **								**
 ** Input Parms:        None.                                   **
 ** Output Parms:       None.                                   **
 ** Result:		Natural logarithm based on the natural	**
 **			number 'e' exponential.			**
 ****************************************************************/
int main()
	{
		double dbl_n=V_ZERO;

		printf("+---|----+---|----+---|----+---|---|----+---|---+\n");
		printf("| Logaritmo natural base 'e' para una 'x' dada. |\n");
		printf("+---|----+---|----+---|----+---|---|----+---|---+\n");
		printf("Base 'x' : ");
		scanf("%lf", &dbl_n);

		printf("\n");
		printf("+---|----+---|----+---|----+---|---|----+---|---+\n");
		printf("| Valor de la base 'e' para 'x' : [%lf].\n", dbl_n);
		printf("| Logaritmo natural de base 'e' : [%lf].\n", ln(dbl_n));
		printf("+---|----+---|----+---|----+---|---|----+---|---+\n");
		printf("\n");

		return dbl_n;
	}
