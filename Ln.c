/****************** Natural logarithm base 'e'. ******************
 ** Source Code:        Ln.c					**
 ** Author:             Gustavo Islas Gálvez.			**
 ** Creation Date:      Saturday, December 30, 2023.		**
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
#define V_MINUS_ONE	-1
#define V_NUM_TERMS	65536
#define V_TWO		2.0
#define V_ONE		1
#define V_ZERO		0

/*****************************************************************
 ** Function:           static double dbl_potency.		**
 ** Explanation:        Returns a base coefficient raised to the**
 **                     specified power recursively by means of **
 **                     successive multiplications or divisions.**
 **                                                             **
 **                     This function can also be programmed    **
 **                     recursively in the form:                **
 **                     (szt_exp == V_ZERO) ? V_ONE : dbl_base  **
 **                      * dbl_potency(dbl_base,		**
 **					szt_exp - V_ONE);	**
 **                                                             **
 ** Input Parms:        const double dbl_base,			**
 **                     const size_t szt_exp.			**
 ** Output Parms:       None.                                   **
 ** Result:             dbl_base raised to int_exp.             **
 ****************************************************************/
static double dbl_potency(double dbl_base, size_t szt_exp)
	{
		return	(szt_exp > V_ZERO) ? dbl_base * dbl_potency(dbl_base, szt_exp + V_MINUS_ONE) :
			(szt_exp == V_ZERO) ? V_ONE :
			(szt_exp < V_ZERO) ? dbl_base / dbl_potency(dbl_base, szt_exp + V_ONE) : V_ONE;
	}

/*****************************************************************
 ** Function:		static double ln.			**
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
 ** Input Parms:        const double dbl_x.			**
 ** Output Parms:       None.					**
 ** Result:		Returns the natural logarithm based on	**
 **			the exponential natural number 'e',	**
 **			that is, it is its inverse.		**
 ****************************************************************/
static double ln(const double dbl_x)
	{
		double dbl_outcome = V_ZERO;

		for (size_t szt_idx = V_ZERO; szt_idx < V_NUM_TERMS; szt_idx++)
			dbl_outcome += (V_ONE / (V_TWO * szt_idx + V_ONE)) *
				dbl_potency(((dbl_x + V_MINUS_ONE) / (dbl_x + V_ONE)), (V_TWO * szt_idx + V_ONE));

		return V_TWO * dbl_outcome;
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
		double dbl_ln = V_ZERO;
		double dbl_n = V_ZERO;

		printf("+---|----+---|----+---|----+---|---|---\n");
		printf("| Natural logarithm by Taylor series. |\n");
		printf("+---|----+---|----+---|----+---|---|---\n");
		printf("Base 'x' : ");
		scanf("%lf", &dbl_n);

		dbl_ln = ln(dbl_n);	//Call the natural logarithm function.

		printf("\n");
		printf("+---|----+---|----+---|----+---|---|---\n");
		printf("| Base value\t: [%lf].\n", dbl_n);
		printf("| Terms value\t: [%d].\n", V_NUM_TERMS);
		printf("| Natural log\t: [%lf].\n", dbl_ln);
		printf("+---|----+---|----+---|----+---|---|---\n");
		printf("\n");

		return V_ZERO;
	}
